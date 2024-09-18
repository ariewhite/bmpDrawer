#include "BMPFile.hpp"

BMPFile::BMPFile()
{
	cout << "Default constuctor called\n";
}

BMPFile::~BMPFile()
{
	cout << "Destructor called\n";
}

void BMPFile::openBMP(const string& fileName)
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
		throw runtime_error("It s not BMP file!");
	}

	file.read(reinterpret_cast<char*>(&fileInfo), sizeof(fileInfo));

	cout << "File size: "	 << fileHeader.bfSize	 << endl;
	cout << "Width: "		 << fileInfo.biWidth	 << endl;
	cout << "Height: "		 << fileInfo.biHeight	 << endl;
	cout << "Bit Per Metr: " << fileInfo.biBitCount	 << endl;
	cout << "Image size: "	 << fileInfo.biSizeImage << endl;
	cout << "Offset: "		 << fileHeader.bfOffBits << endl;

	file.seekg(fileHeader.bfOffBits, std::ios::beg);
	rowSize_ = (fileInfo.biWidth * fileInfo.biBitCount + 31) / 32 * 4;

	data.resize(rowSize_ * fileInfo.biHeight);

	file.read(reinterpret_cast<char*>(data.data()), data.size());
	//std::copy(data1.begin(), data1.end(), data.begin());

	file.close();
}

void BMPFile::displayBMP() const
{
	for (int i = fileInfo.biHeight - 1; i >= 0; --i)
	{
		for (int x = 0; x < fileInfo.biWidth; ++x)
		{
			int pxlOffset = i * rowSize_ + x * (fileInfo.biBitCount / 8);
			//cout << pxlOffset << " ";
			uint8_t blue = data[pxlOffset];
			uint8_t green = data[pxlOffset + 1];
			uint8_t red = data[pxlOffset + 2];

			if (red == 0 && green == 0 && blue == 0)
			{
				cout << "0";
			}
			else if (red == 255 && green == 255 && blue == 255) {
				cout << ".";
			}
			else {
				cout << "?";
			}
		}
		cout << endl;
	}
}

void BMPFile::closeBMP()
{
}
