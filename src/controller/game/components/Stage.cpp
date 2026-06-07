#include "Stage.hpp"

struct GridPosition {
    int row, column;
    bool operator<(const GridPosition& other) const {
        return row == other.row ? column < other.column : row < other.row;
    }
    bool operator==(const GridPosition& other) const {
        return row == other.row && column == other.column;
    }
};

Stage::Stage(){};

Stage::~Stage(){};

std::vector<Vector2> Stage::generatePath() {
    if (grid.empty() || grid[0].empty()) return {};

    int rows = grid.size();
    int columns = grid[0].size();
    GridPosition startPosition = {-1, -1};
    GridPosition endPosition = {-1, -1};

    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (grid[row][column] == 3) startPosition = {row, column};
            if (grid[row][column] == 4) endPosition = {row, column};
        }
    }

    if (startPosition.row == -1 || endPosition.row == -1) return {}; // Invalid map

    std::queue<GridPosition> queue;
    std::map<GridPosition, GridPosition> parentMap;
    std::map<GridPosition, bool> visited;

    queue.push(startPosition);
    visited[startPosition] = true;

    int directionRow[] = {-1, 1, 0, 0};
    int directionColumn[] = {0, 0, -1, 1};

    bool foundEnd = false;

    while (!queue.empty()) {
        GridPosition currentPosition = queue.front();
        queue.pop();

        if (currentPosition == endPosition) {
            foundEnd = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nextRow = currentPosition.row + directionRow[i];
            int nextColumn = currentPosition.column + directionColumn[i];

            if (nextRow >= 0 && nextRow < rows && nextColumn >= 0 && nextColumn < columns) {
                int tileType = grid[nextRow][nextColumn];
                GridPosition nextPosition = {nextRow, nextColumn};

                if ((tileType == 2 || tileType == 4) && !visited[nextPosition]) {
                    visited[nextPosition] = true;
                    parentMap[nextPosition] = currentPosition;
                    queue.push(nextPosition);
                }
            }
        }
    }

    std::vector<Vector2> waypoints;
    if (foundEnd) {
        GridPosition currentPosition = endPosition;
        while (!(currentPosition == startPosition)) {
            waypoints.push_back(Vector2{ static_cast<float>(currentPosition.column), static_cast<float>(currentPosition.row) });
            currentPosition = parentMap[currentPosition];
        }
        waypoints.push_back(Vector2{ static_cast<float>(startPosition.column), static_cast<float>(startPosition.row) });
        
        std::reverse(waypoints.begin(), waypoints.end());
    }

    return waypoints;
}

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