#include "EnemyBullet_Component.hpp"
#include "CS_Object.hpp"
#include "CS_ObjectManager.hpp"
#include "SphereCollider_Component.hpp"
#include "../Dependencies/imgui/imgui.h"

EnemyBullet_Component::EnemyBullet_Component() : CS_Component(CS_ComponentTypes::EnemyBullet_Component)
{
}

void EnemyBullet_Component::ReadFromFile(CS_JsonObject & jsonObject)
{
}

void EnemyBullet_Component::WriteToFile(CS_JsonObject & jsonObject)
{
}

void EnemyBullet_Component::Init()
{
        m_Parent->m_name = "Enemy_Bullet";
	std::string texture =  "Textures/Bullet_Red.png";
	auto t = m_Parent->gfx.SetTextureHandle(texture);
	time = 0;
}

EnemyBullet_Component::~EnemyBullet_Component()
{
}

void EnemyBullet_Component::Update(float dt)
{
	float duration = 3.f;
	time += dt;
	if (time >= duration)
		m_Parent->is_dead = true;
	if (CS_Physics::IsThereCollidingWithName(m_Parent->my_id, "Player"))
		m_Parent->is_dead = true;
}

EnemyBullet_Component * EnemyBullet_Component::Clone() const
{
	return new EnemyBullet_Component;
}

void EnemyBullet_Component::ShowGui()
{
	if (ImGui::TreeNode("EnemyBullet_Component"))
	{
		is_Dead = ImGui::Button("remove");
		ImGui::TreePop();
	}
}
