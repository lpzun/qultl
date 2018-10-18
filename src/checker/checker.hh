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
	unordered_map<alpha, nat> counting;
	nat size_Q;
	bool eval(const deque<string>& Q);

	string recover_phi(const formula& phi);
	void recover(const expr_op& op, stack<string>& worklist);
	void recover_binary(const string& op, stack<string>& worklist);
	void recover_unary(const string& op, stack<string>& worklist);

	bool eval(const deque<alpha>& Q, const formula& phi);
	void eval(const expr_op& op, stack<nat>& worklist);
	void eval_binary(const string& op, stack<nat>& worklist);
	void eval_unary(const string& op, stack<nat>& worklist);
	bool eval_G(const deque<alpha>& Q, const formula& phi);
	bool eval_X(const deque<alpha>& Q, const formula& phi);
	bool eval_F(const deque<alpha>& Q, const formula& phi);
	bool eval_U(const deque<alpha>& Q, const formula& phi);
	nat eval_neg(nat v);
	int eval_counting(const alpha& a);
};

} /* namespace qultl */

#endif /* CHECKER_CHECKER_HH_ */
