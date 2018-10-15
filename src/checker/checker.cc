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
		E(), counting() {
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
		if (E.find(s) == E.end())
			throw runtime_error("Illegal message!");
		counting[s]++;
	}

	return eval(Q);
}

string checker::recover_phi() {
	stack<string> worklist;
	/*
	 for (const string& s : _phi) {

	 }*/
	return worklist.top();
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
