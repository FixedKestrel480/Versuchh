#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Create the scene
    scene = new QGraphicsScene(this);

    // Connect ti QGraphicsView from UI
    ui->graphicsView->setScene(scene);
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
    QMessageBox::information(this, "Eingabe", QString("Du hast eingegeben: %1").arg(eingabe));
    int x = QRandomGenerator::global()->bounded(500);
    int y = QRandomGenerator::global()->bounded(500);
    int size = 30;

    scene->addRect(x, y, size, size);

    if(istZahl){
        int ergebnis = zahl + 4;
        qDebug() << QString("Die Zahl plus 4 ist: %1").arg(ergebnis);
    } else {
        qDebug() << "Die Eingabe ist keine Zahl.";
    }



}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene->clear();//erase all elements of the map
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "Über diese App", "Streetplanner");

}

