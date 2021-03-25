#include "facade.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		patterns::subsystem_1 subsys_1;
		patterns::subsystem_2 subsys_2;
		patterns::facade facade_1(subsys_1, subsys_2);

		facade_1.operation();
	}
}