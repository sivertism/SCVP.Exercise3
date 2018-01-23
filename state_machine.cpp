#include "state_machine.h"
#include <unistd.h>
#include <sstream>

void stateMachine::process()
{
    static int unsigned cur_pos_, matches_;

    cur_pos_ ++;
    base next_state_ = Start; // Default
    switch(state)
    {
        case Start:
            if (input.read() == 'G') next_state_ = G;
            break;
        case G:
            if (input.read() == 'A'){
                next_state_ = GA;
            } else if (input.read() == 'G') {
                next_state_ = G;
            }
            break;
        case GA:
            if (input.read() == 'A'){
                next_state_ = GAA;
            } else if (input.read() == 'G') {
                next_state_ = G;
            }
            break;
        case GAA:
            if (input.read() == 'G') next_state_ = GAAG;
            break;
        case GAAG:
            if (input.read() == 'G') next_state_ = Start;
            matches_ ++;
            std::cout << "Match number " << matches_ << " at character# " << cur_pos_ << std::endl;
            break;
    }
    state = next_state_;
}

