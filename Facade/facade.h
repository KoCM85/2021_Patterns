#ifndef FACADE_H

#define FACADE_H

#include <string>

namespace patterns {

	class subsystem_1 {
	public:
		void operation(const std::string& data_in) const;
		std::string operation_2() const;
	};

	class subsystem_2 {
	public:
		std::string read_data() const;
		void enter_data(const std::string&) const;
	};

	class facade {
		subsystem_1& subsys_1;
		subsystem_2& subsys_2;

	public:
		facade(subsystem_1& subsys_1_in, subsystem_2& subsys_2_in) : subsys_1(subsys_1_in), subsys_2(subsys_2_in) {}

		void operation() const;
	};

}

#endif // FACADE_H