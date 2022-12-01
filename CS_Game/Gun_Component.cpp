/**
 * @file Gun_Component.cpp
 * @author Sungmin Moon
 * @email elphior0\@gmail.com
 * @brief Gun and shooting mechanics management.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Gun_Component.hpp"
#include "CS_Object.hpp"
#include "CS_Input.hpp"
#include "Player_Component.hpp"
#include "CS_ObjectManager.hpp"
#include "../Dependencies/imgui/imgui.h"
/**
 * @brief Construct a new Gun_Component::Gun_Component object
 * 
 */
Gun_Component::Gun_Component() :CS_Component(CS_ComponentTypes::Gun_Component)
{
}
/**
 * @brief Read initialization data from the JSON file.
 * 
 * @param jsonObject The JSON file to read from,
 */
void Gun_Component::ReadFromFile(CS_JsonObject & jsonObject)
{
}
/**
 * @brief Write data into the JSON file.
 * 
 * @param jsonObject The JSON file to write into.
 */
void Gun_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}
/**
 * @brief Initialize status, timer and cooldown.
 * 
 */
void Gun_Component::Init()
{
	method = Pistol;
	status = Ready;
	ammocount = 0;
	guntimer = 0.f;
	cooltime = 5.f;
	next_shot_timer = 0.5f;
}
/**
 * @brief Destroy the Gun_Component::Gun_Component object
 * 
 */
Gun_Component::~Gun_Component()
{
}
/**
 * @brief Shooting based on the status and updating timers.
 * 
 * @param dt Delta time.
 */
void Gun_Component::Update(float dt)
{
	// Space to shoot
	// left to trigger gatling
	// right to trigger shotgun
	// cooldown is shared

	if (method == Pistol)
	{
		if (CS_Input::IsTriggered(InputButtons::Space))
		{
			CS_SoundManager::PlaySound(CS_SoundTypes::Pistol);
			MakeBullet(m_Parent->transform.GetTranslation(), { bullet_speed, 0 }, bulletsize);
			muzzleflash = CS_ObjectManager::CreateObjectWithArcheType(CS_ArcheTypes::Flash);
			muzzleflash->gfx.SetTextureHandle(mf_texture);
			muzzleflash->transform.SetTranslation({ m_Parent->transform.GetTranslation_x() + gun_distance
				, m_Parent->transform.GetTranslation_y() });
			muzzleflash->transform.SetScale(mf_size);
		}
	}

	if (method == Shotgun)
	{
		if (CS_Input::IsTriggered(InputButtons::Space))
		{
			CS_SoundManager::PlaySound(CS_SoundTypes::Shotgun);
			MakeBullet(m_Parent->transform.GetTranslation(), { bullet_speed, 0 }, bulletsize);
			MakeBullet(m_Parent->transform.GetTranslation(), { bullet_speed, -(bullet_speed / 2) }, bulletsize);
			bullet->transform.SetRotationWithVector({bullet_speed, -(bullet_speed / 2)});
			MakeBullet(m_Parent->transform.GetTranslation(), { bullet_speed, (bullet_speed / 2) }, bulletsize);
			bullet->transform.SetRotationWithVector({ bullet_speed, bullet_speed / 2 });

			muzzleflash = CS_ObjectManager::CreateObjectWithArcheType(CS_ArcheTypes::Flash);
			muzzleflash->gfx.SetTextureHandle(mf_texture);
			muzzleflash->transform.SetTranslation({ m_Parent->transform.GetTranslation_x() + gun_distance
				, m_Parent->transform.GetTranslation_y() });
			muzzleflash->transform.SetScale({ 200.f, 200.f });
			/*ammocount++;
			if (ammocount == 30)
			{
				method = Pistol;
				ammocount = 0;
			}*/
		}
		guntimer += dt;
		if (guntimer >= 5.f)
		{
			method = Pistol;
			status = Cooldown;
			CS_SoundManager::PlaySound(CS_SoundTypes::Deactivate);

		}
	
	}
	if (method == Gatling)
	{
		next_shot_timer += dt;
		if (next_shot_timer >= barrage_timer)
		{
			if (CS_Input::IsPressed(InputButtons::Space))
			{
				if (ammocount % 2 == 0)
				{
					CS_SoundManager::PlaySound(CS_SoundTypes::Gatling);
					MakeBullet({ m_Parent->transform.GetTranslation().x, m_Parent->transform.GetTranslation().y - 10 }, { bullet_speed * 3, 0 }, gatlingsize);
					muzzleflash = CS_ObjectManager::CreateObjectWithArcheType(CS_ArcheTypes::Flash);
					muzzleflash->gfx.SetTextureHandle(mf_texture);
					muzzleflash->transform.SetTranslation({ m_Parent->transform.GetTranslation_x() + gun_distance
						, m_Parent->transform.GetTranslation_y() - 10 });
					muzzleflash->transform.SetScale(mf_size);
				}
					
				else if (ammocount % 2 == 1)
				{
					CS_SoundManager::PlaySound(CS_SoundTypes::Gatling);
					MakeBullet({ m_Parent->transform.GetTranslation().x, m_Parent->transform.GetTranslation().y + 10 }, { bullet_speed * 3, 0 }, gatlingsize);
					muzzleflash = CS_ObjectManager::CreateObjectWithArcheType(CS_ArcheTypes::Flash);
					muzzleflash->gfx.SetTextureHandle(mf_texture);
					muzzleflash->transform.SetTranslation({ m_Parent->transform.GetTranslation_x() + gun_distance
						, m_Parent->transform.GetTranslation_y() + 10 });
					muzzleflash->transform.SetScale(mf_size);
				}
					
				bullet->transform.SetScale(gatlingsize);
				next_shot_timer = 0;
				ammocount++;
				/*if (ammocount == 50)
				{
					method = Pistol;
					ammocount = 0;
				}*/
			}
		}
		guntimer += dt;
		if (guntimer >= 5.f)
		{
			method = Pistol;
			status = Cooldown;
			CS_SoundManager::PlaySound(CS_SoundTypes::Deactivate);
		}
	}

	if (CS_Input::IsTriggered(InputButtons::C))
	{
		if (method == Pistol)
		{
			if (status == Ready)
			{
				int i = ((int)method + 1) % 3;
				method = Gatling;
				ammocount = 0;
				guntimer = 0;
				cooltime = 5.f;
				barrage_timer = 0.1f;
				CS_SoundManager::PlaySound(CS_SoundTypes::Activate);
			}
		}
	}
	if (CS_Input::IsTriggered(InputButtons::V))
	{
		if (method == Pistol)
		{
			if (status == Ready)
			{
				int i = ((int)method + 1) % 3;
				method = Shotgun;
				//ammocount = 0;
				guntimer = 0;
				cooltime = 5.f;
				CS_SoundManager::PlaySound(CS_SoundTypes::Activate);
			}
		}
	}
	//Movement();
	UpdateCooltime(dt);
}
/**
 * @brief Make bullet and give position, velocity and size.
 * 
 * @param position The position to generate.
 * @param velocity The velocity of the bullet.
 * @param size Size of the bullet.
 */
