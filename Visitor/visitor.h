#ifndef VISITOR_H

#define VISITOR_H

#include <string>
#include <vector>
#include <iostream>

namespace patterns {

	class female;
	class male;

	class Ivisitor {
	public:
		virtual ~Ivisitor() = default;

		virtual void visit_female(female* female_in) = 0;
		virtual void visit_male(male* male_in) = 0;
	};


	class human {
	public:
		virtual ~human() = default;

		inline virtual void accept(Ivisitor& visitor_in) = 0;
	};


	class female : public human {
		std::vector<std::string> flowers;

	public:
		inline void accept(Ivisitor& visitor_in) override;
		inline void add_flower(const std::string& flower_in);
		inline void look_flowers();
	};


	class male : public human {
		std::vector<std::string> weapons;

	public:
		inline void accept(Ivisitor& visitor_in) override;
		inline void add_weapon(const std::string& weapon_in);
		inline void look_weapons();
	};


	class visitor : public Ivisitor {
	public:
		inline void visit_female(female* female_in) override;
		inline void visit_male(male* male_in) override;
	};

}



// definitions
namespace patterns {

	// female
	void female::accept(Ivisitor& visitor_in) {
		visitor_in.visit_female(this);
	}

	void female::add_flower(const std::string& flower_in) {
		flowers.emplace_back(flower_in);
	}

	void female::look_flowers() {
		std::cout << "My flowers: ";
		for (auto&& flower : flowers)
			std::cout << flower << ' ';
		std::cout << '\n';
	}


	// male
	void male::accept(Ivisitor& visitor_in) {
		visitor_in.visit_male(this);
	}

	void male::add_weapon(const std::string& weapon_in) {
		weapons.emplace_back(weapon_in);
	}

	void male::look_weapons() {
		std::cout << "My weapons: ";
		for (auto&& weapon : weapons)
			std::cout << weapon << ' ';
		std::cout << '\n';
	}


	// visitor
	void visitor::visit_female(female* female_in) {
		female_in->look_flowers();
	}

	void visitor::visit_male(male* male_in) {
		male_in->look_weapons();
	}

}

#endif // VISITOR_H