/**
 * @file Logo_Stage.cpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com)
 * @brief Stage to display logo.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Logo_Stage.hpp"
#include "CS_Input.hpp"
#include "CS_StageManager.hpp"
#include "CS_ObjectManager.hpp"
#include "CS_Object.hpp"
#include <sstream>
#include "CS_JsonManager.hpp"
#include "CS_ObjectManager.hpp"
/**
 * @brief Destroy the Logo_Stage::Logo_Stage object
 * 
 */
Logo_Stage::~Logo_Stage()
{
}
/**
 * @brief Initialize this stage.
 * 
 */
void Logo_Stage::Init()
{
    Logo_timer = 0;
    std::stringstream file;
    file << "OtherLevels/";
    file << "Logo_stage"<<".json";
    CS_ObjectManager::LoadObjectFromFile(file.str().c_str());
}
/**
 * @brief Update and display logo.
 * 
 * @param dt Delta time.
 */
void Logo_Stage::Update(float dt)
{
    Logo_timer += dt;
    bool time_over = Logo_timer > 4.0f;
    if(CS_Input::IsAnyPressed() || time_over)
    {
        CS_StageManager::SetNextStage(CS_StageTypes::FMOD_Logo_Stage);
        CS_Input::Rest();
    }

}
/**
 * @brief Shut down this stage.
 * 
 */
void Logo_Stage::Shutdown()
{
    CS_ObjectManager::DestroyAllObjects(false);
}
