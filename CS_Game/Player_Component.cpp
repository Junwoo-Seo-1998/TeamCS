/**
 * @file Player_Component.cpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief Player control and management.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Player_Component.hpp"
#include "CS_ObjectManager.hpp"
#include "CS_Input.hpp"
#include "CS_Object.hpp"
#include <glm/glm.hpp>
#include "../Dependencies/imgui/imgui.h"
#include "CS_Physics.hpp"
#include "CS_StageManager.hpp"
#include "CS_Camera.hpp"
/**
 * @brief Construct a new Player_Component::Player_Component object
 * 
 */
Player_Component::Player_Component():CS_Component(CS_ComponentTypes::Player_Component)
{

}
/**
 * @brief Destroy the Player_Component::Player_Component object
 * 
 */
Player_Component::~Player_Component()
{
}
/**
 * @brief Read initialization data from the JSON file.
 * 
 * @param jsonObject The JSON file to read from.
 */
void Player_Component::ReadFromFile(CS_JsonObject & jsonObject)
{
}
/**
 * @brief Write data into the JSON file.
 * 
 * @param jsonObject The JSON file to write into.
 */
void Player_Component::WriteToFile(CS_JsonObject & jsonObject)
{
}
/**
 * @brief Initialize.
 * 
 */
void Player_Component::Init()
{
    max_health = 7;
    health = max_health;
    m_Parent->m_name = "Player";
	timer = 0.f;
	invincible_mode = false;
}
/**
 * @brief Update player based on the input.
 * 
 * @param dt Delta time.
 */
void Player_Component::Update(float dt)
{
        last_pos = m_Parent->transform.GetTranslation();
	m_Parent->GetComponent(CS_ComponentTypes::SphereCollider_Component, collider);
	if (collider != nullptr)
	{
		if (CS_Physics::IsThereCollidingWithName(m_Parent->my_id, "Enemy_Bullet")
			|| CS_Physics::IsThereCollidingWithName(m_Parent->my_id, "Enemy"))
		{
			health -= 1;
			collider->is_Ghost = true;
			timer = 0.f;
		}
		if (collider->is_Ghost == true)
			timer += dt;
		if (timer >= invincibility)
		{
			collider->is_Ghost = false;
			timer = 0.f;
		}
	}
	
	if (CS_Input::IsTriggered(InputButtons::I))
	{
		if (invincible_mode == false)
		{
			invincible_mode = true;
		}
		else
			invincible_mode = false;
	}
	if (invincible_mode == true)
		health = 7;
	if (health == 0)
	{
            m_Parent->is_dead = true;
            CS_StageManager::SetNextStage(CS_StageTypes::Lose_Stage);
	}
        PlayerInput();
        CS_Camera *cam = CS_StageManager::GetCameraOfCurrentLevel();
        float x=glm::clamp(last_pos.x, cam->GetLeft_x(), cam->GetRight_x());
        float y=glm::clamp(last_pos.y, cam->GetBot_y(), cam->GetTop_y());
        m_Parent->transform.SetTranslation({ x,y });
        
       
}
/**
 * @brief Make a clone of this component.
 * 
 * @return Player_Component* Clone of this component.
 */
Player_Component * Player_Component::Clone() const
{
    Player_Component *temp = new Player_Component;
    temp->down = down;
    temp->up = up;
    temp->right = right;
    temp->left = left;
    return temp;
}
/**
 * @brief For imgui button usage.
 * 
 */
void Player_Component::ShowGui()
{
	if (ImGui::TreeNode("Player_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}
int Player_Component::GetHealth() const 
{
	return health;
}

int Player_Component::GetMaxHealth() const
{
    return max_health;
}

/**
 * @brief Move player based on the input.
 * 
 */
void Player_Component::PlayerInput()
{
    const float speed = 400.f;
    glm::vec2 movement = { 0.f,0.f };

    if (CS_Input::IsPressed(InputButtons::Left))
        left = true;
    else
        left = false;

    if (CS_Input::IsPressed(InputButtons::Right))
        right = true;
    else
        right = false;

    if (CS_Input::IsPressed(InputButtons::Up))
        up = true;
    else
        up = false;

    if (CS_Input::IsPressed(InputButtons::Down))
        down = true;
    else
        down = false;

    if (left)
    {
        movement.x = -1;

    }
    if (right)
    {
        movement.x = 1;
       
    }
    if (up)
    {
        movement.y = 1;
    }

    if (down)
    {
        movement.y = -1;
    }

    movement.x *= speed;
    movement.y *= speed;
    m_Parent->physics.setVelocity({ movement.x, movement.y });
}
