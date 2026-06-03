#include "Publisher.hpp"
#include <algorithm>

Publisher::Publisher() {}
Publisher::~Publisher() {}

void Publisher::addSubscriber(std::shared_ptr<Subscriber> subscriber) {
    this->subscribers.push_back(subscriber);
}

void Publisher::removeSubscriber(std::shared_ptr<Subscriber> subscriber) {
    this->subscribers.erase(
        std::remove(this->subscribers.begin(), this->subscribers.end(), subscriber),
        this->subscribers.end()
    );
}

void Publisher::notifySubscribers(Event event) {
    for (const auto &subscriber : this->subscribers) {
        subscriber->update(event);
    }
}