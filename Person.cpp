#include "Person.hpp"

Person::Person() : name("") {}

Person::Person(std::string name) : name(name) {}

Person::Person(const Person &source) : name(source.name) {}

Person::~Person() {}

std::string Person::get_name() const { return name; } 

void Person::set_name(std::string name) { this->name = name; }

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << rhs.get_name();
    return os;
}

std::istream &operator>>(std::istream &in, Person &rhs) {
    std::string temp_name;
    std::cout << "Please give the name of the person: ";
    in >> temp_name;
    rhs.set_name(temp_name);
    return in;
}

bool Person::operator==(const Person &rhs) const {
    return name == rhs.name;
}