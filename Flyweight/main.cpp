#include "flyweight.h"

#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		patterns::factory_flyweight factory_flyweight_1;
		patterns::people people_1(factory_flyweight_1.get_flyweight("male", "russian"), "Cat", "Inga");
		patterns::people people_2(factory_flyweight_1.get_flyweight("female", "russian"), "Cat", "Serge");
		patterns::people people_3(factory_flyweight_1.get_flyweight("female", "chinese"), "Heinz", "Lanselot");

		patterns::people people_4(factory_flyweight_1.get_flyweight("female", "chinese"), "Heinz", "Lanselot");
		patterns::people people_5(factory_flyweight_1.get_flyweight("female", "russian"), "Clide", "Kate");
		patterns::people people_6(factory_flyweight_1.get_flyweight("female", "russian"), "Clide", "Kate");
		patterns::people people_7(factory_flyweight_1.get_flyweight("female", "russian"), "Clide", "Kate");

		std::cout << factory_flyweight_1.size() << '\n';
		people_1.info();
		people_2.info();
		people_3.info();
		people_4.info();
		people_5.info();
		people_6.info();
		people_7.info();
	}
}