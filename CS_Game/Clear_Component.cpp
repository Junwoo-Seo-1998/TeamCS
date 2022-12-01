#include "Clear_Component.hpp"

Clear_Component::Clear_Component() : CS_Component(CS_ComponentTypes::Clear_Component)
{
}

Clear_Component::~Clear_Component()
{
}

void Clear_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}

void Clear_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}

void Clear_Component::Init()
{
}

void Clear_Component::Update(float dt)
{
}

CS_Component* Clear_Component::Clone() const
{
    return new Clear_Component;
}

void Clear_Component::ShowGui()
{
}
