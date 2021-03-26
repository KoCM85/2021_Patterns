#include "flyweight.h"

#include <iostream>

namespace patterns {

	// people
	void people::info() {
		std::cout << "flyweight address " << flyweight_data << ' ';
		flyweight_data->operation(last_name, first_name);
	}


	// flyweight
	void flyweight::operation(const std::string& last_name_in, const std::string& first_name_in, const char& ch) {
		std::cout << last_name_in << ' ' << first_name_in << ' ' << ptr->gender << ' ' << ptr->nationality << ch;
	}


	// factory_flyweight
	flyweight& factory_flyweight::get_flyweight(const std::string& gender_in, const std::string& nationality_in) {
		std::string key = get_key(gender_in, nationality_in);

		auto pair = flyweights.try_emplace(key, flyweight{ gender_in, nationality_in });

		return pair.first->second;
	}

	size_t factory_flyweight::size() {
		return flyweights.size();
	}

	std::string factory_flyweight::get_key(const std::string& gender_in, const std::string& nationality_in) {
		return gender_in + nationality_in;
	}

}