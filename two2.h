#ifndef TWO2_H
#define TWO2_H

#include <QWidget>

namespace Ui {
class Two2;
}

class Two2 : public QWidget
{
    Q_OBJECT

public:
    explicit Two2(QWidget *parent = nullptr);
    ~Two2();

private slots:
    void on_exit_clicked();

private:
    Ui::Two2 *ui;
};

#endif // TWO2_H
