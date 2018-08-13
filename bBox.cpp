#include <opencv2/opencv.hpp>
// selectROI is part of tracking API
#include <opencv2/tracking.hpp>

using namespace std;
using namespace cv;

int main (int argc, char **arv)
{
    // Read image
    Mat im = imread("test.png");
     
    // Select ROI
    vector<Rect> rects;
    bool fromCenter = false;
    selectROIs("Image", im, rects, fromCenter);
     
    // Crop image
    Mat imCrop = im(r);
     
    // Display Cropped Image
    imshow("Image", imCrop);
    waitKey(0);
     
    return 0;
}
