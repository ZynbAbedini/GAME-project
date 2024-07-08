#include "Two2.h"
#include <QComboBox>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPointer>
#include <QPushButton>
#include <QRadioButton>
#include <QStringList>
#include "global_variables.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <random>
#include "ui_Two2.h"
#include <QDebug>
#include <QRandomGenerator>
#include <algorithm>
#include "QApplication"


Two2::Two2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Two2),
    player1_score(0),
    player2_score(0),
    currentPlayer(1),
    questionIndex(0),
    timer(new QTimer(this)),
    timeLeft(30),
    c("9"), // Default category
    d("easy") // Default difficulty
{
    ui->setupUi(this);

    ui->comboBox_cat->addItem("general knowledge");
    ui->comboBox_cat->addItem("book");
    ui->comboBox_cat->addItem("film");
    ui->comboBox_cat->addItem("music");
    ui->comboBox_cat->addItem("musicals & theaters");
    ui->comboBox_cat->addItem("television");
    ui->comboBox_cat->addItem("video games");
    ui->comboBox_cat->addItem("board games");
    ui->comboBox_cat->addItem("art");
    ui->comboBox_cat->addItem("animals");
    ui->comboBox_cat->addItem("comics");
    ui->comboBox_cat->addItem("anime & manga");
    ui->comboBox_cat->addItem("science & nature");
    ui->comboBox_cat->addItem("computers");
    ui->comboBox_cat->addItem("mathematics");
    ui->comboBox_cat->addItem("mythology");
    ui->comboBox_cat->addItem("sports");
    ui->comboBox_cat->addItem("geography");
    ui->comboBox_cat->addItem("history");
    ui->comboBox_cat->addItem("politics");
    ui->comboBox_cat->addItem("celebrities");
    ui->comboBox_cat->addItem("vehicles");
    ui->comboBox_cat->addItem("gadgets");
    ui->comboBox_cat->addItem("carton & animations");

    connect(ui->comboBox_cat, SIGNAL(currentIndexChanged(int)), this, SLOT(set_c()));

    connect(ui->pushButton, &QPushButton::clicked, this, &Two2::startGame);
    connect(timer, &QTimer::timeout, this, &Two2::updateTimer);
}

void Two2::set_c() {
    int index = ui->comboBox_cat->currentIndex();
    qDebug() << index;
    switch (index) {
    case 0:
        c = "9";
        break;
    case 1:
        c = "10";
        break;
    case 2:
        c = "11";
        break;
    case 3:
        c = "12";
        break;
    case 4:
        c = "13";
        break;
    case 5:
        c = "14";
        break;
    case 6:
        c = "15";
        break;
    case 7:
        c = "16";
        break;
    case 8:
        c = "17";
        break;
    case 9:
        c = "18";
        break;
    case 10:
        c = "19";
        break;
    case 11:
        c = "20";
        break;
    case 12:
        c = "21";
        break;
    case 13:
        c = "22";
        break;
    case 14:
        c = "23";
        break;
    case 15:
        c = "24";
        break;
    case 16:
        c = "25";
        break;
    case 17:
        c = "26";
        break;
    case 18:
        c = "27";
        break;
    case 19:
        c = "28";
        break;
    case 20:
        c = "29";
        break;
    case 21:
        c = "30";
        break;
    case 22:
        c = "31";
        break;
    case 23:
        c = "32";
        break;
    }
    qDebug() << c;
}

void Two2::startGame() {
    player1_score = 0;
    player2_score = 0;
    currentPlayer = 1;
    questionIndex = 0;
    fetchQuestions();
}

void Two2::fetchQuestions() {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl(QString("https://opentdb.com/api.php?amount=5&category=%1&difficulty=%2&type=multiple").arg(c).arg(d)));
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);
            QJsonObject obj = doc.object();
            questions = obj["results"].toArray();
            displayNextQuestion();
        } else {
            qDebug() << "Error fetching questions: " << reply->errorString();
        }
        reply->deleteLater();
    });
}
void Two2::displayNextQuestion() {
    if (questionIndex < questions.size()) {
        QJsonObject questionObj = questions[questionIndex].toObject();
        QString question = questionObj["question"].toString();
        ui->textBrowser->setText(question);

        QJsonArray incorrectAnswers = questionObj["incorrect_answers"].toArray();
        choices.clear();
        for (const auto &answer : incorrectAnswers) {
            choices.append(answer.toString());
        }
        correctAnswer = questionObj["correct_answer"].toString();
        choices.append(correctAnswer);

        // Randomize the order of the list
        std::random_device rd;
        std::mt19937 generator(rd());
        std::shuffle(choices.begin(), choices.end(), generator);

        ui->radioButton_1->setText(choices[0]);
        ui->radioButton_2->setText(choices[1]);
        ui->radioButton_3->setText(choices[2]);
        ui->radioButton_4->setText(choices[3]);

        questionIndex++;
        timeLeft = 30;
        ui->label_timer->setText("Time: " + QString::number(timeLeft));
        timer->start(1000);
    } else {
        if (currentPlayer == 1) {
            currentPlayer = 2;
            questionIndex = 0;
            fetchQuestions();
        } else {
            // Display final scores
            ui->label_score1->setText("Player 1 Score: " + QString::number(player1_score));
            ui->label_score2->setText("Player 2 Score: " + QString::number(player2_score));
        }
    }
}

void Two2::updateTimer() {
    timeLeft--;
    ui->label_timer->setText("Time: " + QString::number(timeLeft));
    if (timeLeft == 0) {
        timer->stop();
        checkAnswer("");
        displayNextQuestion();
    }
}

void Two2::checkAnswer(QString answer) {
    if (answer == correctAnswer) {
        if (currentPlayer == 1) {
            player1_score++;
        } else {
            player2_score++;
        }
    }
    displayNextQuestion();
}

void Two2::on_radioButton_1_clicked() { timer->stop(); checkAnswer(ui->radioButton_1->text()); }
void Two2::on_radioButton_2_clicked() { timer->stop(); checkAnswer(ui->radioButton_2->text()); }
void Two2::on_radioButton_3_clicked() { timer->stop(); checkAnswer(ui->radioButton_3->text()); }
void Two2::on_radioButton_4_clicked() { timer->stop(); checkAnswer(ui->radioButton_4->text()); }

Two2::~Two2() {
    delete ui;
}

// void Two2::on_exit_clicked()
// {
//       QApplication::exit();
// }

