#include <QTimer>
#include <iostream>
#include <Swap.h>
#include <bird.h>
Stepper::Stepper()
    {
        // create a timer
    /*
        timer = new QTimer(this);

        // setup signal and slot
        connect(timer, SIGNAL(timeout()),
              this, SLOT(MyTimerSlot()));
              */
    }
void Stepper::UpdateSet(){

}
void Stepper::MyTimerSlot(){
        std::cout << "Timer..." << "\n";
    }
void Stepper::deInitialize(){
    timer->stop();
}
void Stepper::Initialize(){
    timer->start(1);
}


