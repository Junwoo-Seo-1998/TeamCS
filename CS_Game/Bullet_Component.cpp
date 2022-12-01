/**
 * @file Bullet_Component.cpp
 * @author Sungmin Moon
 * @email elphior0\@gmail.com)
 * @brief Bullet controls.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Bullet_Component.hpp"
#include "Player_Component.hpp"
#include "CS_Object.hpp"
#include "SphereCollider_Component.hpp"
#include "CS_Input.hpp"
#include "CS_ObjectManager.hpp"
#include "../Dependencies/imgui/imgui.h"
/**
 * @brief Construct a new Bullet_Component::Bullet_Component object
 * 
 */
Bullet_Component::Bullet_Component() :CS_Component(CS_ComponentTypes::Bullet_Component)
{

}
/**
 * @brief Read initialization data from JSON file.
 * 
 * @param jsonObject The JSON file to read from.
 */
void Bullet_Component::ReadFromFile(CS_JsonObject & jsonObject)
{
}
/**
 * @brief Write data into JSON file.
 * 
 * @param jsonObject The JSON file to write into.
 */
void Bullet_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}
/**
 * @brief Texture and timer initialization.
 * 
 */
void Bullet_Component::Init()
{
        m_Parent->m_name = "Bullet";
	std::string texture = "Textures/Bullet_Friendly.png";
	auto t = m_Parent->gfx.SetTextureHandle(texture);
	time = 0;
}
/**
 * @brief Destroy the Bullet_Component::Bullet_Component object
 * 
 */
Bullet_Component::~Bullet_Component()
{
}
/**
 * @brief Up
 * 
 * @param dt 
 */
void Bullet_Component::Update(float dt)
{
	float duration = 3.f;
	time += dt;
	if (time >= duration)
		m_Parent->is_dead = true;
    if (CS_Physics::IsThereCollidingWithName(m_Parent->my_id, "Enemy"))
        m_Parent->is_dead = true;
    if(!m_Parent->is_inside_screen_enemy())
    {
        m_Parent->is_dead = true;
    }
}
/**
 * @brief Make a clone of this component.
 * 
 * @return Bullet_Component* Clone of this component.
 */
Bullet_Component * Bullet_Component::Clone() const
{
	return new Bullet_Component;
}
/**
 * @brief For imgui button usage.
 * 
 */
void Bullet_Component::ShowGui()
{
	if (ImGui::TreeNode("Bullet_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}
