#pragma once
#include "TvProgram.h"
class Show :
    public TvProgram
{
    string theme;
public:
    Show();
    Show(string _theme, string _name, Time_ _time);

    virtual string toString() const override;
    virtual string type() const override;

    virtual void save(ofstream& file) const override;
    virtual void load(ifstream& file) override;
};


