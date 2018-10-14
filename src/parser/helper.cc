/*
 * helper.cc
 *
 * @date  : Oct 13, 2018
 * @author: lpzun
 */

#include <helper.hh>

namespace qultl {

qultl_helper::qultl_helper() :
		phi(), formulae(), E() {

}

qultl_helper::~qultl_helper() {

}

void qultl_helper::parse_and_update(const string& qexpr) {
	phi.push_back(qexpr);
}

bool qultl_helper::syntax_check(const string& qexpr) {
	return false;
}

bool qultl_helper::is_legal_alpha(const string& alpha) {
	return E.find(alpha) != E.end();
}

void qultl_helper::print() {
	for (const auto e : phi)
		cout << e << " ";
}

} /* namespace qultl */
