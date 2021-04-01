#ifndef MEMENTO_H

#define MEMENTO_H

#include <string>
#include <vector>
#include <iostream>

namespace patterns {

	class human;
	class caretaker;

	class memento {
		std::string nick;
		int age;

	protected:
		memento(const std::string& nick_in, const int& age_in) : nick(nick_in), age(age_in) {}
		memento(std::string&& nick_in, int&& age_in) : nick(nick_in), age(age_in) {}

		inline std::string get_nick();
		inline int get_age();

		friend class human;
		friend class caretaker;
	};



	class human {
		std::string nick;
		int age;

	public:
		human(const std::string& nick_in, const int& age_in) : nick(nick_in), age(age_in) {}
		human(std::string&& nick_in, int&& age_in) : nick(nick_in), age(age_in) {}

		inline memento snapshot();
		inline void restore(memento&);
		inline void state(std::string&&, int&&);
		inline void info();
	};



	class caretaker {
		std::vector<memento> mementos;
		human* human_val;

	public:
		inline caretaker(human& human__in);

		inline void save();
		inline void undo();
		inline void info();
	};
}



// definitions
namespace patterns{

	// memento
	std::string memento::get_nick() {
		return nick;
	}

	int memento::get_age() {
		return age;
	}



	// human
	memento human::snapshot() {
		return memento(nick, age);
	}

	void human::restore(memento& obj_in) {
		nick = obj_in.nick;
		age = obj_in.age;
	}

	void human::state(std::string&& nick_in, int&& age_in) {
		nick = nick_in;
		age = age_in;
	}

	void human::info() {
		std::cout << nick << ' ' << age << '\n';
	}



	// caretaker
	caretaker::caretaker(human& human__in) : human_val(&human__in) {
		mementos.reserve(10);
	}

	void caretaker::save() {
		mementos.emplace_back(human_val->snapshot());
	}

	void caretaker::undo() {
		if (mementos.size()) {
			human_val->restore(mementos.back());
			mementos.pop_back();
		}
	}

	void caretaker::info() {
		for (auto&& val : mementos) {
			std::cout << val.nick << ' ' << val.age << "   ";
		}
		std::cout << '\n';
	}
}

#endif // MEMENTO_H