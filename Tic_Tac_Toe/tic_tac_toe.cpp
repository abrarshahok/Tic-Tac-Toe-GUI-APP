#include "tic_tac_toe.h"
#include "ui_tic_tac_toe.h"
#include <QMessageBox>

Tic_Tac_Toe::Tic_Tac_Toe(QWidget *parent) : QMainWindow(parent) , ui(new Ui::Tic_Tac_Toe)
{
    ui->setupUi(this);
    Tic_Tac_Toe::blockAllSignals();
    ui->Winner_Text->setText("Player 1, Choose Marker!");
}

Tic_Tac_Toe::~Tic_Tac_Toe()
{
    delete ui;
}

QString Empty = "";
QString CurrentMark   = "";
QString CurrentPlayer = "";

void Tic_Tac_Toe::on_mark_X_clicked()
{
    // When Mark X is Selected
    CurrentMark = "X";
    CurrentPlayer = "1";
    Tic_Tac_Toe::recoverAllSignals();
    ui->Winner_Text->setText("Player 1's Turn");
    ui->mark_O->blockSignals(true);
    ui->mark_X->blockSignals(true);
}

void Tic_Tac_Toe::on_mark_O_clicked()
{
    // When Marks O is selected
    CurrentMark = "O";
    CurrentPlayer = "1";
    Tic_Tac_Toe::recoverAllSignals();
    ui->Winner_Text->setText("Player 1's Turn");
    ui->mark_O->blockSignals(true);
    ui->mark_X->blockSignals(true);
}

void Tic_Tac_Toe::swaping()
{
    // Swaping Players
    if(CurrentPlayer == "1"){
        CurrentPlayer = "2";
        ui->Winner_Text->setText("Playes 2's Turn.");
    }
    else if (CurrentPlayer == "2"){
        CurrentPlayer = "1";
        ui->Winner_Text->setText("Playes 1's Turn.");
    }
    else{
        ui->Winner_Text->setText("Player 1, Choose Marker!");
    }

    // Swaping Markers
    if(CurrentMark == "X"){
        CurrentMark = "O";
    }
    else{
        CurrentMark = "X";
    }

}

void Tic_Tac_Toe::blockAllSignals()
{
    // Blocking Signals
    ui->Slot_1->blockSignals(true);
    ui->Slot_2->blockSignals(true);
    ui->Slot_3->blockSignals(true);
    ui->Slot_4->blockSignals(true);
    ui->Slot_5->blockSignals(true);
    ui->Slot_6->blockSignals(true);
    ui->Slot_7->blockSignals(true);
    ui->Slot_8->blockSignals(true);
    ui->Slot_9->blockSignals(true);
}

void Tic_Tac_Toe::recoverAllSignals()
{
    // Recovering Signals
    ui->Slot_1->blockSignals(false);
    ui->Slot_2->blockSignals(false);
    ui->Slot_3->blockSignals(false);
    ui->Slot_4->blockSignals(false);
    ui->Slot_5->blockSignals(false);
    ui->Slot_6->blockSignals(false);
    ui->Slot_7->blockSignals(false);
    ui->Slot_8->blockSignals(false);
    ui->Slot_9->blockSignals(false);
}

void Tic_Tac_Toe::Empty_all_Slots()
{
    // Empty All Slots
    ui->Slot_1->setText("");
    ui->Slot_2->setText("");
    ui->Slot_3->setText("");
    ui->Slot_4->setText("");
    ui->Slot_5->setText("");
    ui->Slot_6->setText("");
    ui->Slot_7->setText("");
    ui->Slot_8->setText("");
    ui->Slot_9->setText("");
}

void Tic_Tac_Toe::replay_Game()
{
    // Function to Repaly Game
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Winner is Player : "+CurrentPlayer,
                                                                    "Do You Want to Play Again?",QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes){          
                Tic_Tac_Toe::Empty_all_Slots();
                ui->mark_O->blockSignals(false);
                ui->mark_X->blockSignals(false);
            }
            else{
                QApplication::quit();
            }
}

