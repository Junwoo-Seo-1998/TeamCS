/**
 * @file Waving_Tracing_Enemy_Component.cpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief Component for waving, tracing enemy.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Waving_Tracing_Enemy_Component.hpp"
#include "CS_Object.hpp"
#include "CS_ObjectManager.hpp"
#include <iostream>
#include "../Dependencies/imgui/imgui.h"
#include "CS_Physics.hpp"

/**
 * @brief Construct a new Waving_Tracing_Enemy_Component::Waving_Tracing_Enemy_Component object
 * 
 */
Waving_Tracing_Enemy_Component::Waving_Tracing_Enemy_Component() : CS_Component(CS_ComponentTypes::Waving_Tracing_Enemy_Component)
{
}
/**
 * @brief Destroy the Waving_Tracing_Enemy_Component::Waving_Tracing_Enemy_Component object
 * 
 */
Waving_Tracing_Enemy_Component::~Waving_Tracing_Enemy_Component()
{
}
/**
 * @brief Read initialization data from the JSON file.
 * 
 * @param jsonObject The JSON file to read from.
 */
void Waving_Tracing_Enemy_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}
/**
 * @brief Write data into the JSON file.
 * 
 * @param jsonObject The JSON file to write into.
 */
void Waving_Tracing_Enemy_Component::WriteToFile(CS_JsonObject & jsonObject)
{
}
/**
 * @brief Time, amplitude, and speed initialization.
 * 
 */
void Waving_Tracing_Enemy_Component::Init()
{
        m_Parent->m_name = "Enemy";
	time = 0;
	amplitude = 100;
	speed = 100;
	rotation = 0;
}
/**
 * @brief Update the movement, and kill itself if it gets out of the screen range.
 * 
 * @param dt 
 */
void Waving_Tracing_Enemy_Component::Update(float dt)
{
	rotation += dt;
	m_Parent->transform.SetRotation(10.f * rotation);
    if (m_Parent->is_inside_screen_enemy())
        Waving_Tracing_movement(dt);
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
 * @return CS_Component* Clone of this component.
 */
CS_Component* Waving_Tracing_Enemy_Component::Clone() const
{
	return new Waving_Tracing_Enemy_Component;
}
/**
 * @brief For imgui button usage.
 * 
 */
void Waving_Tracing_Enemy_Component::ShowGui()
{
	if (ImGui::TreeNode("Waving_Tracing_Enemy_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}
/**
 * @brief Movement calculation based on time.
 * 
 * @param dt Delta time.
 */
void Waving_Tracing_Enemy_Component::Waving_Tracing_movement(float dt)
{
	time += dt * 1.f;
	if (time > 360)
	{
		time = 0;
	}
	float current_y = m_Parent->transform.GetTranslation().y;
	float check = glm::sin(glm::radians(time));
	float waved_y = 800 * glm::sin(time * 5);
	
        CS_Object* player_ptr = CS_ObjectManager::GetFirstObjectByType(CS_ArcheTypes::Player);
		if (player_ptr != nullptr)
		{
			float d = glm::distance(player_ptr->transform.GetTranslation(), { m_Parent->transform.GetTranslation() });
			if (d)
			{
				trace_x = (((player_ptr->transform.GetTranslation().x) - (m_Parent->transform.GetTranslation().x)) / d * speed);
				trace_y = (((player_ptr->transform.GetTranslation().y) - (m_Parent->transform.GetTranslation().y)) / d * speed);
				m_Parent->physics.setVelocity({ trace_x, trace_y + waved_y });
			}
			else
			{
				m_Parent->physics.setVelocity({ 0, 0 });
			}
		}
}
