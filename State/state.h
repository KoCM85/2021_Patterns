#ifndef STATE_H

#define STATE_H

#include <memory>
#include <iostream>

namespace patterns {

	class state;

	class human {
		std::unique_ptr<state> state_v;

	public:
		inline human(state* state_in);

		inline void operation();
		inline void set_state(state* state_in);
	};



	class state {
	protected:
		human* human_v;

	public:
		virtual ~state() = default;

		virtual void move() = 0;
		virtual void move_change() = 0;
		inline void set_context(human*);
	};



	class stop : public state {
	public:
		inline void move() override;
		inline void move_change() override;
	};



	class walk : public state {
	public:
		inline void move() override;
		inline void move_change() override;
	};



	class run : public state {
	public:
		inline void move() override;
		inline void move_change() override;
	};

}



// definitions
namespace patterns {

	// human
	human::human(state* state_in) : state_v(state_in) {
		state_v->set_context(this);
	}

	void human::operation() {
		std::cout << "I am ";
		state_v->move();
		std::cout << " changing to ";
		state_v->move_change();
		state_v->move();
		std::cout << '\n';
	}

	void human::set_state(state* state_in) {
		state_v.reset(state_in);
		state_v->set_context(this);
	}


	// state
	void state::set_context(human* human_in) {
		human_v = human_in;
	}


	// stop
	void stop::move() {
		std::cout << "stop";
	}

	void stop::move_change() {
		human_v->set_state(new walk);
	}


	// walk
	void walk::move() {
		std::cout << "walking";
	}

	void walk::move_change() {
		human_v->set_state(new run);
	}


	// run
	void run::move() {
		std::cout << "run";
	}

	void run::move_change() {
		human_v->set_state(new stop);
	}

}

#endif // STATE_H