/**
 * @file GamePlay_Stage.cpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief The gameplay stage management.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "GamePlay_Stage.hpp"
#include "CS_Object.hpp"
#include "CS_ObjectManager.hpp"
#include "CS_StageManager.hpp"
#include "Player_Component.hpp"
#include "Enemy_Component.hpp"
#include "Waving_Enemy_Component.hpp"
#include "CS_Input.hpp"
#include <sstream>
#include "CS_JsonManager.hpp"
#include "CS_GUI.hpp"
#include <iostream>
/**
 * @brief Destroy the GamePlay_Stage::GamePlay_Stage object
 * 
 */
GamePlay_Stage::~GamePlay_Stage()
{
    
}
/**
 * @brief Initialize the game level based on the level JSON file.
 * 
 */
void GamePlay_Stage::Init()
{
    std::cout << "test\n";
    std::stringstream file;
    file << "GamePlayLevels/";
    file <<"Level"<<CS_StageManager::GetGameData().level<<".json";
    CS_ObjectManager::LoadObjectFromFile(file.str().c_str());
    CS_SoundManager::SetSoundMode(CS_SoundTypes::BGM, CS_SoundMode::Loop_Normal);
    CS_SoundManager::PlaySound(CS_SoundTypes::BGM);
    
}
/**
 * @brief Update based on the inputs.
 * 
 * @param dt Delta time.
 */
void GamePlay_Stage::Update(float dt)
{
	camera.SetVelocity({ 50.f,0.f });
    if (CS_Input::IsTriggered(InputButtons::R))
    {
        CS_StageManager::Restart();
    }
    if(CS_Input::IsTriggered(InputButtons::Escape))
    {
            
	    CS_StageManager::PauseAndSetNextStage(CS_StageTypes::Menu_Stage, false);
		CS_SoundManager::GetChannel(CS_SoundTypes::BGM)->setPaused(true);
	    //CS_Input::Rest();
    }
}
/**
 * @brief Shut down current level.
 * 
 */
void GamePlay_Stage::Shutdown()
{
    camera.SetCenter_x(0);
    CS_ObjectManager::DestroyAllObjects(false);
    CS_SoundManager::StopSound(CS_SoundTypes::BGM);
}



