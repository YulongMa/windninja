#ifndef POINTINITIALIZATION_H
#define POINTINITIALIZATION_H

#include <QWidget>

namespace Ui {
class PointInitialization;
}

class PointInitialization : public QWidget
{
    Q_OBJECT

public:
    explicit PointInitialization(QWidget *parent = 0);
    ~PointInitialization();

private:
    Ui::PointInitialization *ui;
};

#endif // POINTINITIALIZATION_H
