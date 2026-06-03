#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include "picojson.h"
#include "../../Enums.hpp"

using GridMatrix = std::vector<std::vector<short>>;

class Stage
{
    private:
        GridMatrix loadGridFromJson(const std::string& filepath);
        GridMatrix getGrid(Difficulty difficulty);
    public: 
        GridMatrix grid;
        Stage();
        ~Stage();
        void init(Difficulty difficulty);
};