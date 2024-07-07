#ifndef ONE2_H
#define ONE2_H

#include <QWidget>

namespace Ui {
class One2;
}

class One2 : public QWidget
{
    Q_OBJECT

public:
    explicit One2(QWidget *parent = nullptr);
    ~One2();

private slots:
    void on_exit_clicked();

private:
    Ui::One2 *ui;
};

#endif // ONE2_H
