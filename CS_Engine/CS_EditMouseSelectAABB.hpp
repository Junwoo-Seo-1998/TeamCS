#pragma once
class CS_Object;

class CS_EditMouseSelectAABB
{
public:
    void SetParent(CS_Object* pParent);
    void Update();

	bool IsMouseIn();
private:
	void CheckMouseIn();
	bool isMouseIn=false;
    CS_Object * m_Parent=nullptr;
};
