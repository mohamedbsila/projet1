#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFileDialog>
#include <QMainWindow>
#include "perso.h"
#include <QVBoxLayout>
#include "statistique.h"

#include "login1.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();


    void on_pb_chercher_nom_clicked();

    QString on_pb_image_clicked();

    void on_pb_trier_nom_clicked();

    void on_pb_trier_prenom_clicked();

    void on_pb_trier_password_clicked();

    void on_pb_chercher_prenom_clicked();

    void on_pb_chercher_password_clicked();

    void on_pb_stat_clicked();

    void on_pb_video_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_groupBox_2_clicked();

    void on_le_nom_cursorPositionChanged(int arg1, int arg2);

    void on_pb_login_clicked();

    void on_le_prenom_ch_cursorPositionChanged(int arg1, int arg2);

    void on_pb_chercher_type_clicked();

    void on_pb_chercher_nom_2_clicked();

private:
    Ui::MainWindow *ui;
    perso o;
    Statistique *statistique;



};
#endif // MAINWINDOW_H
