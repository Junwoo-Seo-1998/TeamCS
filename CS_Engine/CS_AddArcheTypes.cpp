/**
 * @file CS_AddArcheTypes.cpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief Add archtypes for the components.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "CS_ObjectManager.hpp" 
#include "CS_AddArcheTypes.hpp" 
 
 
void CS_AddArcheTypes(void) {  
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Bullet, "ArcheTypes\\Bullet.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Clear, "ArcheTypes\\Clear.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::CooldownBar, "ArcheTypes\\CooldownBar.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::End_Button, "ArcheTypes\\End_Button.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Enemy, "ArcheTypes\\Enemy.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::EnemyBullet, "ArcheTypes\\EnemyBullet.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Explosion, "ArcheTypes\\Explosion.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Flash, "ArcheTypes\\Flash.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Gun, "ArcheTypes\\Gun.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::HP, "ArcheTypes\\HP.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Logo, "ArcheTypes\\Logo.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Lose, "ArcheTypes\\Lose.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::NewObject, "ArcheTypes\\NewObject.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Player, "ArcheTypes\\Player.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Start_Button, "ArcheTypes\\Start_Button.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Straight_Enemy, "ArcheTypes\\Straight_Enemy.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Waving_Enemy, "ArcheTypes\\Waving_Enemy.json"); 
CS_ObjectManager::AddArcheType(CS_ArcheTypes::Waving_Tracing_Enemy, "ArcheTypes\\Waving_Tracing_Enemy.json"); 
} 
