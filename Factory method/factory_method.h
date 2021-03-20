#ifndef FACTORY_METHOD_H

#define FACTORY_METHOD_H

#include <memory>
#include <iostream>

namespace patterns {

	// factory. first example. BEGIN
	enum class human_t : short { male = 1, female };

	class human {
	public:
		virtual ~human() = default;

		virtual void something() = 0;

		static inline std::unique_ptr<human> create_human(human_t);
	};

	class male : public human {
	public:
		inline void something() override;
	};

	class female : public human {
	public:
		inline void something() override;
	};
	// factory. first example. END


	// factory. second example. BEGIN
	class human_2 {
	public:
		virtual ~human_2() = default;

		virtual void something() = 0;
	};

	class male_2 : public human_2 {
	public:
		inline void something() override;
	};

	class female_2 : public human_2 {
	public:
		inline void something() override;
	};


	class factory {
	public:
		virtual ~factory() = default;

		virtual std::unique_ptr<human_2> create_human() = 0;
	};

	class male_factory : public factory {
	public:
		inline std::unique_ptr<human_2> create_human() override;
	};

	class female_factory : public factory {
	public:
		inline std::unique_ptr<human_2> create_human() override;
	};

	// factory. second example. END
}



namespace patterns {

	// factory. first example. BEGIN
	std::unique_ptr<human> human::create_human(human_t type) {
		if (type == human_t::male) {
			return std::unique_ptr<human>(new male);
		}
		else {
			return std::unique_ptr<human>(new female);
		}
	}


	void male::something() {
		std::cout << "i am going to do my work \n";
	}

	void female::something() {
		std::cout << "i wanna sleep \n";
	}
	// factory. first example. END


	// factory. second example. BEGIN
	void male_2::something() {
		std::cout << "i am going to do my work \n";
	}

	void female_2::something() {
		std::cout << "i wanna sleep \n";
	}

	std::unique_ptr<human_2> male_factory::create_human() {
		return std::make_unique<male_2>();
	}

	std::unique_ptr<human_2> female_factory::create_human() {
		return std::make_unique<female_2>();
	}

	// factory. second example. END
}

#endif // FACTORY_METHOD_H