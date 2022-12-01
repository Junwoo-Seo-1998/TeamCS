/**
 * @file Button_Component.cpp
 * @author Chunmook Kim
 * @email kimmistral@naver.com
 * @brief For main menu buttons.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Button_Component.hpp"
/**
 * @brief Construct a new Button_Component::Button_Component object
 * 
 */
Button_Component::Button_Component() : CS_Component(CS_ComponentTypes::Button_Component)
{
}
/**
 * @brief Destroy the Button_Component::Button_Component object
 * 
 */
Button_Component::~Button_Component()
{
}
/**
 * @brief Read initialization data from the JSON file.
 * 
 * @param jsonObject The JSON file to read from.
 */
void Button_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}
/**
 * @brief Write data into the JSON file.
 * 
 * @param jsonObject The JSON file to write into.
 */
void Button_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}
/**
 * @brief Initialization.
 * 
 */
void Button_Component::Init()
{
}
/**
 * @brief Update.
 * 
 * @param dt Delta time.
 */
void Button_Component::Update(float dt)
{
}
/**
 * @brief Make a clone of this component.
 * 
 * @return CS_Component* Clone of this component.
 */
CS_Component* Button_Component::Clone() const
{
    Button_Component* temp = new Button_Component;
    return temp;
}
/**
 * @brief For imgui button usage.
 * 
 */
void Button_Component::ShowGui()
{
}
