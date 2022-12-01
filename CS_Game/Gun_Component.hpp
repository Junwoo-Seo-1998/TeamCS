/**
 * @file Gun_Component.hpp
 * @author Sungmin Moon
 * @email elphior0\@gmail.com
 * @brief Gun and shooting mechanics management.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_Components.hpp"
#include "Bullet_Component.hpp"
#include "CS_ObjectManager.hpp"
#include "CS_SoundManager.hpp"

enum ShootMethod
{
	Pistol,
	Gatling,
	Shotgun
};

enum CoolDown
{
	Cooldown,
	Ready
};

class Gun_Component :public CS_Component
{
public:
	Gun_Component();
	void ReadFromFile(CS_JsonObject& jsonObject) override;
	void WriteToFile(CS_JsonObject& jsonObject) override;
	void Init() override;
	virtual ~Gun_Component();
	virtual void Update(float dt);
	void MakeBullet(glm::vec2 position, glm::vec2 velocity, glm::vec2 size);
	Gun_Component* Clone() const override;
	void UpdateCooltime(float dt);
	void ShowGui() override;

        float GetGuntimer() const;
        CoolDown GetStatus() const;
        float GetCooltime() const;
private:
	bool up, down, left, right;
	CS_Object* bullet;
	CS_Object* muzzleflash;
	glm::vec2 bulletsize = { 40, 20 };
	glm::vec2 gatlingsize = { 60, 30 };
	const float bullet_speed = 700.f;
	ShootMethod method;
	CoolDown status;
	int ammocount;
	float cooltime;
	float guntimer;
	float next_shot_timer, barrage_timer;
	float gun_distance = 50.f;
	glm::vec2 mf_size = { 150.f, 150.f };
	std::string mf_texture = "Textures/MuzzleFlash_Friendly.png";
	
};