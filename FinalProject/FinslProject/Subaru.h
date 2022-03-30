// Anthony Fierro

#pragma once
#ifndef SUBARU_H
#define SUBARU_H

#include "Cars.h"
#include <iostream>
#include <string>
using namespace std;

class Subaru : public Cars
{
public:
	Subaru();
	~Subaru();
	virtual void showDetails(Cars &) override;
};


#endif // !SUBARU_H

