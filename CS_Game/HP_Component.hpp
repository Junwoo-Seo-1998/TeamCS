/**
 * @file HP_Component.hpp
 * @author Sungmin Moon
 * @email elphior0\@gmail.com
 * @brief HP component
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "Player_Component.hpp"
#include "CS_Components.hpp"
#include <glm/glm.hpp>

class HP_Component : public CS_Component
{
public:
	HP_Component();
	void ReadFromFile(CS_JsonObject& jsonObject) override;
	void WriteToFile(CS_JsonObject& jsonObject) override;
	void Init() override;
	virtual ~HP_Component();
	virtual void Update(float dt);
	HP_Component* Clone() const override;
	void ShowGui() override;
private:
	CS_Object* object_ptr;
	Player_Component* Player_component;
        glm::vec2 center = { -300, 343.5 };
	std::string texture = "Texture/Ready.png";
	int currenthealth;
	float width;
	float height = 30.f;
        float last_width;
        const int block = 100;
};