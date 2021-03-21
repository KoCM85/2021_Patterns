#ifndef PROTOTYPE_H

#define PROTOTYPE_H

#include <memory>
#include <array>
#include <iostream>

namespace patterns {

	class human {
	protected:
		short age;

	public:
		human() : age(0) {}
		human(const short& age_in) : age(age_in) {}

		human(const human&) = default;

		virtual ~human() = default;

		virtual void something() = 0;

		virtual std::unique_ptr<human> clone() = 0;
	};

	class male : public human {
	public:
		male() : human() {}
		male(const short& age_in) : human(age_in) {}

		male(const male&) = default;

		inline void something() override;

		inline std::unique_ptr<human> clone() override;
	};

	class female : public human {
	public:
		female() : human() {}
		female(const short& age_in) : human(age_in) {}

		female(const female&) = default;

		inline void something() override;

		inline std::unique_ptr<human> clone() override;
	};


	class prototype_factory final {
		std::array<std::unique_ptr<human>, 2> prototypes;

	public:
		enum class human_t : short unsigned {
			male,
			female
		};

	public:
		inline prototype_factory();

		inline std::unique_ptr<human> create_prototype(const human_t&);
	};

}



namespace patterns {

	void male::something() {
		std::cout << "I am male. Age " << age;
	}

	std::unique_ptr<human> male::clone() {
		return std::make_unique<male>(*this);
	}

	void female::something() {
		std::cout << "I am female. Age " << age;
	}

	std::unique_ptr<human> female::clone() {
		return std::make_unique<female>(*this);
	}


	prototype_factory::prototype_factory() {
		prototypes[0] = std::make_unique<male>(25);
		prototypes[1] = std::make_unique<female>(18);
	}

	std::unique_ptr<human> prototype_factory::create_prototype(const human_t& value_in) {
		short index = static_cast<short>(value_in);

		return prototypes[index]->clone();
	}
}

#endif // PROTOTYPE_H