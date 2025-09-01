#include "Person.hpp"

Person::Person() // Constructor Person no arguments implementation
    : name {""} {
}

Person::Person(std::string name) // Constructor Person with arguments implementation
    : name {name} {
}

Person::Person(const Person &source)
    : name(source.name) {
}

Person::~Person() { // Destructor Person implementation
}

//Get information about Person implementation
std::string Person::get_name() const { return name; } 
// Set information about Person
void Person::set_name(std::string name) { this->name = name; }


// overloaded insertion operator for print Person inforamtion implementation
std::ostream &operator<<(std::ostream &os, const Person &rhs) {

    os << rhs.get_name() << " |\t" << std::endl;
    return os;
}

// overloaded extraction operator for input Person information implementation
std::istream &operator>>(std::istream &in, Person &rhs) {
    std::string temp_name;
    std::cout << "Please give the name of the person: ";
    in >> temp_name;
    rhs.set_name(temp_name);
    return in;
}

// overloaded equality operator implementation
bool Person::operator==(Person &rhs)  {
    if (name.compare(rhs.get_name()) == 0) {
        return true;
    }
    return false;
}