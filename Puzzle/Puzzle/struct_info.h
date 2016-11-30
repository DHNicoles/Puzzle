#ifndef __STRUCT_INFO_H__
#define __STRUCT_INFO_H__
#include "utils.h"

#include "product_image.h"
#include "text.h"
class StructInfo
{
public:
	StructInfo(){};
	~StructInfo(){};
	void OnInit(){};
	void OnDestory(){};
	unsigned int& GetBottomColor(){ return bottom_color_; }
	cv::Mat& GetSrc(){ return src_; }
	std::vector<ProductImage>& GetProductImage(){ return product_image_vec_; }
	std::vector<Text>& GetText(){ return text_vec_; }

private:
	unsigned int bottom_color_;
	cv::Mat src_;
	std::vector<ProductImage> product_image_vec_;
	std::vector<Text> text_vec_;
};
#endif // __STRUCT_INFO_H__