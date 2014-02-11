
#ifndef BBPREDICT_H_
#define BBPREDICT_H_

#include <opencv/cv.h>

/**
 * @param bb0   The previous BoundingBox.
 * @param pt0   Feature points in the previous BoundingBox.
 * @param pt1   Feature points of the new BoundingBox.
 * @param nPts  Length of pt0/pt1.
 * @param bb1   Output, contains predicted BoundingBox.
 * @param shift Output, contains relative scale change.
 *              1 == no scalechange, experience: if shift == 0
 *              BoundingBox moved completely out of picture
 *              (not validated)
 */
int predictbb(float *bb0, CvPoint2D32f *pt0, CvPoint2D32f *pt1, int nPts,
              float *bb1, float *shift);

#endif /* BBPREDICT_H_ */
