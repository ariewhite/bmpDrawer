// bmpPicturePrinter.cpp : Defines the entry point for the application.
//
#include "bmpPicturePrinter.hpp"


using namespace std;

int main()
{
	std::string path = "C:\\Users\\ariew\\project\\bmpPicturePrinter\\assets\\picture1.bmp";

	BmpDrawer b;
	b.openBMP(path);
	
	return 0;
}
