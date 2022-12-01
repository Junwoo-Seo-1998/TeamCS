/**
 * @file Flash_Component.hpp
 * @author Sungmin Moon
 * @email elphior0\@gmail.com
 * @brief Flash component
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Components.hpp"
#include <glm/glm.hpp>

class Flash_Component : public CS_Component
{
public:
	Flash_Component();
	void ReadFromFile(CS_JsonObject& jsonObject) override;
	void WriteToFile(CS_JsonObject& jsonObject) override;
	void Init() override;
	virtual ~Flash_Component();
	virtual void Update(float dt);
	Flash_Component* Clone() const override;
	void ShowGui() override;
private:
	float timer;
	float lifetime = 0.03f;
};