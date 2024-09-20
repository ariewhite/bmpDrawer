#include "gtest/gtest.h"
#include "../headers/BMPFile.hpp"


TEST(BMPFileTest, OpenValidBMPFile) {
	BMPFile bmp;
	ASSERT_NO_THROW(bmp.openBMP("assets\\test1.bmp"));
}

TEST(BMPFileTest, OpenInvalidBMPFile) {
	BMPFile bmp;
	ASSERT_THROW(bmp.openBMP("empty.bmp"), std::runtime_error);
}

TEST(BNPFileTest, CheckImageSize)
{
	BMPFile bmp;
	bmp.openBMP("assets\\test1.bmp");
	EXPECT_EQ(bmp.getW(), 16);
	EXPECT_EQ(bmp.getH(), 16);
	EXPECT_EQ(bmp.getOff(), 54);
}