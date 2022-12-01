/**
 * @file Credit_Stage.hpp
 * @author Chunmook Kim
 * @email kimmistral@naver.com
 * @brief for credit Stage
 * @version 0.1
 * @date 2018-12-12
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Stages.hpp"
#include "CS_Object.hpp"
class Credit_Stage : public CS_Stage
{
public:
    ~Credit_Stage() override;
    void Init() override;
    void Update(float dt) override;
    void Shutdown() override;
};
