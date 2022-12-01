/**
 * @file CS_StageTypes.hpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief For define stage types 
 * @version 0.1
 * @date 2018-12-14
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once 
#include <string> 
 
 
enum class CS_StageTypes {  
Clear_Stage, 
Credit_Stage, 
Edit_Stage, 
FMOD_Logo_Stage, 
GamePlay_Stage, 
Logo_Stage, 
Lose_Stage, 
Menu_Stage, 
Test_Stage, 
INVALID_Stage 
}; 
 
 
inline CS_StageTypes StringToStage(const std::string& string) { 
if(string == "Clear_Stage") return CS_StageTypes::Clear_Stage; 
if(string == "Credit_Stage") return CS_StageTypes::Credit_Stage; 
if(string == "Edit_Stage") return CS_StageTypes::Edit_Stage; 
if(string == "FMOD_Logo_Stage") return CS_StageTypes::FMOD_Logo_Stage; 
if(string == "GamePlay_Stage") return CS_StageTypes::GamePlay_Stage; 
if(string == "Logo_Stage") return CS_StageTypes::Logo_Stage; 
if(string == "Lose_Stage") return CS_StageTypes::Lose_Stage; 
if(string == "Menu_Stage") return CS_StageTypes::Menu_Stage; 
if(string == "Test_Stage") return CS_StageTypes::Test_Stage; 
return CS_StageTypes::INVALID_Stage; 
} 
