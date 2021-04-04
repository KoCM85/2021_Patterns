#include "strategy.h"

#include <vector>
#include <array>
#include <iostream>

template<class type_t>
void info(type_t& container_in) {
	for (auto&& val : container_in)
		std::cout << val << ' ';
	std::cout << '\n';
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;
		using type_t = std::vector<int>;

		less<type_t> less_1;
		greater<type_t> greater_1;
		data<type_t> data_1;
		type_t datas{ 12, 988 ,4455, 232, 1, 99866 };

		if (data_1.is_empty())
			std::cout << "data_1: empty \n";
		else {
			data_1.sort(datas);
		}
		
		data_1.set_sort(greater_1);
		data_1.sort(datas);
		info(datas);

		data_1.set_sort(less_1);
		data_1.sort(datas);
		info(datas);
	}

	return 0;
}