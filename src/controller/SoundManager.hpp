#include <vector>
#include <string>
#include "raylib.h"

class SoundManager {
    private:
        bool isSfxOn;
        bool isMusicOn;
        Music* currentMusic;
        std::vector<Music> musicList;
        std::vector<Sound> sfxList;
    public: 
        SoundManager();
        ~SoundManager();
        bool getIsSfxOn();
        void setIsSfxOn(bool isOn);
        bool getIsMusicOn();
        void setIsMusicOn(bool isOn);
        void playMusic(int index);
        void playSfx(int index);
        void update();
};