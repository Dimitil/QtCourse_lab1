#include <QIcon>
#include <QPalette>
#include <QPixmap>
#include <QBitmap>
#include <QBrush>
#include <QGuiApplication>
#include <QScreen>
#include <QColorDialog>
#include <QFileDialog>
#include <iostream>
#include <QtDebug>
#include "spider.h"

Spider::Spider(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlag(Qt::CustomizeWindowHint);
    Qt::WindowFlags f = windowFlags();
    f |= Qt::WindowStaysOnTopHint;
    setWindowFlags(f | Qt::WindowTitleHint | Qt::WindowSystemMenuHint);
    //Qt::WindowStates s = windowState();
    //s |= Qt::WindowState::WindowMinimized;
    //setWindowState(s);

    QString title = QObject::tr("Spider");
    setWindowTitle(title);

    QIcon icon("./spider1.bmp");
    setWindowIcon(icon);

    QString colorDialogTitle = QObject::tr("Choose background color");

    QColor activBgColor = QColorDialog::getColor(Qt::white, nullptr, colorDialogTitle);
    //QColor activBgColor = QColorDialog::getColor();

    QPalette pal = palette();

    if ( activBgColor.isValid() )
    {
        pal.setColor(QPalette::Active, QPalette::Window, activBgColor);
    }
    else {
        pal.setColor(QPalette::Active, QPalette::Window, Qt::red);
    }

    QString fileDialogTitle = QObject::tr("Choose background");


    QString file = QFileDialog::getOpenFileName(nullptr, fileDialogTitle, "./Images_lab1/");
    QPixmap bg;
    if (file.isNull())
    {
        if (!bg.load("./images_lab1/WomanAndDog.jpg")) {
            qDebug() << "Cannot load background image";
            exit(1);
        }
    }
    else {
        if (!bg.load(file)) {
            qDebug() << "Cannot load background image";
            exit(2);
        }
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

    QPixmap pix("./Images_lab1/cursor1.cur");
    pix.setMask(QBitmap("./Images_lab1/cursor1.cur"));
    spCursor = new QCursor(pix);
    setCursor(*spCursor);
}

Spider::~Spider()
{
    delete spCursor;
}

