#pragma once
#include "../../../events/Subscriber.hpp"
#include "../../../events/Publisher.hpp"

class Invader : public Subscriber, public Publisher
{
    protected:
        short life;
        short speed;
    public:
        Invader(short life, short speed);
        ~Invader();
        void update(Event event);
};