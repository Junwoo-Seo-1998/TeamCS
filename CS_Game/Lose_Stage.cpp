#include "Lose_Stage.hpp"
#include "CS_ObjectManager.hpp"
#include <sstream>
#include "CS_Input.hpp"
#include "CS_StageManager.hpp"
Lose_Stage::~Lose_Stage()
{
}

void Lose_Stage::Init()
{
    std::stringstream file;
    file << "OtherLevels/";
    CS_StageManager::GetGameData().menuFile = "Lose_stage";
    file << CS_StageManager::GetGameData().menuFile << ".json";
    CS_ObjectManager::LoadObjectFromFile(file.str().c_str());
}

void Lose_Stage::Update(float dt)
{
    if (CS_Input::IsPressed(InputButtons::Space))
    {
        CS_StageManager::GetGameData().menuFile = "FMOD_Logo_Stage";
        CS_StageManager::SetNextStage(CS_StageTypes::Menu_Stage);
    }
}

void Lose_Stage::Shutdown()
{
    CS_ObjectManager::DestroyAllObjects(false);
}
