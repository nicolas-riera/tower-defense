#include <memory>
#include "src/controller/TowerDefense.hpp"

int main(void)
{
    std::unique_ptr<TowerDefense> game = std::make_unique<TowerDefense>();
    game->init();
    game->show();
    
    return 0;
};