void Tic_Tac_Toe::Game_Tied()
{
    // Function for Tie Game
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Game Tied!",
                                                                    "Do You Want to Play Again?",QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes){
                Tic_Tac_Toe::Empty_all_Slots();
                ui->mark_O->blockSignals(false);
                ui->mark_X->blockSignals(false);
            }
            else{
                QApplication::quit();
            }
}

void Tic_Tac_Toe::Get_Winner()
{
    // Fetching Text
    QString slot_one   = ui->Slot_1->text();
    QString slot_two   = ui->Slot_2->text();
    QString slot_three = ui->Slot_3->text();
    QString slot_four  = ui->Slot_4->text();
    QString slot_five  = ui->Slot_5->text();
    QString slot_six   = ui->Slot_6->text();
    QString slot_seven = ui->Slot_7->text();
    QString slot_eight = ui->Slot_8->text();
    QString slot_nine  = ui->Slot_9->text();

    // Winning Conditon for Row 1
    if(slot_one == slot_two && slot_two == slot_three && slot_one != Empty && slot_two != Empty && slot_three != Empty){
        ui->Winner_Text->setText("Winner is Player : "+CurrentPlayer);
        Tic_Tac_Toe::blockAllSignals();
        Tic_Tac_Toe::replay_Game();
        CurrentPlayer = "";
        return;
    }

    // Winning Conditon for Row 2
    if(slot_four == slot_five && slot_five == slot_six && slot_four != Empty && slot_five != Empty && slot_six != Empty){
        ui->Winner_Text->setText("Winner is Player : "+CurrentPlayer);
        Tic_Tac_Toe::blockAllSignals();
        Tic_Tac_Toe::replay_Game();
        CurrentPlayer = "";
        return;
    }

    // Winning Conditon for Row 3
    if(slot_seven == slot_eight && slot_eight == slot_nine && slot_seven != Empty && slot_eight != Empty && slot_nine != Empty){
        ui->Winner_Text->setText("Winner is Player : "+CurrentPlayer);      
        Tic_Tac_Toe::blockAllSignals();
        Tic_Tac_Toe::replay_Game();
        CurrentPlayer = "";
        return;
    }

    // Winning Conditon for Column 1
    if(slot_one == slot_four && slot_four == slot_seven && slot_one != Empty && slot_four != Empty && slot_seven != Empty){
        ui->Winner_Text->setText("Winner is Player : "+CurrentPlayer);        
        Tic_Tac_Toe::blockAllSignals();
        Tic_Tac_Toe::replay_Game();
        CurrentPlayer = "";
        return;
    }

    // Winning Conditon for Column 2
    if(slot_two == slot_five && slot_five == slot_eight && slot_two != Empty && slot_five != Empty && slot_eight != Empty){
        ui->Winner_Text->setText("Winner is Player : "+CurrentPlayer);       
        Tic_Tac_Toe::blockAllSignals();
        Tic_Tac_Toe::replay_Game();
        CurrentPlayer = "";
        return;
    }

    // Winning Conditon for Column 3
    if(slot_three == slot_six && slot_six == slot_nine && slot_three != Empty && slot_six != Empty && slot_nine != Empty){
        ui->Winner_Text->setText("Winner is Player : "+CurrentPlayer);
        Tic_Tac_Toe::blockAllSignals();
        Tic_Tac_Toe::replay_Game();
        CurrentPlayer = "";
        return;
    }

    // Winning Conditon for Left Diagonal
    if(slot_one == slot_five && slot_five == slot_nine && slot_one != Empty && slot_five != Empty && slot_nine != Empty){
        ui->Winner_Text->setText("Winner is Player : "+CurrentPlayer);
        Tic_Tac_Toe::blockAllSignals();
        Tic_Tac_Toe::replay_Game();
        CurrentPlayer = "";
        return;
    }

    // Winning Conditon for Right Diagonal
    if(slot_three == slot_five && slot_five == slot_seven && slot_three != Empty && slot_five != Empty && slot_seven != Empty){
        ui->Winner_Text->setText("Winner is Player : "+CurrentPlayer);
        Tic_Tac_Toe::blockAllSignals();
        Tic_Tac_Toe::replay_Game();
        CurrentPlayer = "";
        return;
    }

    // Codition When Game is Tied
    if (slot_one != Empty && slot_two != Empty && slot_three != Empty &&
        slot_four != Empty && slot_five != Empty && slot_six != Empty &&
        slot_seven != Empty && slot_eight != Empty && slot_nine != Empty)
    {
        ui->Winner_Text->setText("Game Tied!");
        Tic_Tac_Toe::Game_Tied();
        CurrentPlayer = "";
    }
}

