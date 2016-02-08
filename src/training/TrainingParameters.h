/**
 *
 * @file    TrainingParameters.h
 * @brief   Global parameter algorithm
 *
 */

#ifndef  __DETECTIONPARAMETERS_INC__
#define  __DETECTIONPARAMETERS_INC__

#include <opencv2/opencv.hpp>

namespace emogen {

  /// SVM C factor parameter
  const double kCfactor = 0.5;
  /// SVM max interation termination criteria
  const int kMaxIteration = 1000000;
  /// SVM error margin termination criteria
  const double kErrorMargin = 1e-6;

}


#endif   /* ----- #ifndef __DETECTIONPARAMETERS_INC__  ----- */
