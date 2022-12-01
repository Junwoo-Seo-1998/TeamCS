#include "Goal_Component.hpp"
#include "CS_ObjectManager.hpp"
#include "CS_Physics.hpp"
#include "CS_StageManager.hpp"
#include "../Dependencies/imgui/imgui.h"

Goal_Component::Goal_Component() : CS_Component(CS_ComponentTypes::Goal_Component)
{
}

Goal_Component::~Goal_Component()
{
}

void Goal_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}

void Goal_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}

void Goal_Component::Init()
{
    m_Parent->transform.SetScale({ 30, 1000 });
}

void Goal_Component::Update(float dt)
{
    CS_Object* player_ptr = CS_ObjectManager::GetFirstObjectByType(CS_ArcheTypes::Player);
    if (player_ptr == nullptr)
        return;
    if(CS_Physics::IsThereCollidingWithName(m_Parent->my_id, "Player"))
        CS_StageManager::SetNextStage(CS_StageTypes::Clear_Stage);
}

CS_Component* Goal_Component::Clone() const
{
    return new Goal_Component;
}

void Goal_Component::ShowGui()
{
    if (ImGui::TreeNode("Goal_Component"))
    {
        is_Dead = ImGui::Button("remove");
        ImGui::TreePop();
    }
}