void Tic_Tac_Toe::on_Slot_1_clicked()
{
    ui->Slot_1->setText(CurrentMark);
    Tic_Tac_Toe::Get_Winner();
    Tic_Tac_Toe::swaping();
    ui->Slot_1->blockSignals(true);
}


void Tic_Tac_Toe::on_Slot_2_clicked()
{
    ui->Slot_2->setText(CurrentMark);
    Tic_Tac_Toe::Get_Winner();
    Tic_Tac_Toe::swaping();
    ui->Slot_2->blockSignals(true);
}


void Tic_Tac_Toe::on_Slot_3_clicked()
{
    ui->Slot_3->setText(CurrentMark);
    Tic_Tac_Toe::Get_Winner();
    Tic_Tac_Toe::swaping();
    ui->Slot_3->blockSignals(true);
}


void Tic_Tac_Toe::on_Slot_4_clicked()
{
    ui->Slot_4->setText(CurrentMark);
    Tic_Tac_Toe::Get_Winner();
    Tic_Tac_Toe::swaping();
    ui->Slot_4->blockSignals(true);
}


void Tic_Tac_Toe::on_Slot_5_clicked()
{

    ui->Slot_5->setText(CurrentMark);
    Tic_Tac_Toe::Get_Winner();
    Tic_Tac_Toe::swaping();
    ui->Slot_5->blockSignals(true);
}


void Tic_Tac_Toe::on_Slot_6_clicked()
{
    ui->Slot_6->setText(CurrentMark);
    Tic_Tac_Toe::Get_Winner();
    Tic_Tac_Toe::swaping();
    ui->Slot_6->blockSignals(true);
}


void Tic_Tac_Toe::on_Slot_7_clicked()
{
    ui->Slot_7->setText(CurrentMark);
    Tic_Tac_Toe::Get_Winner();
    Tic_Tac_Toe::swaping();
    ui->Slot_7->blockSignals(true);
}


void Tic_Tac_Toe::on_Slot_8_clicked()
{
    ui->Slot_8->setText(CurrentMark);
    Tic_Tac_Toe::Get_Winner();
    Tic_Tac_Toe::swaping();
    ui->Slot_8->blockSignals(true);
}


void Tic_Tac_Toe::on_Slot_9_clicked()
{
    ui->Slot_9->setText(CurrentMark);
    Tic_Tac_Toe::Get_Winner();
    Tic_Tac_Toe::swaping();
    ui->Slot_9->blockSignals(true);
}


void Tic_Tac_Toe::on_About_clicked()
{
    QMessageBox aboutDev(QMessageBox::NoIcon,"About Developer","Made by Abrar Ahmed Shahok (21BSCS-20)\n"
                                                               "Features : Human vs Human Only\n"
                                                               "I'll Soon Add Feature for Pc vs Human\n"
                                                               "For More Info Vist : https://github.com/abrar-ahmed-21bscs20\n",QMessageBox::Ok);
    QPixmap devPic(":/resources/devPic.jpg");
    aboutDev.setIconPixmap(devPic.scaled(100,100,Qt::KeepAspectRatio));
    aboutDev.exec();

}
