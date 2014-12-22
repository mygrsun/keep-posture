#ifndef DETECTTHREAD_H
#define DETECTTHREAD_H
#include <QThread>














///////////////////////

#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <cxcore.h>
#include <iostream>
#ifdef _EiC
#define WIN32
#endif

//const char* cascade_name ="haarcascade_frontalface_alt.xml";
////////////////////////


#include "detectheadresult.h"







class DetectThread: public QThread
{
    Q_OBJECT

public:
    DetectThread();
    int getStandardY() const;
    void setStandardY(int value);

    void beginMonitor();
    Detectheadresult detect_and_draw(IplImage *img);
    IplImage *takephoto();
    int getIntervalTime() const;
    void setIntervalTime(int value);

    bool getRunFlag() const;
    void setRunFlag(bool value);

protected:
    void run();
private:
    int intervalTime;
    int standardY;
    CvMemStorage* storage;
    CvHaarClassifierCascade* cascade;
    bool runFlag;
    CvCapture* pCapture;
signals:
    void getResult(Detectheadresult result);
};

#endif // DETECTTHREAD_H
