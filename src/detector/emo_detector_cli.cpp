/**
 *
 * @file    emo_detector_cli.cpp
 * @brief
 *
 * @details
 *
 */

#include "SVMEmoDetector.h"
#include "ANNEmoDetector.h"
#include "matrix_io.h"
#include "FacePreProcessor.h"

#include "TrainingParameters.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <iostream>

using namespace cv;
using namespace emogen;

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::pair;

int main(int argc, const char *argv[]) {
  if (argc < 9) {
		//banner();
		//help();
		cerr << "ERR: missing parameters" << endl;
		return -3;
	}
	string infile; // = string(argv[1]);
	string method(argv[1]);
	string config(argv[2]);
	string config_e(argv[3]);

  cv::Size size(0,0);
  int nwidths, nlambdas, nthetas;
  size.width = abs(atoi(argv[4]));
	size.height = abs(atoi(argv[5]));
  nwidths = abs(atoi(argv[6]));
  nlambdas= abs(atoi(argv[7]));
  nthetas = abs(atoi(argv[8]));
  vector<string> classifier_paths;

  if (argc >= 10) {
    // Read boost XML paths
    for (int i = 9; i < argc; i++) {
      string clpath(argv[i]);
      classifier_paths.push_back(string(argv[i]));
    }
  } else {
    cerr << "ERR: you must specify some classifiers" << endl;
    return -2;
  }

  FacePreProcessor* preprocessor;
  EmoDetector* emodetector;

	try {

    if (config_e == "none") {
      preprocessor = new FacePreProcessor(config, size.width, size.height,
          nwidths, nlambdas, nthetas);
    } else {
      preprocessor = new FacePreProcessor(config, config_e, size.width,
          size.height, nwidths, nlambdas, nthetas);
    }

    if (method == "svm") {
      emodetector = new SVMEmoDetector(kCfactor, kMaxIteration, kErrorMargin);
    }
    else{
      emodetector = new ANNEmoDetector();
    }
    emodetector->init(classifier_paths);

    cout << "Insert the image file path: " << endl;
    while(std::getline(std::cin, infile)) {
      try {
        cout << "Processing '" << infile << "'" << endl;
		    Mat img = matrix_io_load(infile);
        Mat features;
        bool canPreprocess = preprocessor->preprocess(img, features);
        if (!canPreprocess) {
          cerr << "ERR: Cannot preprocess this image '" << infile << "'" << endl;
          continue;
        }
        pair<Emotion,float> prediction = emodetector->predict(features);
        cout << "Emotion predicted: " << emotionStrings(prediction.first) << " with score " << prediction.second << endl;
        cout << "Insert the image file path: " << endl;
      } catch (int ee) {
        cerr << "ERR: Something wrong with '" << infile << "' (" << ee << ")" << endl;
      }
    }

    delete emodetector;
    delete preprocessor;
	} catch (int e) {
		cerr << "ERR: Exception #" << e << endl;
		return -e;
	}

  return 0;
}
