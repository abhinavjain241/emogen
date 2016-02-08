
import argparse
import datasetConfigParser as dcp
import os
import sys

def launch_gui(dsfolder, config, mode, eye_detection, do_prints=True):

  if mode == 'svm':
    class_dir = os.path.join(dsfolder, config['CLASSIFIER_SVM_FOLDER'])
    mode_s = 'svm'
  else:
    class_dir = os.path.join(dsfolder, config['CLASSIFIER_ANN_FOLDER'])
    mode_s = 'ann'

  execut = config['GUI_TOOL']

  classificators = []
  for f in os.listdir(class_dir):
    abs_f = os.path.join(class_dir, f)
    if os.path.isfile(abs_f):
      classificators.append(abs_f)

  args = [execut, config['FACECROP_FACE_DETECTOR_CFG']]
  if eye_detection:
    args.append(config['FACECROP_EYE_DETECTOR_CFG'])
  else:
    args.append('none')
  args += [config['SIZE']['width'], config['SIZE']['height'],
      config['GABOR_NWIDTHS'], config['GABOR_NLAMBDAS'],
      config['GABOR_NTHETAS'], mode_s] + classificators

  print "Launching emogen gui! Smile :)"
  os.execv(execut, args);


if __name__ == "__main__":

  dsFolder = "my_dataset"
  cfg = "example_dataset.cfg"
  mode = "svm"

  try:
    config = {}
    config = dcp.parse_ini_config(cfg)
    launch_gui(dsFolder, config, mode, True)
  except Exception as e:
    print "ERR: something wrong (%s)" % str(e)
    sys.exit(1)
