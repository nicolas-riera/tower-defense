#include "Stage.hpp"

Stage::Stage(){};

Stage::~Stage(){};

void Stage::init(Difficulty difficulty){
   this->grid = this->getGrid(difficulty);
};

GridMatrix Stage::loadGridFromJson(const std::string& filepath) {
    GridMatrix grid;
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filepath << std::endl;
        return grid;
    }

    picojson::value v;
    std::string err = picojson::parse(v, file);
    file.close();

    if (!err.empty()) {
        std::cerr << "Error parsing JSON: " << err << std::endl;
        return grid;
    }

    if (v.is<picojson::object>()) {
        const picojson::object& obj = v.get<picojson::object>();
        
        if (obj.count("grid") && obj.at("grid").is<picojson::array>()) {
            const picojson::array& jsonMatrix = obj.at("grid").get<picojson::array>();

            for (const auto& rowValue : jsonMatrix) {
                if (rowValue.is<picojson::array>()) {
                    const picojson::array& jsonRow = rowValue.get<picojson::array>();
                    std::vector<short> currentRow;

                    for (const auto& cellValue : jsonRow) {
                        if (cellValue.is<double>()) {
                            currentRow.push_back(static_cast<short>(cellValue.get<double>()));
                        }
                    }
                    grid.push_back(currentRow);
                }
            }
        }
    }

    return grid;
}

GridMatrix Stage::getGrid(Difficulty difficulty) {
    std::string diffStr;
    
    switch (difficulty) {
        case EASY:
            diffStr = "easy";
            break;
        case NORMAL:
            diffStr = "normal";
            break;
        case HARD:
            diffStr = "hard";
            break;
        default:
            diffStr = "error";
            break;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 3);
    int mapIndex = distr(gen);

    std::string filepath = "assets/levels/" + diffStr + "/" + diffStr + "_" + std::to_string(mapIndex) + ".json";

    return loadGridFromJson(filepath);
}