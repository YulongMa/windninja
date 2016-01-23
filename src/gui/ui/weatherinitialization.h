#ifndef WEATHERINITIALIZATION_H
#define WEATHERINITIALIZATION_H

#include <QWidget>

namespace Ui {
class WeatherInitialization;
}

class WeatherInitialization : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherInitialization(QWidget *parent = 0);
    ~WeatherInitialization();

private:
    Ui::WeatherInitialization *ui;
};

#endif // WEATHERINITIALIZATION_H
