/**
 * helper.hh
 *
 * @date  : Oct 13, 2018
 * @author: lpzun
 */

#ifndef PARSER_QULTL_EXPR_HH_
#define PARSER_QULTL_EXPR_HH_

#include "head.hh"

namespace qultl {

enum class expr_op {
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

ostream& operator<<(ostream& os, const expr_op& o);

/**
 * types of expression components
 */
enum class type_expr_node {
	OPERATOR, //!< OPERATOR
	VARIABLE, //!< VARIABLE
	CONSTANT //!< CONSTANT
};

struct expr {
	deque<expr_op> operators;
	deque<string> operands;
};

using nat = unsigned int;
/// operator
using alpha = string;

using alphabet = unordered_set<alpha>;

/**
 * expression components
 */
class expr_node {
public:
	expr_node(const type_expr_node& type, const expr_op& op);
	expr_node(const type_expr_node& type, const nat v);
	expr_node(const type_expr_node& type, const alpha& a);
	~expr_node();

	expr_op get_op() const {
		return _op;
	}

	type_expr_node get_type() const {
		return _type;
	}

	nat get_val() const {
		return _val;
	}

	const alpha& get_var() const {
		return _var;
	}

	friend ostream& operator<<(ostream& os, const expr_node& e);
private:
	type_expr_node _type;
	expr_op _op;
	nat _val;
	alpha _var;
};

class ast_node {
public:
	expr_node _node;
	shared_ptr<ast_node> left;
	shared_ptr<ast_node> right;

	ast_node(const expr_node& node) :
			_node(node), left(nullptr), right(nullptr) {
	}
	~ast_node() {

	}
};

/// formula
using formula = deque<expr_node>;

/**
 * A helper class for qultl helper.
 *
 * It stores the parsed result.
 */
class qultl_expr {
public:
	qultl_expr(const alphabet& E);
	~qultl_expr();

	void parse_phi(const string& var);
	void parse_phi(const expr_op& op);
	void parse_phi(const nat val);

	bool syntax_check(const string& qexpr);
	bool is_legal_alpha(const alpha& a);
	void print();

	const formula& get_phi() const {
		return phi;
	}

	void build_ast();

private:
	formula phi;
	alphabet _E;
	shared_ptr<ast_node> root;


	void build_ast(const expr_node& enode,
			stack<shared_ptr<ast_node>>& worklist);
	void print(const shared_ptr<ast_node> root);
};

} /* namespace qultl */

#endif /* PARSER_QULTL_EXPR_HH_ */
