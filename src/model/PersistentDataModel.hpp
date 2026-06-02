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

        PersistentDataModel();
        ~PersistentDataModel();

        void save(short difficulty, int score, const std::string& username);
        std::vector<PlayerScore> load();
};