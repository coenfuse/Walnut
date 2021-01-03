#include <iostream>

#include "..\..\Walnut\walnut.h"

Walnut::stats Walnut::Test::sq_set() {

	unsigned short counter = 0;
	short response = 0;
	unsigned short score = 0;
	const double max_score = 20;
	double percentage = 0.0;
	unsigned int total_duration = 0;

	while (counter < section_length) {
		
		srand((unsigned int)time(NULL));
		short operand = rand() % 101;
		short correct_answer = operand * operand;

		std::cout << "What is the square of: " << operand << std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		get_input(&response);
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<time_precision>(end - start);

		if (response == correct_answer) {
			score++;
			total_duration += duration.count();
		}

	}

	auto average_duration = total_duration / counter;
	percentage = double((score / max_score) * 100);
	
	return { average_duration, percentage, score };

}