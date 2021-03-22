#ifndef BUILDER_H

#define BUILDER_H

#include <vector>
#include <iostream>

namespace patterns {
	using unsign = short unsigned;

	class male {
		unsign age;

	public:
		male(unsign age_in) : age(age_in) {}

		inline void info() const;
	};

	class female {
		unsign age;

	public:
		female(unsign age_in) : age(age_in) {}

		inline void info() const;
	};

	class child {
		unsign age;

	public:
		child(unsign age_in) : age(age_in) {}

		inline void info() const;
	};

	class old_male {
		unsign age;

	public:
		old_male(unsign age_in) : age(age_in) {}

		inline void info() const;
	};

	class old_female {
		unsign age;

	public:
		old_female(unsign age_in) : age(age_in) {}

		inline void info() const;
	};

	struct city {
		std::string race;
		std::vector<male> males;
		std::vector<female> females;
		std::vector<child> childs;
		std::vector<old_male> old_males;
		std::vector<old_female> old_females;

	public:
		city(std::string race_in) : race(race_in) {}
	};

	class builder {
	public:
		virtual ~builder() = default;

		virtual std::string get_race() const = 0;
		virtual void create_male(city& city_in, const unsign& age_in) {}
		virtual void create_female(city& city_in, const unsign& age_in) {}
		virtual void create_child(city& city_in, const unsign& age_in) {}
		virtual void create_old_male(city& city_in, const unsign& age_in) {}
		virtual void create_old_female(city& city_in, const unsign& age_in) {}
	};

	class amazon_builder : public builder {
	public:
		inline std::string get_race() const override;
		inline void create_female(city& city_in, const unsign& age_in) override;
		inline void create_old_female(city& city_in, const unsign& age_in) override;
	};

	class human_builder : public builder {
	public:
		inline std::string get_race() const override;
		inline void create_male(city& city_in, const unsign& age_in) override;
		inline void create_female(city& city_in, const unsign& age_in) override;
		inline void create_child(city& city_in, const unsign& age_in) override;
		inline void create_old_male(city& city_in, const unsign& age_in) override;
		inline void create_old_female(city& city_in, const unsign& age_in) override;
	};

	class elf_builder : public builder {
	public:
		inline std::string get_race() const override;
		inline void create_male(city& city_in, const unsign& age_in) override;
		inline void create_female(city& city_in, const unsign& age_in) override;
		inline void create_child(city& city_in, const unsign& age_in) override;
	};

	class director {
	public:
		inline void create_city(std::vector<city>& cities_in, builder&);
	};

}



namespace patterns {

	void male::info() const {
		std::cout << "I am male. Age " << age;
	}

	void female::info() const {
		std::cout << "I am female. Age " << age;
	}

	void child::info() const {
		std::cout << "I am child. Age " << age;
	}

	void old_male::info() const {
		std::cout << "I am old male. Age " << age;
	}

	void old_female::info() const {
		std::cout << "I am old female. Age " << age;
	}

	// amazom 
	std::string amazon_builder::get_race() const {
		return "amazons";
	}

	void amazon_builder::create_female(city& city_in, const unsign& age_in) {
		city_in.females.emplace_back(age_in);
	}

	void amazon_builder::create_old_female(city& city_in, const unsign& age_in) {
		city_in.old_females.emplace_back(age_in);
	}


	// human
	std::string human_builder::get_race() const {
		return "humans";
	}

	void human_builder::create_male(city& city_in, const unsign& age_in) {
		city_in.males.emplace_back(age_in);
	}

	void human_builder::create_female(city& city_in, const unsign& age_in) {
		city_in.females.emplace_back(age_in);
	}

	void human_builder::create_child(city& city_in, const unsign& age_in) {
		city_in.childs.emplace_back(age_in);
	}

	void human_builder::create_old_male(city& city_in, const unsign& age_in) {
		city_in.old_males.emplace_back(age_in);
	}

	void human_builder::create_old_female(city& city_in, const unsign& age_in) {
		city_in.old_females.emplace_back(age_in);
	}


	// elf
	std::string elf_builder::get_race() const {
		return "elfs";
	}

	void elf_builder::create_male(city& city_in, const unsign& age_in) {
		city_in.males.emplace_back(age_in);
	}

	void elf_builder::create_female(city& city_in, const unsign& age_in) {
		city_in.females.emplace_back(age_in);
	}

	void elf_builder::create_child(city& city_in, const unsign& age_in) {
		city_in.childs.emplace_back(age_in);
	}


	// director
	void director::create_city(std::vector<city>& cities_in, builder& builder_in) {
		cities_in.emplace_back(builder_in.get_race());
		city & last_city = *(cities_in.end() - 1);

		builder_in.create_child(last_city, 12);
		builder_in.create_child(last_city, 12);

		builder_in.create_female(last_city, 29);
		builder_in.create_female(last_city, 29);
		builder_in.create_female(last_city, 29);

		builder_in.create_male(last_city, 34);
		builder_in.create_male(last_city, 34);

		builder_in.create_old_female(last_city, 100);
		builder_in.create_old_male(last_city, 120);
	}
}

#endif // BUILDER_H