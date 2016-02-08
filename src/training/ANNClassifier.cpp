/**
 *
 * @file    ANNClassifier.cpp
 *
 * @brief   Implementation of ANNClassifier
 *
 */

#include "ANNClassifier.h"

using std::vector;
using std::pair;
using std::string;
using std::cerr;
using std::endl;

namespace emogen {

  ANNClassifier::ANNClassifier() {

    // Set up ANN's parameters

    this->layers = cv::Mat(3, 1, CV_32SC1);
    this->layers.row(0) = cv::Scalar(256);
    this->layers.row(1) = cv::Scalar(10);
    this->layers.row(2) = cv::Scalar(8); //change the numbers here.

    
    this->criteria.max_iter = 100;
    this->criteria.epsilon = 0.00001f;
    this->criteria.type = CV_TERMCRIT_ITER | CV_TERMCRIT_EPS;

    this->params.train_method = CvANN_MLP_TrainParams::BACKPROP;
    this->params.bp_dw_scale = 0.05f;
    this->params.bp_moment_scale = 0.05f;
    this->params.term_crit = criteria;

    this->ANN.create(layers);
  }

  ANNClassifier::~ANNClassifier() {

  }

  bool ANNClassifier::doTraining(cv::Mat train_data, cv::Mat train_labels) {
    return this->ANN.train(train_data, train_labels, cv::Mat(), cv::Mat(), this->params);
  }

  bool ANNClassifier::save(std::string outfile) {
    this->ANN.save(outfile.c_str());
    return true;
  }

  bool ANNClassifier::load(std::string infile) {
    this->ANN.load(infile.c_str());
    return ANN.get_layer_count() > 0;
  }

  float ANNClassifier::predict(cv::Mat& features) {
    cv::Mat response(1, 1, CV_32FC1);
    this->ANN.predict(features, response);
    return float(response.at<uchar>(0));
  }

}
