#include "composite.h"

#include <iostream>
#include <iterator>

namespace patterns {

	// human
	void human::add_human(std::unique_ptr<human>&&) {
		std::cout << "can't add human \n";
	}

	void human::remove_human(const size_t&) {
		std::cout << "can't remove human \n";
	}


	// male
	std::string male::operation() {
		return "male";
	}


	// female
	std::string female::operation() {
		return "female";
	}


	// child
	std::string child::operation() {
		return "child";
	}


	// family
	bool family::is_composite() {
		return true;
	}

	void family::add_human(std::unique_ptr<human>&& human_in) {
		family.emplace_back(std::forward<std::unique_ptr<human>>(human_in));
	}

	void family::remove_human(const size_t& pos) {
		if (pos <= family.size()) {
			auto iter = std::next(family.begin(), pos - 1);
			family.erase(iter);
		}
	}

	std::string family::operation() {
		std::string str;

		str.reserve(200);
		str = "family: ";

		for (auto&& value : family) {
			str += value->operation() + ' ';
		}

		return str;
	}

}