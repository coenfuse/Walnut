#include <iostream>
#include<time.h>

class Test {

	static unsigned int player_count;
	static float global_avg;
	const float max_score = 40;
	float m_score;

private:

	unsigned short find_square();
	unsigned short find_perfect_root();
	unsigned short find_root();
	unsigned short find_product();
	unsigned short find_sum();
	unsigned short division_set();
	unsigned short subtraction_set();
	unsigned short cube_set();

public:

	Test() {
		m_score = 0;
	}
	~Test(){}
	void start();
	void close(){}
	void report();

};

unsigned int Test::player_count = 0;
float Test::global_avg = 0;

void Test::start() {
	
	player_count++;

	std::cout << "Starting Test..." << std::endl;
	m_score += find_square();
	m_score += find_perfect_root();
	m_score += find_root();
	m_score += find_product();
	m_score += subtraction_set();
	m_score += division_set();
	m_score += find_sum();
	m_score += cube_set();
	std::cout << "Test has been finished" << std::endl;

}

void Test::report() {
	float percentage = (m_score / max_score) * 100;
	std::cout << "\n\nYour score is: " << m_score << std::endl;
	std::cout << "Your percentage is: " << percentage << " %" << std::endl;
}

unsigned short Test::find_square() {
	
	std::system("cls");

	unsigned short duration = 0;
	unsigned short score = 0;
	while (duration < 5) {
		
		srand((unsigned int)time(NULL));
		unsigned short operand = rand() % 101;
		unsigned short correct_answer = operand * operand;
		unsigned short response;
		
		std::cout << "\nWhat is the square of: " << operand << " ?" << std::endl;
		std::cin >> response;
		if (response == correct_answer)
			score++;

		duration++;
	}
	return score;
}

unsigned short Test::find_perfect_root() {
	std::system("cls");

	unsigned short duration = 0;
	unsigned short score = 0;
	while (duration < 5) {

		srand((unsigned int)time(NULL));
		unsigned short operand = rand() % 101;
		unsigned short correct_answer = operand;
		unsigned short response;

		std::cout << "\nWhat is the square root of: " << operand * operand << " ?" << std::endl;
		std::cin >> response;
		if (response == correct_answer)
			score++;
		duration++;
	}
	return score;
}

unsigned short Test::find_root() {

	std::system("cls");

	unsigned short duration = 0;
	unsigned short score = 0;
	while (duration < 5) {

		srand((unsigned int)time(NULL));
		unsigned short operand = rand() % 10001;
		unsigned short correct_answer = (short)std::pow(operand, 0.5);
		float response;

		std::cout << "\nWhat is the sqaure root of: " << operand << " ? (Round of to nearest floor)" << std::endl;
		std::cin >> response;
		if (response == correct_answer)
			score++;
		duration++;
	}
	return score;
}

unsigned short Test::find_product() {
	
	std::system("cls");

	unsigned short duration = 0;
	unsigned short score = 0;
	while (duration < 5) {

		srand((unsigned int)time(NULL));
		unsigned short operand_1 = rand() & 101;
		unsigned short operand_2 = rand() & 101;
		unsigned int correct_answer = operand_1 * operand_2;
		unsigned int response;

		std::cout << "What is the product of following expression: " << operand_1 << " * " << operand_2 << " ?" << std::endl;
		std::cin >> response;
		if (response == correct_answer)
			score++;
		duration++;
	}
	return score;
}

unsigned short Test::division_set() {

	std::system("cls");

	unsigned short duration = 0;
	unsigned short score = 0;
	while (duration < 5) {

		srand((unsigned int)time(NULL));
		unsigned short operand_1 = rand() & 101;
		unsigned short operand_2 = rand() & 101;
		short correct_answer = operand_1 / operand_2;
		unsigned int response;

		std::cout << "What is the quotient from the following expression: " << operand_1 << " / " << operand_2 << " ?" << std::endl;
		std::cin >> response;
		if (response == correct_answer)
			score++;
		duration++;
	}
	return score;
}

unsigned short Test::subtraction_set(){

	std::system("cls");

	unsigned short duration = 0;
	unsigned short score = 0;
	while (duration < 5) {

		srand((unsigned int)time(NULL));
		unsigned int operand_1 = rand() % 9999;
		unsigned int operand_2 = rand() & 9999;
		short correct_answer = operand_1 - operand_2;
		unsigned int response;

		std::cout << "What is the difference of following expression: " << operand_1 << " - " << operand_2 << " ?" << std::endl;
		std::cin >> response;
		if (response == correct_answer)
			score++;
		duration++;
	}
	return score;
}

unsigned short Test::find_sum() {

	std::system("cls");

	unsigned short duration = 0;
	unsigned short score = 0;
	while (duration < 5) {

		srand((unsigned int)time(NULL));
		unsigned int operand_1 = rand() % 9999;
		unsigned int operand_2 = rand() % 9999;
		unsigned int correct_answer = operand_1 + operand_2;
		unsigned int response;

		std::cout << "\nWhat is the sum of the following expression: " << operand_1 << " + " << operand_2 << std::endl;
		std::cin >> response;
		if (response == correct_answer)
			score++;
		duration++;
	}
	return score;
}

unsigned short Test::cube_set() {

	std::system("cls");

	unsigned short duration = 0;
	unsigned short score = 0;
	while (duration < 5) {

		srand((unsigned int)time(NULL));
		unsigned short operand = rand() % 21;
		unsigned short correct_answer = operand;
		unsigned short response;

		std::cout << "\n What is the cube root of the following: " << operand * operand * operand << " ?" << std::endl;
		std::cin >> response;
		if (response == correct_answer)
			score++;
		duration++;
	}
	return score;

}

int main() {
	std::cout << "Working" << std::endl;
	Test newTest; 
	newTest.start();
	std::cout << "Press enter to see your result" << std::endl;
	std::cin.get();
	newTest.report();
	return 0;
}