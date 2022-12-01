#include "Credit_texture_Component.hpp"
#include "CS_Object.hpp"
Credit_texture_Component::Credit_texture_Component() : CS_Component(CS_ComponentTypes::Credit_texture_Component)
{
}

Credit_texture_Component::~Credit_texture_Component()
{
}

void Credit_texture_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}

void Credit_texture_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}

void Credit_texture_Component::Init()
{
}

void Credit_texture_Component::Update(float dt)
{
    m_Parent->transform.SetScale({ CS_Graphics::GetDisplayAreaSize().x, CS_Graphics::GetDisplayAreaSize().y });
}

CS_Component* Credit_texture_Component::Clone() const
{
    return new Credit_texture_Component;
}

void Credit_texture_Component::ShowGui()
{
}
