#ifndef ITERATOR_H

#define ITERATOR_H

#include <string>

namespace patterns {

	template<class data_t>
	class container_iterator {
		data_t* data;

	private:
		using const_reference = const data_t&;
		using const_pointer = const data_t*;

	public:
		container_iterator(data_t* data_in) : data(data_in) {}

		inline const_reference operator[](size_t index_in) const;
		inline const_reference operator*() const;
		inline const_pointer operator->() const;
		inline container_iterator& operator++();
		inline bool operator!=(const container_iterator&);
	};

	template<class type, size_t arr_size>
	class container {
		type arr[arr_size];

	public:
		using iterator = container_iterator<type>;
		using reference = type&;

	public:
		inline iterator begin();
		inline iterator end();
		inline size_t size();
		inline type* data();
		inline reference operator[](size_t index_in);
	};

}



// definition
namespace patterns {

	// container_iterator
	template<class data_t>
	typename container_iterator<data_t>::const_reference container_iterator<data_t>::operator[](size_t index_in) const {
		return data[index_in];
	}

	template<class data_t>
	typename container_iterator<data_t>::const_reference container_iterator<data_t>::operator*() const {
		return *data;
	}

	template<class data_t>
	typename container_iterator<data_t>::const_pointer container_iterator<data_t>::operator->() const {
		return data;
	}

	template<class data_t>
	container_iterator<data_t>& container_iterator<data_t>::operator++() {
		++data;
		return *this;
	}

	template<class data_t>
	bool container_iterator<data_t>::operator!=(const container_iterator& iter_right) {
		return data != iter_right.data;
	}



	// container
	template<class type, size_t arr_size>
	typename container<type, arr_size>::iterator container<type, arr_size>::begin() {
		return iterator(arr);
	}

	template<class type, size_t arr_size>
	typename container<type, arr_size>::iterator container<type, arr_size>::end() {
		return iterator(arr + arr_size);
	}

	template<class type, size_t arr_size>
	size_t container<type, arr_size>::size() {
		return arr_size;
	}

	template<class type, size_t arr_size>
	type* container<type, arr_size>::data() {
		return arr;
	}

	template<class type, size_t arr_size>
	typename container<type, arr_size>::reference container<type, arr_size>::operator[](size_t index_in) {
		return arr[index_in];
	}

}

#endif // ITERATOR_H