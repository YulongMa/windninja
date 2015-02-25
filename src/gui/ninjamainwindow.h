#ifndef NINJAMAINWINDOW_H
#define NINJAMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class NinjaMainWindow;
}

class NinjaMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit NinjaMainWindow(QWidget *parent = 0);
    ~NinjaMainWindow();
    
private:
    Ui::NinjaMainWindow *ui;
};

#endif // NINJAMAINWINDOW_H
