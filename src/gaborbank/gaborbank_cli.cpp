/**
 *
 * @file    gaborbank_cli.cpp
 * @brief   CLI interface for filtering an image using Gabor's Filters.
 *
 * @details 
 *
 */

#include <iostream>
#include <sstream>
#include <string>

#include "GaborBank.h"
#include "matrix_io.h"

using namespace emogen;

using std::cout;
using std::cerr;
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
  cout << "   gaborbank_cli <imageWidth> <imageHeight> <nwidths> <nlambdas> <nthetas> <inputImage> <outputFile>" << endl;
  cout << "Parameters:" << endl;
  cout << "   <imageWidth>    - Width of the image, the input image will be scaled" << endl;
  cout << "   <imageHeight>   - Height of the image, the input image will be scaled" << endl;
  cout << "   <nwidths>       - " << endl;
  cout << "   <nlambdas>      - " << endl;
  cout << "   <nthetas>       - " << endl;
  cout << "   <inputImage>    - Input image" << endl;
  cout << "   <outputFile>    - Output file  where to store filtered images" << endl;
  cout << endl;
}

void banner() {
   cout << "GaborBank Utility:" << endl;
   cout << "     Filter with a bank of Gabor filters with different " <<  endl;
   cout << "     orientations and frequencies. (Gabor magnitude)" << endl;
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
int main(int argc, const char* argv[]){
  if (argc < 5) {
    banner();
    help();
    cerr << "ERR: missing parameters" << endl;
    return -3;
  }
  cv::Size size;
  size.width = abs(atoi(argv[1]));
  size.height = abs(atoi(argv[2]));
  double nwidths = (atof(argv[3]));
  double nlambdas = (atof(argv[4]));
  double nthetas = (atof(argv[5]));
  string infile(argv[6]);
  string outfile(argv[7]);

  Mat img = matrix_io_load(infile);
  GaborBank bank;
  bank.fillGaborBank((double) nwidths, (double) nlambdas, (double) nthetas);
  Mat dest = bank.filterImage(img, size);
  matrix_io_save(dest, outfile);
  dest.release();
}
