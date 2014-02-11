
#ifndef TLD_H_
#define TLD_H_

#include <opencv/cv.h>

#include "MedianFlowTracker.h"
#include "DetectorCascade.h"

namespace tld
{

class TLD
{
    void storeCurrentData();
    void fuseHypotheses();
    void learn();
    void initialLearning();
public:
    bool trackerEnabled;
    bool detectorEnabled;
    bool learningEnabled;
    bool alternating;

    MedianFlowTracker *medianFlowTracker;
    DetectorCascade *detectorCascade;
    NNClassifier *nnClassifier;
    bool valid;
    bool wasValid;
    cv::Mat prevImg;
    cv::Mat currImg;
    cv::Rect *prevBB;
    cv::Rect *currBB;
    float currConf;
    bool learning;

    TLD();
    virtual ~TLD();
    void release();
    void selectObject(const cv::Mat &img, cv::Rect *bb);
    void processImage(const cv::Mat &img);
    void writeToFile(const char *path);
    void readFromFile(const char *path);
};

} /* namespace tld */
#endif /* TLD_H_ */
