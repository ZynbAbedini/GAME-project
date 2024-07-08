#ifndef TWO2_H
#define TWO2_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>

namespace Ui {
class Two2;
}

class Two2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Two2(QWidget *parent = nullptr);
    ~Two2();

private slots:
    void set_c();
    void startGame();
    void fetchQuestions();
    void displayNextQuestion();
    void updateTimer();
    void checkAnswer(QString answer);

    void on_radioButton_1_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_4_clicked();

private:
    Ui::Two2 *ui;
    int player1_score;
    int player2_score;
    int currentPlayer;
    int questionIndex;
    QTimer* timer;
    int timeLeft;
    QString correctAnswer;
    QStringList choices;
    QJsonArray questions;
    QString c;
    QString d;
};

#endif // TWO2_H

/*
#ifndef TWO2_H
#define TWO2_H

#include <QMainWindow>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonArray>

namespace Ui {
class Two2;
}

class Two2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Two2(QWidget *parent = nullptr);
    ~Two2();

private slots:
    void set_c();
    void startGame();
    void fetchQuestions();
    void displayNextQuestion();
    void updateTimer();
    void checkAnswer(QString answer);
    void on_radioButton_1_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_4_clicked();

private:
    Ui::Two2 *ui;
    int player1_score;
    int player2_score;
    int currentPlayer;
    int questionIndex;
    QTimer *timer;
    int timeLeft;
    QString c;
    QString d;
    QJsonArray questions;
    QStringList choices;
    QString correctAnswer;
};

#endif // TWO2_H
*/
