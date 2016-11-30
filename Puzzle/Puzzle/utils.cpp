#include "utils.h"
#include "struct_info.h"
#include "product_image.h"
#include "text.h"
void parseOrDie(int argc, char* argv[], StructInfo& structinfo)
{
	structinfo.GetBottomColor() = 0xf42f42;
	structinfo.GetSrc() = cv::imread("..//resource//¶þ²ã±³¾°Í¼.png", cv::IMREAD_UNCHANGED);
	structinfo.GetProductImage().push_back(
		ProductImage(
		"..//resource//Í¼1.jpg",
		true,
		false,
		75,
		cv::Point(212, 136),
		0.0
		)
		);
	structinfo.GetProductImage().push_back(
		ProductImage(
		"..//resource//Í¼2.jpg",
		false,
		true,
		99,
		cv::Point(312, 128),
		25.0
		)
		);
	structinfo.GetProductImage().push_back(
		ProductImage(
		"..//resource//Í¼3.jpg",
		false,
		true,
		99,
		cv::Point(388, 93),
		25.0
		)
		);
	structinfo.GetProductImage().push_back(
		ProductImage(
		"..//resource//Í¼4.jpg",
		false,
		true,
		99,
		cv::Point(469, 55),
		25.0
		)
		);
	structinfo.GetText().push_back(
		Text(
		"×¨ÊôÄãµÄ",
		0xc9ffc5,
		38,
		"Î¢ÈíÑÅºÚ",
		cv::Point(85, 53),
		0.0
		)
		);
	structinfo.GetText().push_back(
		Text(
		"Ë½ÈË¶¨ÖÆ",
		0x0078ff,
		36,
		"Î¢ÈíÑÅºÚ",
		cv::Point(41, 114),
		0.0
		)
		);
}

void int2RGB(int color, uchar& R, uchar & G, uchar& B)
{
	R = ((color & 0xff0000) >> 16);
	G = ((color & 0x00ff00) >> 8);
	B = ((color & 0x0000ff) >> 0);
}

cv::Mat rotateImage(const cv::Mat &src, double angle)
{
	double t = angle;
	angle = 2 * PI * angle / 360;
	cv::Point2f anchor_pt(src.cols / 2.0f, src.rows / 2.0f);
	double a = (1 + tan(angle)*tan(angle));
	double b = ((1 + tan(angle))*((1 + tan(angle))));

	double ratio =  sqrt(a / b);
	std::cout << ratio << "," << a << " ," << b << std::endl;
	cv::Mat rot_mat = cv::getRotationMatrix2D(anchor_pt, t, ratio);
	cv::Mat dst;
	cv::warpAffine(src, dst, rot_mat, src.size(), 1, 0, cv::Scalar(255, 255, 255));
	//resize(dst, dst, cv::Size(dst.size().width * (1 / ratio), dst.size().height * (1 / ratio)));
	return dst;
}

void white2Black(cv::Mat& src)
{
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			cv::Vec4b& v = src.at<cv::Vec4b>(i, j);
			if (v[0] >= 245 && v[1] >= 245 && v[2] >= 245)
			{
				v[0] = 0;
				v[1] = 0;
				v[2] = 0;
			}
		}
	}
}
void black2White(cv::Mat& src)
{
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			cv::Vec4b& v = src.at<cv::Vec4b>(i, j);
			if (v[0] == 0 && v[1] == 0 && v[2] == 0)
			{
				v[0] = 255;
				v[1] = 255;
				v[2] = 255;
			}
		}
	}
}