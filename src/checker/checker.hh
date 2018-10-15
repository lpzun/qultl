/**
 * checker.hh
 *
 * @date  : Oct 13, 2018
 * @author: lpzun
 */

#ifndef CHECKER_CHECKER_HH_
#define CHECKER_CHECKER_HH_

#include "parser.hh"

namespace qultl {

class checker {
public:
	checker(const formula& phi, const alphabet& E);
	~checker();

	bool check(const deque<string>& Q);
private:
	formula phi;
	alphabet E;
	unordered_map<alpha, int> counting;
	bool eval(const deque<string>& Q);
};

} /* namespace qultl */

#endif /* CHECKER_CHECKER_HH_ */
