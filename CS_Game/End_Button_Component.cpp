/**
 * @file End_Button_Component.cpp
 * @author Chunmook Kim
 * @email kimmistral@naver.com
 * @brief For button to end the game.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "End_Button_Component.hpp"
#include "CS_StageManager.hpp"
#include "CS_SoundManager.hpp"
#include "CS_Input.hpp"
#include "CS_Object.hpp"

/**
 * @brief Construct a new End_Button_Component::End_Button_Component object
 * 
 */
End_Button_Component::End_Button_Component() : CS_Component(CS_ComponentTypes::End_Button_Component)
{

}

/**
 * @brief Destroy the End_Button_Component::End_Button_Component object
 * 
 */
End_Button_Component::~End_Button_Component()
{
}

/**
 * @brief Read data form json 
 * 
 * @param jsonObject 
 */
void End_Button_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}

/**
 * @brief write data to json file
 * 
 * @param jsonObject 
 */
void End_Button_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}

/**
 * @brief initialize end button class
 * 
 */
void End_Button_Component::Init()
{
    m_Parent->transform.SetTranslation({ 0 * CS_Graphics::GetDisplayAreaSize().x / 2.f, -0.8 * CS_Graphics::GetDisplayAreaSize().y / 2.f });
}

/**
 * @brief update end button component 
 * 
 * @param dt 
 */
void End_Button_Component::Update(float dt)
{

    m_Parent->transform.SetTranslation({ 0 * CS_Graphics::GetDisplayAreaSize().x / 2.f, -0.75 * CS_Graphics::GetDisplayAreaSize().y / 2.f });

    m_Parent->editMouseSelectAABB.Update();
    if (m_Parent->editMouseSelectAABB.IsMouseIn() && CS_Input::IsPressed(InputButtons::Mouse_Left))
    {
		
        return CS_StageManager::Quit();
    }
}

/**
 * @brief clone end button 
 * 
 * @return CS_Component* 
 */
CS_Component* End_Button_Component::Clone() const
{
    End_Button_Component* temp = new End_Button_Component;
    return temp;
}

/**
 * @brief Show GUI for this component
 * 
 */
void End_Button_Component::ShowGui()
{
}
