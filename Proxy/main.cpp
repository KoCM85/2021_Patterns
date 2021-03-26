#include "proxy.h"

#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;

		sql_database sql_db_1;
		sql_proxy sql_proxy_1(sql_db_1);
		std::string str;

		str = sql_db_1.request();
		std::cout << str << '\n';

		str = sql_proxy_1.request();
		std::cout << str << '\n';
	}
}