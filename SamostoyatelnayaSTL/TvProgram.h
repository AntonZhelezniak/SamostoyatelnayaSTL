#pragma once
#include<iostream>
#include<string>
#include"Time.h"
#include <fstream>
using namespace std;
class TvProgram
{
protected:
	string name;
	Time_ time;

public:
	TvProgram();
	TvProgram(string name, Time_ time);
	TvProgram(string name);
	~TvProgram();

	void setName(string _name);
	void setTime(Time_ _time);
	string getName() const;
	Time_ getTime() const;

	virtual void save(ofstream& file) const=0;
	virtual void load(ifstream& file) = 0;
	virtual string toString() const = 0;
	virtual string type() const = 0;
};

