#ifndef TEMPLATE_METHOD_H

#define TEMPLATE_METHOD_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

namespace patterns {

	class some_operation {
	public:
		virtual ~some_operation() = default;

		inline void template_method(std::vector<int>&);

	private:
		inline void info();
		inline virtual void sort(std::vector<int>&) = 0;
		inline void print_vect(std::vector<int>&);
		inline void last_info();
	};


	class greater : public some_operation {
		inline void sort(std::vector<int>&) override;
	};


	class less : public some_operation {
		inline void sort(std::vector<int>&) override;
	};
}



// definitions
namespace patterns {

	// some_operation
	void some_operation::template_method(std::vector<int>& vect_in) {
		info();
		sort(vect_in);
		print_vect(vect_in);
		last_info();
	}

	void some_operation::info() {
		std::cout << "begin \n";
	}

	void some_operation::print_vect(std::vector<int>& vect_in) {
		for (auto&& val : vect_in)
			std::cout << val << ' ';
		std::cout << '\n';
	}

	void some_operation::last_info() {
		std::cout << "end \n";
	}



	// greater
	void greater::sort(std::vector<int>& vect_in) {
		std::sort(vect_in.begin(), vect_in.end(), std::greater<int>());
	}



	// less
	void less::sort(std::vector<int>& vect_in) {
		std::sort(vect_in.begin(), vect_in.end(), std::less<int>());
	}

}

#endif // TEMPLATE_METHOD_H