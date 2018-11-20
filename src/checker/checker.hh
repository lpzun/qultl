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
	/**
	 *
	 * @param phi: qultl formula
	 * @param P  : prefix of queue
	 * @param Q  : queue
	 * @param E  : the alphabet of queue
	 */
	checker(const shared_ptr<ast_node>& phi, const deque<alpha>& P,
			const deque<alpha>& Q, const alphabet& E);
	~checker();

	bool check(const bool abstract = false);
private:
	shared_ptr<ast_node> _phi;
	deque<alpha> _P;
	deque<alpha> _Q;
	alphabet _E;

	bool abstract_check();
	bool concrete_check();
	bool eval();
	int eval(const size_t i, const shared_ptr<ast_node>& phi);
	int eval_op(const size_t start, const shared_ptr<ast_node>& phi);
	int eval_count(const size_t start, const alpha& a);
};

} /* namespace qultl */

#endif /* CHECKER_CHECKER_HH_ */
