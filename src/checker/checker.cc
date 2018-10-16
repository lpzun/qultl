/**
 * checker.cc
 *
 * @date  : Oct 13, 2018
 * @author: lpzun
 */

#include "checker.hh"

namespace qultl {

/**
 *
 * @param phi
 * @param E
 */
checker::checker(const formula& phi, const alphabet& E) :
		_phi(phi), _E(E), counting() {
}

checker::~checker() {

}

/**
 *
 * @param Q
 * @return bool
 */
bool checker::check(const deque<alpha>& Q) {
	for (const auto& s : Q) {
		if (_E.find(s) == _E.end())
			throw runtime_error("Illegal message!");
		counting[s]++;
	}
	auto psi = recover_phi();
	cout << psi << endl;
	return eval(Q);
}

/**
 * recover phi from expression
 * @return
 */
string checker::recover_phi() {
	stack<string> worklist;
	for (const auto& comp : _phi) {
		switch (comp.get_type()) {
		case type_expr_comp::VARIABLE:
			worklist.push(comp.get_var());
			break;
		case type_expr_comp::CONSTANT:
			worklist.push(std::to_string(comp.get_val()));
			break;
		default:
			recover(comp.get_op(), worklist);
			break;
		}
	}
	return worklist.top();
}

void checker::recover(const expr_op& op, stack<string>& worklist) {
	switch (op) {
	case expr_op::TMP_F:
		recover_unary("F", worklist);
		break;
	case expr_op::TMP_G:
		recover_unary("G", worklist);
		break;
	case expr_op::TMP_X:
		recover_unary("X", worklist);
		break;
	case expr_op::TMP_U:
		recover_binary("U", worklist);
		break;
	case expr_op::COUNT:
		recover_unary("#", worklist);
		break;
	case expr_op::SIZE:
		worklist.emplace("[]");
		break;
	case expr_op::NEGATION:
		recover_unary("!", worklist);
		break;
	case expr_op::AND:
		recover_binary("&", worklist);
		break;
	case expr_op::OR:
		recover_binary("!", worklist);
		break;
	case expr_op::IMPLICATION:
		recover_binary("->", worklist);
		break;
	case expr_op::EQUIVALENCE:
		recover_binary("<->", worklist);
		break;
	case expr_op::EQUAL:
		recover_binary("=", worklist);
		break;
	case expr_op::NOT_EQUAL:
		recover_binary("!=", worklist);
		break;
	case expr_op::LESS_THAN:
		recover_binary("<", worklist);
		break;
	case expr_op::GREATER_THAN:
		recover_binary(">", worklist);
		break;
	case expr_op::LESS_THAN_EQ:
		recover_binary("<=", worklist);
		break;
	case expr_op::GREATER_THAN_EQ:
		recover_binary(">=", worklist);
		break;
	case expr_op::ADDITION:
		recover_binary("+", worklist);
		break;
	case expr_op::SUBTRACTION:
		recover_binary("-", worklist);
		break;
	case expr_op::MULTIPLICATION:
		recover_binary("*", worklist);
		break;
	case expr_op::PARENTHSIS: {
		string lhs = worklist.top();
		worklist.pop();
		worklist.emplace("(" + lhs + ")");
	}
		break;
	default:
		throw runtime_error("illgeal operator!");
		break;
	}
}

/**
 *
 * @param op
 * @param worklist
 */
void checker::recover_binary(const string& op, stack<string>& worklist) {
	string rhs = worklist.top();
	worklist.pop();
	string lhs = worklist.top();
	worklist.pop();
	worklist.emplace(lhs + op + rhs);
}

/**
 *
 * @param op
 * @param worklist
 */
void checker::recover_unary(const string& op, stack<string>& worklist) {
	string lhs = worklist.top();
	worklist.pop();
	worklist.emplace(op + lhs);
}

/**
 *
 * @param Q
 * @return
 */
bool checker::eval(const deque<alpha>& Q) {
	stack<bool> worklist;
	return false;
}

int checker::eval_counting(const alpha& a) {
	return counting[a];
}

} /* namespace qultl */
