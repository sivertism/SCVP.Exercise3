#ifndef FSM_H
#define FSM_H

#include <systemc.h>

SC_MODULE(stateMachine)
{
public:
    sc_in<char> input;
    sc_in<bool> clk;

    enum base {Start, G, GA, GAA, GAAG};
    base state;

    SC_CTOR(stateMachine) : input("input"), clk("clk"), state(Start)
    {
        SC_METHOD(process);
        sensitive << clk.pos();
        dont_initialize();
    }

    void process( void );
};

#endif // FSM_H


