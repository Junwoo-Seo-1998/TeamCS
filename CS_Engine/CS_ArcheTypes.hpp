/**
 * @file CS_ArcheTypes.hpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief Archetype controls.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once 
#include <string> 
 
 
enum class CS_ArcheTypes {  
Bullet, 
Clear, 
CooldownBar, 
End_Button, 
Enemy, 
EnemyBullet, 
Explosion, 
Flash, 
Gun, 
HP, 
Logo, 
Lose, 
NewObject, 
Player, 
Start_Button, 
Straight_Enemy, 
Waving_Enemy, 
Waving_Tracing_Enemy, 
INVALID_ArcheType 
}; 
 
 
inline CS_ArcheTypes StringToArcheType(const std::string& string) { 
if(string == "Bullet") return CS_ArcheTypes::Bullet; 
if(string == "Clear") return CS_ArcheTypes::Clear; 
if(string == "CooldownBar") return CS_ArcheTypes::CooldownBar; 
if(string == "End_Button") return CS_ArcheTypes::End_Button; 
if(string == "Enemy") return CS_ArcheTypes::Enemy; 
if(string == "EnemyBullet") return CS_ArcheTypes::EnemyBullet; 
if(string == "Explosion") return CS_ArcheTypes::Explosion; 
if(string == "Flash") return CS_ArcheTypes::Flash; 
if(string == "Gun") return CS_ArcheTypes::Gun; 
if(string == "HP") return CS_ArcheTypes::HP; 
if(string == "Logo") return CS_ArcheTypes::Logo; 
if(string == "Lose") return CS_ArcheTypes::Lose; 
if(string == "NewObject") return CS_ArcheTypes::NewObject; 
if(string == "Player") return CS_ArcheTypes::Player; 
if(string == "Start_Button") return CS_ArcheTypes::Start_Button; 
if(string == "Straight_Enemy") return CS_ArcheTypes::Straight_Enemy; 
if(string == "Waving_Enemy") return CS_ArcheTypes::Waving_Enemy; 
if(string == "Waving_Tracing_Enemy") return CS_ArcheTypes::Waving_Tracing_Enemy; 
return CS_ArcheTypes::INVALID_ArcheType; 
} 
inline std::string ArcheTypeToString(const CS_ArcheTypes type) { 
if(type == CS_ArcheTypes::Bullet) return "Bullet"; 
if(type == CS_ArcheTypes::Clear) return "Clear"; 
if(type == CS_ArcheTypes::CooldownBar) return "CooldownBar"; 
if(type == CS_ArcheTypes::End_Button) return "End_Button"; 
if(type == CS_ArcheTypes::Enemy) return "Enemy"; 
if(type == CS_ArcheTypes::EnemyBullet) return "EnemyBullet"; 
if(type == CS_ArcheTypes::Explosion) return "Explosion"; 
if(type == CS_ArcheTypes::Flash) return "Flash"; 
if(type == CS_ArcheTypes::Gun) return "Gun"; 
if(type == CS_ArcheTypes::HP) return "HP"; 
if(type == CS_ArcheTypes::Logo) return "Logo"; 
if(type == CS_ArcheTypes::Lose) return "Lose"; 
if(type == CS_ArcheTypes::NewObject) return "NewObject"; 
if(type == CS_ArcheTypes::Player) return "Player"; 
if(type == CS_ArcheTypes::Start_Button) return "Start_Button"; 
if(type == CS_ArcheTypes::Straight_Enemy) return "Straight_Enemy"; 
if(type == CS_ArcheTypes::Waving_Enemy) return "Waving_Enemy"; 
if(type == CS_ArcheTypes::Waving_Tracing_Enemy) return "Waving_Tracing_Enemy"; 
if(type == CS_ArcheTypes::Bullet) return "Bullet"; 
if(type == CS_ArcheTypes::Clear) return "Clear"; 
if(type == CS_ArcheTypes::CooldownBar) return "CooldownBar"; 
if(type == CS_ArcheTypes::End_Button) return "End_Button"; 
if(type == CS_ArcheTypes::Enemy) return "Enemy"; 
if(type == CS_ArcheTypes::EnemyBullet) return "EnemyBullet"; 
if(type == CS_ArcheTypes::Explosion) return "Explosion"; 
if(type == CS_ArcheTypes::Flash) return "Flash"; 
if(type == CS_ArcheTypes::Gun) return "Gun"; 
if(type == CS_ArcheTypes::HP) return "HP"; 
if(type == CS_ArcheTypes::Logo) return "Logo"; 
if(type == CS_ArcheTypes::Lose) return "Lose"; 
if(type == CS_ArcheTypes::NewObject) return "NewObject"; 
if(type == CS_ArcheTypes::Player) return "Player"; 
if(type == CS_ArcheTypes::Start_Button) return "Start_Button"; 
if(type == CS_ArcheTypes::Straight_Enemy) return "Straight_Enemy"; 
if(type == CS_ArcheTypes::Waving_Enemy) return "Waving_Enemy"; 
if(type == CS_ArcheTypes::Waving_Tracing_Enemy) return "Waving_Tracing_Enemy"; 
return "INVALID_ArcheType"; 
} 
