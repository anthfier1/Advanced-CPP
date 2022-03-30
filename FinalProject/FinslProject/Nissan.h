// Anthony Fierro

#pragma once
#ifndef NISSAN_H
#define NISSAN_H


#include "Cars.h"
#include <iostream>
#include <string>
using namespace std;

class Nissan : public Cars
{
public:
	Nissan();
	~Nissan();
	virtual void showDetails(Cars &) override;
};

#endif // !NISSAN_H
