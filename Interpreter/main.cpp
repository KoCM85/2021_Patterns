#include "interpreter.h"

#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;

        std::string str("some message to you");

		str[0] = str[0] + 10;
        for (auto&& val : str) {
            val = ~val;
        }
		std::cout << str << '\n';


		context context_1{ str };
		terminal_expression terminal_expression_1;
		nonterminal_expression nonterminal_expression_1;

		nonterminal_expression_1.set_expression(terminal_expression_1);
		nonterminal_expression_1.interpret(context_1);
		std::cout << context_1.str << '\n';
	}

	return 0;
}