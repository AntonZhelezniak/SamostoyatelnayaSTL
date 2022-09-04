#pragma once
#include "TvProgram.h"
class Education :
    public TvProgram
{
    string sciense;
public:
    Education();
    Education(string _sciense, string _name, Time_ _time);

    virtual string toString() const override;
    virtual string type() const override;

    virtual void save(ofstream& file) const override;
    virtual void load(ifstream& file) override;
};

