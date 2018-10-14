/*
 * helper.hh
 *
 * @date  : Oct 13, 2018
 * @author: lpzun
 */

#ifndef PARSER_HELPER_HH_
#define PARSER_HELPER_HH_

#include "head.hh"

namespace qultl {
/// operator
using alpha = string;
/// operand
using opd = string;
/// formula
using formula = deque<string>;
using alphabet = unordered_set<string>;

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
	bool is_legal_alpha(const alpha& a);
	void print();
private:
	formula phi;
	deque<formula> formulae;
	alphabet E;
};



} /* namespace qultl */

#endif /* PARSER_HELPER_HH_ */
