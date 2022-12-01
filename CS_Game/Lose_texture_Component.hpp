/**
 * @file Lose_texture_Component.hpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com)
 * @brief for lose component
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include"CS_Components.hpp"
class Lose_texture_Component : public CS_Component
{
public:
    Lose_texture_Component();
    ~Lose_texture_Component() override;
    void ReadFromFile(CS_JsonObject& jsonObject) override;
    void WriteToFile(CS_JsonObject& jsonObject) override;
    void Init() override;
    void Update(float dt) override;
    CS_Component* Clone() const override;
    void ShowGui() override;
};
