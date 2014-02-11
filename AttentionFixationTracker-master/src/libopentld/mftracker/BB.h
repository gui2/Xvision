
#ifndef BB_H_
#define BB_H_

/**
 * @param bb        Bounding box represented through 2 points(x1,y1,x2,y2)
 * @param numM      Number of points in height direction.
 * @param numN      Number of points in width direction.
 * @param margin    margin (in pixel)
 * @param pts       Contains the calculated points in the form (x1, y1, x2, y2).
 *                  Size of the array must be numM * numN * 2.
 */
int getFilledBBPoints(float *bb, int numM, int numN, int margin, float *pts);

#endif /* BB_H_ */
