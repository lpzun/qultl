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
	formula _phi;
	alphabet _E;
	unordered_map<alpha, int> counting;
	bool eval(const deque<string>& Q);

	string recover_phi();
	void recover(const expr_op& op, stack<string>& worklist);
	bool eval_F();
	int eval_counting(const alpha& a);
};

} /* namespace qultl */

#endif /* CHECKER_CHECKER_HH_ */
