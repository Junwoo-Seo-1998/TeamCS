#include "Flash_Component.hpp"
#include "CS_Object.hpp"
#include "CS_ObjectManager.hpp"
#include "../Dependencies/imgui/imgui.h"

Flash_Component::Flash_Component() : CS_Component(CS_ComponentTypes::Flash_Component)
{
}

void Flash_Component::ReadFromFile(CS_JsonObject & jsonObject)
{
}

void Flash_Component::WriteToFile(CS_JsonObject & jsonObject)
{
}

void Flash_Component::Init()
{
	timer = 0.f;
}

Flash_Component::~Flash_Component()
{
}

void Flash_Component::Update(float dt)
{
	timer += dt;
	if (timer >= lifetime)
		m_Parent->is_dead = true;
}

Flash_Component * Flash_Component::Clone() const
{
	return new Flash_Component;
}

void Flash_Component::ShowGui()
{
	if (ImGui::TreeNode("Flash_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}
