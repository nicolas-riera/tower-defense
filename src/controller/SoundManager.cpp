#include "SoundManager.hpp"
#include <iostream>

SoundManager::SoundManager(){
    InitAudioDevice();
    this->isSfxOn = true;
    this->isMusicOn = true;
    this->musicList.push_back(LoadSound("./assets/sound/ghouls_n_ghosts_high_score.mp3")); // Music from Tim Follin
    this->sfxList.push_back(LoadSound("./assets/sound/sfx-clic.wav")); // SFX from Robin Plokhaar
    this->sfxList.push_back(LoadSound("./assets/sound/sfx-hit.wav")); // SFX from Robin Plokhaar
    this->sfxList.push_back(LoadSound("./assets/sound/sfx-invader.wav")); // SFX from Robin Plokhaar
    this->sfxList.push_back(LoadSound("./assets/sound/sfx-tower.wav")); // SFX from Robin Plokhaar
};

SoundManager::~SoundManager(){
    for (const Sound music : this->musicList){
        UnloadSound(music);
    };
    for (const Sound sfx : this->sfxList){
        UnloadSound(sfx);
    };
    CloseAudioDevice();
};

bool SoundManager::getIsSfxOn(){
    return this->isSfxOn;
};
void SoundManager::setIsSfxOn(bool isOn){
    this->isSfxOn = isOn;
};
bool SoundManager::getIsMusicOn(){
    return this->isMusicOn;
};
void SoundManager::setIsMusicOn(bool isOn){
    this->isMusicOn = isOn;
};
void SoundManager::playMusic(int index){
    if(index < this->musicList.size()){
        PlaySound(musicList[index]);
    };
};
void SoundManager::playSfx(int index){
    if(index < this->sfxList.size()){
        PlaySound(sfxList[index]);
    };
};