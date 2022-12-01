/**
 * @file Logo_Stage.hpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com)
 * @brief Stage to display logo.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Stages.hpp"
#include "CS_Object.hpp"

class Logo_Stage : public CS_Stage
{
public:

    ~Logo_Stage() override;
    void Init() override;
    void Update(float dt) override;
    void Shutdown() override;
private:
    float Logo_timer;
};
