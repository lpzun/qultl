/**
 *  cmd.cc
 *
 *  @date   Nov 18, 2014
 *  @author TODO
 */

#ifndef CMD_HH_
#define CMD_HH_

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <map>
#include <deque>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::runtime_error;
using std::ostream;
using std::ostringstream;
using std::string;
using std::map;
using std::deque;
using std::vector;
using std::cout;
using std::endl;

extern string v_info;

using ushort = unsigned short;
using ulong = unsigned long int;

namespace cmd {

enum class alignment {
	LEFTJUST, RIGHTJUST, CENTERED
};

template<class T> string widthify(const T& x, const ushort& width = 0,
		const alignment& c = alignment::CENTERED, const char& fill = ' ');

/**
 * @brief customized runtime_error class for command line class
 */
class cmd_runtime_error: public runtime_error {
public:
	cmd_runtime_error() :
			runtime_error("") {
	}

	cmd_runtime_error(const std::string& msg) :
			runtime_error(msg) {
	}
};

class Arguments {
public:
	inline Arguments(const short& type, const string& short_name,
			const string& long_name, const string& meaning) :
			type(type), short_name(short_name), long_name(long_name), meaning(
					meaning) {
	}

	inline virtual ~Arguments() {
	}

	inline const short& get_type() const {
		return type;
	}

	inline const string& get_long_name() const {
		return long_name;
	}

	inline const string& get_meaning() const {
		return meaning;
	}

	inline const string& get_short_name() const {
		return short_name;
	}

protected:
	const short type;
	const string short_name; /// the argument's long name
	const string long_name;  /// the argument's short name
	const string meaning;    /// the meaning of the argument
};

inline bool operator==(const Arguments& arg1, const Arguments& arg2) {
	return (arg1.get_long_name() == arg2.get_long_name());
}

inline bool operator<(const Arguments& arg1, const Arguments& arg2) {
	return (arg1.get_long_name() < arg2.get_long_name());
}

class Options: public Arguments {
public:
	inline Options(const short& type, const string& short_name,
			const string& long_name, const string& meaning,
			const string& default_value) :
			Arguments(type, short_name, long_name, meaning), value(
					default_value) {
	}

	inline Options(const short& type = 0, const string& long_name = "") :
			Arguments(type, "", long_name, "") {
	}

	inline virtual ~Options() {
	}

	inline const string& get_value() const {
		return value;
	}

	inline void set_value(const string& value) {
		this->value = value;
	}

private:
	string value; /// the value of this argument
};

inline bool operator==(const Options& arg1, const Options& arg2) {
	return (arg1.get_long_name() == arg2.get_long_name());
}

inline bool operator<(const Options& arg1, const Options& arg2) {
	return (arg1.get_long_name() < arg2.get_long_name());
}

class Switch: public Arguments {
public:
	inline Switch(const short& type, const string& short_name,
			const string& long_name, const string& meaning) :
			Arguments(type, short_name, long_name, meaning), value(false) {
	}

	inline Switch(const short& type = 0, const string& long_name = "") :
			Arguments(type, "", long_name, ""), value(false) {
	}

	inline virtual ~Switch() {

	}

	bool is_value() const {
		return value;
	}

	void set_value(bool value) {
		this->value = value;
	}

private:
	bool value; /// the value of this switch
};

inline bool operator==(const Switch& arg1, const Switch& arg2) {
	return (arg1.get_long_name() == arg2.get_long_name());
}

inline bool operator<(const Switch& arg1, const Switch& arg2) {
	return (arg1.get_long_name() < arg2.get_long_name());
}

enum class opt_type {
	DEFAULT, PROB, SEQ, CON, OTHER
};

/////////////////// command line class
class cmd_line {
public:
	cmd_line();
	~cmd_line();

	struct help {
	};

	void get_command_line(const int argc, const char* const * const argv);
	bool arg_bool(const unsigned short& type, const string& arg);
	string arg_value(const short& type, const string& arg);

	const vector<string>& get_types() const {
		return types;
	}

	void set_types(const vector<string>& types) {
		this->types = types;
	}

	static string get_opt_types(const opt_type& opt);

	static short get_opt_index(const opt_type& opt);

private:
	string SHORT_HELP_OPT;
	string LONG_HELP_OPT;
	string SHORT_VERSION_OPT;
	string LONG_VERSION_OPT;

	string VERSION;

	ushort name_width;
	ushort xwidth;
	const string help_message;
	string v_info;

	map<short, deque<Options>> cmd_options;
	map<short, deque<Switch>> cmd_switches;
	vector<string> types;

	void create_argument_list();
	string create_version_info();

	void add_option(const short& type, const string& short_name,
			const string& long_name, const string& meaning,
			const string& default_value);

	void add_switch(const short& type, const string& short_name,
			const string& long_name, const string& meaning);

	void get_command_line(const string& prog, const vector<string>& args);

	void print_usage_info(const string& prog_name, const ushort& indent = 1,
			ostream& out = cout) const;
};
}
#endif /* CMD_HH_ */
