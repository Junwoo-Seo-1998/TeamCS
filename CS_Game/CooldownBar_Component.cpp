/**
 * @file CooldownBar_Component.cpp
 * @author Sungmin Moon
 * @email elphior0\@gmail.com
 * @brief Cooldown bar management.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "CooldownBar_Component.hpp"
#include "CS_Object.hpp"
#include "CS_ObjectManager.hpp"
#include "../Dependencies/imgui/imgui.h"
#include "Gun_Component.hpp"
#include <iostream>
/**
 * @brief Construct a new CooldownBar_Component::CooldownBar_Component object
 * 
 */
CooldownBar_Component::CooldownBar_Component() : CS_Component(CS_ComponentTypes::CooldownBar_Component)
{
}
/**
 * @brief Read initialization data from JSON file.
 * 
 * @param jsonObject The JSON file to read from.
 */
void CooldownBar_Component::ReadFromFile(CS_JsonObject & jsonObject)
{
}
/**
 * @brief Write data into the JSON file.
 * 
 * @param jsonObject The JSON file to write into.
 */
void CooldownBar_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}
/**
 * @brief Initializing translation and drawing space.
 * 
 */
void CooldownBar_Component::Init()
{ 
    m_Parent->transform.SetTranslation(center);
    m_Parent->gfx.SetDrawSpace(DrawSpace::Hud);
    width = full_bar_size.x;
    height = full_bar_size.y;

}
/**
 * @brief Destroy the CooldownBar_Component::CooldownBar_Component object
 * 
 */
CooldownBar_Component::~CooldownBar_Component()
{
}
/**
 * @brief Update cooldown bar based on the gun's cooldowns.
 * 
 * @param dt Delta time.
 */
void CooldownBar_Component::Update(float dt)
{
    Gun_object_ptr = CS_ObjectManager::GetFirstObjectByType(CS_ArcheTypes::Player);
    if (Gun_object_ptr)
    {
        Gun_object_ptr->GetComponent(CS_ComponentTypes::Gun_Component, Gun_component);
        if (Gun_component != nullptr)
        {
            if (Gun_component->GetStatus() == Ready)
            {
                if(m_Parent->transform.GetTranslation().x != center.x)
                {
                    m_Parent->transform.SetTranslation(center);
                    width = full_bar_size.x;
                }
                m_Parent->gfx.SetTextureHandle(ready);
                m_Parent->transform.SetScale(full_bar_size);
            }
            else
            {
                last_width = width;
                m_Parent->gfx.SetTextureHandle(notready);
                width = ((full_bar_size.x / 5.f) * Gun_component->GetCooltime());
                m_Parent->transform.SetScale({ width, height });
                m_Parent->transform.SetTranslation_x(m_Parent->transform.GetTranslation_x()- (last_width - width)/2);
            }
        }
    }
   
    
}
/**
 * @brief Make a clone of this component.
 * 
 * @return CooldownBar_Component* Clone of this component.
 */
CooldownBar_Component * CooldownBar_Component::Clone() const
{
	return new CooldownBar_Component;
}
/**
 * @brief For imgui button usage.
 * 
 */
void CooldownBar_Component::ShowGui()
{
	if (ImGui::TreeNode("CooldownBar_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}
