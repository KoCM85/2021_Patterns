#include "chain_resp.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		patterns::first_handler handler_1;
		patterns::second_handler handler_2;
		patterns::third_handler handler_3;
		patterns::default_handler handler_4;

		handler_1.add(handler_2);
		handler_1.add(handler_3);
		handler_1.handle("some string");

		handler_1.add(handler_4);
		handler_1.handle("some string");
		handler_1.handle("second");
		handler_1.handle("third");
	}

	return 0;
}