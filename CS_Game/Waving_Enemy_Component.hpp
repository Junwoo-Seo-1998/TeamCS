/**
 * @file Waving_Enemy_Component.hpp
 * @author Chunmook Kim
 * @email kimmistral\@naver.com
 * @brief Component for waving enemies.
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
class Waving_Enemy_Component : public CS_Component
{
public:
	Waving_Enemy_Component();
	virtual ~Waving_Enemy_Component();
	virtual void ReadFromFile(CS_JsonObject& jsonObject);
	void WriteToFile(CS_JsonObject& jsonObject) override;
	virtual void Init(void);
	virtual void Update(float dt);
	virtual CS_Component* Clone() const;
	virtual void ShowGui();
	void Waving_movement(float dt);
	void Shoot(float dt);
	
private:
	float amplitude;
	float time;
	float guntimer;
	float random;
	int randomrange = 100;
	float randomrange_doubled = 200.f;
	float default_speed = 400.f;
	CS_Object* enemybullet;
	CS_Object* muzzleflash;
        std::string bat_animation = "Textures/Bat_Animation.png";
     	std::string mf_texture = "Textures/MuzzleFlash_Enemy.png";
	glm::vec2 mf_size = { 150.f, 150.f };
	CS_Object* explosion;
	std::string animation = "Textures/Explosion_Animation.png";
};

