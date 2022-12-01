/**
 * @file Straight_Enemy_Component.cpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief Component for enemies moving straightforwards.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Straight_Enemy_Component.hpp"
#include "CS_Object.hpp"
#include "../Dependencies/imgui/imgui.h"
#include "CS_Camera.hpp"
#include "CS_StageManager.hpp"
#include "CS_Physics.hpp"
#include "CS_ObjectManager.hpp"

/**
 * @brief Construct a new Straight_Enemy_Component::Straight_Enemy_Component object
 * 
 */
Straight_Enemy_Component::Straight_Enemy_Component() : CS_Component(CS_ComponentTypes::Straight_Enemy_Component)
{
}
/**
 * @brief Read initialization data from the JSON file.
 * 
 * @param jsonObject The JSON file to read from.
 */
void Straight_Enemy_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}
/**
 * @brief Write data into the JSON file.
 * 
 * @param jsonObject The JSON file to write into.
 */
void Straight_Enemy_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}
/**
 * @brief Speed initialization.
 * 
 */
void Straight_Enemy_Component::Init()
{
    m_Parent->m_name = "Enemy";
	speed = -1000;
}
/**
 * @brief Destroy the Straight_Enemy_Component::Straight_Enemy_Component object
 * 
 */
Straight_Enemy_Component::~Straight_Enemy_Component()
{
}
/**
 * @brief Update its position, and kill itself if outside of screen.
 * 
 * @param dt Delta time.
 */
void Straight_Enemy_Component::Update(float dt)
{
	if (m_Parent->is_inside_screen_enemy())
		m_Parent->physics.setVelocity_X(--speed);
	if (m_Parent->is_outside_screen())
		m_Parent->is_dead = true;

	if (CS_Physics::IsThereCollidingWithName(m_Parent->my_id, "Player")
		|| CS_Physics::IsThereCollidingWithName(m_Parent->my_id, "Bullet"))
	{
		int sound_randomizer = rand() % 2;
		if (sound_randomizer == 0)
			CS_SoundManager::PlaySound(CS_SoundTypes::Explosion1);
		else
			CS_SoundManager::PlaySound(CS_SoundTypes::Explosion2);
		explosion = CS_ObjectManager::CreateObjectWithArcheType(CS_ArcheTypes::Explosion);
		explosion->gfx.SetTextureHandle(animation);
		explosion->gfx.SetAnimation(4, 1, 0.25f);
		explosion->transform.SetTranslation(m_Parent->transform.GetTranslation());
		explosion->transform.SetScale(m_Parent->transform.GetScale());
		m_Parent->is_dead = true;
	}
}
/**
 * @brief Make a clone of this component.
 * 
 * @return Straight_Enemy_Component* Clone of this component.
 */
Straight_Enemy_Component* Straight_Enemy_Component::Clone() const
{
	return new Straight_Enemy_Component;
}
/**
 * @brief For imgui button usage.
 * 
 */
void Straight_Enemy_Component::ShowGui()
{
	if (ImGui::TreeNode("Straight_Enemy_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}
