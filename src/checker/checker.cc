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
		_phi(phi), _E(E), counting(), size_Q() {
}

checker::~checker() {

}

/**
 *
 * @param Q
 * @return bool
 */
bool checker::check(const deque<alpha>& Q) {
	for (const auto &a : Q) {
		if (_E.find(a) == _E.end())
			throw runtime_error("Illegal message!");
	}
	cout << recover_phi(_phi) << endl;
	return eval(Q);
}

/**
 *
 * @param Q
 * @return
 */
bool checker::eval(const deque<alpha>& Q) {
	auto lhs = _phi.begin();
	auto rhs = _phi.begin();
	stack<nat> result;
	while (rhs < _phi.end()) {
		if (rhs->get_type() == type_expr_cpnt::OPERATOR) {
			switch (rhs->get_op()) {
			case expr_op::TMP_G: {

			}
				break;
			case expr_op::TMP_X: {

			}
				break;
			case expr_op::TMP_F: {

			}
				break;
			case expr_op::TMP_U: {

			}
				break;
			default: {

			}
				break;
			}
		}
		++rhs;
	}

	if (lhs != _phi.end()) {

	}

	for (int i = 0; i < _phi.size(); ++i) {
		if (_phi[i].get_type() == type_expr_cpnt::OPERATOR) {
			switch (_phi[i].get_op()) {
			case expr_op::TMP_G: {
				formula phi(_phi.begin(), _phi.begin() + i);
				return eval_G(Q, phi);
			}
				break;
			case expr_op::TMP_X: {
				formula phi(_phi.begin(), _phi.begin() + i);
				return eval_X(Q, phi);
			}
				break;
			case expr_op::TMP_F:
				break;
			case expr_op::TMP_U:
				break;
			default:
				break;
			}
		}
	}
	return eval(Q, _phi);
}

bool checker::eval_G(const deque<alpha>& Q, const formula& phi) {
	cout << recover_phi(phi) << endl;
	for (int i = 0; i < Q.size() - 1; ++i) {
		deque<alpha> qq(Q.begin() + i, Q.end());
		if (!eval(qq, phi))
			return false;
	}
	return true;
}

bool checker::eval_F(const deque<alpha>& Q, const formula& phi) {
	cout << recover_phi(phi) << endl;
	for (int i = 0; i < Q.size() - 1; ++i) {
		deque<alpha> qq(Q.begin() + i, Q.end());
		if (eval(qq, phi))
			return true;
	}
	return false;
}

bool checker::eval_X(const deque<alpha>& Q, const formula& phi) {
	cout << recover_phi(phi) << endl;
	deque<alpha> qq(Q.begin() + 1, Q.end());
	return eval(qq, phi);
}

bool checker::eval(const deque<alpha>& Q, const formula& phi) {
	counting.clear();
	for (const auto& s : Q) {
		counting[s]++;
	}
	size_Q = Q.size();

	stack<nat> worklist;
	for (int i = 0; i < phi.size(); ++i) {
		auto comp = phi[i];
		switch (comp.get_type()) {
		case type_expr_cpnt::VARIABLE:
			if (phi[i + 1].get_op() == expr_op::COUNT) {
				worklist.push(eval_counting(comp.get_var()));
				++i;
			}
			break;
		case type_expr_cpnt::CONSTANT:
			worklist.push(comp.get_val());
			break;
		default:
			eval(comp.get_op(), worklist);
			break;
		}
	}
	return worklist.top() == 1;
}

void checker::eval(const expr_op& op, stack<nat>& worklist) {
	nat lhs, rhs;
	switch (op) {
	case expr_op::TMP_F:
	case expr_op::TMP_G:
	case expr_op::TMP_X:
	case expr_op::TMP_U:
	case expr_op::COUNT:
		cout << op;
		throw runtime_error(" should not appears here\n");
		break;
	case expr_op::SIZE:
		worklist.push(size_Q);
		break;
	case expr_op::NEGATION:
		rhs = worklist.top();
		worklist.pop();
		worklist.push(rhs == 0 ? 1 : 1);
		break;
	case expr_op::AND:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs & rhs);
		break;
	case expr_op::OR:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs | rhs);
		break;
	case expr_op::IMPLICATION:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push((lhs == 0 ? 1 : 0) | rhs);
		break;
	case expr_op::EQUIVALENCE:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs == rhs ? 1 : 0);
		break;
	case expr_op::EQUAL:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs == rhs ? 1 : 0);
		break;
	case expr_op::NOT_EQUAL:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs != rhs ? 1 : 0);
		break;
	case expr_op::LESS_THAN:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs < rhs ? 1 : 0);
		break;
	case expr_op::GREATER_THAN:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs > rhs ? 1 : 0);
		break;
	case expr_op::LESS_THAN_EQ:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs <= rhs ? 1 : 0);
		break;
	case expr_op::GREATER_THAN_EQ:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs >= rhs ? 1 : 0);
		break;
	case expr_op::ADDITION:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs + rhs);
		break;
	case expr_op::SUBTRACTION:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs - rhs);
		break;
	case expr_op::MULTIPLICATION:
		rhs = worklist.top();
		worklist.pop();
		lhs = worklist.top();
		worklist.pop();
		worklist.push(lhs * rhs);
		break;
	case expr_op::PARENTHSIS:
		break;
	default:
		throw runtime_error("illgeal operator!");
		break;
	}
}

int checker::eval_counting(const alpha& a) {
	return counting[a];
}

/**
 * recover phi from expression
 * @return
 */
string checker::recover_phi(const formula& phi) {
	stack<string> worklist;
	for (const auto& comp : phi) {
		switch (comp.get_type()) {
		case type_expr_cpnt::VARIABLE:
			worklist.push(comp.get_var());
			break;
		case type_expr_cpnt::CONSTANT:
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
		recover_binary("|", worklist);
		break;
	case expr_op::IMPLICATION:
		recover_binary("->", worklist);
		break;
	case expr_op::EQUIVALENCE:
		recover_binary("<>", worklist);
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
	worklist.emplace(lhs + " " + op + " " + rhs);
}

/**
 *
 * @param op
 * @param worklist
 */
void checker::recover_unary(const string& op, stack<string>& worklist) {
	string lhs = worklist.top();
	worklist.pop();
	worklist.emplace(op + " " + lhs);
}
} /* namespace qultl */
