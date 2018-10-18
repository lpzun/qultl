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

expr_cpnt::expr_cpnt(const type_expr_cpnt& type, const expr_op& op) :
		_type(type), _op(op), _val(), _var() {

}
expr_cpnt::expr_cpnt(const type_expr_cpnt& type, const nat val) :
		_type(type), _op(), _val(val), _var() {

}
expr_cpnt::expr_cpnt(const type_expr_cpnt& type, const alpha& var) :
		_type(type), _op(), _val(), _var(var) {

}

expr_cpnt::~expr_cpnt() {

}

ostream& operator<<(ostream& os, const expr_cpnt& e) {
	switch (e.get_type()) {
	case type_expr_cpnt::OPERATOR:
		os << e.get_op();
		break;
	case type_expr_cpnt::CONSTANT:
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
	phi.emplace_back(type_expr_cpnt::OPERATOR, op);
}
///////////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////////////////
void qultl_expr::parse_phi(const string& var) {
	if (!is_legal_alpha(var))
		throw runtime_error("Illegal message in LTL formula!");
	phi.emplace_back(type_expr_cpnt::VARIABLE, var);
}

void qultl_expr::parse_phi(const nat val) {
	phi.emplace_back(type_expr_cpnt::CONSTANT, val);
}

bool qultl_expr::syntax_check(const alpha& var) {
	return false;
}

bool qultl_expr::is_legal_alpha(const alpha& var) {
	return _E.find(var) != _E.end();
}

void qultl_expr::print() {
	for (const auto& e : phi)
		cout << e << " ";
}

} /* namespace qultl */
