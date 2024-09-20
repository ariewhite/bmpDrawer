#include "gtest/gtest.h"
#include "../headers/BMPFile.hpp"


TEST(BMPFileTest, OpenValidBMPFile) {
	BMPFile bmp;
	ASSERT_NO_THROW(bmp.openBMP("C:\\Users\\ariew\\project\\bmpPicturePrinter\\assets\\cpp.bmp"));
}

TEST(BNPFileTest, CheckImageData)
{
	BMPFile bmp;
	bmp.openBMP("C:\\Users\\ariew\\project\\bmpPicturePrinter\\assets\\test1.bmp");
	EXPECT_EQ(bmp.getW(), 16);
	EXPECT_EQ(bmp.getH(), 16);
	EXPECT_EQ(bmp.getOff(), 54);
}