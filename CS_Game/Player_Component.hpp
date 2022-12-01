/**
 * @file Player_Component.hpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief Player control and management.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "SphereCollider_Component.hpp"
#include "CS_Components.hpp"

class Player_Component :public CS_Component
{
public:
    void ReadFromFile(CS_JsonObject& jsonObject) override;
	void WriteToFile(CS_JsonObject& jsonObject) override;
    void Init() override;
    Player_Component();
    virtual ~Player_Component();
    virtual void Update(float dt);
    Player_Component* Clone() const override;
	void ShowGui() override;
	int GetHealth() const;
        int GetMaxHealth()const;
private:
    glm::vec2 last_pos;
    bool up, down, left, right;
	void PlayerInput();
	CS_Object * gun;
    int max_health = 7;
	int health;
	float timer;
	float invincibility = 0.05f;
	SphereCollider_Component* collider;
	bool invincible_mode;
};