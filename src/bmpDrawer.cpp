#include "bmpDrawer.hpp"

BmpDrawer::BmpDrawer()
{
	cout << "Default constuctor called\n";
}

BmpDrawer::~BmpDrawer()
{
	cout << "Destructor called\n";
}

void BmpDrawer::openBMP(const string& fileName)
{
	if (!std::filesystem::exists(fileName)) {
		std::cerr << "File not found: " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	fstream file(fileName, std:: ios::in | std::ios::binary);
	if (!file){
		cerr << "Error opening file\n";
		file.close();
		exit(EXIT_FAILURE);
	}

	file.read(reinterpret_cast<char*> (&fileHeader), sizeof(fileHeader));

	if (fileHeader.bfType != 0x4D42){
		cout << "It s not BMP file!";
	}

	file.read(reinterpret_cast<char*>(&fileInfo), sizeof(fileInfo));

	cout << "File size: "	 << fileHeader.bfSize	 << endl;
	cout << "Width: "		 << fileInfo.biWidth	 << endl;
	cout << "Height: "		 << fileInfo.biHeight	 << endl;
	cout << "Bit Per Metr: " << fileInfo.biBitCount	 << endl;
	cout << "Image size: "	 << fileInfo.biSizeImage << endl;


	file.close();
}

void BmpDrawer::displayBMP()
{
}

void BmpDrawer::closeBMP()
{
}
