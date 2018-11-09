/**
 * parser.cc
 *
 * @date  : Oct 11, 2018
 * @author: lpzun
 */

#include "parser.hh"

namespace qultl {

alphabet queue_parser::E;
/**
 *
 * @param filename
 * @return
 */
deque<string> queue_parser::parse_intput_queue(const string& filename) {
	deque<string> Q;
	/// original input file, possibly with comments
	ifstream org_in(filename.c_str());
	if (!org_in.good())
		throw runtime_error("Input file does not exist!");
	remove_comments(org_in, "/tmp/tmp.pds.no_comment", "//");
	org_in.close();

	ifstream new_in("/tmp/tmp.pds.no_comment");
	if (!new_in.good())
		throw runtime_error("Something wrong when reading the input CPDS!");

	string line;
	string var;
	string sep;
	string val;

	deque<string> EE;
	while (std::getline(new_in, line)) {
		if (line == "" || line.size() <= 2)
			continue;
		istringstream iss(line);
		iss >> var >> sep >> val;
		if (var == "Q")
			Q = split(val, ',');
		if (var == "E")
			EE = split(val, ',');
	}
	for (const auto& a : EE) {
		queue_parser::E.emplace(a);
	}
	return Q;
}

/**
 * @brief remove the comments of input files
 * @param in
 * @param filename
 * @param comment
 */
void queue_parser::remove_comments(istream& in, const string& filename,
		const string& comment) {
	ofstream out(filename.c_str());
	remove_comments(in, out, comment);
}

/**
 * remove comments
 * @param in
 * @param out
 * @param comment
 */
void queue_parser::remove_comments(istream& in, ostream& out,
		const string& comment) {
	string line;
	while (getline(in, line = "")) {
		auto comment_start = line.find(comment);
		out
				<< (comment_start == string::npos ?
						line : line.substr(0, comment_start)) << endl;
	}
}

/**
 *
 * @param in
 * @param line
 * @param eol
 * @return bool
 */
bool queue_parser::getline(istream& in, string& line, const char eol) {
	char c = 0;
	while (in.get(c) ? c != eol : false)
		line += c;
	return c != 0;
}

/**
 * @brief split a string into a vector of strings via a delimiter
 * @param s: object string
 * @param delim: a delimiter
 * @return a vector of string
 */
deque<string> queue_parser::split(const string &s, const char delim) {
	deque<string> elems;
	istringstream ss(s);
	string item;
	while (std::getline(ss, item, delim)) {
		elems.emplace_back(item);
	}
	return elems;
}

///////////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////////
qultl_parser::qultl_parser(const string& filename, const alphabet& _E) :
		phi() {
	FILE *ltl_file = fopen(filename.c_str(), "r");
	if (!ltl_file)
		throw runtime_error(filename + " open failed!");

	cout << "start parsing QuLTL ...\n";
	yyin = ltl_file;
	qultl_expr qh(queue_parser::E);

	yy::qultl parser(qh);
	int result = parser.parse();
	if (result != 0)
		throw runtime_error(
				"Parser exit with error code: " + std::to_string(result));
	qh.build_ast();
	cout << "phi := ";
	qh.print();
	phi = qh.get_phi();
}

qultl_parser::~qultl_parser() {

}

} /* namespace qultl */
