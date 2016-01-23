#include "weatherinitialization.h"
#include "ui_weatherinitialization.h"

WeatherInitialization::WeatherInitialization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherInitialization)
{
    ui->setupUi(this);
}

WeatherInitialization::~WeatherInitialization()
{
    delete ui;
}
