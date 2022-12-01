/**
 * @file CooldownBar_Component.hpp
 * @author Sungmin Moon
 * @email elphior0\@gmail.com
 * @brief Cooldown bar management.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Components.hpp"
#include <glm/glm.hpp>
#include "Gun_Component.hpp"

class CooldownBar_Component :public CS_Component
{
public:
	CooldownBar_Component();
	void ReadFromFile(CS_JsonObject& jsonObject) override;
	void WriteToFile(CS_JsonObject& jsonObject) override;
	void Init() override;
	virtual ~CooldownBar_Component();
	virtual void Update(float dt);
	CooldownBar_Component* Clone() const override;
	void ShowGui() override;

private:
    CS_Object* Gun_object_ptr;
    Gun_Component* Gun_component;

    std::string ready = "Textures/Ready.png";
    std::string notready = "Textures/NotReady.png";
    glm::vec2 full_bar_size = { 500.f, 30.f };
    glm::vec2 zero_bar_size = { 0.f , 30.f };
    glm::vec2 center = { -370, 303.5 };
    float width;
    float height = 30.f;
    float last_width;
};
