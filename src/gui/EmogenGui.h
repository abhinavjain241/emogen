/**
 *
 * @file    EmogenGui.h
 * @brief   Definition of EmogenGUI
 *
 */

#ifndef EMOGENGUI_H
#define EMOGENGUI_H


#include "AGui.h"
#include "WebcamCapture.h"

namespace emogen{

  /**
   * @class EmogenGui
   *
   * @brief Gui that detects emotion.
   *
   */
  class EmogenGui : public AGui {

    public:

      /**
       *  @brief          Creates an EmogenGUI with a webcam capture
       *
       *  @param[in]      fp    The face preprocessor to use
       *  @param[in]      detect  An EmoDetector instance
       *  @param[in]      fps  Desired frame per second
       *
       */
      EmogenGui(FacePreProcessor* fp, EmoDetector* detect, int fps);

       /**
        *  @brief          Creates an EmogenGUI with a custom capture
        *
        *  @param[in]      capture    The ACapture to use
        *  @param[in]      fp    The face preprocessor to use
        *  @param[in]      detect  An EmoDetector instance
        *  @param[in]      fps  Desired frame per second
        *
        */
      EmogenGui(ACapture * capture, FacePreProcessor* fp, EmoDetector* detect, int fps);

      ~EmogenGui();

    protected:


      /**
       *  @brief          Prints the prediction over the frame
       *
       *  @param[in,out]      frame The frame filled with the prediction
       *  @param[in]          prediction The prediction to display
       *
       *  @returns Always returns true
       */
      bool newFrame(Mat& frame, pair<Emotion, float> prediction);

    private:

  };

}

#endif /* !EMOGENGUI_H */

