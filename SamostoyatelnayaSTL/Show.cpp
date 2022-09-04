#include "Show.h"

Show::Show()
{
	theme = "NoTheme";
}

Show::Show(string _theme, string _name, Time_ _time) : TvProgram(_name, _time)
{
	theme = _theme;
}

string Show::toString() const
{
	return(theme + " " + name + " >>>> " + to_string(time.getHour()) + ":" + to_string(time.getMinutes()));
}

string Show::type() const
{
	return "Show";
}

void Show::save(ofstream& file) const
{
	file << type()<< endl << name <<endl<<theme<< endl << to_string(time.getHour()) << endl << to_string(time.getMinutes()) << endl;
}

void Show::load(ifstream& file)
{
	string temp;
	file >> name >> theme >> temp;
	time.setHour(stoi(temp));
	file >> temp;
	time.setMinutes(stoi(temp));
}
