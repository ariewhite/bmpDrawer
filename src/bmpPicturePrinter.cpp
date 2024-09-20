// bmpPicturePrinter.cpp : Defines the entry point for the application.
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

	for (size_t i = 0; i < path.length(); ++i)   // экранируем \ 
	{
		if (path[i] == '\\')
		{
			path.insert(i, "\\");
			i++;
		}
	}

	cout << "File path - " << path << endl;
	
	BMPFile b;
	b.openBMP(path);
	b.displayBMP();
	
	return 0;
}
