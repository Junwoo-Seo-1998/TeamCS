/**
 * @file Logo_Component.cpp
 * @author Chunmook Kim
 * @email kimmistral@naver.com
 * @brief Logo display component.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Components.hpp"
/**
 * @brief Class for define Logo component 
 * 
 */
class Logo_Component : public CS_Component
{
public:
    Logo_Component();
    ~Logo_Component() override;
    void ReadFromFile(CS_JsonObject& jsonObject) override;
    void WriteToFile(CS_JsonObject& jsonObject) override;
    void Init() override;
    void Update(float dt) override;
    CS_Component* Clone() const override;
    void ShowGui() override;
private:
    float size_x, size_y;
};
