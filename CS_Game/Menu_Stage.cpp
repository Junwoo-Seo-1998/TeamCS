/**
 * @file Menu_Stage.cpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief Level to display main menu.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Menu_Stage.hpp"
#include "CS_StageManager.hpp"
#include "CS_Input.hpp"
#include "CS_ObjectManager.hpp"
#include "CS_JsonManager.hpp"
#include "CS_SoundManager.hpp"

/**
 * @brief Destroy the Menu_Stage::Menu_Stage object
 * 
 */
Menu_Stage::~Menu_Stage()
{
}
/**
 * @brief Initialize this level based on the JSON file.
 * 
 */
void Menu_Stage::Init()
{
    std::stringstream file;
    file << "OtherLevels/";
    file << CS_StageManager::GetGameData().menuFile <<".json";
    CS_ObjectManager::LoadObjectFromFile(file.str().c_str());
    press_check = false;
}
/**
 * @brief Get inputs and update this level.
 * 
 * @param dt Delta time.
 */
void Menu_Stage::Update(float dt)
{
   
    if (CS_Input::IsRepeating(InputButtons::P))
    {
        CS_StageManager::SetNextStage(CS_StageTypes::Edit_Stage);
	        CS_Input::Rest();
    }
   
    if (CS_Input::IsPressed(InputButtons::Escape)&&press_check)
    {
    	CS_StageManager::Resume();
        press_check = false;
		CS_SoundManager::GetChannel(CS_SoundTypes::BGM)->setPaused(false);
    }
    if(!press_check)
        press_check = CS_Input::IsReleased(InputButtons::Escape);

}
/**
 * @brief Shut down this level.
 * 
 */
void Menu_Stage::Shutdown()
{
    CS_ObjectManager::DestroyAllObjects(false);
}
