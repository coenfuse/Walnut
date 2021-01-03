#pragma once
#include <set>
#include <string>
#include <chrono>

static void spectate_loop();

class Walnut {

public:		// Walnut's interface section

	enum class USER_TYPE {
		HUMAN = 0,
		ROBOT = 1,
	};

	Walnut();
	Walnut(USER_TYPE);
	~Walnut();

	void start();
	void customize();
	void get_report();
	void spectate();

private:	// Walnut's utility section

	using duration_type = std::chrono::milliseconds;

	struct stats {
		unsigned short score = 0;
		double percentage = 0.0;
		unsigned int avg_duration = 0;
	};

	class Test {

	public:		// Test's Interface

		Test();
		~Test();
		Test(Walnut::USER_TYPE TYPE);
		std::set<Walnut::stats>* start();

	private:	// Test's private attributes section

		using time_precision = Walnut::duration_type;

		const unsigned short section_length = Walnut::section_length;
		std::set<short> question_memory;
		unsigned short score;
		unsigned int average_duration;
		bool robot_mode;
		std::set<Walnut::stats> result_set;

	private:	// Test's private methods section

		void take_input(short*);
		void get_bot_input();

	private:	// Test's question sets

		Walnut::stats sq_set();
		Walnut::stats psqrt_set();
		Walnut::stats sqrt_set();
		Walnut::stats add_set();
		Walnut::stats sub_set();
		Walnut::stats mul_set();
		Walnut::stats div_set();
		Walnut::stats cb_set();
		Walnut::stats cbrt_set();

	};

private:	// Walnut's static attributes section

	static unsigned short active_players;
	static unsigned int global_average_score;
	static double global_percentage;
	static unsigned int global_average_duration;
	const static unsigned short section_length;

private:	// Walnut's private attributes section

	bool robot_mode = false;
	std::string candidate_name = "";
	std::set<stats> container = { {0,0,0} };
	Test test_obj;

private:	// Walnut's private methods section

	stats get_stats(const std::string* of);
	void update_stats(const std::string* of, stats new_stats);
	friend void spectate_loop();	// To access the private attributes

};