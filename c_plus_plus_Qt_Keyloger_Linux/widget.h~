//Author: Shiv Kumar
//Licence: Open Source

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer> //for timer in signal-slot
#include <QProcess>
#include <QEvent> // to catch event from keyboard and mouse



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
 QTimer *timer = new QTimer(this);

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
 void closeEvent(QCloseEvent *event); //capture close 'X' event when close dialog
private:
    Ui::Widget *ui;
private slots:
    void catkeybrd();

};

#endif // WIDGET_H
