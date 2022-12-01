/**
 * @file Credit_texture_Component.hpp
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
#include"CS_Components.hpp"
class Credit_texture_Component : public CS_Component
{
public:
    Credit_texture_Component();
    ~Credit_texture_Component() override;
    void ReadFromFile(CS_JsonObject& jsonObject) override;
    void WriteToFile(CS_JsonObject& jsonObject) override;
    void Init() override;
    void Update(float dt) override;
    CS_Component* Clone() const override;
    void ShowGui() override;
};
