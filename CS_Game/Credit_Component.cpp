#include "Credit_Component.hpp"
#include "CS_SoundTypes.hpp"
#include "CS_SoundManager.hpp"
#include "CS_StageTypes.hpp"
#include "CS_Input.hpp"
#include "CS_Graphics.hpp"
#include "CS_Object.hpp"
#include "CS_StageManager.hpp"
Credit_Component::Credit_Component() : CS_Component(CS_ComponentTypes::Credit_Component)
{
}


Credit_Component::~Credit_Component()
{
}

void Credit_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}

void Credit_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}

void Credit_Component::Init()
{
}

void Credit_Component::Update(float dt)
{
    m_Parent->transform.SetTranslation({ 0 * CS_Graphics::GetDisplayAreaSize().x / 2.f, 0.4 * CS_Graphics::GetDisplayAreaSize().y / 2.f });

    m_Parent->editMouseSelectAABB.Update();
    if (m_Parent->editMouseSelectAABB.IsMouseIn() && CS_Input::IsPressed(InputButtons::Mouse_Left))
    {
        CS_StageManager::SetNextStage(CS_StageTypes::Credit_Stage);
        CS_SoundManager::PlaySound(CS_SoundTypes::Select);
    }
}

CS_Component* Credit_Component::Clone() const
{
    return new Credit_Component;
}

void Credit_Component::ShowGui()
{
}
