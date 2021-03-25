#include "facade.h"

#include <iostream>
#include <iomanip>

namespace patterns {

	// subsystem_1
	void subsystem_1::operation(const std::string& data_in) const {
		std::cout << "Do some operation on data " << std::quoted(data_in) << " ";
	}

	std::string subsystem_1::operation_2() const {
		return "I am doing so huge work";
	}


	// subsystem_2
	std::string subsystem_2::read_data() const {
		return "Data from anywhere";
	}

	void subsystem_2::enter_data(const std::string& data_in) const {
		std::cout << "Data entered " << std::quoted(data_in) << " ";
	}


	//facade
	void facade::operation() const {
		auto data_1 = subsys_2.read_data();
		auto data_2 = subsys_1.operation_2();

		subsys_1.operation(data_1);
		subsys_2.enter_data(data_2);

		std::cout << '\n' << "Facade finished work" << '\n';
	}
}