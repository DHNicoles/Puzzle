#include "CvvText.h"

using namespace cv;
int main(int argc, char *argv[])
{
	// 定义CvxApplication对象

	// 打开一个影象

	IplImage *img = cvLoadImage("e://1.jpg", 1);

	// 输出汉字

	{
		// "wqy-zenhei.ttf"为文泉驿正黑体

		CvxText text("C:\\Windows\\Fonts\\FZSTK.TTF");

		const char *msg = "在中输出汉字！";

		float p = 0.5;
		text.setFont(NULL, &cvScalar(35,0,0.1,0), NULL, &p);   // 透明处理

		text.putText(img, msg, cvPoint(100, 100), CV_RGB(0, 0, 0));
	}
	// 定义窗口，并显示影象
	imshow("img", Mat(img));
	waitKey(0);

	// 进入消息循环
}
