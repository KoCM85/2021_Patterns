#include "factory_method.h"

#include <vector>

int main([[maybe_unused]] int argc, [[maybe_unused]] char * argv[]) {
    // factory. first example
    {

        std::vector<std::unique_ptr<patterns::human>> humans;

        humans.emplace_back(patterns::human::create_human(patterns::human_t::female));
        humans.emplace_back(patterns::human::create_human(patterns::human_t::male));
        humans.emplace_back(patterns::human::create_human(patterns::human_t::male));
        humans.emplace_back(patterns::human::create_human(patterns::human_t::female));
        humans.emplace_back(patterns::human::create_human(patterns::human_t::female));
        humans.emplace_back(patterns::human::create_human(patterns::human_t::female));

        for (auto&& value : humans)
            value->something();

        humans[0] = patterns::human::create_human(patterns::human_t::male);

        std::cout << '\n';
        for (auto&& value : humans)
            value->something();

    }

    std::cout << "\n\n";

    // factory. second example
    {
        std::vector<std::unique_ptr<patterns::human_2>> humans_2;

        std::unique_ptr<patterns::factory> factory_ptr1 = std::make_unique<patterns::female_factory>();
        std::unique_ptr<patterns::factory> factory_ptr2 = std::make_unique<patterns::male_factory>();

        humans_2.emplace_back(factory_ptr1->create_human());
        humans_2.emplace_back(factory_ptr1->create_human());
        humans_2.emplace_back(factory_ptr2->create_human());
        humans_2.emplace_back(factory_ptr1->create_human());
        humans_2.emplace_back(factory_ptr2->create_human());

        for (auto&& value : humans_2)
            value->something();

        auto iter = --humans_2.end();
        *iter = factory_ptr1->create_human();

        std::cout << '\n';
        for (auto&& value : humans_2)
            value->something();
    }

    return 0;
}