/**
 * @file Start_Button_Component.cpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief Component for Start button.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Start_Button_Component.hpp"
#include "CS_Object.hpp"
#include"CS_Input.hpp"
#include "CS_StageManager.hpp"
#include "CS_SoundManager.hpp"

/**
 * @brief Construct a new Start_Button_Component::Start_Button_Component object
 * 
 */
Start_Button_Component::Start_Button_Component() : CS_Component(CS_ComponentTypes::Start_Button_Component)
{
}

/**
 * @brief Destroy the Start_Button_Component::Start_Button_Component object
 * 
 */
Start_Button_Component::~Start_Button_Component()
{
}

/**
 * @brief Read related data from file
 * 
 * @param jsonObject 
 */
void Start_Button_Component::ReadFromFile(CS_JsonObject& jsonObject)
{
}

/**
 * @brief write data which related
 * 
 * @param jsonObject 
 */
void Start_Button_Component::WriteToFile(CS_JsonObject& jsonObject)
{
}

/**
 * @brief initialize some information for this component
 * 
 */
void Start_Button_Component::Init()
{
    m_Parent->transform.SetTranslation({ 0 * CS_Graphics::GetDisplayAreaSize().x / 2.f, 0.75 * CS_Graphics::GetDisplayAreaSize().y / 2.f });
}

/**
 * @brief update this component
 * 
 * @param dt 
 */
void Start_Button_Component::Update(float dt)
{
    m_Parent->transform.SetTranslation({ 0 * CS_Graphics::GetDisplayAreaSize().x / 2.f, 0.8 * CS_Graphics::GetDisplayAreaSize().y / 2.f });

    m_Parent->editMouseSelectAABB.Update();
    if(m_Parent->editMouseSelectAABB.IsMouseIn()&& CS_Input::IsPressed(InputButtons::Mouse_Left))
    {
        CS_StageManager::SetNextStage(CS_StageTypes::GamePlay_Stage);
		CS_SoundManager::PlaySound(CS_SoundTypes::Select);
    }
}

/**
 * @brief clone this component
 * 
 * @return CS_Component* 
 */
CS_Component* Start_Button_Component::Clone() const
{
    Start_Button_Component* temp = new Start_Button_Component;
    return temp;
}

/**
 * @brief show this component on GUI
 * 
 */
void Start_Button_Component::ShowGui()
{
}
