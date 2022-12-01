/**
 * @file FMOD_Logo_Stage.hpp
 * @author Chunmook Kim
 * @email kimmistral@naver.com
 * @brief for fmod component
 * @version 0.1
 * @date 2018-12-12
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include"CS_Stages.hpp"
class FMOD_Logo_Stage : public CS_Stage
{
public:

    ~FMOD_Logo_Stage() override;
    void Init() override;
    void Update(float dt) override;
    void Shutdown() override;
private:
    float Logo_timer;
};
