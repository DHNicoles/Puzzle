#include "puzzle.h"
#include "struct_info.h"
#include <iostream>
Puzzle::Puzzle()
{
	font_path_[std::string("Î¢ÈíÑÅºÚ")] = "C:\\Windows\\Fonts\\msyh.TTF";
}

Puzzle::~Puzzle()
{
}

cv::Mat Puzzle::Make(StructInfo& structinfo)
{

	unsigned int bottom_color = structinfo.GetBottomColor();
	uchar R, G, B;
	int2RGB(bottom_color, R, G, B);
	cv::Mat& src = structinfo.GetSrc();
	std::vector<Text>& textVec = structinfo.GetText();
	std::vector<ProductImage>& productImageVec = structinfo.GetProductImage();
	cv::Mat result = src.clone();
	DrawBackground(result, B, G, R);
	DrawProductImage(result, productImageVec);
	DrawText(result, textVec);
	cv::imshow("result", result);
	cv::waitKey(0);

	return result;
}

void Puzzle::DrawProductImage(cv::Mat& src, std::vector<ProductImage>& productImageVec)
{
	for (size_t i = 0; i < productImageVec.size(); ++i)
	{
		//attributes
		std::string url = productImageVec[i].url_;
		bool white_bottom = productImageVec[i].white_bottom_;
		bool background_remove = productImageVec[i].background_remove_;
		int size = productImageVec[i].size_;
		cv::Point top_left = productImageVec[i].top_left_;
		double angle = productImageVec[i].angle_;
		cv::Mat img = cv::imread(url.c_str(), cv::IMREAD_UNCHANGED);
		//resize
		resize(img, img, cv::Size(size, size));
		//imshow("img", img);
		//rotate
		img = rotateImage(img, angle);
		//imshow("rotate", img);
		//cv::waitKey(0);
		double r = 1.414 * sin(2 * PI * (45 + angle) / 360) - 1;
		int diff = r * size / 2;
		top_left.y -= diff;
		cv::Mat roi = src(cv::Rect(top_left, cv::Point(top_left.x + size, top_left.y + size)));
		cv::cvtColor(img, img, cv::COLOR_BGR2BGRA);
		white2Black(img);
		roi += img;
		/*for (int i = 0; i < roi.rows; i++)
		{
			for (int j = 0; j < roi.cols; j++)
			{
				cv::Vec4b& v = img.at<cv::Vec4b>(cv::Point(0, 0));
				if (v[0] || v[1] || v[2])
				{
					roi.at<cv::Vec4b>(i, j)[0] = v[0];
					roi.at<cv::Vec4b>(i, j)[1] = v[1];
					roi.at<cv::Vec4b>(i, j)[2] = v[2];
				}
			}
		}*/

	}
	black2White(src);
}

void Puzzle::DrawBackground(cv::Mat& src, uchar B, uchar G, uchar R)
{
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			cv::Vec4b& v = src.at<cv::Vec4b>(i, j);
			double alpha = v[3];
			if (abs(alpha - 0.0) < 0.01)
			{
				v[0] = B;
				v[1] = G;
				v[2] = R;
			}
			else
			{
				v[0] = 0;
				v[1] = 0;
				v[2] = 0;
			}
		}
	}
}

void Puzzle::DrawText(cv::Mat& src, std::vector<Text>& textVec)
{
	for (size_t i = 0; i < textVec.size(); ++i)
	{
		//attributes
		std::string show_text = textVec[i].show_text_;
		unsigned int color = textVec[i].color_;

		int size = textVec[i].size_;
		std::string fonts = textVec[i].fonts_;
		cv::Point top_left = textVec[i].top_left_;
		uchar R, G, B;
		int2RGB(color, R, G, B);
		//fonts
		if (font_path_.count(fonts))
		{
			CvxText ct(font_path_[fonts].c_str());
			float p = 1;
			ct.setFont(NULL, &cvScalar(size, 0, 0.1, 0), NULL, &p);   // Í¸Ã÷´¦Àí

			ct.putText(&IplImage(src), show_text.c_str(), cvPoint(top_left.x, top_left.y + size), CV_RGB(R, G, B));
		}
	}
}

