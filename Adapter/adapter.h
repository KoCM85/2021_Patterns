#ifndef ADAPTER_H

#define ADAPTER_H

#include <string>

namespace patterns {

	class signal {
	public:
		virtual ~signal() = default;

		virtual inline std::string read();
	};

	class signal_2 {
	public:
		inline std::string read_temp();
	};

	class adapter : public signal {
		signal_2 * signal_ptr;

	public:
		inline adapter(signal_2& signal_in);

		inline std::string read() override;
	};

}

namespace patterns {

	std::string signal::read() {
		return "OK";
	}

	std::string signal_2::read_temp() {
		return "40";
	}

	adapter::adapter(signal_2& signal_in) : signal_ptr(&signal_in) {
	}

	std::string adapter::read() {
		return signal::read() + ":" + signal_ptr->read_temp();
	}

}

#endif // ADAPTER_H