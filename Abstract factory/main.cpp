#include "abstract_factory.h"

#include <vector>

namespace {
	using unit = std::pair<std::unique_ptr<patterns::human>, std::unique_ptr<patterns::weapon>>;

	void pri(std::vector<unit>& units_in) {
		for (auto&& value : units_in) {
			value.first->something();
			std::cout << " with ";
			value.second->some_weapon();
			std::cout << '\n';
		}
	}
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	// factory. first example
	{
		using factory_sptr = std::unique_ptr<patterns::factory>;

		factory_sptr peasant = std::make_unique<patterns::peasant_factory>();
		factory_sptr guard = std::make_unique<patterns::guard_factory>();
		factory_sptr archer = std::make_unique<patterns::archer_factory>();

		std::vector<unit> units;

		units.reserve(5);

		units.emplace_back(peasant->create_human(), peasant->create_weapon());
		units.emplace_back(peasant->create_human(), peasant->create_weapon());
		units.emplace_back(guard->create_human(), guard->create_weapon());
		units.emplace_back(peasant->create_human(), peasant->create_weapon());
		units.emplace_back(archer->create_human(), archer->create_weapon());

		pri(units);

		units[0] = std::make_pair(archer->create_human(), archer->create_weapon());
		units[2] = std::make_pair(archer->create_human(), archer->create_weapon());

		std::cout << '\n';
		pri(units);
	}

	std::cout << "\n\n";

	// factory. second example
	{
		using factory =  patterns::factory_2;
		using unit_t = factory::unit_t;

		std::vector<unit> units;

		units.reserve(5);

		units.emplace_back(factory::create_human(unit_t::peasant), factory::create_weapon(unit_t::peasant));
		units.emplace_back(factory::create_human(unit_t::peasant), factory::create_weapon(unit_t::peasant));
		units.emplace_back(factory::create_human(unit_t::guard), factory::create_weapon(unit_t::guard));
		units.emplace_back(factory::create_human(unit_t::peasant), factory::create_weapon(unit_t::peasant));
		units.emplace_back(factory::create_human(unit_t::archer), factory::create_weapon(unit_t::archer));

		pri(units);

		units[0] = std::make_pair(factory::create_human(unit_t::archer), factory::create_weapon(unit_t::archer));
		units[2] = std::make_pair(factory::create_human(unit_t::archer), factory::create_weapon(unit_t::archer));

		std::cout << '\n';
		pri(units);
	}
}