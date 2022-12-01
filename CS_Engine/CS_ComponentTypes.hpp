/**
 * @file CS_ComponentTypes.hpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief List of component types.
 * @version 0.1
 * @date 2018-12-14
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once 
#include <string> 
 
 
enum class CS_ComponentTypes {  
AABB_BoxCollider_Component, 
Graphics_Component, 
OBB_BoxCollider_Component, 
Physics_Component, 
SphereCollider_Component, 
Transform_Component, 
Background_Component, 
Background_NO_Adv_Component, 
Bullet_Component, 
Button_Component, 
Clear_Component, 
Clear_texture_Component, 
CooldownBar_Component, 
Credit_Component, 
Credit_texture_Component, 
End_Button_Component, 
EnemyBullet_Component, 
Enemy_Component, 
Explosion_Component, 
Flash_Component, 
FMOD_Logo_Component, 
Goal_Component, 
Gun_Component, 
HP_Component, 
Logo_Component, 
Lose_Component, 
Lose_texture_Component, 
Player_Component, 
Start_Button_Component, 
Straight_Enemy_Component, 
Waving_Enemy_Component, 
Waving_Tracing_Enemy_Component, 
INVALID_Component 
}; 
 
 
inline CS_ComponentTypes StringToComponent(const std::string& string) { 
if(string == "AABB_BoxCollider_Component") return CS_ComponentTypes::AABB_BoxCollider_Component; 
if(string == "Graphics_Component") return CS_ComponentTypes::Graphics_Component; 
if(string == "OBB_BoxCollider_Component") return CS_ComponentTypes::OBB_BoxCollider_Component; 
if(string == "Physics_Component") return CS_ComponentTypes::Physics_Component; 
if(string == "SphereCollider_Component") return CS_ComponentTypes::SphereCollider_Component; 
if(string == "Transform_Component") return CS_ComponentTypes::Transform_Component; 
if(string == "Background_Component") return CS_ComponentTypes::Background_Component; 
if(string == "Background_NO_Adv_Component") return CS_ComponentTypes::Background_NO_Adv_Component; 
if(string == "Bullet_Component") return CS_ComponentTypes::Bullet_Component; 
if(string == "Button_Component") return CS_ComponentTypes::Button_Component; 
if(string == "Clear_Component") return CS_ComponentTypes::Clear_Component; 
if(string == "Clear_texture_Component") return CS_ComponentTypes::Clear_texture_Component; 
if(string == "CooldownBar_Component") return CS_ComponentTypes::CooldownBar_Component; 
if(string == "Credit_Component") return CS_ComponentTypes::Credit_Component; 
if(string == "Credit_texture_Component") return CS_ComponentTypes::Credit_texture_Component; 
if(string == "End_Button_Component") return CS_ComponentTypes::End_Button_Component; 
if(string == "EnemyBullet_Component") return CS_ComponentTypes::EnemyBullet_Component; 
if(string == "Enemy_Component") return CS_ComponentTypes::Enemy_Component; 
if(string == "Explosion_Component") return CS_ComponentTypes::Explosion_Component; 
if(string == "Flash_Component") return CS_ComponentTypes::Flash_Component; 
if(string == "FMOD_Logo_Component") return CS_ComponentTypes::FMOD_Logo_Component; 
if(string == "Goal_Component") return CS_ComponentTypes::Goal_Component; 
if(string == "Gun_Component") return CS_ComponentTypes::Gun_Component; 
if(string == "HP_Component") return CS_ComponentTypes::HP_Component; 
if(string == "Logo_Component") return CS_ComponentTypes::Logo_Component; 
if(string == "Lose_Component") return CS_ComponentTypes::Lose_Component; 
if(string == "Lose_texture_Component") return CS_ComponentTypes::Lose_texture_Component; 
if(string == "Player_Component") return CS_ComponentTypes::Player_Component; 
if(string == "Start_Button_Component") return CS_ComponentTypes::Start_Button_Component; 
if(string == "Straight_Enemy_Component") return CS_ComponentTypes::Straight_Enemy_Component; 
if(string == "Waving_Enemy_Component") return CS_ComponentTypes::Waving_Enemy_Component; 
if(string == "Waving_Tracing_Enemy_Component") return CS_ComponentTypes::Waving_Tracing_Enemy_Component; 
return CS_ComponentTypes::INVALID_Component; 
} 
inline std::string ComponentToString(const CS_ComponentTypes type) { 
if(type == CS_ComponentTypes::AABB_BoxCollider_Component) return "AABB_BoxCollider_Component"; 
if(type == CS_ComponentTypes::Graphics_Component) return "Graphics_Component"; 
if(type == CS_ComponentTypes::OBB_BoxCollider_Component) return "OBB_BoxCollider_Component"; 
if(type == CS_ComponentTypes::Physics_Component) return "Physics_Component"; 
if(type == CS_ComponentTypes::SphereCollider_Component) return "SphereCollider_Component"; 
if(type == CS_ComponentTypes::Transform_Component) return "Transform_Component"; 
if(type == CS_ComponentTypes::Background_Component) return "Background_Component"; 
if(type == CS_ComponentTypes::Background_NO_Adv_Component) return "Background_NO_Adv_Component"; 
if(type == CS_ComponentTypes::Bullet_Component) return "Bullet_Component"; 
if(type == CS_ComponentTypes::Button_Component) return "Button_Component"; 
if(type == CS_ComponentTypes::Clear_Component) return "Clear_Component"; 
if(type == CS_ComponentTypes::Clear_texture_Component) return "Clear_texture_Component"; 
if(type == CS_ComponentTypes::CooldownBar_Component) return "CooldownBar_Component"; 
if(type == CS_ComponentTypes::Credit_Component) return "Credit_Component"; 
if(type == CS_ComponentTypes::Credit_texture_Component) return "Credit_texture_Component"; 
if(type == CS_ComponentTypes::End_Button_Component) return "End_Button_Component"; 
if(type == CS_ComponentTypes::EnemyBullet_Component) return "EnemyBullet_Component"; 
if(type == CS_ComponentTypes::Enemy_Component) return "Enemy_Component"; 
if(type == CS_ComponentTypes::Explosion_Component) return "Explosion_Component"; 
if(type == CS_ComponentTypes::Flash_Component) return "Flash_Component"; 
if(type == CS_ComponentTypes::FMOD_Logo_Component) return "FMOD_Logo_Component"; 
if(type == CS_ComponentTypes::Goal_Component) return "Goal_Component"; 
if(type == CS_ComponentTypes::Gun_Component) return "Gun_Component"; 
if(type == CS_ComponentTypes::HP_Component) return "HP_Component"; 
if(type == CS_ComponentTypes::Logo_Component) return "Logo_Component"; 
if(type == CS_ComponentTypes::Lose_Component) return "Lose_Component"; 
if(type == CS_ComponentTypes::Lose_texture_Component) return "Lose_texture_Component"; 
if(type == CS_ComponentTypes::Player_Component) return "Player_Component"; 
if(type == CS_ComponentTypes::Start_Button_Component) return "Start_Button_Component"; 
if(type == CS_ComponentTypes::Straight_Enemy_Component) return "Straight_Enemy_Component"; 
if(type == CS_ComponentTypes::Waving_Enemy_Component) return "Waving_Enemy_Component"; 
if(type == CS_ComponentTypes::Waving_Tracing_Enemy_Component) return "Waving_Tracing_Enemy_Component"; 
return "INVALID_Component"; 
} 
