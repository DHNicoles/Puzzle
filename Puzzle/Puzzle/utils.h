/************************************************************************/
/* tools                                                                     */
/************************************************************************/

#include <cv.h>
#include <highgui.h>
#include <string>
#include <vector>
#include <imgproc/imgproc.hpp>
#include "CvvText.h"
#include <map>
#include <math.h>
#define PI 3.1415926
class StructInfo;

void parseOrDie(int argc, char* argv[], StructInfo& structinfo);
void int2RGB(int color, uchar& R, uchar & G, uchar& B);
cv::Mat rotateImage(const cv::Mat &src, double angle);
void white2Black(cv::Mat& src);
void black2White(cv::Mat& src);

