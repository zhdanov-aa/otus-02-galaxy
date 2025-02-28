#include <FuelLevel.h>

FuelLevel::FuelLevel(int level)
    : m_nLevel(level)
{
}

int operator == (const FuelLevel &level1, const FuelLevel &level2)
{
    return level1.m_nLevel == level2.m_nLevel;
}

int operator != (const FuelLevel &level1, const FuelLevel &level2)
{
    return level1.m_nLevel != level2.m_nLevel;
}

int operator < (const FuelLevel &level1, const FuelLevel &level2)
{
    return level1.m_nLevel < level2.m_nLevel;
}

FuelLevel operator - (const FuelLevel &level1, const FuelLevel &level2)
{
    return FuelLevel(level1.m_nLevel - level2.m_nLevel);
}