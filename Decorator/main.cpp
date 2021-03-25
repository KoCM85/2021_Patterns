#include "decorator.h"

#include "iostream"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;
		
		std::shared_ptr<human> ptr_1(new female);
		std::shared_ptr<human> ptr_2(new helmet(ptr_1));
		std::shared_ptr<human> ptr_3(new boots(ptr_2));
		std::shared_ptr<human> ptr_4(new hair(ptr_3));

		std::cout << ptr_1->some_operation() << '\n';
		std::cout << ptr_2->some_operation() << '\n';
		std::cout << ptr_3->some_operation() << '\n';
		std::cout << ptr_4->some_operation(" white") << '\n';
	}
}