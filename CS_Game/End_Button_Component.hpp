/**
 * @file End_Button_Component.hpp
 * @author Chunmook Kim
 * @email kimmistral@naver.com
 * @brief For button to end the game.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Components.hpp"
/**
 * @brief Class for End button component
 * 
 */
class End_Button_Component : public CS_Component
{
public:
    End_Button_Component();
    ~End_Button_Component() override;
    void ReadFromFile(CS_JsonObject& jsonObject) override;
    void WriteToFile(CS_JsonObject& jsonObject) override;
    void Init() override;
    void Update(float dt) override;
    CS_Component* Clone() const override;
    void ShowGui() override;
};
