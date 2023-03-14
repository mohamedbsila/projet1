#include "video.h"
#include "ui_video.h"

video::video(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::video)
{
    ui->setupUi(this);

       player = new QMediaPlayer(this);
        vw = new QVideoWidget(this);
        player->setVideoOutput(vw);
        //this->setCentralWidget(vw);
        vw->setGeometry(50, 50,350, 350);
        slider= new QSlider(this);
        bar =new QProgressBar(this);
        slider->setOrientation(Qt::Horizontal);
        ui->statusbar->addPermanentWidget(slider);
        ui->statusbar->addPermanentWidget(bar);

        connect (player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
        connect (player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
        connect (slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);


        connect (player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
        connect (player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);
}

video::~video()
{
    delete ui;
}

void video::on_pb_importervid_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"open a File","","Video File (*.*)");
    on_pb_stop_clicked();

    player->setMedia(QUrl::fromLocalFile(filename));


    on_pb_play_clicked();

}

void video::on_pb_play_clicked()
{

player->play();
ui->statusbar->showMessage("Playing");
}

void video::on_pb_stop_clicked()
{
    player->stop();
    ui->statusbar->showMessage("Stopped...");
}

void video::on_pb_pause_clicked()
{
player->pause();
ui->statusbar->showMessage("Paused...");
}
