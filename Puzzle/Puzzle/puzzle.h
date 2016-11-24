/************************************************************************/
/* pazzle main tools
*/
/************************************************************************/
#ifndef __PUZZLE_H__
#define __PUZZLE_H__
#include "utils.h"
class StructInfo;
class ProductImage;
class Text;
class Puzzle
{
public:
	Puzzle();
	~Puzzle();
	cv::Mat Make(StructInfo& structinfo);
	void DrawProductImage(cv::Mat& src, std::vector<ProductImage>& productImageVec);
	void DrawBackground(cv::Mat& src, uchar B, uchar G, uchar R);
	void DrawText(cv::Mat& src, std::vector<Text>& textVec);

private:
	std::map<std::string, std::string> font_path_;
};

#endif//__PUZZLE_H__