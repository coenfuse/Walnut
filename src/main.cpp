#include <iostream>
#include <time.h>
#include <chrono>
#include <fstream>
#include <string>
#include <set>
#include <thread> // std::this_thread::sleep_for
#include <algorithm>

class Test {

	using time_precision = std::chrono::milliseconds;	// Global response duration counter senstivity

	static unsigned int player_count;
	static float global_avg;
	const static unsigned int section_length;
	static std::set<int> qmemory;				// Later replace this with CADS iteration
	float m_score;

	bool bot_active = true;						// Set this to true to active a bot that gets a right answer extremely rarely.

private:

	struct m_stats {
		unsigned short questions;
		double score;
		unsigned int avg_duration;
	};

	m_stats results[9];

	int get_input() {
		std::string input;
		int fixed_val;

		if (bot_active) {
			// Extremely basic bot. Not even a bot actually.
			input = std::to_string(rand() % 100);
			std::this_thread::sleep_for(std::chrono::seconds(rand() % 10 + 2));
		}
		else {
			std::cin >> input;
			if (input == "X" || input == "x")
				exit (-1);
			//std::transform(input.begin(), input.end(), input.begin(), std::tolower);
		}

		try {
			fixed_val = std::stoi(input);
		}
		catch (...) {
			return 0;
		}

		return fixed_val;
	}

	int prev_rec(int new_val = 0) {
		// Need excessive cleaning.
		using namespace std;

		fstream file("report.dat", std::ios::in);
		if (file) {
			// File exists
			int current, counter = 0;
			int total = 0;

			while (file >> current) {
				total += current;
				counter++;
			}
			
			file.close();
			fstream out("report.dat", std::ios::out | std::ios::app);
			out << std::endl;
			out << new_val;
			out.close();

			if (counter == 0)
				counter = 1;
			return (total / counter);
		}
		else {
			// File didn't existed
			fstream new_file("report.dat", std::ios::out);
			new_file << new_val;
			new_file.close();
			return -1;
		}
	}

private:

	m_stats square_set();
	m_stats perfect_root_set();
	m_stats root_set();
	m_stats product_set();
	m_stats sum_set();
	m_stats division_set();
	m_stats difference_set();
	m_stats cube_set();
	m_stats cube_root_set();

public:

	Test() : m_score(0){}
	~Test(){}
	void start();
	void report();

};

unsigned int Test::player_count = 0;
float Test::global_avg = 0;
const unsigned int Test::section_length = 10;
std::set<int> Test::qmemory = { 0 }; 

void Test::start() {
	
	player_count++;

	std::cout << "Starting Test..." << std::endl;

	results[0] = square_set();
	results[1] = perfect_root_set();
	results[2] = root_set();
	results[3] = product_set();
	results[4] = sum_set();
	results[5] = division_set();
	results[6] = difference_set();
	results[7] = cube_set();
	results[8] = cube_root_set();

	std::cout << "\nTest has been finished" << std::endl;

}

