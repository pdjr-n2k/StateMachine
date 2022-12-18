# StateMachine

ADT implementing a hybrid state machine / jump vector.

StateMachine allows an application to register a collection of
functions each of which is associated with a unique machine state
represented by an integer value.

At each processing tick the state machine executes the callback
function associated with the current machine state, updating the
state to the value returned by the callback.

The library was built to support microprocessor firmware which needed
to handle a range of actions dependent upon the operation or sequence
of operations of a single configuration button.

## Types

### typedef struct { int _state_; int (_*handler_)(int _value_); } tJump;
```
StateMachine::tJump jumpVector[] = {
  { 0, updateModuleInstance },  
  { 0, 0 }
};
```
The tJump type is used by the host application to define a jump vector
array, each entry of which maps an integer machine *state* onto a
callback function *handler* reponsible for processing that *state* value.

The last entry in the jump vector must be the value ```{ 0, 0 }``` which
signals the end of the vector.

## Constructor

### StateMachine(*initialState*, *jumpVector*);
```
StateMachine stateMachine(0, jumpVector);
```
Create a new StateMachine consisting of the callback functions passed
in *jumpVector* and with the specified *initialState*.

## Methods

### setState(*state*)
```
stateMachine.setState(1);
```
Force the state machine into the state specified by integer value
*state*.

### currentState()
```
int state = stateMachine.currentState();
```
Get the current state of the state machine.

### process(int *value*)
```
stateMachine.process(23);
```
Process the state machine by executing the callback function associated
with the current value of the machine's internal state and subsequently
updating the internal state to the value returned by the callback. 
