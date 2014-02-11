#include "Main.h"
#include "Config.h"
#include "ImAcq.h"
#include "Gui.h"
#include "TLDUtil.h"
#include "Trajectory.h"

using namespace tld;
using namespace cv;
using namespace std;



void Main::doWork()
{   Rect bb;
    Trajectory trajectory;
    //this uses standart opencv images
    img = imAcqGetImg(imAcq);
    cvFlip(img, img, 0);
    Mat grey(img->height, img->width, CV_8UC1);
    cvtColor(cv::Mat(img), grey, CV_BGR2GRAY);

    int context =0;
    tld->detectorCascade->imgWidth = grey.cols;
    tld->detectorCascade->imgHeight = grey.rows;
    tld->detectorCascade->imgWidthStep = grey.step;

    cout << " we are here "<< endl;

    // this part defines the initialization of a square in the middle.
    int W_onethird= floor(tld->detectorCascade->imgWidth/3);
    int H_onethird= floor(tld->detectorCascade->imgHeight/3);

    if(initialBB == NULL)
    {
        initialBB = new int[4];
    }

    initialBB[0] = floor(tld->detectorCascade->imgWidth/2) - W_onethird ;
    initialBB[1] = floor(tld->detectorCascade->imgHeight/2) - H_onethird ;
    initialBB[2] = W_onethird*2;
    initialBB[3] = H_onethird*2;

    if(showTrajectory)
    {
            trajectory.init(trajectoryLength);
    }

    cout << " we are here "<< endl;
  cout << printResults << endl;

    if(selectManually)
    {

        CvRect box;

        if(getBBFromUser(img, box, gui) == PROGRAM_EXIT)
        {
            return;
        }

        if(initialBB == NULL)
        {
            initialBB = new int[4];
        }

        initialBB[0] = box.x;
        initialBB[1] = box.y;
        initialBB[2] = box.width;
        initialBB[3] = box.height;
    }

    FILE *resultsFile = NULL;





    bool reuseFrameOnce = false;
    bool skipProcessingOnce = false;

    if(loadModel && modelPath != NULL)
    {
        tld->readFromFile(modelPath);
        reuseFrameOnce = true;
    }

    else if(initialBB != NULL)
    {
        bb = tldArrayToRect(initialBB);

        //printf("Starting at %d %d %d %d\n", bb.x, bb.y, bb.width, bb.height);
        tld->selectObject(grey, &bb);
        skipProcessingOnce = true;
        reuseFrameOnce = true;
    }

    int a=0,b=0,c=0,d=0;
    //cout<< Main.printResults <<endl;
    // aca esta EL PROBLEMA
    resultsFile = fopen(printResults,"w");

    fclose(resultsFile);


   int m_startFrame = 0;//3786;
   imAcq->currentFrame = 0;
    while(imAcqHasMoreFrames(imAcq))
    {
        if (m_startFrame >= 0){
           cout << m_startFrame<< endl;
            double tic = cvGetTickCount();

        if(!reuseFrameOnce)
        {
            img = imAcqGetImg(imAcq);
            cvFlip(img, img, 0);
            if(img == NULL)
            {
                printf("current image is NULL, assuming end of input.\n");
                break;
            }

            cvtColor(cv::Mat(img), grey, CV_BGR2GRAY);
        }

        if(!skipProcessingOnce)
        {
            tld->processImage(img);
        }
        else
        {
            skipProcessingOnce = false;
        }




// added
        if(tld->currBB != NULL){
        a=tld->currBB->x;
        b=tld->currBB->y;
        c=tld->currBB->width;
        d=tld->currBB->height;
        }
// added

       //if(printResults != NULL)
       //{
           resultsFile = fopen(printResults,"a+");
            if(tld->currBB != NULL && imAcq->ChunkFrameCount>0){
               fprintf(resultsFile, "%d %.2d %.2d %.2d %.2d %f %d %d %d\n", imAcq->currentFrame - 1, tld->currBB->x, tld->currBB->y, tld->currBB->width, tld->currBB->height, tld->currConf, context, imAcq->ChunkFrameCount,1 );
               //fflush(resultsFile);
               //char buffer [50];
               //sprintf(buffer, "%d %.2d %.2d %.2d %.2d %f\n", imAcq->currentFrame - 1, tld->currBB->x, tld->currBB->y, tld->currBB->width, tld->currBB->height, tld->currConf);
               //resultsFile<<buffer;
               //printf("%d %.2d %.2d %.2d %.2d %f\n", imAcq->currentFrame - 1, tld->currBB->x, tld->currBB->y, tld->currBB->width, tld->currBB->height, tld->currConf);
               //cout << printResults << endl;
              }

            else{
                //remove -- fprintf(resultsFile, "%d %.2d %.2d %.2d %.2d %f %d %d\n", imAcq->currentFrame - 1,a,b,c,d,0.000,context,imAcq->ChunkFrameCount);
                //fflush(resultsFile);
                fprintf(resultsFile,"%d NaN NaN NaN NaN NaN 0\n", imAcq->currentFrame - 1);
                }
            fclose(resultsFile);
        //}

        cout << " we are here "<< endl;

        cout << "Frame:"<<imAcq->currentFrame - 1 <<endl;
        double toc = (cvGetTickCount() - tic) / cvGetTickFrequency();

        toc = toc/1000000;

        float fps = 1 / toc;

        int confident = (tld->currConf >= threshold) ? 1 : 0;

        if(showOutput || saveDir != NULL)
        {
            char string[128];

            char learningString[10] = "";

            if(tld->learning)
            {
                strcpy(learningString, "Learning");
            }

            sprintf(string, "#%d,Posterior %.2f; fps: %.2f, #numwindows:%d, %s", imAcq->currentFrame - 1, tld->currConf, fps, tld->detectorCascade->numWindows, learningString);
            CvScalar green = CV_RGB(0,255, 0);
            CvScalar blue = CV_RGB(0, 0, 255);
            CvScalar black = CV_RGB(0, 0, 0);
            CvScalar white = CV_RGB(255, 255, 255);

            if(tld->currBB != NULL)
            {
                CvScalar rectangleColor = (confident) ? white : black;
                cvRectangle(img, tld->currBB->tl(), tld->currBB->br(), rectangleColor, 4, 4, 0);

               // if(showTrajectory)
               // {
                        CvPoint center = cvPoint(tld->currBB->x+tld->currBB->width/2, tld->currBB->y+tld->currBB->height/2);
                        cvLine(img, cvPoint(center.x-2, center.y-2), cvPoint(center.x+2, center.y+2), rectangleColor, 2);
                        cvLine(img, cvPoint(center.x-2, center.y+2), cvPoint(center.x+2, center.y-2), rectangleColor, 2);
                        trajectory.addPoint(center, rectangleColor);
               // }

                //print important stuff
                CvFont font;
                cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX,1.3 , 1.3, 3, 3, 3);
                //cvRectangle(img, cvPoint(tld->currBB->x, tld->currBB->y), cvPoint(tld->currBB->x+W_onethird*2,tld->currBB->y+50), black, CV_FILLED, 8, 0);
                //cvLine(img, cvPoint(tld->currBB->x, tld->currBB->y),cvPoint(initialBB[0]+W_onethird,initialBB[1]+W_onethird),black,1.5,8);
                char string[128];
                if (imAcq->ChunkFrameCount<2){
                sprintf(string, "TAC");
                cvPutText(img, string, cvPoint(tld->currBB->x+20, tld->currBB->y+20), &font, white);
                }
                if (imAcq->ChunkFrameCount>2){
                sprintf(string, "ENGAGED ATTENTION ", context,imAcq->ChunkFrameCount);
                cvPutText(img, string, cvPoint(tld->currBB->x+20, tld->currBB->y+20), &font, green);
                sprintf(string, "%d - Lenght: %d", context,imAcq->ChunkFrameCount);
                cvPutText(img, string, cvPoint(tld->currBB->x+20, tld->currBB->y+55), &font, green);

                }
                imAcq->ChunkFrameCount++;

            }else{
                if(showTrajectory)
                                        {
                                                //trajectory.addPoint(cvPoint(-1, -1), cvScalar(-1, -1, -1));
                                                //trajectory.drawTrajectory(img);
                                        }
            //cout << "object lost"<<endl;
            //reset the contect count number
            imAcq->ChunkFrameCount=0;
            // increase the context number.
            context++;

            //restart a new object
               //1. clear old
               tld->release();
               // 2. reuse The initialBB
               bb = tldArrayToRect(initialBB);
               //printf("Starting at %d %d %d %d\n", bb.x, bb.y, bb.width, bb.height);
               tld->selectObject(grey, &bb);
               skipProcessingOnce = true;
               reuseFrameOnce = true;
              }

            if(showForeground)
            {

                for(size_t i = 0; i < tld->detectorCascade->detectionResult->fgList->size(); i++)
                {
                    Rect r = tld->detectorCascade->detectionResult->fgList->at(i);
                    cvRectangle(img, r.tl(), r.br(), white, 1);
                }

            }

            if(showOutput)
            {
                gui->showImage(img);
                char key = gui->getKey();

                if(key == 'q') break;

                if(key == 'b')
                {

                    ForegroundDetector *fg = tld->detectorCascade->foregroundDetector;

                    if(fg->bgImg.empty())
                    {
                        fg->bgImg = grey.clone();
                    }
                    else
                    {
                        fg->bgImg.release();
                    }
                }

                if(key == 'c')
                {
                    //clear everything
                    tld->release();
                }

                if(key == 'l')
                {
                    tld->learningEnabled = !tld->learningEnabled;
                    printf("LearningEnabled: %d\n", tld->learningEnabled);
                }

                if(key == 'a')
                {
                    tld->alternating = !tld->alternating;
                    printf("alternating: %d\n", tld->alternating);
                }

                if(key == 'e')
                {
                    tld->writeToFile(modelExportFile);
                }

                if(key == 'i')
                {
                    tld->readFromFile(modelPath);
                }

                if(key == 'r'){
                    CvRect box;
                    if(getBBFromUser(img, box, gui) == PROGRAM_EXIT){
                     break;
                     }
                    Rect r = Rect(box);
                    tld->selectObject(grey, &r);
                }

                if(key == 's'){
                }

            }

            if(saveDir != NULL)
            {
                char fileName[256];
                sprintf(fileName,"%s/%.5d.png",saveDir,imAcq->currentFrame-1);
                cvSaveImage(fileName, img);
            }
        }

        if(!reuseFrameOnce){
            cvReleaseImage(&img);}
         else{
            reuseFrameOnce = false;}
        }else{
        cout << m_startFrame<< endl;
            m_startFrame ++;}
        }

    if(exportModelAfterRun)
    {
        tld->writeToFile(modelExportFile);
    }
}
