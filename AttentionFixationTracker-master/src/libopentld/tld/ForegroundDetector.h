
#ifndef FOREGROUNDDETECTOR_H_
#define FOREGROUNDDETECTOR_H_

#include <vector>

#include <opencv/cv.h>

#include "DetectionResult.h"

namespace tld
{

class ForegroundDetector
{
public:
    int fgThreshold;
    int minBlobSize;
    cv::Mat bgImg;
    DetectionResult *detectionResult;

    ForegroundDetector();
    virtual ~ForegroundDetector();
    void release();
    void nextIteration(const cv::Mat &img);
    bool isActive();
};

} /* namespace tld */
#endif /* FOREGROUNDDETECTOR_H_ */
