#include "adapter.h"

#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;

		signal_2 signal_1;
		adapter adapter_1(signal_1);

		auto data = adapter_1.read();

		std::cout << data << '\n';
	}

	return 0;
}