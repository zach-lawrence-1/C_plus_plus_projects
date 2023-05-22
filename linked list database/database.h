#ifndef DATABASE
#define DATABASE

#include<iostream>
using std::string, std::cout, std::cin, std::endl;

class Employee
{
    private:
        string company;
        string name;
        int id;
        string job;
    
    public:
        //getters and setters
        string GetCompany() const {return this->company;};
        string GetName() const {return this->name;};
        int GetID() const {return this->id;};
        string GetJob() const {return this->job;};

        void SetCompany(string Company) {company = Company;};
        void SetName(string Name) {name = Name;};
        void SetID(int ID) {id = ID;};
        void SetJob(string Job) {job = Job;};

        //constructors and operator overloaders
        Employee();
        Employee(string Company, string Name, int ID, string Job);
		bool operator<(const Employee& emp);
};

#endif