/**
 * VideoCapture.cpp
 *
 */

#include "VideoCapture.h"

namespace emogen{

  VideoCapture::VideoCapture(int deviceID, bool grayScale): ACapture(grayScale) {
    cap.open(deviceID);
  }
      
  VideoCapture::VideoCapture(string infile, bool grayScale): ACapture(grayScale) {
    cap.open(infile.c_str());
  }
  
  VideoCapture::~VideoCapture() {
    cap.release();
  }
  
  bool VideoCapture::isReady() {
    if (cap.isOpened()) {
      return true;
    } else {
      return true;
    }
  }

  bool VideoCapture::extractFrame(Mat& frm) {
    return cap.read(frm);
  }

}


