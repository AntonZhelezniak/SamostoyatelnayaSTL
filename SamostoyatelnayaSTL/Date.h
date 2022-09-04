#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int year;
	int month;
	int day;
	bool isLeapYear(); 
	int monthDays(); 
	void nextDate(); 
	void prevDate();


public:
	Date();
	Date(int year, int month, int day);
	~Date();
	Date(const Date& obj);
	//-------------

	void showDate();


	//------------------

	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	const char* getSMonth(const char* = "EN");
	void setDay(int day);
	int getDay();

	bool valid(); 

	//-----------------

	bool operator == (const Date& obj) const&;
	bool operator != (const Date& obj) const&;
	bool operator > (const Date& obj) const&;
	bool operator < (const Date& obj) const&;
	bool operator >= (const Date& obj) const&;
	bool operator <= (const Date& obj) const&;

	Date& operator = (const Date& obj);
	Date& operator += (int n);
	Date& operator -= (int n);

	Date operator + (int n);
	Date operator - (int n);
	
	friend Date operator + (int n, Date a);
	friend Date operator - (int n, Date a);
	friend int operator + (Date a, Date b);
	friend int operator - (Date a, Date b);

	friend istream& operator>>(istream& in, Date& d);
	friend ostream& operator<<(ostream& in,const Date d);

	Date& operator -- ();
	Date operator -- (int n);
	Date& operator ++ ();
	Date operator ++ (int n);
	


};

