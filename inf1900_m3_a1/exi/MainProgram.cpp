#include "MainProgram.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

void verify_directory(std::string path);
void show_folders_tree(std::string path);

int main() 
{
	auto path = fs::current_path().generic_string();
	std::string band_path = path + "/Gravadora/BandaX";

	//Creating directories
	fs::create_directories(path + "/Gravadora/BandaX/Album_1");	
	verify_directory(path + "/Gravadora/BandaX/Album_1");

	fs::create_directory("Gravadora/BandaX/Album_2");
	verify_directory("Gravadora/BandaX/Album_2");

	fs::create_directory(path + "/Album_3");
	verify_directory(path + "/Album_3");

	//Copying Album_3 to the right place
	fs::copy(path + "/Album_3", path + "/Gravadora/BandaX/Album_3");
	verify_directory(path + "/Gravadora/BandaX/Album_3");
	std::cout << "\nDirectory copied from: " + path + "/Album_3" + " \nto " + path + "/Gravadora/BandaX/Album_3\n\n";

	//Removing old Album_3
	fs::remove(path + "/Album_3");
	std::cout << "\nRemoved original /Album_3 directory\n";

	fs::rename(band_path + "/Album_1", band_path + "/Album_1 - The truth about the lies");
	std::cout << "\nRenamed directory from: /Album_1\n to /Album_1 - The truth about the lies\n\n";

	show_folders_tree(path + "/Gravadora");

	return 0;
}

void verify_directory(std::string path)
{
	if (fs::exists(path))
		std::cout << "\nPath: " + path + " created succefully!\n";
	else
		std::cout << "\nPath " + path + "does not exist!\n";
}

void show_folders_tree(std::string path)
{
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ path })
	{
		std::cout << dir_entry;

		if (fs::is_empty(dir_entry))
			std::cout << " - This directory is empty!\n";
		else
			std::cout << '\n';
	}
		
}