/**
 *
 * @file    AGui.h
 * @brief   Defines the class AGui
 *
 */

#ifndef AGUI_H
#define AGUI_H

#include <iostream>
#include <string>
#include <sstream>
#include <opencv2/opencv.hpp>

#include "ACapture.h"
#include "EmoDetector.h"
#include "FacePreProcessor.h"

using std::stringstream;
using std::string;
using std::pair;

using namespace emogen;

namespace emogen {

  /**
   * @class    AGui
   *
   * @brief   Generic GUI
   *
   * @details
   *
   */
  class AGui {

    public:

      /**
       *  @brief          Creates an AGui
       *
       *  @param[in]      capt  A capture instance
       *  @param[in]      fp    The face preprocessor to use
       *  @param[in]      detect  An EmoDetector instance
       *  @param[in]      fps  Desired frame per second
       *  @param[in]      title The title of the GUI
       *
       */
      AGui(ACapture* capt, FacePreProcessor* fp, EmoDetector* detect, int fps, string title="AGui: Main Emogen GUI");

      /**
       *  @brief    Starts the gui
       *
       *  @return   False if something wrong.
       *
       */
      bool run();

    protected:

      /// Face preprocessor
      FacePreProcessor* preprocessor;
      /// Emotion detector
      EmoDetector* detector;
      /// Capture instance
      ACapture* capture;
      /// Title for the main window
      string mainWinTitle;
      /// Desired frames per second
      int fps;

      /**
       *  @brief          Initialize the windows
       *
       *  @return         Returns true if the initialization succeded
       *
       */
      virtual bool init();

      /**
       *  @brief          Produce the next frame
       *
       *  @return         False if there is no next frame
       *
       */
      virtual bool nextFrame();

      /**
       *  @brief          A new frame is available
       *
       *  @param[in,out]      frame The new frame that will be drawn after returing
       *  @param[in]      prediction The predicted emotion
       *
       *  @return         False if something wrong
       *
       */
      virtual bool newFrame(Mat& frame, pair<Emotion, float> prediction) = 0;

  };
}

#endif

