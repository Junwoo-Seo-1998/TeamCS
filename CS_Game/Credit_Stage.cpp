#include "Credit_Stage.hpp"
#include "CS_StageTypes.hpp"
#include "CS_Input.hpp"
#include "CS_StageManager.hpp"
#include "CS_ObjectManager.hpp"
#include <sstream>
Credit_Stage::~Credit_Stage()
{
}

void Credit_Stage::Init()
{
    std::stringstream file;
    file << "OtherLevels/";
    CS_StageManager::GetGameData().menuFile = "Credit_stage";
    file << CS_StageManager::GetGameData().menuFile << ".json";
    CS_ObjectManager::LoadObjectFromFile(file.str().c_str());
}

void Credit_Stage::Update(float dt)
{
    if (CS_Input::IsPressed(InputButtons::Space))
    {
        CS_StageManager::GetGameData().menuFile = "Main_menu";
        CS_StageManager::SetNextStage(CS_StageTypes::Menu_Stage);
    }
}

void Credit_Stage::Shutdown()
{
    CS_ObjectManager::DestroyAllObjects(false);
}
