#ifndef COMMAND_H

#define COMMAND_H

#include <iostream>

namespace patterns{

	class command {
	public:
		virtual ~command() = default;

		virtual void execute() = 0;
	};

	class some_command_1 : public command {
	public:
		inline void execute() override;
	};

	class some_command_2 : public command {
		class receiver* receiver_1;
		std::string str;

	public:
		some_command_2(receiver& receiver_in, std::string& str_in) : receiver_1(&receiver_in), str(std::move(str_in)) {}
		some_command_2(receiver& receiver_in, std::string&& str_in) : receiver_1(&receiver_in), str(str_in) {}

		inline void execute() override;
	};

	class receiver {
	public:
		inline void some_logic_1();
		inline void some_logic_2(std::string&);
	};

	class invoker {
		command* command_1;
		command* command_2;

	public:
		inline void set_command_1(command& command_in);
		inline void set_command_2(command& command_in);
		inline void some_operation_1();
		inline void some_operation_2();
	};

}



// definitions
namespace patterns {

	// some_command_1
	void some_command_1::execute() {
		std::cout << "easy command ";
	}


	// some_command_2
	void some_command_2::execute() {
		std::cout << "hard command ";
		receiver_1->some_logic_1();
		receiver_1->some_logic_2(str);
	}


	// receiver
	void receiver::some_logic_1() {
		std::cout << "logic 1 ";
	}

	void receiver::some_logic_2(std::string& str_in) {
		std::cout << "logic 2 " << str_in << ' ';
	}


	// invoker
	void invoker::set_command_1(command& command_in) {
		command_1 = &command_in;
	}

	void invoker::set_command_2(command& command_in) {
		command_2 = &command_in;
	}

	void invoker::some_operation_1() {
		std::cout << "invoker invoke 1 operation: ";
		command_1->execute();
		command_2->execute();
		std::cout << '\n';
	}

	void invoker::some_operation_2() {
		std::cout << "invoker invoke 2 operation: ";
		command_2->execute();
		std::cout << '\n';
	}
}

#endif // COMMAND_H