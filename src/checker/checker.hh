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
	checker(const shared_ptr<ast_node>& phi, const deque<alpha>& Q,
			const alphabet& E);
	~checker();

	bool check();
private:
	shared_ptr<ast_node> _phi;
	deque<alpha> _Q;
	alphabet _E;

	bool eval();
	int eval(const size_t i, const shared_ptr<ast_node>& phi);
	int eval_op(const size_t start, const shared_ptr<ast_node>& phi);
	int eval_count(const size_t start, const alpha& a);
};

} /* namespace qultl */

#endif /* CHECKER_CHECKER_HH_ */
