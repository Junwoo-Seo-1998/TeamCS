#include "Clear_texture_Component.hpp"
#include "CS_Object.hpp"
Clear_texture_Component::Clear_texture_Component() : CS_Component(CS_ComponentTypes::Clear_texture_Component)
{
}

Clear_texture_Component::~Clear_texture_Component()
{
}

void Clear_texture_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}

void Clear_texture_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}

void Clear_texture_Component::Init()
{
}

void Clear_texture_Component::Update(float dt)
{
    m_Parent->transform.SetScale({ CS_Graphics::GetDisplayAreaSize().x , CS_Graphics::GetDisplayAreaSize().y });
}

CS_Component* Clear_texture_Component::Clone() const
{
    return new Clear_texture_Component;
}

void Clear_texture_Component::ShowGui()
{
}
