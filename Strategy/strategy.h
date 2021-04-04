#ifndef STRATEGY_H

#define STRATEGY_H

#include <algorithm>
#include <functional>

namespace patterns {

	template<class type>
	class sorting {
	public:
		virtual ~sorting() = default;
		
		virtual void sort(type& obj) = 0;
	};


	template<class type>
	class greater : public sorting<type> {
	public:
		void sort(type& obj) override;
	};


	template<class type>
	class less : public sorting<type> {
	public:
		void sort(type& obj) override;
	};

	template<class type>
	class data {
		sorting<type>* sort_v;

	public:
		data(sorting<type>* sort_in = nullptr) : sort_v(sort_in) {}

		void sort(type& obj);
		void set_sort(sorting<type>& sort_in);
		bool is_empty();
	};

}

// definitions
namespace patterns {

	// greater
	template<class type>
	void greater<type>::sort(type& obj) {
		std::sort(obj.begin(), obj.end(), std::greater<type::value_type>());
	}



	// less
	template<class type>
	void less<type>::sort(type& obj) {
		std::sort(obj.begin(), obj.end(), std::less<type::value_type>());
	}



	// data
	template<class type>
	void data<type>::sort(type& obj) {
		sort_v->sort(obj);
	}


	template<class type>
	void data<type>::set_sort(sorting<type>& sort_in) {
		sort_v = &sort_in;
	}


	template<class type>
	bool data<type>::is_empty() {
		return !sort_v;
	}
}

#endif // STRATEGY_H