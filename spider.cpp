#include <QIcon>
#include <QPalette>
#include <QPixmap>
#include <QBitmap>
#include <QBrush>
#include <QGuiApplication>
#include <QScreen>
#include <QColorDialog>
#include <QFileDialog>
#include "spider.h"

Spider::Spider(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlag(Qt::CustomizeWindowHint);
    Qt::WindowFlags f = windowFlags();
    f |= Qt::WindowStaysOnTopHint;
  //  f |= Qt::WindowSystemMenuHint; // зачем?
    setWindowFlags(f);
    //Qt::WindowStates s = windowState();
    //s |= Qt::WindowState::WindowMinimized;
    //setWindowState(s);

    QString title = QStringLiteral("Spider");
    setWindowTitle(title);

    QIcon icon("/home/dmitry/cpp/qt/lab1/Images_lab1/spider1.bmp");
    setWindowIcon(icon);

    QColorDialog cd;

    QColor activBgColor = cd.getColor();


    QPalette pal = palette();

    if ( activBgColor.isValid() )
    {
        pal.setColor(QPalette::Active, QPalette::Window, activBgColor);
    }
    else {
        pal.setColor(QPalette::Active, QPalette::Window, Qt::red);
    }

    QString fileDialogTitle = QStringLiteral("Choose background");
    QFileDialog fd;

    QString file = fd.getOpenFileName(nullptr, fileDialogTitle, "/home/dmitry/cpp/qt/lab1/Images_lab1/");
    QPixmap bg;
    if (file.isNull())
    {
        bg.load("/home/dmitry/cpp/qt/lab1/Images_lab1/WomanAndDog.jpg");
    }
    else {
        bg.load(file);
    }

    QBrush br(bg);
    pal.setBrush(QPalette::Inactive, QPalette::Window, br);
    setPalette(pal);

    setWindowOpacity(0.5);


    resize(400, 300);
    //move(200, 300);

    QRect screenRect = QGuiApplication::primaryScreen()->availableGeometry();
    move(screenRect.center().x(), screenRect.center().y() - height());

    setMaximumSize(bg.size());
    setMinimumSize(100, 100);

    //setCursor(Qt::PointingHandCursor);

    QPixmap pix("/home/dmitry/cpp/qt/lab1/Images_lab1/cursor1.cur");
    pix.setMask(QBitmap("/home/dmitry/cpp/qt/lab1/Images_lab1/cursor1.cur")); //тут не понятное место
    spCursor = new QCursor(pix);
    setCursor(*spCursor);



}

Spider::~Spider()
{
    delete spCursor;
}