void Test::report() {

	std::system("cls");

	double max_score = 0;
	double percentage;

	// Score card for Square_Set()
	max_score = 2 * results[0].questions;
	percentage = (results[0].score / max_score) * 100;
	std::cout << "\nScore card for Section A (Finding Squares)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Score obtained: " << results[0].score << std::endl;
	std::cout << "Percentage obtained: " << percentage << " %" << std::endl;
	std::cout << "Average time spent on each question: " << results[0].avg_duration << " ms (" << (results[0].avg_duration / 1000) << " seconds)" << std::endl;

	// Score card for Perfect_Root_Set()
	max_score = 2 * results[1].questions;
	percentage = (results[1].score / max_score) * 100;
	std::cout << "\nScore card for Section B (Finding Perfect Roots)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Score obtained: " << results[1].score << std::endl;
	std::cout << "Percentage obtained: " << percentage << " %" << std::endl;
	std::cout << "Average time spend on each question: " << results[1].avg_duration << " ms (" << (results[1].avg_duration / 1000) << " seconds)" << std::endl;

	// Score card for Root_Set()
	max_score = 2 * results[2].questions;
	percentage = (results[2].score / max_score) * 100;
	std::cout << "\nScore card for Section C (Finding Roots)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Score obtained: " << results[2].score << std::endl;
	std::cout << "Percentage obtained: " << percentage << " %" << std::endl;
	std::cout << "Average time spend on each question: " << results[2].avg_duration << " ms (" << (results[2].avg_duration / 1000) << " seconds)" << std::endl;

	// Score card for Product_Set()
	max_score = 2 * results[3].questions;
	percentage = (results[3].score / max_score) * 100;
	std::cout << "\nScore card for Section D (Finding Products)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Score obtained: " << results[3].score << std::endl;
	std::cout << "Percentage obtained: " << percentage << " %" << std::endl;
	std::cout << "Average time spend on each question: " << results[3].avg_duration << " ms (" << (results[3].avg_duration / 1000) << " seconds)" << std::endl;

	// Score card for Sum_Set()
	max_score = 2 * results[4].questions;
	percentage = (results[4].score / max_score) * 100;
	std::cout << "\nScore card for Section E (Finding Sum)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Score obtained: " << results[4].score << std::endl;
	std::cout << "Percentage obtained: " << percentage << " %" << std::endl;
	std::cout << "Average time spend on each question: " << results[4].avg_duration << " ms (" << (results[4].avg_duration / 1000) << " seconds)" << std::endl;

	// Score card for Division_Set()
	max_score = 2 * results[5].questions;
	percentage = (results[5].score / max_score) * 100;
	std::cout << "\nScore card for Section F (Finding Divisor)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Score obtained: " << results[5].score << std::endl;
	std::cout << "Percentage obtained: " << percentage << " %" << std::endl;
	std::cout << "Average time spend on each question: " << results[5].avg_duration << " ms (" << (results[5].avg_duration / 1000) << " seconds)" << std::endl;

	// Score card for Difference_Set()
	max_score = 2 * results[6].questions;
	percentage = (results[6].score / max_score) * 100;
	std::cout << "\nScore card for Section G (Finding Difference)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Score obtained: " << results[6].score << std::endl;
	std::cout << "Percentage obtained: " << percentage << " %" << std::endl;
	std::cout << "Average time spend on each question: " << results[6].avg_duration << " ms (" << (results[6].avg_duration / 1000) << " seconds)" << std::endl;

	// Score card for Cube_Set()
	max_score = 2 * results[7].questions;
	percentage = (results[7].score / max_score) * 100;
	std::cout << "\nScore card for Section H (Finding Cube)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Score obtained: " << results[7].score << std::endl;
	std::cout << "Percentage obtained: " << percentage << " %" << std::endl;
	std::cout << "Average time spend on each question: " << results[7].avg_duration << " ms (" << (results[7].avg_duration / 1000) << " seconds)" << std::endl;

	// Score card for Cube_Root_Set()
	max_score = 2 * results[8].questions;
	percentage = (results[8].score / max_score) * 100;
	std::cout << "\nScore card for Section I (Finding Cube Roots)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Score obtained: " << results[8].score << std::endl;
	std::cout << "Percentage obtained: " << percentage << " %" << std::endl;
	std::cout << "Average time spend on each question: " << results[8].avg_duration << " ms (" << (results[8].avg_duration / 1000) << " seconds)" << std::endl;

	// Final Score Calculation
	int test_avg_time = 0;
	unsigned int global_avg_time = 0;
	unsigned int total_questions = 0;
	unsigned int total_score = 0;

	for (size_t i = 0; i < 9; i++) {
		test_avg_time += results[i].avg_duration;
		total_questions += results[i].questions;
		total_score     += results[i].score;
	}

	max_score = 2 * total_questions;
	percentage = (total_score / max_score) * 100;
	test_avg_time = test_avg_time / 9;	// Number of sections

	// Update and fetch previous record
	short prev_avg = 0;
	prev_avg = prev_rec(test_avg_time);
	if (prev_avg == -1)
		prev_avg = 0;

	int improvement = prev_avg - test_avg_time;

	std::cout << "\n\nFINAL REPORT CARD" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "You scored " << total_score << " out of " << max_score << "." << std::endl;
	std::cout << "Your final percentage is: " << percentage << " %" << std::endl;
	std::cout << "Your average duration on each question is: " << test_avg_time << " ms" << std::endl;
	
	if (prev_avg == 0) {
		std::cout << "Your all time average is: NULL" << std::endl;
	}
	else if (improvement > 0) {
		std::cout << "Your all time average is: " << prev_avg <<" ms"<< std::endl;
		std::cout << "You improved by: " << improvement << " ms, on your all time average calculation speed." << std::endl;
	}
	else {
		std::cout << "Your all time average is: " << prev_avg << " ms" << std::endl;
		std::cout << "You slowed down by: " << improvement*(-1) << " ms, compared to your all time average calculation speed." << std::endl;
	}
}

