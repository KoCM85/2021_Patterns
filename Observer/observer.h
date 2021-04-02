#ifndef OBSERVER_H

#define OBSERVER_H

#include <deque>
#include <string>
#include <algorithm>
#include <iostream>

namespace patterns {
	
	class subject;

	class observer {
		std::deque<subject*> subjects;

	public:
		inline void add_subject(subject&);
		inline void remove_subject(subject&);
		inline void changes(const std::string);
		inline void info();
	};

	class subject {
		std::deque<observer*> observers;
		std::string str;

		friend class observer;

	public:
		subject(const std::string& str_in) : str(str_in) {}
		subject(std::string&& str_in) : str(str_in) {}

	private:
		inline void add_observer(observer*);
		inline void remove_observer(observer*);
		inline void notify();
		inline void update(const std::string&);

	public:
		inline const std::string& get_str() const;
		inline void set_str(const std::string&);
	};

}



// definitions
namespace patterns {

	// observer
	void observer::add_subject(subject& subject_in) {
		subjects.push_back(&subject_in);
		subject_in.add_observer(this);
	}

	void observer::remove_subject(subject& subject_in) {
		auto lambda = [&subject_in](subject*& subj) {return &subject_in == subj; };
		std::deque<subject*>::iterator iter;

		subject_in.remove_observer(this);

		do {
			iter = std::find_if(subjects.begin(), subjects.end(), lambda);

			if (iter != subjects.end())
				subjects.erase(iter);
			else
				break;
		
		} while (true);
	}

	void observer::changes(const std::string str_in) {
		for (auto&& subject_v : subjects)
			subject_v->update(str_in);
	}

	void observer::info() {
		for (auto&& subject_v : subjects)
			std::cout << subject_v->get_str() << "   ";
		std::cout << '\n';
	}



	// subject
	void subject::add_observer(observer* observer_in) {
		observers.push_back(observer_in);
	}

	void subject::remove_observer(observer* observer_in) {
		auto lambda = [&observer_in](observer*& observ) { return observer_in == observ; };
		std::deque<observer*>::iterator iter;

		do {
			iter = std::find_if(observers.begin(), observers.end(), lambda);

			if (iter != observers.end())
				observers.erase(iter);
			else
				break;

		} while (true);
	}

	void subject::notify() {
		for (auto&& observer_v : observers)
			observer_v->changes(str);
	}

	void subject::update(const std::string& str_in) {
		str = str_in;
	}

	const std::string& subject::get_str() const {
		return str;
	}

	void subject::set_str(const std::string& str_in) {
		str = str_in;
		notify();
	}
}

#endif // OBSERVER_H