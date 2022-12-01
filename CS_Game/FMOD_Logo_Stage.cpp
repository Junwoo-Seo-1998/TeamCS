#include "FMOD_Logo_Stage.hpp"
#include <sstream>
#include "CS_ObjectManager.hpp"
#include "CS_StageManager.hpp"
#include "CS_Input.hpp"

FMOD_Logo_Stage::~FMOD_Logo_Stage()
{
}

void FMOD_Logo_Stage::Init()
{
    Logo_timer = 0;
    std::stringstream file;
    file << "OtherLevels/";
    file << "FMOD_Logo_stage" << ".json";
    CS_ObjectManager::LoadObjectFromFile(file.str().c_str());
}

void FMOD_Logo_Stage::Update(float dt)
{
    Logo_timer += dt;
    bool time_over = Logo_timer > 2.0f;
    if(time_over)
    {
        CS_StageManager::GetGameData().menuFile = "Main_menu";
        CS_StageManager::SetNextStage(CS_StageTypes::Menu_Stage);
        CS_Input::Rest();
    }
    if (CS_Input::IsAnyPressed())
    {
        CS_StageManager::GetGameData().menuFile = "Main_menu";
        CS_StageManager::SetNextStage(CS_StageTypes::Menu_Stage);
        CS_Input::Rest();
    }
}

void FMOD_Logo_Stage::Shutdown()
{
    CS_ObjectManager::DestroyAllObjects(false);
}