Test::m_stats Test::square_set() {
	
	std::system("cls");
	unsigned short questions_asked = 0;
	double score = 0;
	unsigned int total_time_taken = 0;

	qmemory.clear();

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand;
		
		while (true) {
			operand = rand() % 101;
			if (qmemory.find(operand) == qmemory.end()) {
				qmemory.insert(operand);
				break;
			}
		}
		
		unsigned short correct_answer = operand * operand;
		unsigned short response = 0;
		
		std::cout << "What is the square of: " << operand << " ?" << std::endl;
		
		auto start = std::chrono::high_resolution_clock::now();
		response = get_input();
		auto end = std::chrono::high_resolution_clock::now();
		
		auto duration = std::chrono::duration_cast<time_precision>(end - start);
		total_time_taken += duration.count();

		if (response == correct_answer)
			score += 2;
		
		questions_asked++;
	}
	
	unsigned int avg_time_taken = total_time_taken / questions_asked;
	return { questions_asked, score, avg_time_taken };
}

Test::m_stats Test::perfect_root_set() {

	std::system("cls");
	unsigned short questions_asked = 0;
	double score = 0;
	unsigned int total_time_taken = 0;

	qmemory.clear();

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand;		// Operand itself is the correct answer

		while (true) {
			operand = rand() % 101;
			if (qmemory.find(operand) == qmemory.end()) {
				qmemory.insert(operand);
				break;
			}
		}

		unsigned short response;

		std::cout << "What is the square root of: " << operand * operand << " ?" << std::endl;
		
		auto start = std::chrono::high_resolution_clock::now();
		response = get_input();
		auto end = std::chrono::high_resolution_clock::now();
		
		auto duration = std::chrono::duration_cast<time_precision>(end - start);
		total_time_taken += duration.count();

		if (response == operand)
			score += 2;
		questions_asked++;
	}

	unsigned int avg_time_taken = total_time_taken / questions_asked;
	return { questions_asked, score, avg_time_taken };
}

Test::m_stats Test::root_set(){

	std::system("cls");
	unsigned short questions_asked = 0;
	double score = 0;
	unsigned int total_time_taken = 0;

	qmemory.clear();

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand;

		while (true) {
			operand = rand() % 10001;
			if (qmemory.find(operand) == qmemory.end()) {
				qmemory.insert(operand);
				break;
			}
		}

		unsigned short correct_answer = std::pow(operand, 0.5);
		unsigned short response;

		std::cout << "What is the square root approx. of: " << operand << " ? (Round to nearest floor, ignore decimals)" << std::endl;
		
		auto start = std::chrono::high_resolution_clock::now();
		response = get_input();
		auto end = std::chrono::high_resolution_clock::now();
		
		auto duration = std::chrono::duration_cast<time_precision>(end - start);
		total_time_taken += duration.count();

		if (response == correct_answer)
			score += 2;
		questions_asked++;
	}

	unsigned int avg_time_taken = total_time_taken / questions_asked;
	return {questions_asked, score, avg_time_taken};
}

