#include "database.h"

using std::string;

Employee::Employee() : company(""), name(""), id(0), job("") {}

Employee::Employee(string Company, string Name, int ID, string Job) : company(Company), name(Name), id(ID), job(Job)
{}

//compare all data in an instance of an object to another object for sorting
bool Employee::operator<(const Employee& emp)
{
    if (this->company < emp.company)
    {
        return true;
    }
    else if (this->company == emp.company)
    {
        if (this->name < emp.name)
        {
            return true;
        }
        else if (this->name == emp.name)
        {
            if (this->id < emp.id)
            {
                return true;
            }
            else if (this->id == emp.id)
            {
                if (this->job < emp.job)
                {
                    return true;
                }
            }
        }
    }
    return false;
}