#include "detectthread.h"
#include <QDebug>
#include <Windows.h>
DetectThread::DetectThread()
{
    this->intervalTime=30;
    char* cascade_name = "./cofg/haarcascade_frontalface_alt2.xml";
    cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name, 0, 0, 0 );
    this->runFlag=false;
    pCapture = cvCreateCameraCapture(-1);
}

void DetectThread::run()
{
    while(this->runFlag){
        this->beginMonitor();
        Sleep(this->intervalTime);
    }

}
bool DetectThread::getRunFlag() const
{
    return runFlag;
}

void DetectThread::setRunFlag(bool value)
{
    runFlag = value;
}

int DetectThread::getIntervalTime() const
{
    return intervalTime;
}

void DetectThread::setIntervalTime(int value)
{
    intervalTime = value;
}

int DetectThread::getStandardY() const
{
    return standardY;
}

void DetectThread::setStandardY(int value)
{
    standardY = value;
}







Detectheadresult DetectThread::detect_and_draw(IplImage* img )
{



    storage = cvCreateMemStorage(0);

    double scale=1.2;
    static CvScalar colors[] = {
        {{0,0,255}},{{0,128,255}},{{0,255,255}},{{0,255,0}},
        {{255,128,0}},{{255,255,0}},{{255,0,0}},{{255,0,255}}
    };//Just some pretty colors to draw with

    //Image Preparation
    //
    IplImage* gray = cvCreateImage(cvSize(img->width,img->height),8,1);
    IplImage* small_img=cvCreateImage(cvSize(cvRound(img->width/scale),cvRound(img->height/scale)),8,1);
    cvCvtColor(img,gray, CV_BGR2GRAY);
    cvResize(gray, small_img, CV_INTER_LINEAR);

    cvEqualizeHist(small_img,small_img); //直方图均衡

    //Detect objects if any
    //
    cvClearMemStorage(storage);
    double t = (double)cvGetTickCount();
    CvSeq* objects = cvHaarDetectObjects(small_img,this->cascade,this->storage,1.1,2,0/*CV_HAAR_DO_CANNY_PRUNING*/,cvSize(30,30));

    t = (double)cvGetTickCount() - t;
    printf( "detection time = %gms    ", t/((double)cvGetTickFrequency()*1000.) );

    //Loop through found objects and draw boxes around them
    qDebug()<<"total:"<<objects->total<<"   ";
    Detectheadresult rest;

    rest.setCount(objects->total);
    for(int i=0;i<(objects? objects->total:0);++i)
    {
        CvRect* r=(CvRect*)cvGetSeqElem(objects,i);
        cvRectangle(img, cvPoint(r->x*scale,r->y*scale), cvPoint((r->x+r->width)*scale,(r->y+r->height)*scale), colors[i%8]);
    }
    for( int i = 0; i < (objects? objects->total : 0); i++ )
    {
        CvRect* r = (CvRect*)cvGetSeqElem( objects, i );
        CvPoint center;
        int radius,radius2;
        center.x = cvRound((r->x + r->width*0.5)*scale);
        center.y = cvRound((r->y + r->height*0.5)*scale);
        rest.setCenterY(center.y);
        qDebug()<<"center:("<<center.x<<","<<center.y<<")";
        radius = cvRound((r->width + r->height)*0.25*scale);
        cvCircle( img, center, radius, colors[i%8], 3, 8, 0 );
        radius2 = 10;
        cvCircle( img, center, radius2, colors[i%8], 3, 8, 0 );
    }

    cvReleaseImage(&gray);
    cvReleaseImage(&small_img);

    return rest;
}









IplImage* DetectThread::takephoto(){
    //声明IplImage指针
    IplImage* pFrame = NULL;



    for(int i=0;i<1;i++)
    {
        pFrame=cvQueryFrame( pCapture );
        if(!pFrame)
            return 0;
    }
//    cvReleaseCapture(&pCapture);
    return pFrame;


}







void DetectThread::beginMonitor(){

    Detectheadresult rest;
    IplImage *img=this->takephoto();
    if(!img){
        return;
    }
    rest=detect_and_draw(img);
    if(rest.getCount()==1){
        emit getResult(rest);
    }


}
