/**
 * @file Explosion_Component.hpp
 * @author Sungmin Moon
 * @email elphior0\@gmail.com
 * @brief explosion component
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Components.hpp"
#include <glm/glm.hpp>

class Explosion_Component : public CS_Component
{
public:
	Explosion_Component();
	void ReadFromFile(CS_JsonObject& jsonObject) override;
	void WriteToFile(CS_JsonObject& jsonObject) override;
	void Init() override;
	virtual ~Explosion_Component();
	virtual void Update(float dt);
	Explosion_Component* Clone() const override;
	void ShowGui() override;
private:
	float timer;
	float lifetime = 1.f;
};