void Gun_Component::MakeBullet(glm::vec2 position, glm::vec2 velocity, glm::vec2 size)
{
	bullet = CS_ObjectManager::CreateObjectWithArcheType(CS_ArcheTypes::Bullet);
	bullet->transform.SetTranslation({ position.x + gun_distance, position.y });
	bullet->transform.SetScale(size);
	bullet->physics.setDamping(1.f);
	bullet->physics.setVelocity(velocity);
}
/**
 * @brief Make a clone of this component.
 * 
 * @return Gun_Component* Clone of this component.
 */
Gun_Component * Gun_Component::Clone() const
{
	return new Gun_Component;
}
/**
 * @brief Get the gun timer.
 * 
 * @return float Gun timer.
 */
float Gun_Component::GetGuntimer() const
{
    return guntimer;
}
/**
 * @brief Get the status.
 * 
 * @return CoolDown Status.
 */
CoolDown Gun_Component::GetStatus() const
{
    return status;
}
/**
 * @brief Get the cooltime.
 * 
 * @return float Cooltime.
 */
float Gun_Component::GetCooltime() const
{
    return cooltime;
}
/**
 * @brief Keep updating the cooldown.
 * 
 * @param dt Delta time.
 */
void Gun_Component::UpdateCooltime(float dt)
{
	if (status == Cooldown)
	{
		cooltime -= dt;
		
	}
	if (cooltime <= 0.f)
	{
		status = Ready;
	}
}
/**
 * @brief For imgui button usage.
 * 
 */
void Gun_Component::ShowGui()
{
	if (ImGui::TreeNode("Gun_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}