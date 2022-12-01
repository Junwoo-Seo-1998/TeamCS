#include "CS_Components.hpp"
#include "CS_Object.hpp"



CS_Component::CS_Component(CS_ComponentTypes m_component_type, bool shouldBeOnlyOne)
:is_Dead(false), m_Parent(nullptr),
 m_component_type(m_component_type), ShouldBeOnlyOne(shouldBeOnlyOne)
{
}

CS_Component::~CS_Component()
{
}

void CS_Component::Init(void)
{
}



void CS_Component::SetParent(CS_Object * pParent)
{
    m_Parent = pParent;
}

CS_Object * CS_Component::GetParent() const
{
    return m_Parent;
}

CS_ComponentTypes CS_Component::GetComponentType()
{
    return m_component_type;
}

bool CS_Component::ShouldBeOnlyOneInOneObject() const
{
	return ShouldBeOnlyOne;
}
