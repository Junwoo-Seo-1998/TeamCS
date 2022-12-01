/**
 * @file Waving_Enemy_Component.cpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief Component for waving enemies.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Waving_Enemy_Component.hpp"
#include "CS_Object.hpp"
#include "CS_ObjectManager.hpp"
#include "../Dependencies/imgui/imgui.h"
#include "CS_Physics.hpp"
#include <ctime>
/**
 * @brief Construct a new Waving_Enemy_Component::Waving_Enemy_Component object
 * 
 */
Waving_Enemy_Component::Waving_Enemy_Component() : CS_Component(CS_ComponentTypes::Waving_Enemy_Component)
{
}
/**
 * @brief Destroy the Waving_Enemy_Component::Waving_Enemy_Component object
 * 
 */
Waving_Enemy_Component::~Waving_Enemy_Component()
{
}
/**
 * @brief Read initialize data from the JSON file.
 * 
 * @param jsonObject The JSON file to read from.
 */
void Waving_Enemy_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
	
}
/**
 * @brief Write data into the JSON file.
 * 
 * @param jsonObject The JSON file to write into.
 */
void Waving_Enemy_Component::WriteToFile(CS_JsonObject & jsonObject)
{
}
/**
 * @brief Timer and amplitude initialization.
 * 
 */
void Waving_Enemy_Component::Init()
{
    m_Parent->m_name = "Enemy";
	time = 0;
	amplitude = 100;
	guntimer = 0;
        m_Parent->gfx.SetTextureHandle(bat_animation);
        m_Parent->gfx.SetAnimation(2, 1, 0.5);
}
/**
 * @brief Update movemnt based on time.
 * 
 * @param dt Delta time.
 */
void Waving_Enemy_Component::Update(float dt)
{

	if (m_Parent->is_inside_screen_enemy())
	{
            Waving_movement(dt);
            Shoot(dt);
	}
		
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
CS_Component* Waving_Enemy_Component::Clone() const
{
	return new Waving_Enemy_Component;
}
/**
 * @brief For imgui button usage.
 * 
 */
void Waving_Enemy_Component::ShowGui()
{
	if (ImGui::TreeNode("Waving_Enemy_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}
/**
 * @brief Update waving angles based on time.
 * 
 * @param dt Delta time.
 */
void Waving_Enemy_Component::Waving_movement(float dt)
{
	time += dt * 1.f;
	if(time > 360)
	{
		time = 0;
	}
	float current_y = m_Parent->transform.GetTranslation().y;
	float check = glm::sin(glm::radians(time));
	float waved_y = 300 * glm::sin(time*5);
	m_Parent->physics.setVelocity({ -100, waved_y });
}

void Waving_Enemy_Component::Shoot(float dt)
{
	CS_Object* player_ptr = CS_ObjectManager::GetFirstObjectByType(CS_ArcheTypes::Player);
    if(player_ptr == nullptr)
    {
        return;
    }
	guntimer += dt;
	if (guntimer >= 1.f)
	{
		if (player_ptr->transform.GetTranslation().x - m_Parent->transform.GetTranslation().x < 0)
		{
			random = (std::rand() % randomrange) + 1;
			random -= randomrange_doubled;
			enemybullet = CS_ObjectManager::CreateObjectWithArcheType(CS_ArcheTypes::EnemyBullet);
			enemybullet->transform.SetTranslation(m_Parent->transform.GetTranslation());
			enemybullet->transform.SetScale({ 30, 10 });
			enemybullet->physics.setDamping(1.f);
			auto vec = player_ptr->transform.GetTranslation() - m_Parent->transform.GetTranslation() + random;
			auto normal = glm::normalize(vec);
			enemybullet->physics.setVelocity({normal.x * default_speed, normal.y * default_speed});
			enemybullet->transform.SetRotationWithVector(normal);

			muzzleflash = CS_ObjectManager::CreateObjectWithArcheType(CS_ArcheTypes::Flash);
			muzzleflash->gfx.SetTextureHandle(mf_texture);
			muzzleflash->transform.SetTranslation({ m_Parent->transform.GetTranslation_x() - 20.f, m_Parent->transform.GetTranslation_y() });
			muzzleflash->transform.SetScale(mf_size);
			muzzleflash->transform.SetRotation(enemybullet->transform.GetRotation());
		}
		guntimer = 0.f;
	}
}
