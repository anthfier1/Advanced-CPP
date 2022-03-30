#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
private:
	int attackPoints, healthPoints;
	string specialSkill;

public:
	int getAttackPoints();
	int getHealthPoints();


};

#endif // !CHARACTER

