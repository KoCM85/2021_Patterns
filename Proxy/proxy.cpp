#include "proxy.h"

#include <algorithm>

namespace patterns {

	std::string sql_database::request() {
		return std::string("esabatad morf atad");
	}

	std::string sql_proxy::decode_data(std::string && str_in) {
		std::reverse(str_in.begin(), str_in.end());
		return str_in;
	}

	std::string sql_proxy::request() {
		return decode_data(base.request());
	}
}