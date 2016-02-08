/**
 *
 * @file    train_cli.cpp
 *
 * @brief   CLI interface for training a Classifier
 *
 * @details 
 *
 */

#include "Classifier.h"
#include "SVMClassifier.h"
#include "ANNClassifier.h"
#include "TrainingParameters.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace cv;

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, const char* argv[]) {

  if (argc < 4) {
    //banner();
    //help();
    cerr << "ERR: missing parameters" << endl;
    return 1;
  }
  string method(argv[1]);
  string infile(argv[2]);
  string outfile(argv[3]);

  emogen::Classifier* classifier;
	if (method == "svm") {
    classifier = new emogen::SVMClassifier(emogen::kCfactor,
        emogen::kMaxIteration, emogen::kErrorMargin);
  }
  else {
    classifier = new emogen::ANNClassifier();
  }

  int ret = 0;
  if (!classifier->train(infile)) {
    cerr << "Error training!" << endl;
    ret = 1;
  } else if (!classifier->save(outfile)) {
    cerr << "Error saving!" << endl;
    ret = 1;
  }

  delete classifier;
  return ret;
}
