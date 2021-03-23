#include "deed.h"

namespace patterns {

	// good_deed
	std::string good_deed::info() {
		return "did a good deed: " + some_deed();
	}

	std::string good_deed::some_deed() {
		return "rescue";
	}

	// bad_deed
	std::string bad_deed::info() {
		return "did a bad deed: " + some_deed();
	}

	std::string bad_deed::some_deed() {
		return "steal";
	}

}