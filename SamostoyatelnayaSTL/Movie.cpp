#include "Movie.h"

Movie::Movie()
{
	directBox = "NoBox";
	year = 18;
}

Movie::Movie(string _directBox, int _year, string _name, Time_ _time) : TvProgram(_name, _time)
{
	directBox = _directBox;
	year = _year;
}

string Movie::toString() const
{
	return(directBox + " " + to_string(year) + " " + name + " >>>> " + to_string(time.getHour()) + ":" + to_string(time.getMinutes()));
}

string Movie::type() const
{
	return "Movie";
}

void Movie::save(ofstream& file) const
{
	file << type() << endl << name <<endl<< directBox << endl<<year << endl << to_string(time.getHour()) << endl << to_string(time.getMinutes()) << endl;
}

void Movie::load(ifstream& file)
{
	string temp;
	file >> name >> directBox>>year >> temp;
	time.setHour(stoi(temp));
	file >> temp;
	time.setMinutes(stoi(temp));
}
