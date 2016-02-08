/**
 *
 * @file    ANNClassifier.h
 * @brief   Definition of ANNClassifier
 *
 */

#ifndef  __ANNCLASSIFIER_INC__
#define  __ANNCLASSIFIER_INC__

#include "Classifier.h"

#include <opencv2/opencv.hpp>
#include <opencv2/ml/ml.hpp>

namespace emogen {

  /**
   * @class   ANNClassifier
   *
   * @brief   Classifier specialization using ANN.
   *
   * @details
   *
   */
  class ANNClassifier : public Classifier {

    public:

      /**
       *  @brief          Create a linear C ANN classifier.
       *
       *  @param[in]      C_factor  The algorithm C factor
       *  @param[in]      max_iteration Maximum number of iteration termination criteria
       *  @param[in]      error_margin Minimum error termination criteria
       *
       */
      ANNClassifier();
      ~ANNClassifier();

      bool save(std::string outfile);

      bool load(std::string infile);

      float predict(cv::Mat& features);

    protected:

      bool doTraining(cv::Mat train_data, cv::Mat train_labels);

    private:

      /// The opencv implementation of ANN
      CvANN_MLP ANN;
      cv::Mat layers;
      CvTermCriteria criteria;
      /// The ANN parameters
      CvANN_MLP_TrainParams params;

  };

}


#endif   /* ----- #ifndef __ANNCLASSIFIER_INC__  ----- */
