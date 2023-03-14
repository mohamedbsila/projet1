#ifndef VIDEO_H
#define VIDEO_H
#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QVideoWidget>

namespace Ui {
class video;
}

class video : public QMainWindow
{
    Q_OBJECT

public:
    explicit video(QWidget *parent = nullptr);
    ~video();


private slots:
    void on_pb_importervid_clicked();

    void on_pb_play_clicked();

    void on_pb_stop_clicked();

    void on_pb_pause_clicked();

private:
    Ui::video *ui;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QProgressBar* bar;
    QSlider* slider;
};

#endif // VIDEO_H
