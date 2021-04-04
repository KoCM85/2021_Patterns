#include "template_method.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		patterns::greater greater_v;
		patterns::less less_v;
		patterns::some_operation* ptr = &greater_v;
		std::vector<int> datas{443, 56, 9, 90966, 613, 1, 4516};

		ptr->template_method(datas);
		std::cout << "\n\n";

		ptr = &less_v;
		ptr->template_method(datas);
	}

	return 0;
}