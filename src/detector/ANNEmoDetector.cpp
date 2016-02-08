/**
 *
 * @file    SVMEmoDetector.cpp
 * @brief   Implementation of SVMEmoDetector
 *
 * @details
 *
 */

#include "ANNEmoDetector.h"
#include "ANNClassifier.h"

namespace emogen {

  ANNEmoDetector::ANNEmoDetector() : EmoDetector() {

  }

  ANNEmoDetector::ANNEmoDetector(std::map<std::string, std::pair<vector<Emotion>, Classifier*> >
      detmap_ext) : EmoDetector(detmap_ext) {
  }


  Classifier* ANNEmoDetector::createClassifier() {
    return new ANNClassifier();
  }

  std::pair<Emotion, float> ANNEmoDetector::predict(cv::Mat& frame) {
    return EmoDetector::predictVotingOneVsAllExt(frame);
  }
}