Test::m_stats Test::product_set() { 

	std::system("cls");
	unsigned short questions_asked = 0;
	double score = 0;
	unsigned int total_time_taken = 0;

	qmemory.clear();

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand_1, operand_2;

		while (true) {
			operand_1 = rand() % 101;
			if (qmemory.find(operand_1) == qmemory.end()) {
				qmemory.insert(operand_1);
				break;
			}
		}

		while (true) {
			operand_2 = rand() % 101;
			if (qmemory.find(operand_2) == qmemory.end()) {
				qmemory.insert(operand_2);
				break;
			}
		}

		unsigned short correct_answer = operand_1 * operand_2;
		unsigned short response;

		std::cout << "What is the result of this expression: " << operand_1 << " x " << operand_2 <<" ?"<< std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		response = get_input();
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<time_precision>(end - start);
		total_time_taken += duration.count();
	
		if (response == correct_answer)
			score += 2;
		questions_asked++;
	}

	unsigned int avg_time_taken = total_time_taken / questions_asked;
	return { questions_asked, score, avg_time_taken };
}

Test::m_stats Test::sum_set(){

	std::system("cls");

	unsigned short questions_asked = 0;
	double score = 0;
	unsigned int total_time_taken = 0;

	qmemory.clear();

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand_1, operand_2;

		while (true) {
			operand_1 = rand() % 10000;
			if (qmemory.find(operand_1) == qmemory.end()) {
				qmemory.insert(operand_1);
				break;
			}
		}

		while (true) {
			operand_2 = rand() % 10000;
			if (qmemory.find(operand_2) == qmemory.end()) {
				qmemory.insert(operand_2);
				break;
			}
		}

		unsigned int correct_answer = operand_1 + operand_2;
		unsigned int response;

		std::cout << "What is the result of this expression: " << operand_1 << " + " << operand_2 <<" ?"<< std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		response = get_input();
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<time_precision>(end - start);
		total_time_taken += duration.count();

		if (response == correct_answer)
			score += 2;
		questions_asked++;
	}

	unsigned int avg_time_taken = total_time_taken / questions_asked;
	return { questions_asked, score, avg_time_taken };
}

Test::m_stats Test::division_set() {

	std::system("cls");

	unsigned short questions_asked = 0;
	double score = 0;
	unsigned int total_time_taken = 0;

	qmemory.clear();

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand_1, operand_2;

		while (true) {
			operand_1 = rand() % 10000;
			if (qmemory.find(operand_1) == qmemory.end()) {
				qmemory.insert(operand_1);
				break;
			}
		}

		while (true) {
			operand_2 = (rand() % 20 + 2);	// See note at the end of this method
			if (qmemory.find(operand_2) == qmemory.end()) {
				qmemory.insert(operand_2);
				break;
			}
		}

		unsigned int correct_answer = operand_1 / operand_2;
		unsigned int response;

		std::cout << "What is the result of this expression: " << operand_1 << " / " << operand_2 << " ? (Round to nearest floor, ignore decimals)" << std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		response = get_input();
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<time_precision>(end - start);
		total_time_taken += duration.count();

		if (response == correct_answer)
			score += 2;
		questions_asked++;
	}

	unsigned int avg_time_taken = total_time_taken / questions_asked;
	return { questions_asked, score, avg_time_taken };

	// NOTE: cplusplus.com/reference/clibrary/cstlib/rand/

	// (value % 100) is in the range 0 to 99
	// (value % 100 + 1) is in the range 1 to 100
	// (value % 30 + 1985) is in the range 1985 to 2014
}

