/**
 * helper.cc
 *
 * @date  : Oct 13, 2018
 * @author: lpzun
 */

#include <qultl_expr.hh>

namespace qultl {

ostream& operator<<(ostream& os, const expr_op& op) {
	switch (op) {
	case expr_op::TMP_F:
		os << 'F';
		break;
	case expr_op::TMP_G:
		os << 'G';
		break;
	case expr_op::TMP_X:
		os << 'X';
		break;
	case expr_op::TMP_U:
		os << 'U';
		break;
	case expr_op::TMP_N:
		os << '~';
		break;
	case expr_op::COUNT:
		os << '#';
		break;
	case expr_op::SIZE:
		os << "[]";
		break;
	case expr_op::NEGATION:
		os << '!';
		break;
	case expr_op::AND:
		os << '&';
		break;
	case expr_op::OR:
		os << '|';
		break;
	case expr_op::IMPLICATION:
		os << "->";
		break;
	case expr_op::EQUIVALENCE:
		os << "<->";
		break;
	case expr_op::EQUAL:
		os << '=';
		break;
	case expr_op::NOT_EQUAL:
		os << "!=";
		break;
	case expr_op::LESS_THAN:
		os << '<';
		break;
	case expr_op::GREATER_THAN:
		os << '>';
		break;
	case expr_op::LESS_THAN_EQ:
		os << "<=";
		break;
	case expr_op::GREATER_THAN_EQ:
		os << ">=";
		break;
	case expr_op::ADDITION:
		os << '+';
		break;
	case expr_op::SUBTRACTION:
		os << '-';
		break;
	case expr_op::MULTIPLICATION:
		os << '*';
		break;
	case expr_op::PARENTHSIS:
		os << "()";
		break;
	default:
		os << "illgeal operator!";
		break;
	}
	return os;
}

expr_node::expr_node(const type_expr_node& type, const expr_op& op) :
		_type(type), _op(op), _val(), _var() {

}
expr_node::expr_node(const type_expr_node& type, const nat val) :
		_type(type), _op(), _val(val), _var() {

}
expr_node::expr_node(const type_expr_node& type, const alpha& var) :
		_type(type), _op(), _val(), _var(var) {

}

expr_node::~expr_node() {

}

ostream& operator<<(ostream& os, const expr_node& e) {
	switch (e.get_type()) {
	case type_expr_node::OPERATOR:
		os << e.get_op();
		break;
	case type_expr_node::CONSTANT:
		os << e.get_val();
		break;
	default:
		os << e.get_var();
		break;
	}
	return os;
}

qultl_expr::qultl_expr(const alphabet& E) :
		phi(), _E(E) {
}

qultl_expr::~qultl_expr() {

}

void qultl_expr::parse_phi(const expr_op& op) {
	phi.emplace_back(type_expr_node::OPERATOR, op);
}
void qultl_expr::parse_phi(const string& var) {
	if (!is_legal_alpha(var))
		throw runtime_error("Illegal message in LTL formula!");
	phi.emplace_back(type_expr_node::VARIABLE, var);
}

void qultl_expr::parse_phi(const nat val) {
	phi.emplace_back(type_expr_node::CONSTANT, val);
}

bool qultl_expr::syntax_check(const alpha& var) {
	return false;
}

bool qultl_expr::is_legal_alpha(const alpha& var) {
	return _E.find(var) != _E.end();
}

void qultl_expr::build_ast() {
	stack<shared_ptr<ast_node>> worklist;
	for (const auto enode : phi) {
		switch (enode.get_type()) {
		case type_expr_node::VARIABLE:
			worklist.push(std::make_shared<ast_node>(enode));
			break;
		case type_expr_node::CONSTANT:
			worklist.push(std::make_shared<ast_node>(enode));
			break;
		default:
			build_ast(enode, worklist);
			break;
		}
	}
	root = worklist.top();
}

void qultl_expr::build_ast(const expr_node& enode,
		stack<shared_ptr<ast_node>>& worklist) {
	switch (enode.get_op()) {
	case expr_op::TMP_F:
	case expr_op::TMP_G:
	case expr_op::TMP_X:
	case expr_op::TMP_N: {
		auto sp = make_shared<ast_node>(enode);
		const auto lch = worklist.top();
		worklist.pop();
		sp->left = lch;
		worklist.push(sp);
	}
		break;
	case expr_op::TMP_U: {
		auto sp = make_shared<ast_node>(enode);
		const auto rch = worklist.top();
		worklist.pop();
		sp->right = rch;

		const auto lch = worklist.top();
		worklist.pop();
		sp->left = lch;

		worklist.push(sp);
	}
		break;
	case expr_op::COUNT: {
		auto sp = make_shared<ast_node>(enode);
		const auto lch = worklist.top();
		worklist.pop();
		sp->left = lch;
		worklist.push(sp);
	}
		break;
	case expr_op::SIZE: {
		auto sp = make_shared<ast_node>(enode);
		worklist.push(sp);
	}
		break;
	case expr_op::NEGATION: {
		auto sp = make_shared<ast_node>(enode);
		const auto lch = worklist.top();
		worklist.pop();
		sp->left = lch;
		worklist.push(sp);
	}
		break;
	case expr_op::AND:
	case expr_op::OR:
	case expr_op::IMPLICATION:
	case expr_op::EQUIVALENCE:
	case expr_op::EQUAL:
	case expr_op::NOT_EQUAL:
	case expr_op::LESS_THAN:
	case expr_op::GREATER_THAN:
	case expr_op::LESS_THAN_EQ:
	case expr_op::GREATER_THAN_EQ:
	case expr_op::ADDITION:
	case expr_op::SUBTRACTION:
	case expr_op::MULTIPLICATION: {
		auto sp = make_shared<ast_node>(enode);
		const auto rch = worklist.top();
		worklist.pop();
		sp->right = rch;

		const auto lch = worklist.top();
		worklist.pop();
		sp->left = lch;

		worklist.push(sp);
	}
		break;
	case expr_op::PARENTHSIS: {
		auto sp = make_shared<ast_node>(enode);
		const auto lch = worklist.top();
		worklist.pop();
		sp->left = lch;
		worklist.push(sp);
	}
		break;
	default:
		throw runtime_error("illgeal operator!");
		break;
	}
}

void qultl_expr::print() {
	print(root);
}

void qultl_expr::print(const shared_ptr<ast_node> root) {
	if (root == nullptr)
		return;
	const auto& n = root->_node;
	bool par = n.get_type() == type_expr_node::OPERATOR
			&& n.get_op() == expr_op::PARENTHSIS;

	if (par)
		cout << "(";
	if (root->right) {
		print(root->left);
		cout << " ";
		if (!par)
			cout << n;
		cout << " ";
		print(root->right);
	} else {
		if (!par)
			cout << n;
		print(root->left);
	}
	if (par)
		cout << ")";
}

///////////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////////

} /* namespace qultl */
