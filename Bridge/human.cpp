#include "human.h"
#include "deed.h"

#include <iostream>

namespace patterns {

	// human
	human::human(std::unique_ptr<deed>& ptr_in) : ptr(std::move(ptr_in)) {}
	human::human(std::unique_ptr<deed>&& ptr_in) : ptr(std::forward<std::unique_ptr<deed>>(ptr_in)) {}

	std::string human::some_operation() {
		return ptr->some_deed();
	}

	// male
	male::male(std::unique_ptr<deed>& ptr_in) : human(ptr_in) {}
	male::male(std::unique_ptr<deed>&& ptr_in) : human(std::forward<std::unique_ptr<deed>>(ptr_in)) {}

	void male::info() {
		std::cout << "male " + ptr->info() << '\n';
	}

	// female
	female::female(std::unique_ptr<deed>& ptr_in) : human(ptr_in) {}
	female::female(std::unique_ptr<deed>&& ptr_in) : human(std::forward<std::unique_ptr<deed>>(ptr_in)) {}

	void female::info() {
		std::cout << "female " + ptr->info() << '\n';
	}
}