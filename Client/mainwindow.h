#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    

private slots:
    void getStart();

    void getStop();

    void getSave();

private:
    Ui::MainWindow *ui;

    QUdpSocket *socket;
};

#endif // MAINWINDOW_H
