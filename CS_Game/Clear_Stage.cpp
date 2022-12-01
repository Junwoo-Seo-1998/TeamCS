#include "Clear_Stage.hpp"
#include "CS_ObjectManager.hpp"
#include <sstream>
#include "CS_StageManager.hpp"
#include "CS_Input.hpp"
Clear_Stage::~Clear_Stage()
{
}

void Clear_Stage::Init()
{
    std::stringstream file;
    file << "OtherLevels/";
    CS_StageManager::GetGameData().menuFile = "Clear_stage";
    file << CS_StageManager::GetGameData().menuFile << ".json";
    CS_ObjectManager::LoadObjectFromFile(file.str().c_str());
}

void Clear_Stage::Update(float dt)
{
    if (CS_Input::IsPressed(InputButtons::Space))
    {
        CS_StageManager::GetGameData().menuFile = "Main_menu";
        CS_StageManager::SetNextStage(CS_StageTypes::Menu_Stage);
    }
}

void Clear_Stage::Shutdown()
{
    CS_ObjectManager::DestroyAllObjects(false);
}
