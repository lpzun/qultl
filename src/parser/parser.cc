/*
 * parser.cc
 *
 * @date  : Oct 11, 2018
 * @author: lpzun
 */

#include "parser.hh"

namespace qultl {

qultl_helper::qultl_helper() :
		phi(), formulae(), alphabet() {

}

void qultl_helper::parse_and_update(const string& qexpr) {

}

bool qultl_helper::syntax_check(const string& qexpr) {
	return false;
}

bool qultl_helper::is_legal_message(const string& msg) {
	return alphabet.find(msg) != alphabet.end();
}

qultl_parser::qultl_parser() {

}

qultl_parser::~qultl_parser() {

}

} /* namespace qultl */
