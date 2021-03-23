#ifndef HUMAN_H

#define HUMAN_H

#include <memory>
#include <string>

namespace patterns {

	class deed;

	class human {
	protected:
		std::unique_ptr<deed> ptr;

	public:
		human(std::unique_ptr<deed>& ptr_in);
		human(std::unique_ptr<deed>&& ptr_in);
		virtual ~human() = default;

		virtual void info() = 0;
		std::string some_operation();
	};

	class male : public human {
	public:
		male(std::unique_ptr<deed>& ptr_in);
		male(std::unique_ptr<deed>&& ptr_in);

		void info() override;
	};

	class female : public human {
	public:
		female(std::unique_ptr<deed>& ptr_in);
		female(std::unique_ptr<deed>&& ptr_in);

		void info() override;
	};

}

#endif // HUMAN_H