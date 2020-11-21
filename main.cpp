#include "spider.h"
#include <QTranslator>
#include <QApplication>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load(QLocale::system(), "spider", "_");
    QApplication::installTranslator(&translator);

    QString filespec = QString("qt_") + QLocale::system().name();
    QString directory = QLibraryInfo::location(QLibraryInfo::TranslationsPath);

    QTranslator translator2;
    translator2.load(filespec, directory);
    QApplication::installTranslator(&translator2);
    Spider w;

    w.show();
    return a.exec();
}
