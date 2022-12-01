#include "Lose_texture_Component.hpp"
#include "CS_Graphics.hpp"
#include "CS_Object.hpp"
Lose_texture_Component::Lose_texture_Component() : CS_Component(CS_ComponentTypes::Lose_texture_Component)
{
}

Lose_texture_Component::~Lose_texture_Component()
{
}

void Lose_texture_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}

void Lose_texture_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}

void Lose_texture_Component::Init()
{
}

void Lose_texture_Component::Update(float dt)
{
    m_Parent->transform.SetScale({ CS_Graphics::GetDisplayAreaSize().x , CS_Graphics::GetDisplayAreaSize().y });
}

CS_Component* Lose_texture_Component::Clone() const
{
    return new Lose_texture_Component;
}

void Lose_texture_Component::ShowGui()
{
}
