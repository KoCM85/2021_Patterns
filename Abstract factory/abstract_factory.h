#ifndef ABSTRACT_FACTORY_H

#define ABSTRACT_FACTORY_H

#include <memory>
#include <iostream>

namespace patterns {

	class human {
	public:
		virtual ~human() = default;

		virtual void something() = 0;
	};

	class male : public human {
	public:
		inline void something() override;
	};

	class female : public human {
	public:
		inline void something() override;
	};


	class weapon {
	public:
		virtual ~weapon() = default;

		virtual void some_weapon() = 0;
	};

	class sword : public weapon {
	public:
		inline void some_weapon() override;
	};

	class bow : public weapon {
	public:
		inline void some_weapon() override;
	};

	class stick : public weapon {
	public:
		inline void some_weapon() override;
	};

	// factory. first example. BEGIN
	class factory {
	public:
		virtual ~factory() = default;

		virtual std::unique_ptr<human> create_human() = 0;
		virtual std::unique_ptr<weapon> create_weapon() = 0;
	};

	class peasant_factory : public factory {
	public:
		inline std::unique_ptr<human> create_human() override;
		inline std::unique_ptr<weapon> create_weapon() override;
	};

	class guard_factory : public factory {
	public:
		inline std::unique_ptr<human> create_human() override;
		inline std::unique_ptr<weapon> create_weapon() override;
	};

	class archer_factory : public factory {
	public:
		inline std::unique_ptr<human> create_human() override;
		inline std::unique_ptr<weapon> create_weapon() override;
	};
	// factory. first example. END


	// factory. second example. 
	class factory_2 {
	public:
		enum class unit_t {
			peasant = 1,
			guard,
			archer
		};

		static inline std::unique_ptr<human> create_human(const unit_t&);
		static inline std::unique_ptr<weapon> create_weapon(const unit_t&);
	};
	// factory. second example. END
}



namespace patterns {
	
	void male::something() {
		std::cout << "I am male";
	}

	void female::something() {
		std::cout << "I am woman";
	}



	void sword::some_weapon() {
		std::cout << "sword";
	}

	void bow::some_weapon() {
		std::cout << "bow";
	}

	void stick::some_weapon() {
		std::cout << "stick";
	}


	// factory. first example. BEGIN
	std::unique_ptr<human> peasant_factory::create_human() {
		return std::make_unique<male>();
	}

	std::unique_ptr<weapon> peasant_factory::create_weapon() {
		return std::make_unique<stick>();
	}


	std::unique_ptr<human> guard_factory::create_human() {
		return std::make_unique<male>();
	}

	std::unique_ptr<weapon> guard_factory::create_weapon() {
		return std::make_unique<sword>();
	}


	std::unique_ptr<human> archer_factory::create_human() {
		return std::make_unique<female>();
	}

	std::unique_ptr<weapon> archer_factory::create_weapon() {
		return std::make_unique<bow>();
	}
	// factory. first example. END



	// factory. second example. BEGIN
	std::unique_ptr<human> factory_2::create_human(const unit_t & value_in) {
		if (value_in == unit_t::peasant)
			return std::make_unique<male>();
		else if (value_in == unit_t::guard)
			return std::make_unique<male>();
		else
			return std::make_unique<female>();
	}

	std::unique_ptr<weapon> factory_2::create_weapon(const unit_t & value_in) {
		if (value_in == unit_t::peasant)
			return std::make_unique<stick>();
		else if (value_in == unit_t::guard)
			return std::make_unique<sword>();
		else
			return std::make_unique<bow>();
	}
	// factory. second example. END
}

#endif // ABSTRACT_FACTORY_H