/******************************************************************************
 * Synopsis	 [QuLTL Model Checker]
 *
 * Developer [Peizun Liu]
 *
 * (C) 2017 - 2018 Peizun Liu @ Thomas Wahl's Group
 *
 * All rights reserved. Redistribution and use in source and binary forms,
 * with or without modification, are permitted provided that the following
 * conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgment:
 *
 *    This product includes software developed by Peizun Liu @ Thomas Wahl's
 *    group, Northeastern University, United States and its contributors.
 *
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS `AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include <iostream>
#include "parser.hh"
#include "checker.hh"
#include "cmd.hh"

using namespace std;
using namespace cmd;
using namespace qultl;

/**
 *
 * @param argc
 * @param argv
 * @return int
 *
 */
int main(const int argc, const char * const * const argv) {
	try {
		cmd_line cmd;
		try {
			cmd.get_command_line(argc, argv);
		} catch (cmd_line::help) {
			return 0;
		}

		/// Problem Instances
		const string& file = cmd.arg_value(
				cmd_line::get_opt_index(opt_type::PROB), "--input-file");
		if (file == "X")
			throw runtime_error("Please specify an input file!");

		const string& phi = cmd.arg_value(
				cmd_line::get_opt_index(opt_type::PROB), "--qultl-file");
		if (phi == "X")
			throw runtime_error("Please specify a qultl file!");

		cout << "Start parsing queue ..." << endl;

		const auto& Q = queue_parser::parse_intput_queue(file);

		qultl_parser parser(phi, queue_parser::E);
		cout << endl;

		checker mc(parser.get_phi(), queue_parser::E);

		cout<<"==============================================\n";
		if (mc.check(Q)) {
			cout << "Check succeeded! Q |= phi holds! \n";
		} else {
			cout << "Check failed! Q |= phi does not hold! \n";
		}
		cout<<"==============================================\n";
	} catch (const std::exception& e) {
		cerr << "ERROR: " << e.what() << endl;
	}
	return 0;
}
