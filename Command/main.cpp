#include "command.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;

		receiver receiver_1;
		some_command_1 command_1;
		some_command_2 command_2(receiver_1, "example pattern command");
		invoker invoker_1;

		invoker_1.set_command_1(command_1);
		invoker_1.set_command_2(command_2);
		invoker_1.some_operation_1();
		invoker_1.some_operation_2();
	}
}