#include "HP_Component.hpp"
#include "CS_Object.hpp"
#include "CS_ObjectManager.hpp"
#include "../Dependencies/imgui/imgui.h"

HP_Component::HP_Component() : CS_Component(CS_ComponentTypes::HP_Component)
{
}

void HP_Component::ReadFromFile(CS_JsonObject & jsonObject)
{
}

void HP_Component::WriteToFile(CS_JsonObject & jsonObject)
{
}

void HP_Component::Init()
{
	m_Parent->gfx.SetTextureHandle("Textures/Health.png");
        object_ptr = CS_ObjectManager::GetFirstObjectByType(CS_ArcheTypes::Player);
        if (object_ptr)
        {
            object_ptr->GetComponent(CS_ComponentTypes::Player_Component, Player_component);
            if (Player_component != nullptr)
            {
                last_width = block * Player_component->GetMaxHealth();
            }
        }
	m_Parent->transform.SetTranslation(center);
	m_Parent->gfx.SetDrawSpace(DrawSpace::Hud);
}

HP_Component::~HP_Component()
{
}

void HP_Component::Update(float dt)
{
	object_ptr = CS_ObjectManager::GetFirstObjectByType(CS_ArcheTypes::Player);
	if (object_ptr)
	{
		object_ptr->GetComponent(CS_ComponentTypes::Player_Component, Player_component);
		if (Player_component != nullptr)
		{
			currenthealth = Player_component->GetHealth();
			width = 100 * currenthealth;
			m_Parent->transform.SetScale({ width, height });

                        if (last_width != width)
                        {
                            m_Parent->transform.SetTranslation_x(m_Parent->transform.GetTranslation().x - (last_width - width) / 2);
                            last_width = width;
                        }
		}
	}
}

HP_Component * HP_Component::Clone() const
{
	return new HP_Component;
}

void HP_Component::ShowGui()
{
	if (ImGui::TreeNode("HP_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}
