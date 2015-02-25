#include "ninjamainwindow.h"
#include "ui_ninjamainwindow.h"

NinjaMainWindow::NinjaMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NinjaMainWindow)
{
    ui->setupUi(this);
}

NinjaMainWindow::~NinjaMainWindow()
{
    delete ui;
}
