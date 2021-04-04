#include "visitor.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;
		female female_v;
		male male_v;
		visitor visitor_v;

		female_v.add_flower("rose");
		female_v.add_flower("violet");
		female_v.add_flower("snowdrop");
		female_v.add_flower("lily");

		male_v.add_weapon("sword");
		male_v.add_weapon("stick");
		male_v.add_weapon("spear");

		female_v.accept(visitor_v);
		male_v.accept(visitor_v);
	}

	return 0;
}