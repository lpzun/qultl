/**
 * parser.hh
 *
 * @date  : Oct 11, 2018
 * @author: lpzun
 */

#ifndef PARSER_PARSER_HH_
#define PARSER_PARSER_HH_

#include "qultl.tab.hh"
#include "head.hh"

extern FILE *yyin;

namespace qultl {


using event_queue = pair<deque<alpha>, deque<alpha>>;

class queue_parser {
public:
	static event_queue parse_intput_queue(const string& filename);
	static alphabet E;
private:
	static void remove_comments(istream& in, ostream& out,
			const string& comment);
	static void remove_comments(istream& in, const string& filename,
			const string& comment);
	static bool getline(istream& in, string& line, const char eol = '\n');

	static deque<string> split(const string &s, const char delim);
};

///////////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////////

class qultl_parser {
public:
	qultl_parser(const string& filename, const alphabet& _E);
	~qultl_parser();

	const shared_ptr<ast_node>& get_phi() const {
		return phi;
	}

private:
	shared_ptr<ast_node> phi;
};

} /* namespace qultl */

#endif /* PARSER_PARSER_HH_ */
