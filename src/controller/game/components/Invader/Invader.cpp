#include "Invader.hpp"
#include <cmath>

Invader::Invader(std::vector<Vector2> waypoints, 
                 short life, 
                 float speed, 
                 InvaderSelection invaderType) : waypoints(waypoints), 
                                                 life(life), 
                                                 speed(speed), 
                                                 invaderType(invaderType){
    this->position.x = waypoints[0].x;
    this->position.y = waypoints[0].y;
}

Invader::~Invader(){}

InvaderSelection Invader::getType(){
    return this->invaderType;
}

void Invader::move(float deltaTime) {
    if (waypointIndex >= waypoints.size()) {
        // Invader reached the end tile (Player loses health/life)
        return;
    }

    Vector2 target = waypoints[waypointIndex];

    Vector2 direction = { target.x - position.x, target.y - position.y };
    
    float distance = sqrtf(direction.x * direction.x + direction.y * direction.y);

    float moveDistance = speed * deltaTime;

    if (moveDistance >= distance) {
        position = target;
        waypointIndex++;
    } else {
        position.x += (direction.x / distance) * moveDistance;
        position.y += (direction.y / distance) * moveDistance;
    }
}

void Invader::update(Event event){
    if(event == SHOOT){
        --this->life;
    }
}