/**
 * @file Straight_Enemy_Component.hpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief Component for enemies moving straightforwards.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Components.hpp"
#include "CS_SoundManager.hpp"
#include <glm/glm.hpp>
class Straight_Enemy_Component :public CS_Component
{
public:
	Straight_Enemy_Component();
	void ReadFromFile(CS_JsonObject& jsonObject) override;
	void WriteToFile(CS_JsonObject& jsonObject) override;
	void Init() override;
	virtual ~Straight_Enemy_Component();
	virtual void Update(float dt);
	Straight_Enemy_Component* Clone() const override;
	void ShowGui() override;
	
private:
	float speed;

	CS_Object* explosion;
	std::string animation = "Textures/Explosion_Animation.png";
};