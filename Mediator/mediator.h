#ifndef MEDIATOR_H

#define MEDIATOR_H

#include <string>
#include <iostream>

namespace patterns {

	class mediator;

	class operation {
		mediator* mediator_val = nullptr;

	public:
		virtual ~operation() = default;
		inline void set_mediator(mediator*);
	};

	class operation_a : public operation {
		std::string str;

	public:
		inline void set(const std::string&);
		inline int inform(bool);
	};

	class operation_b : public operation {
		std::string str;

	public:
		operation_b(const std::string& str_in) : str(str_in) {}
		operation_b(std::string&& str_in) : str(str_in) {}

		inline std::string get();
		inline bool empty();
	};

	class mediator {
		operation_a* op_a;
		operation_b* op_b;

	public:
		inline mediator(operation_a& op_a_in, operation_b& op_b_in);

		inline void work(bool);
	};

}



// definitions
namespace patterns {

	// operation
	void operation::set_mediator(mediator* mediator_in) {
		mediator_val = mediator_in;
	}



	// operation_a
	void operation_a::set(const std::string& str_in) {
		str = str_in;
	}

	int operation_a::inform(bool flag) {
		if (flag)
			return 20;
		else
			return 10;
	}



	// operation_b
	std::string operation_b::get() {
		return str;
	}

	bool operation_b::empty() {
		return str.empty();
	}



	// mediator
	mediator::mediator(operation_a& op_a_in, operation_b& op_b_in) : op_a(&op_a_in), op_b(&op_b_in) {
		op_a->set_mediator(this);
		op_b->set_mediator(this);
	}

	void mediator::work(bool flag_in) {
		if (flag_in) {
			int val;
			std::string str = op_b->get();
			bool flag = op_b->empty();

			op_a->set(str);
			val = op_a->inform(flag);

			std::cout << "flag: " << std::boolalpha << flag_in << ' ' << str << ' ' << val << '\n';
		}
		else {
			bool flag = op_b->empty();
			int val = op_a->inform(flag);

			std::cout << "flag: " << std::boolalpha << flag_in << ' ' << op_b->get() << ' ' << val << '\n';
		}
	}

}

#endif // MEDIATOR_H