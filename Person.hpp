#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
public:
    Person(); 
    Person(std::string name); 
    Person(const Person &source);
    
    virtual ~Person();

    std::string get_name() const;
    void set_name(std::string name);
    
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
    friend std::istream &operator>>(std::istream &in, Person &rhs);
    bool operator==(const Person &rhs) const;
};

#endif