#ifndef DEED_H

#define DEED_H

#include <string>

namespace patterns {

	class deed {
	public:
		virtual ~deed() = default;

		virtual std::string info() = 0;
		virtual std::string some_deed() = 0;
	};

	class good_deed : public deed {
	public:
		std::string info() override;
		std::string some_deed() override;
	};

	class bad_deed : public deed {
	public:
		std::string info() override;
		std::string some_deed() override;
	};

}

#endif // DEED_H