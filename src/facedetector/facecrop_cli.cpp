/**
 *
 * @file    facecrop_cli.cpp
 *
 * @brief   CLI utils for face cropping
 *
 * @details
 *
 */

#include <iostream>

#include "FaceDetector.h"
#include "matrix_io.h"

using namespace emogen;

using std::cerr;
using std::cout;
using std::endl;
using std::string;

using cv::Mat;

/**
 *  @brief          Prints the CLI banner
 *
 */
void banner();

/**
 *  @brief          Prints the CLI help
 *
 */
void help();

void help() {
	cout << "Usage:" << endl;
	cout << "   facecrop_cli <FaceConfigFile> [<EyeConfigFile>] <inputImage> <outputImage>" << endl;
	cout << "Parameters:" << endl;
	cout << "   <FaceConfigFile>    - OpenCV cascade classifier configuration file (Haar or LBP)" << endl;
	cout << "   <EyesConfigFile>    - OpenCV cascade classifier configuration file (Haar or LBP)" << endl;
	cout << "   <inputImage>        - Input image" << endl;
	cout << "   <outputImage>       - Output image" << endl;
	cout << endl;
}
void banner(){
 	cout << "FaceCrop Utility:" << endl;
 	cout << "     Crop faces from images" << endl;
}

/**
 *  @brief          Main
 *
 *  @param[in]      argc
 *  @param[in]     argv
 *
 *  @returns  1
 *
 */
int main( int argc, const char* argv[] ){
	if (argc < 4) {
		banner();
		help();
		cerr << "ERR: missing parameters" << endl;
		return -3;
	}
	string config_f(argv[1]);
  string* config_e = NULL;
	int i = 2;

  if (argc == 5) {
    config_e = new string(argv[i++]);
  }
	string infile(argv[i++]);
	string outfile(argv[i++]);

		FaceDetector* detector;
	  if (config_e != NULL) {
      detector = new FaceDetector(config_f, *config_e);
    } else {
      detector = new FaceDetector(config_f);
    }
    delete config_e;
	try {
		Mat img = matrix_io_load(infile);
		Mat cropped;
		if (detector->detect(img, cropped)){
		  matrix_io_save(cropped, outfile); 
    } else {
      //cerr << "ERR: no face found.." << endl;
      return 1;
    }
    delete detector;
	}
	catch (int e) {
		cerr << "ERR: Exception #" << e << endl;
		return -e;
	}
	return 0;
}
