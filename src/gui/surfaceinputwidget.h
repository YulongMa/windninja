#ifndef SURFACEINPUTWIDGET_H
#define SURFACEINPUTWIDGET_H

#include <QWidget>

namespace Ui {
class SurfaceInputWidget;
}

class SurfaceInputWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit SurfaceInputWidget(QWidget *parent = 0);
    ~SurfaceInputWidget();
    
private:
    Ui::SurfaceInputWidget *ui;
};

#endif // SURFACEINPUTWIDGET_H
