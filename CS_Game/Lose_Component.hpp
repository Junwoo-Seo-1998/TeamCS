#pragma once
#include"CS_Components.hpp"
class Lose_Component:public CS_Component
{
public:
    Lose_Component();
    ~Lose_Component() override;
    void ReadFromFile(CS_JsonObject& jsonObject) override;
    void WriteToFile(CS_JsonObject& jsonObject) override;
    void Init() override;
    void Update(float dt) override;
    CS_Component* Clone() const override;
    void ShowGui() override;
};