Test::m_stats Test::difference_set() {

	std::system("cls");

	unsigned short questions_asked = 0;
	double score = 0;
	unsigned int total_time_taken = 0;

	qmemory.clear();

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand_1,operand_2;

		while (true) {
			operand_1 = rand() % 10000;
			if (qmemory.find(operand_1) == qmemory.end()) {
				qmemory.insert(operand_1);
				break;
			}
		}

		while (true) {
			operand_2 = rand() % 10000;
			if (qmemory.find(operand_2) == qmemory.end()) {
				qmemory.insert(operand_2);
				break;
			}
		}

		unsigned int correct_answer = operand_1 - operand_2;
		unsigned int response;

		std::cout << "What is the result of this expression: " << operand_1 << " - " << operand_2 << " ?" << std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		response = get_input();
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<time_precision>(end - start);
		total_time_taken += duration.count();

		if (response == correct_answer)
			score += 2;
		questions_asked++;
	}

	unsigned int avg_time_taken = total_time_taken / questions_asked;
	return { questions_asked, score, avg_time_taken };
}

Test::m_stats Test::cube_set() {

	std::system("cls");
	unsigned short questions_asked = 0;
	double score = 0;
	unsigned int total_time_taken = 0;

	qmemory.clear();

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand;

		while (true) {
			operand = rand() % 11;
			if (qmemory.find(operand) == qmemory.end()) {
				qmemory.insert(operand);
				break;
			}
		}

		unsigned short correct_answer = operand * operand * operand;
		unsigned short response = 0;

		std::cout << "What is the cube of: " << operand << " ?" << std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		response = get_input();
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<time_precision>(end - start);
		total_time_taken += duration.count();

		if (response == correct_answer)
			score += 2;

		questions_asked++;
	}

	unsigned int avg_time_taken = total_time_taken / questions_asked;
	return { questions_asked, score, avg_time_taken };
}

Test::m_stats Test::cube_root_set() {

	std::system("cls");
	unsigned short questions_asked = 0;
	double score = 0;
	unsigned int total_time_taken = 0;

	qmemory.clear();

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand = rand() % 11;		// Operand itself is the correct answer

		while (true) {
			operand = rand() % 11;
			if (qmemory.find(operand) == qmemory.end()) {
				qmemory.insert(operand);
				break;
			}
		}

		unsigned short response;

		std::cout << "What is the cube root of: " << operand * operand * operand << " ?" << std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		response = get_input();
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<time_precision>(end - start);
		total_time_taken += duration.count();

		if (response == operand)
			score += 2;
		questions_asked++;
	}

	unsigned int avg_time_taken = total_time_taken / questions_asked;
	return { questions_asked, score, avg_time_taken };
}

int main() {
	
	Test Test;

	std::cout << "To start the test, press Enter. Press \'X\' anywhere in the program to exit." << std::endl;
	std::cin.get();

	auto start = std::chrono::high_resolution_clock::now();
	Test.start();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	int time = duration.count();
	
	std::cout << "Press enter to see your result" << std::endl;
	std::cin.get();

	std::cout << "\n\nTest Duration: " << time << " minutes." << std::endl;
	Test.report();

	std::cout << "\n\nYour performance report is saved in report.dat"<<std::endl;
	std::cout << "Press enter to exit";
	std::cin.get();
	return 0;
}

// DONE Create a bounds check for invalid input.
// DONE Fix the progress record function. Do finishing and testing. Release V1.
// DONE Made generated question fully random.

// TODO Increase the variance betweem the randomly generated questions.
// TODO Fix all the warnings. Data Type conversion verification.
// TODO Find a way to improve the time inconsistency. The get_input() itself has its own overhead and it is getting added to user's time. This affects the efficiency of duration counter.
// TODO Break the program into multiple files and store them appropriately.
// TODO Restructure using templates if its okay.
// TODO Add more features to progress record function
// TODO Add memory feature, the program will keep track of all the questions where the answer wasn't right and will try to throw it next time.
// TODO Make proprietary API for bots. Use polymorphism is possible.
// TODO Define bots and implement a small scale ecosystem to run the bots.
