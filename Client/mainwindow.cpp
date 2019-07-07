#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    connect( ui->startBtn, SIGNAL(clicked()), this, SLOT(getStart()) );
    connect( ui->stopBtn, SIGNAL(clicked()), this, SLOT(getStop()) );
    connect( ui->saveBtn, SIGNAL(clicked()), this, SLOT(getSave()) );

    ui->textBox->setText("HI~");

    socket = new QUdpSocket( this );

}


void MainWindow::getStart(){
    QByteArray buffer( 6, 0 );
    QDataStream stream( &buffer, QIODevice::WriteOnly );
    stream.setVersion( QDataStream::Qt_4_0 );

    quint16 y = 0;

    stream << y;


    socket->writeDatagram( buffer, QHostAddress::Broadcast, 9988 );

    ui->textBox->setText("start");
}

void MainWindow::getStop(){
    QByteArray buffer( 6, 0 );
    QDataStream stream( &buffer, QIODevice::WriteOnly );
    stream.setVersion( QDataStream::Qt_4_0 );

    quint16 y = 1;

    stream << y;


    socket->writeDatagram( buffer, QHostAddress::Broadcast, 9988 );

    ui->textBox->setText("stop");
}

void MainWindow::getSave(){
    QByteArray buffer( 6, 0 );
    QDataStream stream( &buffer, QIODevice::WriteOnly );
    stream.setVersion( QDataStream::Qt_4_0 );

    quint16 y = 2;

    stream << y;

    socket->writeDatagram( buffer, QHostAddress::Broadcast, 9988 );
    ui->textBox->setText("save");

}


MainWindow::~MainWindow()
{
    delete ui;
}
