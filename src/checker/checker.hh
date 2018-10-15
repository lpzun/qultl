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
	alphabet E;
	unordered_map<alpha, int> counting;
	bool eval(const deque<string>& Q);

	string recover_phi();
	bool eval_F();
	int eval_counting(const alpha& a);
};

} /* namespace qultl */

#endif /* CHECKER_CHECKER_HH_ */
