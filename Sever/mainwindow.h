#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

#include <QTimer>

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

    void takePic();

    
private slots:
  void dataPending();

private:
    QTimer *timer;

    QUdpSocket *socket;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
