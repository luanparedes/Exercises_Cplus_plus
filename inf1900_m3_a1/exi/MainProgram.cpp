#include "MainProgram.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main() {
	auto path = fs::current_path().generic_string();

	//Creating directories
	fs::create_directories(path + "/Gravadora/BandaX/Album_1");
	fs::create_directory("Gravadora/BandaX/Album_2");
	fs::create_directory(path + "/Album_3");

	//Copying Album_3 to the right place
	fs::copy(path + "/Album_3", path + "/Gravadora/BandaX/Album_3");

	//Removing old Album_3
	fs::remove(path + "/Album_3");

	return 0;
}