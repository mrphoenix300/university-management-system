#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>
#include <cstring>

class Person
{
protected:
    std::string name;
public:
    Person(); // Constructor Person no arguments
    Person(std::string name); // Constructor Person with arguments
    Person(const Person &source);
    ~Person(); // Destructor Person
    
    //Get information about Person 
    std::string get_name() const;
    // Set information about Person
    void set_name(std::string name);
    
    // overloaded insertion operator for print Person inforamtion
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
    // overloaded extraction operator for input Person information
    friend std::istream &operator>>(std::istream &in, Person &rhs);
    // overloaded equality operator 
    bool operator==(Person &rhs) ;

};

#endif
