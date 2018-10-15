/*
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
		phi(), E(), counting() {
}

checker::~checker() {

}

/**
 *
 * @param Q
 * @return
 */
bool checker::check(const deque<string>& Q) {
	for (const auto& s: Q)
		cout<<s<<endl;

	return false;
}

bool checker::eval(const deque<string>& Q) {

}

} /* namespace qultl */
