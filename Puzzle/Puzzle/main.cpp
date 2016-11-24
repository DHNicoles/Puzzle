#include <iostream>
#include "puzzle.h"
#include "struct_info.h"

int main(int argc, char* argv[])
{
	//cv::Mat img = cv::imread("E:\\workspace\\git\\Puzzle\\Puzzle\\resource//¶þ²ã±³¾°Í¼.png");
	//cv::imshow("img", img);
	//cv::waitKey(0);
	StructInfo structinfo;
	Puzzle pzl;
	parseOrDie(argc, argv, structinfo);
	cv::Mat dst = pzl.Make(structinfo);
	return 0;
}