#include "decorator.h"

namespace patterns {

	// humans
	std::string male::some_operation(const std::string& str_in) {
		return "male with" + str_in;
	}

	std::string female::some_operation(const std::string& str_in) {
		return "female with" + str_in;
	}

	std::string child::some_operation(const std::string& str_in) {
		return "child with" + str_in;
	}


	// decorator
	std::string part::some_operation(const std::string& str_in) {
		return ptr->some_operation() + str_in;
	}

	std::string hair::some_operation(const std::string& str_in) {
		return ptr->some_operation() + str_in + " hair";
	}

	std::string helmet::some_operation(const std::string& str_in) {
		return ptr->some_operation() + str_in + " helmet";
	}

	std::string boots::some_operation(const std::string& str_in) {
		return ptr->some_operation() + str_in + " boots";
	}
}