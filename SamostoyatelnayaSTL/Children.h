#pragma once
#include "TvProgram.h"
class Children :
    public TvProgram
{
    int minAge;
    int maxAge;
public:

    Children();
    Children(int _minAge, int _maxAge, string _name, Time_ _time);

    virtual string toString() const override;
    virtual string type() const override;

    virtual void save(ofstream& file) const override;
    virtual void load(ifstream& file) override;
};


