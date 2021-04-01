#include "memento.h"


int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;

		human human_1("Kroket", 13);
		caretaker caretaker_1(human_1);

		caretaker_1.save();
		human_1.state("Foza", 14);
		caretaker_1.save();
		human_1.info();
		human_1.state("Jojo", 11);
		caretaker_1.save();
		human_1.state("Moni", 15);
		human_1.info();

		std::cout << '\n';
		caretaker_1.info();
		std::cout << '\n';

		caretaker_1.undo();
		human_1.info();
		caretaker_1.undo();
		human_1.info();
		caretaker_1.undo();
		human_1.info();
		caretaker_1.undo();
		human_1.info();
	}

	return 0;
}