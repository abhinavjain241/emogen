# Emogen Video Debug Gui Tool

find_package(OpenCV COMPONENTS opencv_core opencv_ml opencv_imgproc
  opencv_highgui opencv_objdetect REQUIRED)

# Emogen Webcam Gui Tool
add_executable(emogengui_cli emogengui_cli.cpp 
        ACapture.cpp  VideoCapture.cpp AGui.cpp EmogenGui.cpp
        ../detector/EmoDetector.cpp ../detector/FacePreProcessor.cpp 
        ../detector/SVMEmoDetector.cpp ../detector/ANNEmoDetector.cpp
        ../training/Classifier.cpp ../training/SVMClassifier.cpp 
        ../training/ANNClassifier.cpp
        ../facedetector/FaceDetector.cpp
        ../gaborbank/GaborBank.cpp
        ../utils/string_utils.cpp ../utils/matrix_io.cpp )
target_link_libraries(emogengui_cli ${OpenCV_LIBS} )
INSTALL(TARGETS emogengui_cli DESTINATION ${ASSETDIR} )

