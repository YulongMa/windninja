#include "pointinitialization.h"
#include "ui_pointinitialization.h"

PointInitialization::PointInitialization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PointInitialization)
{
    ui->setupUi(this);
}

PointInitialization::~PointInitialization()
{
    delete ui;
}
