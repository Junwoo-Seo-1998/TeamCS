/**
 * @file Enemy_Component.cpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief For basic enemies tracing the player.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Enemy_Component.hpp"
#include "CS_Object.hpp"
#include "CS_ObjectManager.hpp"
#include "CS_Physics.hpp"
#include "../Dependencies/imgui/imgui.h"
/**
 * @brief Construct a new Enemy_Component::Enemy_Component object
 * 
 */
Enemy_Component::Enemy_Component() : CS_Component(CS_ComponentTypes::Enemy_Component)
{
}
/**
 * @brief Read initialization data from the JSON file.
 * 
 * @param jsonObject The JSON file to read from.
 */
void Enemy_Component::ReadFromFile(CS_JsonObject & jsonObject)
{
}
/**
 * @brief Write data into the JSON file.
 * 
 * @param jsonObject The JSON file to write into.
 */
void Enemy_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}
/**
 * @brief Speed initialization.
 * 
 */
void Enemy_Component::Init()
{
    m_Parent->m_name = "Enemy";
	speed = 200;
	rotation = 0.f;
}
/**
 * @brief Destroy the Enemy_Component::Enemy_Component object
 * 
 */
Enemy_Component::~Enemy_Component()
{
}
/**
 * @brief Keep tracing the player, and destroy itself
 * 		  when it gets out of the screen.
 * 
 * @param dt Delta time.
 */
void Enemy_Component::Update(float dt)
{
	rotation += dt;
	m_Parent->transform.SetRotation(10.f * rotation);
    if (m_Parent->is_inside_screen_enemy())
        trace_player();

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
 * @return Enemy_Component* Clone of this component.
 */
Enemy_Component * Enemy_Component::Clone() const
{
	return new Enemy_Component;
}
/**
 * @brief For imgui button usage.
 * 
 */
void Enemy_Component::ShowGui()
{
	if (ImGui::TreeNode("Enemy_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}
/**
 * @brief Function to find the player and trace it.
 * 
 */
void Enemy_Component::trace_player(void)
{
	CS_Object* player_ptr = CS_ObjectManager::GetFirstObjectByType(CS_ArcheTypes::Player);
        if(player_ptr == nullptr)
        {
            return;
        }
	float d = glm::distance(player_ptr->transform.GetTranslation(), { m_Parent->transform.GetTranslation() });
	if (d)
	{
		trace_x = (((player_ptr->transform.GetTranslation().x) - (m_Parent->transform.GetTranslation().x)) / d * speed);
		trace_y = (((player_ptr->transform.GetTranslation().y) - (m_Parent->transform.GetTranslation().y)) / d * speed);
		m_Parent->physics.setVelocity({ trace_x, trace_y});
	}
	else
	{
		m_Parent->physics.setVelocity({ 0, 0 });
	}
}
/**
 * @brief For suicidal attacks.
 * 
 */
void Enemy_Component::suicide()
{
	
}
/**
 * @brief For enemies with patrolling movements.
 * 
 */
void Enemy_Component::patrolling(void)
{
	if (patrol)
	{
		m_Parent->transform.SetTranslation({ 200, m_Parent->transform.GetTranslation().y + 1 });
		if (m_Parent->transform.GetTranslation().y == 100)
		{
			patrol = false;
		}
	}
	else
	{
		m_Parent->transform.SetTranslation({ 200, m_Parent->transform.GetTranslation().y - 1 });
		if (m_Parent->transform.GetTranslation().y == -100)
		{
			patrol = true;
		}
	}
}
