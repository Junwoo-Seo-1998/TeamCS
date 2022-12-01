/**
 * @file Logo_Component.cpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief Logo display component.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Logo_Component.hpp"
#include "CS_Object.hpp"
#include <iostream>
/**
 * @brief Construct a new Logo_Component::Logo_Component object
 * 
 */
Logo_Component::Logo_Component() : CS_Component(CS_ComponentTypes::Logo_Component)
{
}

/**
 * @brief Destroy the Logo_Component::Logo_Component object
 * 
 */
Logo_Component::~Logo_Component()
{
}
/**
 * @brief read data from json file
 * 
 * @param jsonObject 
 */
void Logo_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}
/**
 * @brief write data to json file
 * 
 * @param jsonObject 
 */
void Logo_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}
/**
 * @brief initialize this component 
 * 
 */
void Logo_Component::Init()
{
	size_x = m_Parent->transform.GetScale().x;
	size_y = m_Parent->transform.GetScale().y;
}
/**
 * @brief update this component 
 * 
 * @param dt 
 */
void Logo_Component::Update(float dt)
{
	size_x += 100 * dt;
	size_y += 50 * dt;
	m_Parent->transform.SetScale({ size_x, size_y });
}
/**
 * @brief clone this component
 * 
 * @return CS_Component* 
 */
CS_Component* Logo_Component::Clone() const
{
    Logo_Component* temp = new Logo_Component;
    return temp;
}
/**
 * @brief show GUI information of this component
 * 
 */
void Logo_Component::ShowGui()
{
}
