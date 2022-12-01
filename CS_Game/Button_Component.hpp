/**
 * @file Bullet_Component.hpp
 * @author Sungmin Moon
 * @email elphior0\@gmail.com
 * @brief Bullet component
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "CS_Components.hpp"
#include "CS_SoundManager.hpp"
class Button_Component : public CS_Component
{
public:
    Button_Component();
    ~Button_Component() override;
    void ReadFromFile(CS_JsonObject& jsonObject) override;
    void WriteToFile(CS_JsonObject& jsonObject) override;
    void Init() override;
    void Update(float dt) override;
    CS_Component* Clone() const override;
    void ShowGui() override;
};
