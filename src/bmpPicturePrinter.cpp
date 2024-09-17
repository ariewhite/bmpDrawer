﻿// bmpPicturePrinter.cpp : Defines the entry point for the application.
//
#include "bmpPicturePrinter.hpp"


using namespace std;

int main(int argc, char** argv)
{	
	std::setlocale(LC_ALL, "rus");
	

	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <path_to_bmp_file>\n"
			<< "Example: bmpDrawer.exe C:\\User\\Image\\picture.bmp\n";
		return 1;
	}
	std::string path = argv[1];

	for (size_t i = 0; i < path.length(); ++i)
	{
		if (path[i] == '\\')
		{
			path.insert(i, "\\");
			i++;
		}
	}
	
	BmpDrawer b;
	b.openBMP(path);
	
	return 0;
}
