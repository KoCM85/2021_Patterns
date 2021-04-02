#include "observer.h"

#include <array>

inline void info(std::array<patterns::subject, 5>& subjects_in) {
	for (auto&& subject_v : subjects_in)
		std::cout << subject_v.get_str() << "   ";
	std::cout << '\n';
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;

		observer observer_1;
		observer observer_2;
		observer observer_3;

		std::array<subject, 5> subjects{ { std::string("car"), std::string("Dunkan"), std::string("Anna"), std::string("Moskov"), std::string("Sydney") } };

		info(subjects);

		observer_1.add_subject(subjects[0]);
		observer_1.add_subject(subjects[1]);
		observer_1.add_subject(subjects[2]);

		observer_2.add_subject(subjects[3]);
		observer_2.add_subject(subjects[4]);

		observer_3.add_subject(subjects[1]);
		observer_3.add_subject(subjects[4]);

		info(subjects);

		subjects[0].set_str("kivi");
		subjects[4].set_str("mango");
		info(subjects);

		observer_3.remove_subject(subjects[4]);
		observer_3.remove_subject(subjects[4]);
		subjects[4].set_str("apple");
		info(subjects);

		observer_3.info();
		observer_3.remove_subject(subjects[1]);
		observer_3.info();

		observer_1.info();
		observer_2.info();


		std::cout << '\n' << "observer_2: \n";
		observer_2.remove_subject(subjects[0]);
		observer_2.remove_subject(subjects[1]);
		observer_2.remove_subject(subjects[2]);
		observer_2.info();

		observer_2.remove_subject(subjects[3]);
		observer_2.info();


		std::cout << '\n' << "observer_1: \n";
		observer_1.remove_subject(subjects[0]);
		observer_1.add_subject(subjects[3]);
		observer_1.info();

		subjects[2].set_str("meat");
		observer_1.info();


		std::cout << '\n' << "all subject: \n";
		info(subjects);
	}

	return 0;
}