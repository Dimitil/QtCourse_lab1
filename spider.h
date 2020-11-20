#ifndef SPIDER_H
#define SPIDER_H

#include <QWidget>


class Spider : public QWidget
{
    Q_OBJECT

    QCursor *spCursor;

public:
    Spider(QWidget *parent = nullptr);
    ~Spider();
};
#endif // SPIDER_H
