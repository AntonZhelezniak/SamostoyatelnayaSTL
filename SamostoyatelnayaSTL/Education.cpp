#include "Education.h"

Education::Education()
{
	sciense = "NoSciense";
}

Education::Education(string _sciense, string _name, Time_ _time) : TvProgram(_name, _time)
{
	sciense = _sciense;
}

string Education::toString() const
{
	return(sciense + ": " + name + " >>>> " + to_string(time.getHour()) + ":" + to_string(time.getMinutes()));
}

string Education::type() const
{
	return "Education";
}

void Education::save(ofstream& file) const
{
	file<<type()<<endl<<name<< endl<< sciense << endl << to_string(time.getHour())<<endl<< to_string(time.getMinutes())<<endl;
}

void Education::load(ifstream& file)
{
	string temp;
	file >> name >> sciense >> temp;
	time.setHour(stoi(temp));
	file >> temp;
	time.setMinutes(stoi(temp));
}
