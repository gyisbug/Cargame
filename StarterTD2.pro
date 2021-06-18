# configuration Qt
QT       += core gui opengl widgets
TEMPLATE  = app
CONFIG += c++17

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib\

    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -lGL -lGLU
}

INCLUDEPATH +=C:\opencv-4.5.1\build\install\include\opencv2\
            C:\opencv-4.5.1\build\install\include

LIBS += -LC:\opencv-4.5.1\build\install\x64\mingw\lib\
    -lopencv_core451 \
    -lopencv_highgui451 \
    -lopencv_imgproc451 \
    -lopencv_imgcodecs451 \
    -lopencv_videoio451 \
    -lopencv_features2d451 \
    -lopencv_objdetect451 \
    -lopencv_calib3d451


# nom de l'exe genere
TARGET 	  = Projet

# fichiers sources/headers/ressources
SOURCES += main.cpp myglwidget.cpp \
    Car.cpp \
    Detectimage.cpp \
    Ground.cpp \
    Guitime.cpp \
    bidon.cpp \
    connect.cpp
HEADERS += myglwidget.h \
    Car.h \
    Detectimage.h \
    Ground.h \
    Guitime.h \
    bidon.h \
    connect.h

RESOURCES += \
    res/textures.qrc

DISTFILES +=

