#include "prototype.h"

#include <vector>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;
		using human_t = patterns::prototype_factory::human_t;

		prototype_factory prot_fact;
		std::vector<std::unique_ptr<human>> objects;

		objects.reserve(4);

		objects.emplace_back(prot_fact.create_prototype(human_t::female));
		objects.emplace_back(prot_fact.create_prototype(human_t::female));
		objects.emplace_back(prot_fact.create_prototype(human_t::male));
		objects.emplace_back(prot_fact.create_prototype(human_t::female));

		for (auto&& value : objects) {
			value->something();
			std::cout << '\n';
		}
	}


	return 0;
}
