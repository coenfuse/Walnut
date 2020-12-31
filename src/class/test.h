#pragma once

#include <chrono>
#include <set>
#include <algorithm>
#include <thread>
#include <string>
#include <fstream>
#include <iostream>

class Test {

	using time_precision = std::chrono::milliseconds;

	std::string candidate_name;
	static unsigned short player_count;
	static unsigned short global_average;
	const static unsigned short section_length;
	std::set<short> question_memory = { 0 };
	unsigned short score;
	bool robot_mode;

private:

	// Normal User Utility Function and Attributes
	struct m_stats {
		short average_time;
		short score;
		double percentage;
	};

	std::set<m_stats> results;
	void get_input(short* response_container);
	void update_record(const std::string* which_candidate, m_stats new_record);
	m_stats get_record(const std::string* which_candidate);

private:

	m_stats sqaure_section();
	m_stats perfect_sqaure_root_section();
	m_stats sqaure_root_section();
	m_stats addition_section();
	m_stats subtraction_section();
	m_stats multiplication_section();
	m_stats division_section();
	m_stats cube_section();
	m_stats cube_root_section();

public:

	Test() {}
	~Test() {}

	const enum class TEST_TYPE {
		NORMAL = 0,
		ROBOT = 1,
	};

	// Global Constructor
	Test(TEST_TYPE TYPE) {
		
		score = 0;
		switch (TYPE)
		{
		case Test::TEST_TYPE::NORMAL : {
			std::cout << "Enter your name (case sensitive): ";
			std::cin >> candidate_name;
			robot_mode = false;
		}
			break;
		case Test::TEST_TYPE::ROBOT : robot_mode = true;
			break;
		}
	}

	// Global Destructor
	~Test(){}

public:

	// Normal User Interface
	void start();
	void customize();

public:

	// Robot Interface
	void robot_start();

};

unsigned short Test::player_count = 0;
unsigned short Test::global_average = 0;
const unsigned short Test::section_length = 9;