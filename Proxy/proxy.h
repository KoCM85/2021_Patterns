#ifndef PROXY_H

#define PROXY_H

#include <string>

namespace patterns {

	class database {
	public:
		virtual ~database() = default;

		virtual std::string request() = 0;
	};


	class sql_database : public database {
	public:
		std::string request() override;
	};


	class sql_proxy : public database {
		sql_database& base;

	private:
		std::string decode_data(std::string&&);

	public:
		sql_proxy(sql_database& obj_in) : base(obj_in) {}

		std::string request() override;
	};

}

#endif // PROXY_H