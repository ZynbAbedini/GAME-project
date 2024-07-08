#ifndef ONE_H
#define ONE_H

#include <QWidget>

namespace Ui {
class one;
}

class one : public QWidget
{
    Q_OBJECT

public:
    explicit one(QWidget *parent = nullptr);
    ~one();

private slots:
    void on_exit_clicked();

    void on_pushButton_clicked();

private:
    Ui::one *ui;
};

#endif // ONE_H

