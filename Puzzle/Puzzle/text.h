/************************************************************************/
/*                                                                      */
/************************************************************************/

#ifndef __TEXT_H__
#define __TEXT_H__

#include "utils.h"

class Text
{
public:
	Text(std::string show_text, unsigned int color, int size, std::string fonts, cv::Point top_left, double angle) :
		show_text_(show_text), color_(color), size_(size), fonts_(fonts), top_left_(top_left), angle_(angle)
	{
	}
	~Text(){};
public:
	//attributes
	std::string show_text_;
	unsigned int color_;
	int size_;
	std::string fonts_;
	cv::Point top_left_;
	double angle_;

};
#endif//__TEXT_H__