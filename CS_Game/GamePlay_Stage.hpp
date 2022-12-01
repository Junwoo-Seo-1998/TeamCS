/**
 * @file GamePlay_Stage.hpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief 
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Stages.hpp"

class GamePlay_Stage :public CS_Stage
{
public:
    ~GamePlay_Stage() override;
    void Init() override;
    void Update(float dt) override;
    void Shutdown() override;
	
};