#pragma once
#include <vector>
#include <string>

class PersistentDataModel 
{
    private:
        short difficulty; // 0 for easy, 1 for normal, 2 for hard
        int score;
        std::string username;

    public:
        struct PlayerScore {
            short difficulty;
            int score;
            std::string username;
        };

        struct Config {
            bool music = true;
            bool sfx = true;
        };

        PersistentDataModel();
        ~PersistentDataModel();

        void saveScore(short difficulty, int score, const std::string& username);
        std::vector<PlayerScore> loadScores();

        void saveConfig(const Config& config);
        Config loadConfig();       

};