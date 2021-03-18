#ifndef SINGLETON_H

#define SINGLETON_H

#include <new>

namespace patterns {

	class singleton final {
		static inline short unsigned counter = 0;

	private:
		singleton() { ++counter; }

		singleton(const singleton&) = delete;
		singleton(singleton&&) = delete;

		singleton& operator=(const singleton&) = delete;
		singleton& operator=(singleton&&) = delete;

		~singleton() { --counter; }

	public:
		static inline singleton& get_instance();

		inline const short unsigned& get_counter();
	};



	class singleton_pt final {
		static inline bool created = false;
		static inline short unsigned counter = 0;
		static char storage[];

	private:
		singleton_pt() { created = true; ++counter; }

		singleton_pt(const singleton_pt&) = delete;
		singleton_pt(singleton_pt&&) = delete;

		singleton_pt& operator=(const singleton_pt&) = delete;
		singleton_pt& operator=(singleton_pt&&) = delete;

		~singleton_pt() { created = false; --counter; }

	public:
		static inline singleton_pt * get_instance();

		inline void destroy();

		inline const short unsigned& get_counter();
	};

}

namespace patterns {

	// singleton   BEGIN
	singleton& singleton::get_instance() {
		static singleton single;

		return single;
	}

	const short unsigned& singleton::get_counter() {
		return counter;
	}
	// singleton   END


	// singleton_pt   BEGIN
	inline char singleton_pt::storage[sizeof(singleton_pt)];

	singleton_pt * singleton_pt::get_instance() {
		if (!created) {
			new(storage) singleton_pt;
		}

		return reinterpret_cast<singleton_pt*>(storage);
	}

	void singleton_pt::destroy() {
		if (created)
			reinterpret_cast<singleton_pt*>(storage)->~singleton_pt();
	}

	const short unsigned& singleton_pt::get_counter() {
		return counter;
	}
	// singleton_pt   END
}

#endif // SINGLETON_H