/**
 *
 * @file    EmogenGui.cpp
 * @brief   Implementation of EmogenGUI
 *
 */

#include "EmogenGui.h"

namespace emogen{

  EmogenGui::EmogenGui(FacePreProcessor* fp, EmoDetector* detect, int fps) :
    EmogenGui::AGui(new WebcamCapture(true), fp, detect, fps, "Emogen!") {

  }

  EmogenGui::EmogenGui(ACapture* capture, FacePreProcessor* fp, EmoDetector*
      detect, int fps) : EmogenGui::AGui(capture, fp, detect, fps,
        "Emogen!") {
   }

  EmogenGui::~EmogenGui() {
    //delete this->capture;
  }

  bool EmogenGui::newFrame(Mat& frame, pair<Emotion, float> prediction) {
    Mat copy;
    frame.copyTo(copy);
    stringstream ss, ss2;
    ss << "Emotion: " << emotionStrings(prediction.first);
    ss2 << "Score: " << prediction.second;
    string osd = ss.str();
    string osd2 = ss2.str();

    cv::putText(frame, osd.c_str(), Point(20,60), FONT_HERSHEY_SIMPLEX, 0.7, Scalar::all(255));
    cv::putText(frame, osd2.c_str(), Point(20,100), FONT_HERSHEY_SIMPLEX, 0.7, Scalar::all(255));
    // QT only
    //displayOverlay(mainWinTitle.c_str(), osd.c_str(), 2000);
    return true;
  }


}


