#pragma once
#include "TvProgram.h"
class Movie :
    public TvProgram
{
    string directBox;
    int year;
public:
    Movie();
    Movie(string _directBox, int _year, string _name, Time_ _time);

    virtual string toString() const override;
    virtual string type() const override;

    virtual void save(ofstream& file) const override;
    virtual void load(ifstream& file) override;
};

