#include <iostream>
#include<time.h>
#include<chrono>
#include<fstream>

// 1. - Fix the progress record function. Do finishing and testing. Release V1.
// 2. - Break the program into multiple files and store them appropriately.
// 3. - Restructure using templates if its okay.
// 3. - Add more features to progress record function.
// 4. - Add memory feature, the program will keep track of all the questions where
// the answer wasn't right and will try to throw it next time.
// 5. - Make prioprietary API for bots. Use polymorphism if you could.
// 6. - Define bots and implement a small scale ecosystem to run the bots.

class Test {

	static unsigned int player_count;
	static float global_avg;
	const static unsigned int section_length;

	using duration_type = std::chrono::milliseconds;

	float m_score;

private:
	struct m_stats {
		unsigned short questions;
		double score;
		unsigned int avg_duration;
	};

	m_stats results[9];

	int prev_rec(int new_val = 0) {
		// Need excessive cleaning.
		using namespace std;

		fstream file("data.dat", std::ios::in);
		if (file) {
			// File exists
			int current, counter = 0;
			long long total = 0;

			fstream fin("data.dat", std::ios::in);
			while (fin) {
				fin >> current;
				total += current;
				counter++;
			}
			fin.close();

			fstream fout("data.dat", std::ios::out | std::ios::app);
			fout << new_val << std::endl;
			fout.close();

			return (total / counter);
		}
		else {
			// File didn't existed
			fstream fout("data.dat", std::ios::out);
			fout << new_val;
			fout.close();
			return 0;
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
	unsigned int test_avg_time = 0;
	unsigned int total_questions = 0;
	unsigned int total_score = 0;

	for (size_t i = 0; i < 9; i++) {
		test_avg_time += results[i].avg_duration;
		total_questions += results[i].questions;
		total_score		+= results[i].score;
	}

	max_score = 2 * total_questions;
	percentage = (total_score / max_score) * 100;
	test_avg_time = test_avg_time / 9;	// Number of sections

	// Update and fetch previous record
	int prev_avg = 0;
	prev_avg = prev_rec(test_avg_time);

	std::cout << "\n\nFINAL REPORT CARD" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "You scored " << total_score << " out of " << max_score <<"."<< std::endl;
	std::cout << "Your final percentage is: " << percentage <<" %"<< std::endl;
	std::cout << "Your average duration on each question is: " << test_avg_time << " ms" << std::endl;
	std::cout << "Your previous average was: " << prev_avg << std::endl;
	std::cout << "You have made an improvement of: " << ((prev_avg - test_avg_time)/1000) << " ms"<< std::endl;

	std::cout << "\n\nPress Enter to exit" << std::endl;
	std::cin.get();
}

Test::m_stats Test::square_set() {
	
	std::system("cls");
	unsigned short questions_asked = 0;
	double score = 0;
	unsigned int total_time_taken = 0;

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand = rand() % 101;
		unsigned short correct_answer = operand * operand;
		unsigned short response = 0;
		
		std::cout << "What is the square of: " << operand << " ?" << std::endl;
		
		auto start = std::chrono::high_resolution_clock::now();
		std::cin >> response;
		auto end = std::chrono::high_resolution_clock::now();
		
		auto duration = std::chrono::duration_cast<duration_type>(end - start);
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

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand = rand() % 101;		// Operand itself is the correct answer
		unsigned short response;

		std::cout << "What is the square root of: " << operand * operand << " ?" << std::endl;
		
		auto start = std::chrono::high_resolution_clock::now();
		std::cin >> response;
		auto end = std::chrono::high_resolution_clock::now();
		
		auto duration = std::chrono::duration_cast<duration_type>(end - start);
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

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand = rand() % 10001;
		unsigned short correct_answer = std::pow(operand, 0.5);
		unsigned short response;

		std::cout << "What is the square root approx. of: " << operand << " ? (Round to nearest floor, ignore decimals)" << std::endl;
		
		auto start = std::chrono::high_resolution_clock::now();
		std::cin >> response;
		auto end = std::chrono::high_resolution_clock::now();
		
		auto duration = std::chrono::duration_cast<duration_type>(end - start);
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

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));

		unsigned short operand_1 = rand() % 101;
		unsigned short operand_2 = rand() % 101;
		unsigned short correct_answer = operand_1 * operand_2;
		unsigned short response;

		std::cout << "What is the result of this expression: " << operand_1 << " x " << operand_2 <<" ?"<< std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		std::cin >> response;
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<duration_type>(end - start);
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

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand_1 = rand() % 10000;
		unsigned short operand_2 = rand() % 10000;
		unsigned int correct_answer = operand_1 + operand_2;
		unsigned int response;

