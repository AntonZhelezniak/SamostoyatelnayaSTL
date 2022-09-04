#pragma once
#include"Children.h"
#include"Date.h"
#include"Education.h"
#include"Movie.h"
#include"Show.h"
#include"TvProgram.h"
#include<list>
#include<algorithm>
class DayProgram
{
	Date date;
	list<TvProgram*>programs;
public:
	DayProgram();
	DayProgram(Date date);
	~DayProgram();

	void show() const;
	void add(TvProgram* x);
	void del(string _name);
	void sortByTime();
	void findByTime(Time_ x);//поиск что после этого времени
	void findByType(string _type); //поиск по типу передачи

	void saveToTxt() const;
	void loadFromTxt();

};

