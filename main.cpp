#include "glwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GLWidget w;
    /*
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setAlphaBufferSize(8);
    QSurfaceFormat::setDefaultFormat(format);
    */

    w.resize(640, 480);
    w.show();
    w.startTimer(10);

    return a.exec();
}
