#pragma once
#include "../Enums.hpp"
#include "Subscriber.hpp"
#include <memory>
#include <vector>

class Publisher{
    private:
        std::vector<std::shared_ptr<Subscriber>> subscribers;
    public:
        Publisher();
        ~Publisher();
        void addSubscriber(std::shared_ptr<Subscriber> subscriber);
        void removeSubscriber(std::shared_ptr<Subscriber> subscriber);
        void notifySubscribers(Event event);
};