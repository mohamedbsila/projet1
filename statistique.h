#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <QDialog>

namespace Ui {
class Statistique;
}

class Statistique : public QDialog
{
    Q_OBJECT

public:
    explicit Statistique(QWidget *parent = nullptr);
    ~Statistique();
protected :
    void  paintEvent(QPaintEvent *);

private:
    Ui::Statistique *ui;
};

#endif // STATISTIQUE_H
