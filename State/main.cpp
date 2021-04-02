#include "state.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;

		human human_1(new stop);
		human_1.operation();
		human_1.operation();
		human_1.operation();
		human_1.operation();

		std::cout << '\n';
		human_1.set_state(new run);
		human_1.operation();
		human_1.operation();
	}

	return 0;
}