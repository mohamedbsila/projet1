#ifndef LOGIN1_H
#define LOGIN1_H
#include "statistique.h"
#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class login1;
}

class login1 : public QDialog
{
    Q_OBJECT

public:
    explicit login1(QWidget *parent = nullptr);
    ~login1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login1 *ui;
     Statistique *statistique;
     //MainWindow *mainwindow;
};

#endif // LOGIN1_H
