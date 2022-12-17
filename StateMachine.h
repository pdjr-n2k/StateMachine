#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <Arduino.h>

class StateMachine {
  public:
    typedef struct { int state; int (*handler)(int value); } tJump;

    StateMachine(int initialState, tJump *jumpVector);
    void setState(int state);
    void process(int value);
  
  private:
    tJump *jumpVector;
    int state = 0;

};

#endif