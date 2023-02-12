#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Tic_Tac_Toe; }
QT_END_NAMESPACE

class Tic_Tac_Toe : public QMainWindow
{
    Q_OBJECT

public:
    Tic_Tac_Toe(QWidget *parent = nullptr);
    ~Tic_Tac_Toe();

private slots:

    void on_mark_X_clicked();

    void on_mark_O_clicked();

    void swaping();

    void Get_Winner();

    void on_Slot_1_clicked();

    void on_Slot_2_clicked();

    void on_Slot_3_clicked();

    void on_Slot_4_clicked();

    void on_Slot_5_clicked();

    void on_Slot_6_clicked();

    void on_Slot_7_clicked();

    void on_Slot_8_clicked();

    void on_Slot_9_clicked();

    void blockAllSignals();

    void Empty_all_Slots();

    void recoverAllSignals();

    void replay_Game();

    void Game_Tied();

    void on_About_clicked();

private:
    Ui::Tic_Tac_Toe *ui;
};
#endif // TIC_TAC_TOE_H
