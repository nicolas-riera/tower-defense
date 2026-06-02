#include "SoundManager.hpp"
#include <iostream>

SoundManager::SoundManager()
{
    InitAudioDevice();
    this->isSfxOn = true;
    this->isMusicOn = true;
    this->currentMusic = nullptr;
    this->musicList.push_back(LoadMusicStream("./assets/sound/ghouls_n_ghosts_high_score.mp3")); // Music from Tim Follin
    this->sfxList.push_back(LoadSound("./assets/sound/sfx-clic.wav"));                           // SFX from Robin Plokhaar
    this->sfxList.push_back(LoadSound("./assets/sound/sfx-hit.wav"));                            // SFX from Robin Plokhaar
    this->sfxList.push_back(LoadSound("./assets/sound/sfx-invader.wav"));                        // SFX from Robin Plokhaar
    this->sfxList.push_back(LoadSound("./assets/sound/sfx-tower.wav"));                          // SFX from Robin Plokhaar
}

SoundManager::~SoundManager()
{
    for (const Music music : this->musicList)
    {
        UnloadMusicStream(music);
    };
    for (const Sound sfx : this->sfxList)
    {
        UnloadSound(sfx);
    };
    CloseAudioDevice();
}

bool SoundManager::getIsSfxOn()
{
    return this->isSfxOn;
}

void SoundManager::setIsSfxOn(bool isOn)
{
    this->isSfxOn = isOn;
}

bool SoundManager::getIsMusicOn()
{
    return this->isMusicOn;
}

void SoundManager::setIsMusicOn(bool isOn)
{
    this->isMusicOn = isOn;
}

void SoundManager::playMusic(int index)
{
    if (!this->isMusicOn)
        return;
    if (index >= 0 && static_cast<size_t>(index) < this->musicList.size())
    {
        if (this->currentMusic == &musicList[index])
        {
            return;
        }
        if (this->currentMusic != nullptr)
        {
            StopMusicStream(*currentMusic);
        }
        this->currentMusic = &musicList[index];
        this->currentMusic->looping = true;
        PlayMusicStream(*currentMusic);
    }
}

void SoundManager::playSfx(int index)
{
    if (!this->isSfxOn)
        return;

    if (index >= 0 && static_cast<size_t>(index) < this->sfxList.size())
    {
        PlaySound(sfxList[index]);
    }
}

void SoundManager::update()
{
    if (this->isMusicOn && this->currentMusic != nullptr)
    {
        UpdateMusicStream(*currentMusic);
    }
}