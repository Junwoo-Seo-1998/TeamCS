/**
 * @file EnemyBullet_Component.hpp
 * @author Sungmin Moon
 * @email elphior0\@gmail.com
 * @brief Enemy Bullet component
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Components.hpp"
#include <glm/glm.hpp>

class EnemyBullet_Component : public CS_Component
{
public:
	EnemyBullet_Component();
	void ReadFromFile(CS_JsonObject& jsonObject) override;
	void WriteToFile(CS_JsonObject& jsonObject) override;
	void Init() override;
	virtual ~EnemyBullet_Component();
	virtual void Update(float dt);
	EnemyBullet_Component* Clone() const override;
	void ShowGui() override;
	float time;
	float default_speed;
};