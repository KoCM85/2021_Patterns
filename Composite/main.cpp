#include "composite.h"

#include <iostream>
#include <ios>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;

		std::unique_ptr<human> human_1(new male);

		std::cout << std::boolalpha << human_1->is_composite() << '\n';
		human_1->add_human(std::make_unique<male>());
		human_1->remove_human(3);
		std::cout << human_1->operation() << "\n\n";

		human_1.reset(new female);
		std::cout << std::boolalpha << human_1->is_composite() << '\n';
		human_1->add_human(std::make_unique<male>());
		human_1->remove_human(3);
		std::cout << human_1->operation() << "\n\n";

		human_1.reset(new child);
		std::cout << std::boolalpha << human_1->is_composite() << '\n';
		human_1->add_human(std::make_unique<male>());
		human_1->remove_human(3);
		std::cout << human_1->operation() << "\n\n";

		human_1.reset(new family);
		std::cout << std::boolalpha << human_1->is_composite() << '\n';
		std::cout << human_1->operation() << '\n';

		human_1->add_human(std::make_unique<male>());
		human_1->add_human(std::make_unique<female>());
		human_1->add_human(std::make_unique<child>());
		human_1->add_human(std::make_unique<child>());
		std::cout << human_1->operation() << '\n';

		human_1->remove_human(3);
		std::cout << human_1->operation() << '\n';
	}
}