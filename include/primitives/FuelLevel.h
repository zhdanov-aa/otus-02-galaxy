#ifndef __FUELLEVEL_H_INCLUDED__
#define __FUELLEVEL_H_INCLUDED__

class FuelLevel
{
    int m_nLevel;

public:
    FuelLevel(int level);

    friend int operator == (const FuelLevel &level1, const FuelLevel &level2);
    friend int operator != (const FuelLevel &level1, const FuelLevel &level2);
    friend int operator < (const FuelLevel &level1, const FuelLevel &level2);
    
    friend FuelLevel operator - (const FuelLevel &level1, const FuelLevel &level2);
};

#endif