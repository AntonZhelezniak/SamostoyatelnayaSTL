#include "TvProgram.h"

TvProgram::TvProgram()
{
    name = "";
}

TvProgram::TvProgram(string name, Time_ time): name(name), time(time)
{
}

TvProgram::TvProgram(string name): name(name)
{
}

TvProgram::~TvProgram()
{
}

void TvProgram::setName(string _name)
{
    name = _name;
}

void TvProgram::setTime(Time_ _time)
{
    time = _time;
}

string TvProgram::getName() const
{
    return name;
}

Time_ TvProgram::getTime() const
{
    return time;
}
