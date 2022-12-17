#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <Arduino.h>

class StateMachine {
  public:
    typedef struct { int state; int (*handler)(uint8_t value); } tJump;

    StateMachine(int initialState, tJump *jumpVector);
    void setState(int state);
    void process(uint8_t value);
  
  private:
    tJump *jumpVector;
    int state = 0;

};

#endif