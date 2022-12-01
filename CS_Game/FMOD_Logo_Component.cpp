#include "FMOD_Logo_Component.hpp"
#include "CS_Graphics.hpp"
#include "CS_Object.hpp"
FMOD_Logo_Component::FMOD_Logo_Component() : CS_Component(CS_ComponentTypes::FMOD_Logo_Component)
{
}

FMOD_Logo_Component::~FMOD_Logo_Component()
{
}

void FMOD_Logo_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}

void FMOD_Logo_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}

void FMOD_Logo_Component::Init()
{
    m_Parent->transform.SetScale({ CS_Graphics::GetDisplayAreaSize().x , CS_Graphics::GetDisplayAreaSize().y });
}

void FMOD_Logo_Component::Update(float dt)
{
    m_Parent->transform.SetScale({ CS_Graphics::GetDisplayAreaSize().x , CS_Graphics::GetDisplayAreaSize().y });
}

CS_Component* FMOD_Logo_Component::Clone() const
{
    return new FMOD_Logo_Component;
}

void FMOD_Logo_Component::ShowGui()
{
}
