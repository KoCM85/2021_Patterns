#ifndef INTERPRETER_H

#define INTERPRETER_H

#include <string>

namespace patterns {

	struct context {
		std::string str;
	};


	class Iexpression {
	public:
		virtual ~Iexpression() = default;

		virtual void interpret(context&) = 0;
	};


	class terminal_expression : public Iexpression {
	public:
		inline void interpret(context&) override;
	};


	class nonterminal_expression : public Iexpression {
		Iexpression* expr;

	public:
		nonterminal_expression(Iexpression* expr_in = nullptr) : expr(expr_in) {}

		inline void interpret(context&) override;
		inline void set_expression(Iexpression& expr_in);
	};

}

#include <iostream>

// definitions
namespace patterns {

	// terminal_expression
	void terminal_expression::interpret(context& cont_in) {
		cont_in.str[0] = cont_in.str[0] - 10;
	}



	// nonterminal_expression
	void nonterminal_expression::interpret(context& cont_in) {
		for (auto&& val : cont_in.str)
			val = (~val);

		if (expr)
			expr->interpret(cont_in);
	}

	void nonterminal_expression::set_expression(Iexpression& expr_in) {
		expr = &expr_in;
	}

}

#endif // INTERPRETER_H