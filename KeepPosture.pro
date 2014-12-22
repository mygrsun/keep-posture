#-------------------------------------------------
#
# Project created by QtCreator 2014-04-24T14:15:23
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KeepPosture
TEMPLATE = app


SOURCES += main.cpp\
        posturedialog.cpp \
    detectheadresult.cpp \
    detectthread.cpp \
    notice1dialog.cpp \
    startdetect.cpp \
    advisedialog.cpp

HEADERS  += posturedialog.h \
    detectheadresult.h \
    detectthread.h \
    notice1dialog.h \
    startdetect.h \
    advisedialog.h

FORMS    += posturedialog.ui \
    notice1dialog.ui \
    advisedialog.ui






INCLUDEPATH += D:/opencvblueversion/opencv/build/include
INCLUDEPATH += D:/opencvblueversion/opencv/build/include/opencv/
INCLUDEPATH += D:/opencvblueversion/opencv/build/include/opencv2/

CONFIG(debug,debug|release) {
LIBS += -LD:\opencvblueversion\opencv\build\x86\vc9\lib\
    -lopencv_core243d \
    -lopencv_highgui243d \
    -lopencv_imgproc243d \
    -lopencv_features2d243d \
    -lopencv_calib3d243d  \
    -lopencv_objdetect243d
} else {
LIBS += -LD:\opencvblueversion\opencv\build\x86\vc9\lib\
    -lopencv_core243 \
    -lopencv_highgui243 \
    -lopencv_imgproc243 \
    -lopencv_features2d243 \
    -lopencv_calib3d243\
-lopencv_objdetect243
}

RESOURCES += \
    res.qrc \
    src.qrc
