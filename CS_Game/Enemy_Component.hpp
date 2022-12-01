/**
 * @file Enemy_Component.hpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief For basic enemies tracing the player.
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
class Enemy_Component :public CS_Component
{
public:
	Enemy_Component();
        void ReadFromFile(CS_JsonObject& jsonObject) override;
	void WriteToFile(CS_JsonObject& jsonObject) override;
        void Init() override;
	virtual ~Enemy_Component();
	virtual void Update(float dt);
    Enemy_Component* Clone() const override;
	void ShowGui() override;
	void trace_player(void);
	void patrolling(void);
	void suicide(void);
private:
    bool patrol;
	float speed;
	float trace_x;
	float trace_y;
	float rotation;
	CS_Object* explosion;
	std::string animation = "Textures/Explosion_Animation.png";
};