#include "BMPFile.hpp"

BMPFile::BMPFile() : rowSize_(0)
{	
}

BMPFile::~BMPFile()
{
	//cout << "Destructor called\n";
	closeBMP();
}
/**
* Метод "открытия" BMP файла
* Сохраняет данные картинки для дальнейшей отрисовки.
*/
void BMPFile::openBMP(const string& fileName)
{
	if (!filesystem::exists(fileName)) {							 
		throw runtime_error("File not exist!");
	}

	fstream file(fileName, ios::in | ios::binary);		   // явно указываем, что хотим "читать файл как бинарный"

	if (!file.is_open()){
		file.close();
		throw runtime_error("Can not open file!");
	}

	file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));    // по хорошему заменить на char* 
																		    // или вычленять данные из потока по очередно

	if (fileHeader.bfType != 0x4D42){									    // стандартное начало файла для bitmap 42 4D
		throw runtime_error("It s not BMP file!");
	}

	file.read(reinterpret_cast<char*>(&fileInfo), sizeof(fileInfo));
	/*
	cout << "File size: "	 << fileHeader.bfSize	 << endl;
	cout << "Width: "		 << fileInfo.biWidth	 << endl;
	cout << "Height: "		 << fileInfo.biHeight	 << endl;
	cout << "Bit Per Metr: " << fileInfo.biBitCount	 << endl;
	cout << "Image size: "	 << fileInfo.biSizeImage << endl;
	cout << "Offset: "		 << fileHeader.bfOffBits << endl;

	*/
	
	file.seekg(fileHeader.bfOffBits, ios::beg);							 // меняет позицию в потоке 
	rowSize_ = (fileInfo.biWidth * fileInfo.biBitCount + 31) / 32 * 4;   // подсчитываем длину страйда (округление до 32 бита)

	data.resize(rowSize_ * fileInfo.biHeight);							 // выделяем память для данных

	file.read(reinterpret_cast<char*>(data.data()), data.size());		 // записываем данные в буфер

	file.close();
}
/**
* Метод отрисовки BMP файла
* за исходные данные берет данные из структур класса
*/

void BMPFile::displayBMP() const
{
	for (int i = fileInfo.biHeight - 1; i >= 0; --i)
	{
		for (int x = 0; x < fileInfo.biWidth; ++x)
		{
			int pxlOffset = i * rowSize_ + x * (fileInfo.biBitCount / 8);
			
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
/**
* Метод чистки памяти
* ()
*/
void BMPFile::closeBMP()
{
}

uint32_t BMPFile::getW() const
{
	return fileInfo.biWidth;
}

uint32_t BMPFile::getH() const
{
	return fileInfo.biHeight;
}

uint32_t BMPFile::getOff() const
{
	return fileHeader.bfOffBits;
}

