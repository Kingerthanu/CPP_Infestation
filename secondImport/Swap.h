#ifndef SWAP_H
#define SWAP_H
#include <QObject>

class Stepper : public QObject {
Q_OBJECT
public:
    Stepper();
    QTimer *timer;

public slots:
    void MyTimerSlot();
    void UpdateSet();
    void Initialize();
    void deInitialize();
};

#endif // SWAP_H
