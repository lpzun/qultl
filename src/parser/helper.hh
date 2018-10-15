/**
 * helper.hh
 *
 * @date  : Oct 13, 2018
 * @author: lpzun
 */

#ifndef PARSER_HELPER_HH_
#define PARSER_HELPER_HH_

#include "head.hh"

namespace qultl {

enum class op {
	/// temporal operators
	TMP_F = 0,
	TMP_G,
	TMP_X,
	TMP_U,
	/// queue operators
	COUNT,
	SIZE,
	/// logical operators
	NEGATION,
	AND,
	OR,
	IMPLICATION,
	EQUIVALENCE,
	/// relation operators
	EQUAL,
	NOT_EQUAL,
	LESS_THAN,
	GREATER_THAN,
	LESS_THAN_EQ,
	GREATER_THAN_EQ,
	/// arithmetic operators
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	/// parentheses
	PARENTHSIS,
	///
	CONST_T,
	CONST_F
};

ostream& operator<<(ostream& os, const op& o);

struct expr {
	deque<op> operators;
	deque<string> operands;
};

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

	void parse_phi(const string& qexpr);
	void parse_phi(const op& op);
	bool syntax_check(const string& qexpr);
	bool is_legal_alpha(const alpha& a);
	void print();

	const formula& get_phi() const {
		return phi;
	}

private:
	formula phi;
	deque<op> operators;
	alphabet E;
};

} /* namespace qultl */

#endif /* PARSER_HELPER_HH_ */
