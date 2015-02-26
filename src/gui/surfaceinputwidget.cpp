#include "surfaceinputwidget.h"
#include "ui_surfaceinputwidget.h"

SurfaceInputWidget::SurfaceInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SurfaceInputWidget)
{
    ui->setupUi(this);
}

SurfaceInputWidget::~SurfaceInputWidget()
{
    delete ui;
}
