/**
 *
 * @file    emogengui_cli.cpp
 * @brief   Emogen GUI command line interface
 *
 * @details
 *
 */

#include "WebcamCapture.h"
#include "SVMEmoDetector.h"
#include "ANNEmoDetector.h"
#include "matrix_io.h"
#include "EmogenGui.h"
#include "FaceDetector.h"

#include "TrainingParameters.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

/// Width of the faces used during training
const int kWidth = 48;
/// Height of the faces used during training
const int kHeight = 48;
/// N-Widths used during training
const double kNWidths = 2;
/// N-Lambdas used during training
const double kNLambdas = 5;
/// N-Thetas used during training
const double kNThetas = 4;


int main(int argc, const char* argv[]) {
  if (argc < 5) {
		//banner();
		//help();
		cerr << "ERR: missing parameters" << endl;
		return -3;
	}

  // Intializing the face detector
	string faceDetConfig(argv[1]);
	string eyeDetConfig(argv[2]);
  int width = std::atoi(argv[3]);
  int height = std::atoi(argv[4]);
  int nwidths = std::atoi(argv[5]);
  int nlambdas = std::atoi(argv[6]);
  int nthetas = std::atoi(argv[7]);
  FacePreProcessor facepreproc(faceDetConfig, eyeDetConfig, width, height, nwidths, nlambdas, nthetas);

  // Setting the mode
  int i;
	string mode;
  mode = string(argv[8]);

	if (mode != "svm" && mode != "ada") {
    mode = "ann";
    i = 8;
  } else {
    i = 9;
  }

  // Setting the classifiers
  vector<string> cl_paths;
  EmoDetector* emodetector;

  for(; i < argc; i++) {
    cl_paths.push_back(string(argv[i]));
  }

  if (mode == "svm") {
    emodetector = new SVMEmoDetector(kCfactor, kMaxIteration, kErrorMargin);
  } else {
    emodetector = new ANNEmoDetector();
  }
  emodetector->init(cl_paths);

  // Creating and starting the EmogenGUI
  int fps = 120;
	try {
    EmogenGui gui(&facepreproc, emodetector, fps);
    gui.run();
	} catch (int e) {
		cerr << "ERR: Exception #" << e << endl;
		return -e;
	}

  delete emodetector;
  return 0;
}
