#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include "writeCsv.h"

using namespace std;
using namespace cv;

int main (int argc, char **arv)
{
    Mat im = imread("./data/test.png");
    string input = "yes";
    vector<Rect2d> rects;
    vector<double> myV;
    vector<string> header = {"x", "y", "width", "height"};
    string path;
    int j = 0;
    int oX = im.cols;
    int oY = im.rows;

    while(input == "yes"){
      // figure out how to clear memory on each iteration
      // issue with new window always being behind others

      if(j > 0){
        rectangle(im, rects[j-1], Scalar(255,0,0), 1.5, 8, 0);
      }

      bool fromCenter = false;
      Rect2d r = selectROI("Image", im, fromCenter);

      if(r.x != 0 & r.y != 0 & r.height != 0 & r.width != 0){
        rects.push_back(r);
      }

      cvDestroyWindow("Image");

      input = "init";

      while(input != "yes" & input != "no"){
        cout << "Do you want to select another ROI? (yes|no): ";
        cin >> input;
      }

      j++;
    }

    // edit these to fit with invariance idea
    for(int i = 0; i < rects.size(); i++){
      myV.push_back(rects[i].x/oX);
      myV.push_back(rects[i].y/oY);
      myV.push_back(rects[i].width/oX);
      myV.push_back(rects[i].height/oY);
    }

    writeCsv_h::writeCsv(path = "./results/results.csv", myV, header);

    // this could then later be imported for use with tesseract
    // clear memory of myV at the end and delete all data
    im.release();
    waitKey(0);
    return 0;
}
