#ifndef OUTPUTRESWIDGET_H
#define OUTPUTRESWIDGET_H

#include <QWidget>

namespace Ui {
class OutputResWidget;
}

class OutputResWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit OutputResWidget(QWidget *parent = 0);
    ~OutputResWidget();
    
private:
    Ui::OutputResWidget *ui;
};

#endif // OUTPUTRESWIDGET_H
