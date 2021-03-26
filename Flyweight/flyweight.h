#ifndef FLYWEIGHT_H

#define FLYWEIGHT_H

#include <string>
#include <unordered_map>
#include <memory>

namespace patterns {

	class flyweight;

	class people {
		flyweight* flyweight_data;

		std::string last_name;
		std::string first_name;

	public:
		people(flyweight& flyweight_data_in, const std::string& last_name_in, const std::string& first_name_in) : flyweight_data(&flyweight_data_in), last_name(last_name_in), first_name(first_name_in) {}

		void info();
	};

	class flyweight {
		struct shared_data {
			std::string gender;
			std::string nationality;
		};

	private:
		std::unique_ptr<shared_data> ptr;

	public:
		flyweight(const std::string& gender_in, const std::string& nationality_in) : ptr(new shared_data{ gender_in , nationality_in }) {}

		void operation(const std::string&, const std::string&, const char& ch = '\n');
	};

	class factory_flyweight {
		std::unordered_map<std::string, flyweight> flyweights;

	public:
		factory_flyweight() {}

		flyweight& get_flyweight(const std::string& gender_in, const std::string& nationality_in);
		size_t size();

	private:
		std::string get_key(const std::string& gender_in, const std::string& nationality_in);
	};

}

#endif // FLYWEIGHT_H