#include "mediator.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;

		operation_a op_a;
		operation_b op_b("this is mediator");

		mediator mediator_1(op_a, op_b);
		mediator_1.work(true);
		mediator_1.work(false);
	}

	return 0;
}