#include "builder.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;

		std::vector<city> cities;
		amazon_builder builder_1;
		elf_builder builder_2;
		human_builder builder_3;
		director director;

		cities.reserve(4);

		director.create_city(cities, builder_1);
		director.create_city(cities, builder_2);
		director.create_city(cities, builder_3);

		for (auto&& value : cities) {
			std::cout << value.race << ": \n";

			for (auto&& val : value.childs) {
				val.info();
				std::cout << "   ";
			}
			std::cout << '\n';

			for (auto&& val : value.females) {
				val.info();
				std::cout << "   ";
			}
			std::cout << '\n';

			for (auto&& val : value.males) {
				val.info();
				std::cout << "   ";
			}
			std::cout << '\n';

			for (auto&& val : value.old_females) {
				val.info();
				std::cout << "   ";
			}
			std::cout << '\n';

			for (auto&& val : value.old_males) {
				val.info();
				std::cout << "   ";
			}
			std::cout << "\n\n";
		}
	}


	return 0;
}