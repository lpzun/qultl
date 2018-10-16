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

	return eval(Q);
}

/**
 * recover phi from expression
 * @return
 */
string checker::recover_phi() {
	stack<string> worklist;
	for (const auto& comp : _phi) {
		switch(comp.get_type()) {
		case type_expr_comp::VARIABLE:
			worklist.push(comp.get_var());
			break;
		case type_expr_comp::CONSTANT:
			worklist.push(std::to_string(comp.get_val()));
			break;
		default:

			break;
		}
	}
	return worklist.top();
}

void checker::recover(const expr_op& op, stack<string>& worklist) {

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
