#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include "filesystem"
#include "ios"
#include "Windows.h"

//typedef uint16_t WORD;
//typedef uint32_t DWORD;

using namespace std;

class BMPFile {
public:
	BMPFile();
	~BMPFile();

	void openBMP(const string& fileName);
	void displayBMP() const;
	void closeBMP();

private:
	const string filePath_;

#pragma pack(push, 1)
	struct BMPFileHeader
	{
		uint16_t bfType{0x4D42};	 // сигнатура формата
		uint32_t bfSize{0};			 // размер файла
		uint16_t bfReserved1{0};     // "Зануленная" зарезервированная память
		uint16_t bfReserved2{0};     // 
		uint32_t bfOffBits{0};	     // смещение пикселей относительно начала данных структуры
	};

	struct BMPInfo
	{
		uint32_t biSize{0};		     // размер структуры
		int32_t  biWidth{0};		 // ширина растра
		int32_t  biHeight{0};		 // высота растра
		uint16_t biPlanes{1};		 // поле для курсоров и значков
		uint16_t biBitCount{0};		 // кол-во бит на пиксель
		uint32_t biCompression{0};	 // способ хранения пикселей
		uint32_t biSizeImage{0};	 // размер данных в байтах
		int32_t  biXPelsPerMeter{0}; // кол-во пикселей на метр по горизонтали
		int32_t  biYPelsPerMeter{0}; // кол-во пикселей на метр по вертикали
		uint32_t biCirUsed{0};		 // размер таблицы цветов в ячейках
		uint32_t biCirlImportant{0}; // кол-во ячейек от начала табл до последней используемой
	};

	struct BMPColorHeader {
		uint32_t red_mask{ 0x00ff0000 };
		uint32_t green_mask{ 0x0000ff00 };
		uint32_t blue_mask{ 0x000000ff };
		uint32_t alpha_mask{ 0xff000000 };
		uint32_t color_space_type{ 0x73524742 };
		uint32_t unused[16]{ 0 };
	};
	
#pragma pack(pop)

	BMPFileHeader  fileHeader;
	BMPInfo        fileInfo;
	BMPColorHeader colorHeader;

	vector<uint8_t> data;

	int rowSize_;
};
