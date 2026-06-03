#include "PersistentDataModel.hpp"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <picojson.h>

namespace fs = std::filesystem;

PersistentDataModel::PersistentDataModel(){};
PersistentDataModel::~PersistentDataModel(){};

// Scores

void PersistentDataModel::saveScore(short difficulty, int score, const std::string& username) 
{
    std::string directory = "gamedata";
    std::string filepath = directory + "/scores.json";

    if (!fs::exists(directory)) {
        fs::create_directories(directory);
    }

    std::vector<PlayerScore> currentScores = loadScores();
    currentScores.push_back({difficulty, score, username});

    picojson::array jArray;
    for (const auto& s : currentScores) {
        picojson::object jItem;
        jItem["difficulty"] = picojson::value(static_cast<double>(s.difficulty));
        jItem["score"] = picojson::value(static_cast<double>(s.score));
        jItem["username"] = picojson::value(s.username);
        jArray.push_back(picojson::value(jItem));
    }

    std::ofstream file(filepath);
    if (file.is_open()) {
        file << picojson::value(jArray).serialize(true);
    }
}

std::vector<PersistentDataModel::PlayerScore> PersistentDataModel::loadScores() 
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

    picojson::value v;
    std::string err = picojson::parse(v, file);
    
    if (!err.empty()) {
        return scores;
    }

    if (v.is<picojson::array>()) {
        const picojson::array& jArray = v.get<picojson::array>();
        for (const auto& jItemValue : jArray) {
            if (jItemValue.is<picojson::object>()) {
                const picojson::object& jItem = jItemValue.get<picojson::object>();
                
                if (jItem.count("difficulty") && jItem.count("score") && jItem.count("username")) {
                    PlayerScore s;
                    s.difficulty = static_cast<short>(jItem.at("difficulty").get<double>());
                    s.score = static_cast<int>(jItem.at("score").get<double>());
                    s.username = jItem.at("username").get<std::string>();
                    scores.push_back(s);
                }
            }
        }
    }

    return scores;
}

// Config

void PersistentDataModel::saveConfig(const Config& config)
{
    std::string directory = "gamedata";
    std::string filepath = directory + "/config.json";

    if (!fs::exists(directory)) {
        fs::create_directories(directory);
    }

    picojson::object jItem;
    jItem["music"] = picojson::value(config.music);
    jItem["sfx"] = picojson::value(config.sfx);

    std::ofstream file(filepath);
    if (file.is_open()) {
        file << picojson::value(jItem).serialize(true);
    }
}

PersistentDataModel::Config PersistentDataModel::loadConfig()
{
    Config config;
    std::string filepath = "gamedata/config.json";

    if (!fs::exists(filepath)) {
        return config;
    }

    std::ifstream file(filepath);
    if (!file.is_open()) {
        return config;
    }

    picojson::value v;
    std::string err = picojson::parse(v, file);
    if (!err.empty()) {
        return config;
    }

    if (v.is<picojson::object>()) {
        const picojson::object& jItem = v.get<picojson::object>();
        if (jItem.count("music")) {
            config.music = jItem.at("music").get<bool>();
        }
        if (jItem.count("sfx")) {
            config.sfx = jItem.at("sfx").get<bool>();
        }
    }

    return config;
}