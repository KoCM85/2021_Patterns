#ifndef CHAIN_RESP_H

#define CHAIN_RESP_H

#include <string>
#include <iostream>

namespace patterns {

	class handler {
		handler* hand_ptr = nullptr;

	public:
		virtual ~handler() = default;

		virtual inline void handle(const std::string &) = 0;
		inline void add(handler& handler_in);
	};

	class first_handler : public handler {
	public:
		inline void handle(const std::string&) override;
	};

	class second_handler : public handler {
	public:
		inline void handle(const std::string&) override;
	};

	class third_handler : public handler {
	public:
		inline void handle(const std::string&) override;
	};

	class default_handler : public handler {
	public:
		inline void handle(const std::string&) override;
	};
}


// definitions
namespace patterns {

	// handler
	void handler::handle(const std::string& message_in) {
		if (hand_ptr)
			hand_ptr->handle(message_in);
		else
			std::cout << "message not handled \n";
	}

	void handler::add(handler& handler_in) {
		if (hand_ptr)
			hand_ptr->add(handler_in);
		else
			hand_ptr = &handler_in;
	}


	// first_handler
	void first_handler::handle(const std::string& message_in) {
		if (message_in == "first")
			std::cout << "first_handler handled the message \n";
		else
			handler::handle(message_in);
	}


	// second_handler
	void second_handler::handle(const std::string& message_in) {
		if (message_in == "second")
			std::cout << "second_handler handled the message \n";
		else
			handler::handle(message_in);
	}


	// third_handler
	void third_handler::handle(const std::string& message_in) {
		if (message_in == "third")
			std::cout << "third_handler handled the message \n";
		else
			handler::handle(message_in);
	}


	// default_handler
	void default_handler::handle(const std::string& message_in) {
		std::cout << "default_handler handled the message \n";
	}
}

#endif // CHAIN_RESP_H