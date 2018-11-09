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
checker::checker(const shared_ptr<ast_node>& phi, const deque<alpha>& Q,
		const alphabet& E) :
		_phi(phi), _Q(Q), _E(E) {
}

checker::~checker() {

}

/**
 *
 * @param Q
 * @return bool
 */
bool checker::check() {
	for (const auto &a : _Q) {
		if (_E.find(a) == _E.end())
			throw runtime_error("Illegal message!");
	}
	return eval();
}

/**
 *
 * @param Q
 * @return
 */
bool checker::eval() {
	return eval(0, _phi);
}

int checker::eval(const size_t i, const shared_ptr<ast_node>& phi) {
	if (i == _Q.size() || phi == nullptr)
		return 0;

	auto node = phi->_node;

	switch (node.get_type()) {
	case type_expr_node::VARIABLE:
		return node.get_var() == this->_Q[i] ? 1 : 0;
	case type_expr_node::CONSTANT:
		return node.get_val();
	default:
		return eval_op(i, phi);
	}
	return 0;
}

int checker::eval_op(const size_t start, const shared_ptr<ast_node>& phi) {
	switch (phi->_node.get_op()) {
	case expr_op::TMP_F: {
		for (int i = start; i < this->_Q.size(); ++i) {
			if (eval(i, phi->left))
				return 1;
		}
		return 0;
	}
	case expr_op::TMP_G: {
		for (int i = start; i < this->_Q.size(); ++i) {
			if (!eval(i, phi->left))
				return 0;
		}
		return 1;
	}
	case expr_op::TMP_X: {
		return eval(start + 1, phi->left);
	}
	case expr_op::TMP_N: {
		auto lch = eval(start, phi->left);
		return lch ^ 1; // negate the result
	}
	case expr_op::TMP_U: {
		for (int i = start; i < this->_Q.size(); ++i) {
			if (eval(i, phi->right)) {
				for (int j = start; j < i; ++j) {
					if (!eval(j, phi->left))
						return 0;
				}
				return 1;
			}
		}
		return 0;
	}
		break;
	case expr_op::COUNT: {
		if (!phi->left
				|| phi->left->_node.get_type() != type_expr_node::VARIABLE)
			throw runtime_error("illegal formula: counting");
		return eval_count(start, phi->left->_node.get_var());
	}
	case expr_op::SIZE: {
		return this->_Q.size();
	}
	case expr_op::NEGATION: {
		auto lch = eval(start, phi->left);
		return lch ^ 1; // negate the result
	}
	case expr_op::AND: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch && rch;
	}
	case expr_op::OR: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch || rch;
	}
	case expr_op::IMPLICATION: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return (lch ^ 1) || rch;
	}
	case expr_op::EQUIVALENCE: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch == rch;
	}
	case expr_op::EQUAL: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch == rch;
	}
	case expr_op::NOT_EQUAL: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch != rch;
	}
	case expr_op::LESS_THAN: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch < rch;
	}
	case expr_op::GREATER_THAN: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch > rch;
	}
	case expr_op::LESS_THAN_EQ: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch <= rch;
	}
	case expr_op::GREATER_THAN_EQ: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch >= rch;
	}
	case expr_op::ADDITION: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch + rch;
	}
	case expr_op::SUBTRACTION: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch - rch;
	}
	case expr_op::MULTIPLICATION: {
		auto lch = eval(start, phi->left);
		auto rch = eval(start, phi->right);
		return lch * rch;
	}
	case expr_op::PARENTHSIS:
		return eval(start, phi->left);
	default:
		throw runtime_error("illgeal operator!");
	}
	return 0;
}

/**
 *
 * @param a
 * @return
 */
int checker::eval_count(const size_t start, const alpha& a) {
	int n = 0;
	for (int i = start; i < this->_Q.size(); ++i) {
		if (_Q[i] == a)
			++n;
	}
	return n;
}

} /* namespace qultl */
