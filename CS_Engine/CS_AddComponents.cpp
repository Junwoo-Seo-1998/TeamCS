/**
 * @file CS_AddComponents.cpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief Add component to the object manager.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "CS_AddComponents.hpp" 
#include "CS_ObjectManager.hpp" 
#include "CS_ComponentTypes.hpp" 
#include "CS_ComponentBuilder.hpp" 
#include "AABB_BoxCollider_Component.hpp" 
#include "Graphics_Component.hpp" 
#include "OBB_BoxCollider_Component.hpp" 
#include "Physics_Component.hpp" 
#include "SphereCollider_Component.hpp" 
#include "Transform_Component.hpp" 
#include "Background_Component.hpp" 
#include "Background_NO_Adv_Component.hpp" 
#include "Bullet_Component.hpp" 
#include "Button_Component.hpp" 
#include "Clear_Component.hpp" 
#include "Clear_texture_Component.hpp" 
#include "CooldownBar_Component.hpp" 
#include "Credit_Component.hpp" 
#include "Credit_texture_Component.hpp" 
#include "End_Button_Component.hpp" 
#include "EnemyBullet_Component.hpp" 
#include "Enemy_Component.hpp" 
#include "Explosion_Component.hpp" 
#include "Flash_Component.hpp" 
#include "FMOD_Logo_Component.hpp" 
#include "Goal_Component.hpp" 
#include "Gun_Component.hpp" 
#include "HP_Component.hpp" 
#include "Logo_Component.hpp" 
#include "Lose_Component.hpp" 
#include "Lose_texture_Component.hpp" 
#include "Player_Component.hpp" 
#include "Start_Button_Component.hpp" 
#include "Straight_Enemy_Component.hpp" 
#include "Waving_Enemy_Component.hpp" 
#include "Waving_Tracing_Enemy_Component.hpp" 
 
 
void CS_AddComponents(void) {  
CS_ObjectManager::AddComponent(CS_ComponentTypes::AABB_BoxCollider_Component, new CS_TemplatedComponentBuilder< AABB_BoxCollider_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Graphics_Component, new CS_TemplatedComponentBuilder< Graphics_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::OBB_BoxCollider_Component, new CS_TemplatedComponentBuilder< OBB_BoxCollider_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Physics_Component, new CS_TemplatedComponentBuilder< Physics_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::SphereCollider_Component, new CS_TemplatedComponentBuilder< SphereCollider_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Transform_Component, new CS_TemplatedComponentBuilder< Transform_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Background_Component, new CS_TemplatedComponentBuilder< Background_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Background_NO_Adv_Component, new CS_TemplatedComponentBuilder< Background_NO_Adv_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Bullet_Component, new CS_TemplatedComponentBuilder< Bullet_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Button_Component, new CS_TemplatedComponentBuilder< Button_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Clear_Component, new CS_TemplatedComponentBuilder< Clear_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Clear_texture_Component, new CS_TemplatedComponentBuilder< Clear_texture_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::CooldownBar_Component, new CS_TemplatedComponentBuilder< CooldownBar_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Credit_Component, new CS_TemplatedComponentBuilder< Credit_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Credit_texture_Component, new CS_TemplatedComponentBuilder< Credit_texture_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::End_Button_Component, new CS_TemplatedComponentBuilder< End_Button_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::EnemyBullet_Component, new CS_TemplatedComponentBuilder< EnemyBullet_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Enemy_Component, new CS_TemplatedComponentBuilder< Enemy_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Explosion_Component, new CS_TemplatedComponentBuilder< Explosion_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Flash_Component, new CS_TemplatedComponentBuilder< Flash_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::FMOD_Logo_Component, new CS_TemplatedComponentBuilder< FMOD_Logo_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Goal_Component, new CS_TemplatedComponentBuilder< Goal_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Gun_Component, new CS_TemplatedComponentBuilder< Gun_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::HP_Component, new CS_TemplatedComponentBuilder< HP_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Logo_Component, new CS_TemplatedComponentBuilder< Logo_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Lose_Component, new CS_TemplatedComponentBuilder< Lose_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Lose_texture_Component, new CS_TemplatedComponentBuilder< Lose_texture_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Player_Component, new CS_TemplatedComponentBuilder< Player_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Start_Button_Component, new CS_TemplatedComponentBuilder< Start_Button_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Straight_Enemy_Component, new CS_TemplatedComponentBuilder< Straight_Enemy_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Waving_Enemy_Component, new CS_TemplatedComponentBuilder< Waving_Enemy_Component >() ); 
CS_ObjectManager::AddComponent(CS_ComponentTypes::Waving_Tracing_Enemy_Component, new CS_TemplatedComponentBuilder< Waving_Tracing_Enemy_Component >() ); 
} 
