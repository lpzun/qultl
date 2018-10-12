/*
 * parser.hh
 *
 * @date  : Oct 11, 2018
 * @author: lpzun
 */

#ifndef PARSER_PARSER_HH_
#define PARSER_PARSER_HH_

#include "../util/head.hh"

namespace qultl {

using formula = deque<string>;

/**
 * A helper class for qultl helper.
 *
 * It stores the parsed result.
 */
class qultl_helper {
public:
	qultl_helper();
	~qultl_helper();

	void parse_and_update(const string& qexpr);
	bool syntax_check(const string& qexpr);
	bool is_legal_message(const string& msg);
private:
	formula phi;
	deque<formula> formulae;
	unordered_set<string> alphabet;
};

class qultl_parser {
public:
	qultl_parser();
	~qultl_parser();
};

} /* namespace qultl */

#endif /* PARSER_PARSER_HH_ */
