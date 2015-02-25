#include "outputreswidget.h"
#include "ui_outputreswidget.h"

OutputResWidget::OutputResWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OutputResWidget)
{
    ui->setupUi(this);
}

OutputResWidget::~OutputResWidget()
{
    delete ui;
}
