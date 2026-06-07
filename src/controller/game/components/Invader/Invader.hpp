#pragma once
#include "../../../events/Subscriber.hpp"
#include "../../../events/Publisher.hpp"
#include <raylib.h>

class Invader : public Subscriber, public Publisher
{
    protected:
        short life;
        float speed;
        InvaderSelection invaderType;
        std::vector<Vector2> waypoints;
        int waypointIndex;
    public:
        Vector2 position;
        Invader(std::vector<Vector2> waypoints, short life, float speed, InvaderSelection invaderType);
        ~Invader();
        InvaderSelection getType();
        void move(float deltaTime);
        void update(Event event);
};