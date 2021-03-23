#include "human.h"
#include "deed.h"

#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {

	{
		using namespace patterns;

		male male_1(std::make_unique<good_deed>());
		male_1.info();
		std::cout << male_1.some_operation() << '\n';

		std::cout << '\n';
		male male_2(std::make_unique<bad_deed>());
		male_2.info();
		std::cout << male_2.some_operation() << '\n';

		std::cout << '\n';
		female female_1(std::make_unique<bad_deed>());
		female_1.info();
		std::cout << female_1.some_operation() << '\n';

		std::cout << '\n';
		female female_2(std::make_unique<good_deed>());
		female_2.info();
		std::cout << female_2.some_operation() << '\n';

		std::cout << '\n';
		std::unique_ptr<deed> ptr(new good_deed);
		female female_3(ptr);
		female_3.info();
		std::cout << female_3.some_operation() << '\n';
	}

}