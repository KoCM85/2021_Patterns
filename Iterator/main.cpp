#include "iterator.h"

#include <iostream>
#include <array>

class PO {
	int val;

public:
	PO() : val(0) { std::cout << "PO() \n"; }
	PO(int val_in) : val(val_in) { std::cout << "PO(int) \n"; }
	PO(const PO& obj_in) : val(obj_in.val) { std::cout << "PO(const PO&) \n"; }
	PO(PO&& obj_in) : val(obj_in.val) { obj_in.val = 0; std::cout << "PO(PO&&) \n"; }
	~PO() { std::cout << "~PO() \n"; }

	inline PO& operator=(int val_in);

	inline int& get();
	inline const int& get() const;
	friend inline std::ostream& operator<<(std::ostream& stream, const PO& obj_in);
};

inline PO& PO::operator=(int val_in) {
	val = val_in;

	return *this;
}

int& PO::get() {
	return val;
}

const int& PO::get() const {
	return val;
}

std::ostream& operator<<(std::ostream& stream, const PO& obj_in) {
	return stream << obj_in.val;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	{
		using namespace patterns;

		container<int, 2> arr_1;
		container<PO, 3> arr_2;

		std::cout << arr_1[0] << ' ' << arr_1[1] << '\n';
		std::cout << arr_2[0] << ' ' << arr_2[1] << ' ' << arr_2[2] << "\n\n";


		auto iter_1 = arr_1.begin();
		auto iter_2 = ++arr_1.begin();
		auto iter_3 = arr_2.begin();
		auto iter_4 = ++arr_2.begin();

		std::cout << *iter_1 << ' ' << *iter_2 << '\n';
		std::cout << *iter_3 << ' ' << *iter_4 << "\n\n";

		arr_1[0] = 4;
		arr_1[1] = 21;

		arr_2[0] = 675;
		arr_2[1] = 63;
		arr_2[2] = 909;

		std::cout << arr_1[0] << ' ' << arr_1[1] << '\n';
		std::cout << arr_2[0] << ' ' << arr_2[1] << ' ' << arr_2[2] << '\n';
		std::cout << *iter_1 << ' ' << *iter_2 << '\n';
		std::cout << iter_3->get() << ' ' << iter_4->get() << "\n\n";

		std::cout << "arr_2 size: " << arr_2.size() << '\n';
		std::cout << "arr_2.data(): " << arr_2.data()->get() << "\n\n";

		std::cout << "arr_2: ";
		for (auto&& val : arr_2) {
			std::cout << val.get() << ' ';
		}
		std::cout << '\n';
	}
}