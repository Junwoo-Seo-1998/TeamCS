/**
 * @file Clear_Component.hpp
 * @author Chunmook Kim
 * @email kimmistral@naver.com
 * @brief for Clear Stage
 * @version 0.1
 * @date 2018-12-12
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Stages.hpp"
#include "CS_Object.hpp"
class Clear_Stage : public CS_Stage
{
public:
    ~Clear_Stage() override;
    void Init() override;
    void Update(float dt) override;
    void Shutdown() override;
};
