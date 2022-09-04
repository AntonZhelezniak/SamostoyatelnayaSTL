#include"Children.h"
#include"Date.h"
#include"DayProgram.h"
#include"Education.h"
#include"Movie.h"
#include"Show.h"
#include"Time.h"
#include"TvProgram.h"
#include<new>

int main()
{
	Date _date;
	cout << "Input date of program:" << endl;
	cin >> _date;
	system("cls");
	DayProgram tdy(_date);
	int menu=0;
	int submenu = 0;

	string _name, _science, _theme, _directbox;
	int _minage, _maxage, _year;
	Time_ _time;
	
	
	do
	{
		cout << "1. Add tv program" << endl
			<< "2. Show all programs" << endl
			<< "3. Save to txt file" << endl
			<< "4. Load from txt file" << endl
			<< "5. Find all programs after time" << endl
			<< "6. Find all programs by type" << endl
			<< "7. Delete by name" << endl << endl
			<< "0. Exit" << endl;
		cin >> menu;
		system("cls");
		switch (menu)
		{
			system("cls");
		case 1:
			
			cout << "Add type:" << endl
				<< "1. Education" << endl
				<< "2. Children" << endl
				<< "3. Show" << endl
				<< "4. Movie" << endl << endl
				<< "0. Back to main menu" << endl;
			cin >> submenu;
			
			switch (submenu)
			{
				
			case 1:
				cout << "Enter science: ";
				cin >> _science;
				cout << "Enter name: ";
				cin >> _name;
				cout << "Enter time: ";
				cin >> _time;
				try //if OS did not give RAM to create an object
				{ 
					tdy.add(new Education(_science, _name, _time));
				}
				catch (bad_alloc& x) //can not works on VS 2022 or some compilators
				{
					cerr << "Exception: " << x.what() << endl;
				}				
				break;
			case 2:
				cout << "Enter name: ";
				cin >> _name;
				cout << "Enter min age: ";
				cin >> _minage;
				cout << "Enter max age: ";
				cin >> _maxage;
				cout << "Enter time: ";
				cin >> _time;
				try {
					tdy.add(new Children(_minage, _maxage, _name, _time));
				}
				catch (bad_alloc& x)
				{
					cerr << "Exception: " << x.what() << endl;
				}
				break;
			case 3:
				cout << "Enter name: ";
				cin >> _name;
				cout << "Enter theme: ";
				cin >> _theme;
				cout << "Enter time: ";
				cin >> _time;
				try {
					tdy.add(new Show(_theme, _name, _time));
				}
				catch (bad_alloc& x)
				{
					cerr << "Exception: " << x.what() << endl;
				}
				break;
			case 4:
				cout << "Enter name: ";
				cin >> _name;
				cout << "Enter direct box: ";
				cin >> _directbox;
				cout << "Enter year: ";
				cin >> _year;
				cout << "Enter time: ";
				cin >> _time;
				try {
					tdy.add(new Movie(_directbox, _year, _name, _time));
				}
				catch (bad_alloc& x)
				{
					cerr << "Exception: " << x.what() << endl;
				}
				break;
			}
			break;
		case 2:
			tdy.show();
			break;
		case 3:
			tdy.saveToTxt();
			break;
		case 4:
			try//if data in file is incorrect, will be exception + erasing all list
			{
				tdy.loadFromTxt();
				system("cls");//erase cout from date.h
				cout << "Data loaded!" << endl;
			}
			catch (string x)
			{
				cout << x << endl;
			}
			break;
			
		case 5:
			cout << "Enter time: " << endl;
			cin >> _time;
			tdy.findByTime(_time);
			break;
		case 6:
			cout<<"Enter type:"<<endl
				<< "1. Education" << endl
				<< "2. Children" << endl
				<< "3. Show" << endl
				<< "4. Movie" << endl << endl
				<< "0. Back to main menu" << endl;
			cin >> submenu;
			switch (submenu)
			{
			case 1:
				tdy.findByType("Education");
				break;
			case 2:
				tdy.findByType("Children");
				break;
			case 3:
				tdy.findByType("Show");
				break;
			case 4:
				tdy.findByType("Movie");
				break;
			}
			break;
		case 7:
			cout << "Enter name: ";
			cin >> _name;
			tdy.del(_name);
		}

	} while (menu != 0);
}