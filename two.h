#ifndef TWO_H
#define TWO_H

#include <QWidget>

namespace Ui {
class Two;
}

class Two : public QWidget
{
    Q_OBJECT

public:
    explicit Two(QWidget *parent = nullptr);
    ~Two();

private slots:
    void on_exit_clicked();

    void on_pushButton_clicked();

private:
    Ui::Two *ui;
};

#endif // TWO_H
