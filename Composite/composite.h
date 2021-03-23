#ifndef COMPOSITE_H

#define COMPOSITE_H

#include <deque>
#include <memory>
#include <string>

namespace patterns {

	class human {
	public:
		virtual ~human() = default;

		virtual bool is_composite() { return false; }
		virtual void add_human(std::unique_ptr<human>&&);
		virtual void remove_human(const size_t &);
		virtual std::string operation() = 0;
	};


	class male : public human {
	public:
		std::string operation() override;
	};


	class female : public human {
	public:
		std::string operation() override;
	};

	class child : public human {
	public:
		std::string operation() override;
	};


	class family : public human {
		std::deque<std::unique_ptr<human>> family;

	public:
		bool is_composite() override;
		void add_human(std::unique_ptr<human>&&) override;
		void remove_human(const size_t&) override;
		std::string operation() override;
	};

}

#endif // COMPOSITE_H