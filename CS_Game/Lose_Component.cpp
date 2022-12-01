#include "Lose_Component.hpp"

Lose_Component::Lose_Component() : CS_Component(CS_ComponentTypes::Lose_Component)
{
}

Lose_Component::~Lose_Component()
{
}

void Lose_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}

void Lose_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}

void Lose_Component::Init()
{
}

void Lose_Component::Update(float dt)
{
}

CS_Component* Lose_Component::Clone() const
{
    return new Lose_Component;
}

void Lose_Component::ShowGui()
{
}
