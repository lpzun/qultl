/**
 * helper.cc
 *
 * @date  : Oct 13, 2018
 * @author: lpzun
 */

#include <helper.hh>

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

expr_comp::expr_comp(const type_expr_comp& type, const expr_op& op) :
		_type(type), _op(op), _val(), _var() {

}
expr_comp::expr_comp(const type_expr_comp& type, const nat val) :
		_type(type), _op(), _val(val), _var() {

}
expr_comp::expr_comp(const type_expr_comp& type, const alpha& var) :
		_type(type), _op(), _val(), _var(var) {

}

expr_comp::~expr_comp() {

}

ostream& operator<<(ostream& os, const expr_comp& e) {
	switch (e.get_type()) {
	case type_expr_comp::OPERATOR:
		os << e.get_op();
		break;
	case type_expr_comp::CONSTANT:
		os << e.get_val();
		break;
	default:
		os << e.get_var();
		break;
	}
	return os;
}

qultl_helper::qultl_helper(const alphabet& E) :
		phi(), _E(E) {
}

qultl_helper::~qultl_helper() {

}

void qultl_helper::parse_phi(const expr_op& op) {
	phi.emplace_back(type_expr_comp::OPERATOR, op);
}
///////////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////////
void qultl_helper::parse_phi(const string& var) {
	if (!is_legal_alpha(var))
		throw runtime_error("Illegal message in LTL formula!");
	phi.emplace_back(type_expr_comp::VARIABLE, var);
}

void qultl_helper::parse_phi(const nat val) {
	phi.emplace_back(type_expr_comp::CONSTANT, val);
}

bool qultl_helper::syntax_check(const alpha& var) {
	return false;
}

bool qultl_helper::is_legal_alpha(const alpha& var) {
	return _E.find(var) != _E.end();
}

void qultl_helper::print() {
	for (const auto& e : phi)
		cout << e << " ";
}

} /* namespace qultl */
