/**
 * helper.cc
 *
 * @date  : Oct 13, 2018
 * @author: lpzun
 */

#include <helper.hh>

namespace qultl {

ostream& operator<<(ostream& os, const op& o) {
	switch (o) {
	case op::TMP_F:
		os << 'F';
		break;
	case op::TMP_G:
		os << 'G';
		break;
	case op::TMP_X:
		os << 'X';
		break;
	case op::COUNT:
		os << '#';
		break;
	case op::SIZE:
		os << "[]";
		break;
	case op::NEGATION:
		os << '!';
		break;
	case op::AND:
		os << '&';
		break;
	case op::OR:
		os<<'|';
		break;
	case op::IMPLICATION:
		os<<"->";
		break;
	case op::EQUIVALENCE:
		os<<"<->";
		break;
	case op::EQUAL:
		os<<'=';
		break;
	case op::NOT_EQUAL:
		os<<"!=";
		break;
	case op::LESS_THAN:
		os<<'<';
		break;
	case op::GREATER_THAN:
		os<<'>';
		break;
	case op::LESS_THAN_EQ:
		os<<"<=";
		break;
	case op::GREATER_THAN_EQ:
		os<<">=";
		break;
	case op::ADDITION:
		os<<'+';
		break;
	case op::SUBTRACTION:
		os<<'+';
		break;
	case op::MULTIPLICATION:
		os<<'+';
		break;
	case op::PARENTHSIS:
		os<<"()";
		break;
	default:
		os << "illgeal operator!";
		break;
	}
	return os;
}

qultl_helper::qultl_helper() :
		phi(), E() {

}

qultl_helper::~qultl_helper() {

}

void qultl_helper::parse_phi(const op& op) {
	operators.push_back(op);
}

void qultl_helper::parse_phi(const string& qexpr) {
	phi.push_back(qexpr);
}

bool qultl_helper::syntax_check(const string& qexpr) {
	return false;
}

bool qultl_helper::is_legal_alpha(const string& alpha) {
	return E.find(alpha) != E.end();
}

void qultl_helper::print() {
	for (const auto &o : operators)
		cout <<o<<" ";
	for (const auto& e : phi)
		cout << e << " ";
}

} /* namespace qultl */
