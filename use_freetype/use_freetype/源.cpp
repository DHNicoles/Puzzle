#include "CvvText.h"

using namespace cv;
int main(int argc, char *argv[])
{
	// ����CvxApplication����

	// ��һ��Ӱ��

	IplImage *img = cvLoadImage("e://1.jpg", 1);

	// �������

	{
		// "wqy-zenhei.ttf"Ϊ��Ȫ��������

		CvxText text("C:\\Windows\\Fonts\\FZSTK.TTF");

		const char *msg = "����������֣�";

		float p = 0.5;
		text.setFont(NULL, &cvScalar(35,0,0.1,0), NULL, &p);   // ͸������

		text.putText(img, msg, cvPoint(100, 100), CV_RGB(0, 0, 0));
	}
	// ���崰�ڣ�����ʾӰ��
	imshow("img", Mat(img));
	waitKey(0);

	// ������Ϣѭ��
}
