
#ifndef LK_H_
#define LK_H_

#include <opencv/cv.h>

/**
 * Need before start of trackLK and at the end of the program for cleanup.
 */
void initImgs();
int trackLK(IplImage *imgI, IplImage *imgJ, float ptsI[], int nPtsI,
            float ptsJ[], int nPtsJ, int level, float *fbOut, float *nccOut,
            char *statusOut);

#endif /* LK_H_ */
