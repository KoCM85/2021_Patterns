#ifndef PROTOTYPE_H

#define PROTOTYPE_H

#include <memory>
#include <array>
#include <iostream>

namespace patterns {

	class human {
	public:
		virtual ~human() = default;

		virtual void something() = 0;

		virtual std::unique_ptr<human> clone() = 0;
	};

	class male : public human {
	public:
		inline void something() override;

		inline std::unique_ptr<human> clone() override;
	};

	class female : public human {
	public:
		inline void something() override;

		inline std::unique_ptr<human> clone() override;
	};


	class prototype_factory final {
		std::array<std::unique_ptr<human>, 2> prototypes;

	public:
		enum class human_t {
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
		std::cout << "I am male";
	}

	std::unique_ptr<human> male::clone() {
		return std::make_unique<male>();
	}

	void female::something() {
		std::cout << "I am female";
	}

	std::unique_ptr<human> female::clone() {
		return std::make_unique<female>();
	}


	prototype_factory::prototype_factory() {
		prototypes[0] = std::make_unique<male>();
		prototypes[1] = std::make_unique<female>();
	}

	std::unique_ptr<human> prototype_factory::create_prototype(const human_t& value_in) {
		short index = static_cast<short>(value_in);

		return prototypes[index]->clone();
	}
}

#endif // PROTOTYPE_H