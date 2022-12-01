/**
 * @file CS_AddSounds.cpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief Add sound assets.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "CS_AddSounds.hpp" 
#include "CS_SoundTypes.hpp" 
#include "CS_SoundManager.hpp" 
void CS_AddSounds(void) {  
CS_SoundManager::RegisterSound(CS_SoundTypes::Activate, "Sounds//Activate.mp3"); 
CS_SoundManager::RegisterSound(CS_SoundTypes::Back, "Sounds//Back.mp3"); 
CS_SoundManager::RegisterSound(CS_SoundTypes::BGM, "Sounds//BGM.mp3"); 
CS_SoundManager::RegisterSound(CS_SoundTypes::Deactivate, "Sounds//Deactivate.mp3"); 
CS_SoundManager::RegisterSound(CS_SoundTypes::Explosion1, "Sounds//Explosion1.mp3"); 
CS_SoundManager::RegisterSound(CS_SoundTypes::Explosion2, "Sounds//Explosion2.mp3"); 
CS_SoundManager::RegisterSound(CS_SoundTypes::Gatling, "Sounds//Gatling.mp3"); 
CS_SoundManager::RegisterSound(CS_SoundTypes::Pistol, "Sounds//Pistol.mp3"); 
CS_SoundManager::RegisterSound(CS_SoundTypes::Select, "Sounds//Select.mp3"); 
CS_SoundManager::RegisterSound(CS_SoundTypes::Shotgun, "Sounds//Shotgun.mp3"); 
} 
