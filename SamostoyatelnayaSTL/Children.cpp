#include "Children.h"

Children::Children()
{
	minAge = 0;
	maxAge = 10;
}

Children::Children(int _minAge, int _maxAge, string _name, Time_ _time) : TvProgram(_name, _time)
{
	if (_minAge >= 0 && _minAge <= _maxAge)
	{
		minAge = _minAge;
		maxAge = _maxAge;
	}
	else
	{
		minAge = 0;
		maxAge = 10;
	}
}

string Children::toString() const
{
	return(name + " " + to_string(minAge) + "-" + to_string(maxAge) + " >>>> " + to_string(time.getHour()) + ":" + to_string(time.getMinutes()));
}

string Children::type() const
{
	return "Children";
}

void Children::save(ofstream& file) const
{
	file << type()<<endl <<name << endl << minAge<<endl<<maxAge << endl << to_string(time.getHour()) << endl << to_string(time.getMinutes()) << endl;
}

void Children::load(ifstream& file)
{
	string temp;
	file >>  name >> minAge >>maxAge>>temp;
	time.setHour(stoi(temp));
	file >> temp;
	time.setMinutes(stoi(temp));
}
