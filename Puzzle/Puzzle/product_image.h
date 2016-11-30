/************************************************************************/
/*                                                                      */
/************************************************************************/

#ifndef __PRODUCT_IMAGE_H__
#define __PRODUCT_IMAGE_H__
#include "utils.h"

class ProductImage
{
public:
	ProductImage(std::string url, bool white_bottom, bool background_remove, int size, cv::Point top_left, double angle) :
		url_(url), white_bottom_(white_bottom), background_remove_(background_remove), size_(size), top_left_(top_left), angle_(angle)
	{}
	~ProductImage(){};
public:
	//attributes
	std::string url_;
	bool white_bottom_;
	bool background_remove_;
	int size_;
	cv::Point top_left_;
	double angle_;
};
#endif//__PRODUCT_IMAGE_H__