#include "Explosion_Component.hpp"
#include "Flash_Component.hpp"
#include "CS_Object.hpp"
#include "CS_ObjectManager.hpp"
#include "../Dependencies/imgui/imgui.h"

Explosion_Component::Explosion_Component() : CS_Component(CS_ComponentTypes::Explosion_Component)
{
}

void Explosion_Component::ReadFromFile(CS_JsonObject & jsonObject)
{
}

void Explosion_Component::WriteToFile(CS_JsonObject & jsonObject)
{
}

void Explosion_Component::Init()
{
	timer = 0.f;
}

Explosion_Component::~Explosion_Component()
{
}

void Explosion_Component::Update(float dt)
{
	timer += dt;
	if (timer >= lifetime)
		m_Parent->is_dead = true;
}

Explosion_Component * Explosion_Component::Clone() const
{
	return new Explosion_Component;
}

void Explosion_Component::ShowGui()
{
	if (ImGui::TreeNode("Explosion_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}
