#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_addStadt_clicked()
{
    // Reads line Edit text
    QString eingabe = ui->lineEdit_stadtname->text();
    //show text
    qDebug() << QString("Der Benutzer hat eingegeben: %1").arg(eingabe);

    //try to convert it to number and sum 4
    bool istZahl;
    int zahl = eingabe.toInt(&istZahl); //would be true if conversion erfolg

    if(istZahl){
        int ergebnis = zahl + 4;
        qDebug() << QString("Die Zahl plus 4 ist: %1").arg(ergebnis);
    } else {
        qDebug() << "Die Eingabe ist keine Zahl.";
    }

}

