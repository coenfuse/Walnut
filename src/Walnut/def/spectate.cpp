#include "..\Walnut.h"
#include <thread>
#include <chrono>
#include <iostream>

static bool spectate_mode_active = true;

void spectate_loop() {

	while (spectate_mode_active) {

		std::system("cls");
		std::cout << "Press enter to exit spectate mode" << std::endl;
		std::cout << "Players online: " << Walnut::active_players << std::endl;
		std::cout << "Live global average percentage: " << Walnut::global_percentage << " %" << std::endl;
		std::cout << "Live global average score: " << Walnut::global_average_score << std::endl;
		std::cout << "Live global average duration: " << double(Walnut::global_average_duration / 1000) << " seconds" << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
}

void Walnut::spectate() {
	int input;
	std::thread spectator(spectate_loop);
	std::cin.get();
	spectate_mode_active = false;
	spectator.join();
}