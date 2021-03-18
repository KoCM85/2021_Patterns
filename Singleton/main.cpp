#include "singleton.h"

#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char * argv []) {
	patterns::singleton* obj_1 = &patterns::singleton::get_instance();
	patterns::singleton* obj_2 = &patterns::singleton::get_instance();
	patterns::singleton* obj_3 = &patterns::singleton::get_instance();
	patterns::singleton* obj_4 = &patterns::singleton::get_instance();

	std::cout << obj_4->get_counter() << "\n\n";


	patterns::singleton_pt* singl_pt_1 = patterns::singleton_pt::get_instance();
	patterns::singleton_pt* singl_pt_2 = patterns::singleton_pt::get_instance();
	patterns::singleton_pt* singl_pt_3 = patterns::singleton_pt::get_instance();
	std::cout << singl_pt_3->get_counter() << '\n';

	singl_pt_2->destroy();
	std::cout << singl_pt_2->get_counter() << '\n';

	singl_pt_1->destroy();
	singl_pt_3->destroy();
	std::cout << singl_pt_3->get_counter() << '\n';

	singl_pt_2 = patterns::singleton_pt::get_instance();
	patterns::singleton_pt* singl_pt_4 = patterns::singleton_pt::get_instance();
	std::cout << singl_pt_4->get_counter() << '\n';


	return 0;
}