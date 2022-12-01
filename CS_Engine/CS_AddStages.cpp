/**
 * @file CS_AddStages.hpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief Add stages to stage manager.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "CS_AddStages.hpp" 
#include "CS_StageManager.hpp" 
#include "CS_StageTypes.hpp" 
#include "CS_StageBuilder.hpp" 
#include "Clear_Stage.hpp" 
#include "Credit_Stage.hpp" 
#include "Edit_Stage.hpp" 
#include "FMOD_Logo_Stage.hpp" 
#include "GamePlay_Stage.hpp" 
#include "Logo_Stage.hpp" 
#include "Lose_Stage.hpp" 
#include "Menu_Stage.hpp" 
#include "Test_Stage.hpp" 
 
 
void CS_AddStages(void) {  
CS_StageManager::AddStage(CS_StageTypes::Clear_Stage, new CS_TemplatedStageBuilder< Clear_Stage >() ); 
CS_StageManager::AddStage(CS_StageTypes::Credit_Stage, new CS_TemplatedStageBuilder< Credit_Stage >() ); 
CS_StageManager::AddStage(CS_StageTypes::Edit_Stage, new CS_TemplatedStageBuilder< Edit_Stage >() ); 
CS_StageManager::AddStage(CS_StageTypes::FMOD_Logo_Stage, new CS_TemplatedStageBuilder< FMOD_Logo_Stage >() ); 
CS_StageManager::AddStage(CS_StageTypes::GamePlay_Stage, new CS_TemplatedStageBuilder< GamePlay_Stage >() ); 
CS_StageManager::AddStage(CS_StageTypes::Logo_Stage, new CS_TemplatedStageBuilder< Logo_Stage >() ); 
CS_StageManager::AddStage(CS_StageTypes::Lose_Stage, new CS_TemplatedStageBuilder< Lose_Stage >() ); 
CS_StageManager::AddStage(CS_StageTypes::Menu_Stage, new CS_TemplatedStageBuilder< Menu_Stage >() ); 
CS_StageManager::AddStage(CS_StageTypes::Test_Stage, new CS_TemplatedStageBuilder< Test_Stage >() ); 
} 
