/**
 *
 * @file    SVMEmoDetector.h
 * @brief   Defines SVMEmoDetector
 *
 */

#ifndef  __ANNEMODETECTOR_INC__
#define  __ANNEMODETECTOR_INC__

#include "EmoDetector.h"

namespace emogen {

  /**
   * @class    SVMEmoDetector
   *
   * @brief   EmoDetector specialization using SVMClassifier
   *
   */
  class ANNEmoDetector : public EmoDetector {
    public:

      /**
       *  @brief          Creates an SVMEmoDetector with svm parameters and
       *                  empty classifiers.
       *
       *  @param[in]      C_factor  The algorithm C factor
       *  @param[in]      max_iteration Maximum number of iteration termination criteria
       *  @param[in]      error_margin Minimum error termination criteria
       *
       *  @see SVMClassifier
       */
      ANNEmoDetector();

      /**
       *  @brief          Creates an SVMEmoDetector with svm parameters and
       *                  classifiers.
       *
       *  @param[in]      C_factor  The algorithm C factor
       *  @param[in]      max_iteration Maximum number of iteration termination criteria
       *  @param[in]      error_margin Minimum error termination criteria
       *  @param[in]      detmap_ext Mapping between emotions and classifier.
       *
       *  @see SVMClassifier
       */
      ANNEmoDetector(std::map<std::string, std::pair<vector<Emotion>, Classifier*> >
          detmap_ext);

      std::pair<Emotion, float> predict(cv::Mat& frame);

    protected:

      Classifier* createClassifier();

    private:


  }; /* -----  end of class SVMEmoDetector  ----- */

}


#endif   /* ----- #ifndef __SVMEMODETECTOR_INC__  ----- */
