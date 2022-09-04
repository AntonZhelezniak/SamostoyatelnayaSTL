#include "DayProgram.h"

DayProgram::DayProgram()
{
}

DayProgram::DayProgram(Date date): date(date)
{
}


DayProgram::~DayProgram()
{
}

void DayProgram::show() const
{
	cout << "=========Day program "<<date<<"==========" << endl;
	for (list<TvProgram*>::const_iterator i = programs.begin();i!=programs.end(); i++)
	{
		cout<<(*(i))->toString()<<endl;
	}
	cout << "==============================" << endl;
}

void DayProgram::add(TvProgram* x)
{
	programs.push_back(x);
	sortByTime();//автоматическая сортировка по времени
}

void DayProgram::del(string _name)
{
	list<TvProgram*>::iterator i;
	for (i = programs.begin();i != programs.end();)
	{
		list<TvProgram*>::iterator del = i;
		i++;
		if ((*(del))->getName() == _name)
		{
			programs.erase(del);
			break;
		}
	}
	if (i == programs.end())
	{
		cout << "No name matching!" << endl;
	}
	else
	{
		cout << "Deleted!" << endl;
	}
}

void DayProgram::sortByTime()
{
	programs.sort([](const TvProgram* i, const TvProgram* j) {return (*i).getTime() < (*j).getTime(); });//анонимная функция
}



void DayProgram::findByTime(Time_ x)
{

	for (TvProgram* i : programs)
	{
		if ((*i).getTime() >= x)
		{
			cout << i->toString() << endl;
		}
	}
}

void DayProgram::findByType(string _type)
{
	for (TvProgram* i : programs)
	{
		if ((*i).type() == _type)
		{
			cout << i->toString() << endl;
		}
	}
}

void DayProgram::saveToTxt() const
{
	ofstream file("DayProgram.txt");
	if (file.is_open())
	{
		file << date << endl;
		for (TvProgram* i : programs)
		{
			i->save(file);
		}
		cout << "Data saved to file!" << endl;
		file.close();
	}
	else cout << "Error saving file!" << endl;
}

void DayProgram::loadFromTxt()
{
	ifstream file("DayProgram.txt");
	TvProgram* ptr = nullptr;
	if (file.is_open())
	{
		programs.clear();//delete all elements
		file >> date;
		while (!file.eof())
		{
			string line;
			getline(file, line);
			if (line == "Education")
			{
				ptr = new Education();
				ptr->load(file);
				programs.push_back(ptr);
			}
			else if (line == "Children")
			{
				ptr = new Children();
				ptr->load(file);
				programs.push_back(ptr);
			}
			else if (line == "Show")
			{
				ptr = new Show();
				ptr->load(file);
				programs.push_back(ptr);
			}
			else if (line == "Movie")
			{
				ptr = new Movie();
				ptr->load(file);
				programs.push_back(ptr);
			}
			else if(line.size()!=0){
				programs.clear();//delete all elements
				throw (string)"Error reading from file";
			}
		}
		file.close();
	}
	else cout << "Error loading from file!" << endl;
}


