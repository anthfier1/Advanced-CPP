// Anthony Fierro

#pragma once
#ifndef CHEVY_H
#define CHEVY_H


#include <iostream>
#include <string>
using namespace std;

class Chevy : public Cars
{
public:
	Chevy();
	~Chevy();
	virtual void showDetails(Cars &) override;
};


#endif // !CHEVY_H
