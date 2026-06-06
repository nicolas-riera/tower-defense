#pragma once
#include "../../../events/Subscriber.hpp"
#include "../../../events/Publisher.hpp"

class Invader : public Subscriber, public Publisher
{
    protected:
        short life;
        short speed;
        InvaderSelection invaderType;
    public:
        short x;
        short y;
        Invader(short x, short y, short life, short speed, InvaderSelection invaderType);
        ~Invader();
        InvaderSelection getType();
        void update(Event event);
};