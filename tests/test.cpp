#include "pch.h"
#include "../Practic1/Practic1.cpp"
#include "../Practic1/Image.h"
#include "../Practic1/Image.cpp"

TEST(image, cols) {
    image im1 (1,1);
    EXPECT_THROW(im1.cols(), int);
}
TEST(image, fullness) {
    image im1(0,0);
    im1.random_Image(0, 0);
  EXPECT_EQ(0,im1.fullness() );
}

//TEST(image, Get) {
//    	image im2 p(2);
    //	p[0].x = 1;
    //	p[0].y = 1;
    //	p[1].x = 25;
    //	p[1].y = 33;
    //	EXPECT_EQ(40, p.GetLenght());
    //}
//


//double fullness() { // коэффициент заполненности
//    int fullness = 0;
//    for (int i = 0; i < M; i++) {
//        for (int j = 0; j < N; j++) {
//            if (im_values[i * M + j]) fullness++;
//        }
//    }
//    return (double)fullness / (double)(M * N);
//}
// 
// 
// 
// 
//TEST(Polyline, Constructor) {
//	Polyline p;
//	EXPECT_THROW(p.GetLenght(), const char*);
//}
//
//TEST(Polyline, Constructor_Param) {
//	Polyline p(2);
//	p[0].x = 1;
//	p[0].y = 1;
//	p[1].x = 25;
//	p[1].y = 33;
//	EXPECT_EQ(40, p.GetLenght());
//}
//
//TEST(Polyline, Constructor_Copy) {
//	Polyline p(2);
//	p[0].x = 1;
//	p[0].y = 1;
//	p[1].x = 25;
//	p[1].y = 33;
//	Polyline p_1(p);
//	EXPECT_EQ(40, p_1.GetLenght());
//}
//TEST(Polyline, Method_GetLenght) {
//	Polyline p(2);
//	p[0].x = 1;
//	p[0].y = 1;
//	p[1].x = 25;
//	p[1].y = 33;
//	EXPECT_EQ(40, p.GetLenght());
//}
//
//TEST(Polyline, Method_AddToHead) {
//	Polyline p(1);
//	p[0].x = 25;
//	p[0].y = 33;
//	Point a;
//	a.x = 1;
//	a.y = 1;
//	p.AddToHead(a);
//	EXPECT_EQ(40, p.GetLenght());
//}
//
//TEST(Polyline, Method_AddToEnd) {
//	Polyline p(1);
//	p[0].x = 1;
//	p[0].y = 1;
//	Point a;
//	a.x = 25;
//	a.y = 33;
//	p.AddToEnd(a);
//	EXPECT_EQ(40, p.GetLenght());
//}
//
//TEST(Polyline, Operator_Square_Brackets) {
//	Polyline p(1);
//	p[0].x = 1;
//	p[0].y = 0;
//	EXPECT_EQ(1, p[0].x);
//	EXPECT_EQ(0, p[0].y);
//}
//
//TEST(Polyline, Operator_Square_Brackets_const) {
//	Polyline p;
//	EXPECT_THROW(p[10], const char*);
//}
//
//TEST(Polyline, Operator_Plus) {
//	Polyline p(1), p_1(1);
//	p[0].x = 1;
//	p[0].y = 1;
//	p_1[0].x = 25;
//	p_1[0].y = 33;
//	p = p + p_1;
//	EXPECT_EQ(40, p.GetLenght());
//}
//
//TEST(Polyline, Operator_Equal) {
//	Polyline p, p_1;
//	EXPECT_EQ(1, p == p_1);
//}
//
//TEST(Polyline, Operator_Inequality) {
//	Polyline p, p_1;
//	EXPECT_EQ(0, p != p_1);
//}
//
//TEST(Polyline, Operator_Assignment) {
//	Polyline p(2), p_1(1);
//	p[0].x = 1;
//	p[0].y = 1;
//	p_1[0].x = 25;
//	p_1[0].y = 33;
//	p[1].x = p_1[0].x;
//	p[1].y = p_1[0].y;
//	EXPECT_EQ(40, p.GetLenght());
//}