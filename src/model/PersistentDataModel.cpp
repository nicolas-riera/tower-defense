#include "PersistentDataModel.hpp"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <json.hpp>

using json = nlohmann::json;
namespace fs = std::filesystem;

PersistentDataModel::PersistentDataModel(){};
PersistentDataModel::~PersistentDataModel(){};

void PersistentDataModel::save(short difficulty, int score, const std::string& username) 
{
    std::string directory = "gamedata";
    std::string filepath = directory + "/scores.json";

    if (!fs::exists(directory)) {
        fs::create_directories(directory);
    }

    std::vector<PlayerScore> currentScores = load();
    currentScores.push_back({difficulty, score, username});

    json jArray = json::array();
    for (const auto& s : currentScores) {
        json jItem;
        jItem["difficulty"] = s.difficulty;
        jItem["score"] = s.score;
        jItem["username"] = s.username;
        jArray.push_back(jItem);
    }

    std::ofstream file(filepath);
    if (file.is_open()) {
        file << jArray.dump(4);
        file.close();
    }
};

std::vector<PersistentDataModel::PlayerScore> PersistentDataModel::load() 
{
    std::vector<PlayerScore> scores;
    std::string filepath = "gamedata/scores.json";

    if (!fs::exists(filepath)) {
        return scores;
    }

    std::ifstream file(filepath);
    if (!file.is_open()) {
        return scores;
    }

    try {
        json jArray;
        file >> jArray;
        file.close();

        if (jArray.is_array()) {
            for (const auto& jItem : jArray) {
                if (jItem.contains("difficulty") && jItem.contains("score") && jItem.contains("username")) {
                    PlayerScore s;
                    s.difficulty = jItem["difficulty"].get<short>();
                    s.score = jItem["score"].get<int>();
                    s.username = jItem["username"].get<std::string>();
                    scores.push_back(s);
                }
            }
        }
    } 
    catch (...) {
        return scores;
    }

    return scores;
};