/**
 * @file Bullet_Component.hpp
 * @author Sungmin Moon
 * @email elphior0\@gmail.com
 * @brief Bullet controls.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Components.hpp"
#include <glm/glm.hpp>

class Bullet_Component :public CS_Component
{
public:
	Bullet_Component();
	void ReadFromFile(CS_JsonObject& jsonObject) override;
	void WriteToFile(CS_JsonObject& jsonObject) override;
	void Init() override;
	virtual ~Bullet_Component();
	virtual void Update(float dt);
	Bullet_Component* Clone() const override;
	void ShowGui() override;
	float time;
};