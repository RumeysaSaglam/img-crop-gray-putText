#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{

  Mat image;
  image = imread("00001.jpg", IMREAD_COLOR);

  if (!image.data)
  {
    cout << "Could not open or find the image" << endl;
    return -1;
  }
  imshow("image", image);
   waitKey(0);
  int offset_x = 0;
  int offset_y = 0;

  Rect roi;
  roi.x = offset_x;
  roi.y = offset_y;

  roi.width = image.size().width / 2;
  roi.height = image.size().height;

  Mat crop = image(roi);
  cv::imwrite("cropped.png", crop);

  imshow("crop", crop);
  waitKey(0);

  Mat gray_image;
  cvtColor(crop, gray_image, CV_BGR2GRAY);

  putText(gray_image, "Open CV", cvPoint(30, 30), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255, 255), 3);

  imshow("gray", gray_image);

  waitKey(0);

  return 0;
}