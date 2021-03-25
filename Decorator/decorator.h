#ifndef DECORATOR_H

#define DECORATOR_H

#include <string>
#include <memory>

namespace patterns {

	// humans
	class human {
	public:
		virtual ~human() = default;

		virtual std::string some_operation(const std::string& str_in = "") = 0;
	};

	class male : public human {
	public:
		std::string some_operation(const std::string& str_in = "") override;
	};

	class female : public human {
	public:
		std::string some_operation(const std::string& str_in = "") override;
	};

	class child : public human {
	public:
		std::string some_operation(const std::string& str_in = "") override;
	};


	// decorator
	class part : public human {
	protected:
		std::shared_ptr<human> ptr;

	public:
		part(std::shared_ptr<human>& ptr_in) : ptr(ptr_in) {}

		std::string some_operation(const std::string& str_in = "") override;
	};

	class hair : public part {
	public:
		hair(std::shared_ptr<human>& ptr_in) : part(ptr_in) {}

		std::string some_operation(const std::string& str_in = "") override;
	};

	class helmet : public part {
	public:
		helmet(std::shared_ptr<human>& ptr_in) : part(ptr_in) {}

		std::string some_operation(const std::string& str_in = "") override;
	};

	class boots : public part {
	public:
		boots(std::shared_ptr<human>& ptr_in) : part(ptr_in) {}

		std::string some_operation(const std::string& str_in = "") override;
	};

}

#endif // DECORATOR_H