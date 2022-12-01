/**
 * @file Start_Button_Component.hpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief Component for Start button.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include"CS_Components.hpp"
/**
 * @brief Component of start button component
 * 
 */
class Start_Button_Component : public CS_Component
{
public:
    Start_Button_Component();
    ~Start_Button_Component() override;
    void ReadFromFile(CS_JsonObject& jsonObject) override;
    void WriteToFile(CS_JsonObject& jsonObject) override;
    void Init() override;
    void Update(float dt) override;
    CS_Component* Clone() const override;
    void ShowGui() override;
};