		std::cout << "What is the result of this expression: " << operand_1 << " + " << operand_2 <<" ?"<< std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		std::cin >> response;
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<duration_type>(end - start);
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

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand_1 = rand() % 10000;
		unsigned short operand_2 = (rand() % 20 + 2);	// See note at the end of this method
		unsigned int correct_answer = operand_1 / operand_2;
		unsigned int response;

		std::cout << "What is the result of this expression: " << operand_1 << " / " << operand_2 << " ? (Round to nearest floor, ignore decimals)" << std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		std::cin >> response;
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<duration_type>(end - start);
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

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand_1 = rand() % 10000;
		unsigned short operand_2 = rand() % 10000;
		unsigned int correct_answer = operand_1 - operand_2;
		unsigned int response;

		std::cout << "What is the result of this expression: " << operand_1 << " - " << operand_2 << " ?" << std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		std::cin >> response;
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<duration_type>(end - start);
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

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand = rand() % 11;
		unsigned short correct_answer = operand * operand * operand;
		unsigned short response = 0;

		std::cout << "What is the cube of: " << operand << " ?" << std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		std::cin >> response;
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<duration_type>(end - start);
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

	while (questions_asked < section_length) {

		srand((unsigned int)time(NULL));
		unsigned short operand = rand() % 11;		// Operand itself is the correct answer
		unsigned short response;

		std::cout << "What is the cube root of: " << operand * operand * operand << " ?" << std::endl;

		auto start = std::chrono::high_resolution_clock::now();
		std::cin >> response;
		auto end = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<duration_type>(end - start);
		total_time_taken += duration.count();

		if (response == operand)
			score += 2;
		questions_asked++;
	}

	unsigned int avg_time_taken = total_time_taken / questions_asked;
	return { questions_asked, score, avg_time_taken };
}

int main() {
	
	Test newTest;

	std::cout << "To start the test, press Enter" << std::endl;
	std::cin.get();

	auto start = std::chrono::high_resolution_clock::now();
	newTest.start();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::minutes>(end - start);
	int time = duration.count();

	std::cout << "Press enter to see your result" << std::endl;
	std::cin.get();

	std::cout << "\n\nTest Duration: " << time << " minutes." << std::endl;
	newTest.report();
	

	return 0;
}

/*
// A C++ Program to demonstrate the 
// four file hacks every C/C++ must know 

// Note that we are assuming that the files 
// are present in the same file as the program 
// before doing the below four hacks 
#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h> 

// A Function to get the file size 
unsigned long long int fileSize(const char* filename)
{
	// Open the file 
	FILE* fh = fopen(filename, "rb");
	fseek(fh, 0, SEEK_END);
	unsigned long long int size = ftell(fh);
	fclose(fh);

	return (size);
}

// A Function to check if the file exists or not 
bool fileExists(const char* fname)
{
	FILE* file;
	if (file = fopen(fname, "r"))
	{
		fclose(file);
		return (true);
	}
	return (false);
}

// Driver Program to test above functions 
int main()
{
	printf("%llu Bytes\n", fileSize("Passwords.txt"));
	printf("%llu Bytes\n", fileSize("Notes.docx"));

	if (fileExists("OldData.txt") == true)
		printf("The File exists\n");
	else
		printf("The File doen't exist\n");

	rename("Videos", "English_Videos");
	rename("Songs", "English_Songs");

	remove("OldData.txt");
	remove("Notes.docx");

	if (fileExists("OldData.txt") == true)
		printf("The File exists\n");
	else
		printf("The File doesn't exist\n");

	return 0;
}


File Handling with C++ using fstream class object 
To write the Content in File 
Then to read the content of file
#include <iostream> 

fstream header file for ifstream, ofstream,
   fstream classes
#include <fstream> 

using namespace std;

// Driver Code 
int main()
{
	// Creation of fstream class object 
	fstream fio;

	string line;

	// by default openmode = ios::in|ios::out mode 
	// Automatically overwrites the content of file, To append 
	// the content, open in ios:app 
	// fio.open("sample.txt", ios::in|ios::out|ios::app) 
	// ios::trunc mode delete all conetent before open 
	fio.open("sample.txt", ios::trunc | ios::out | ios::in);

	// Execute a loop If file successfully Opened 
	while (fio) {

		// Read a Line from standard input 
		getline(cin, line);

		// Press -1 to exit 
		if (line == "-1")
			break;

		// Write line in file 
		fio << line << endl;
	}

	// Execute a loop untill EOF (End of File) 
	// point read pointer at beginning of file 
	fio.seekg(0, ios::beg);

	while (fio) {

		// Read a Line from File 
		getline(fio, line);

		// Print line in Console 
		cout << line << endl;
	}

	// Close the file 
	fio.close();

	return 0;
}




*/