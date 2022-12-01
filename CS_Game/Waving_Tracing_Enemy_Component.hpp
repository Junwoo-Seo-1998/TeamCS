/**
 * @file Waving_Tracing_Enemy_Component.hpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief Component for waving, tracing enemy.
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
class Waving_Tracing_Enemy_Component : public CS_Component
{
public:
	Waving_Tracing_Enemy_Component();
	virtual ~Waving_Tracing_Enemy_Component();
	virtual void ReadFromFile(CS_JsonObject& jsonObject);
	void WriteToFile(CS_JsonObject& jsonObject) override;
	virtual void Init(void);
	virtual void Update(float dt);
	virtual CS_Component* Clone() const;
	virtual void ShowGui();
	void Waving_Tracing_movement(float dt);
	
private:
	float amplitude;
	float time;
	float speed;
	float trace_x;
	float trace_y;
	float rotation;
	CS_Object* explosion;
	std::string animation = "Textures/Explosion_Animation.png";
};

