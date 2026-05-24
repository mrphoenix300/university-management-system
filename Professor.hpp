#ifndef _PROFESSOR_H_
#define _PROFESSOR_H_

#include <iostream>
#include <vector>
#include <string>
#include "Person.hpp"

class Course;

class Professor : public Person {
private:
    std::string professorID;
    std::vector<Course*> courses_taught;
public:
    Professor(); 
    Professor(std::string n, std::string id); 
    Professor(const Professor &source); 
    ~Professor(); 
    
    std::string get_professorid() const;
    Professor &operator=(const Professor &rhs);
    
    friend std::istream &operator>>(std::istream &is, Professor &professor);
    friend std::ostream &operator<<(std::ostream &os, const Professor &professor);
    
    void assignCourse(Course* course); 
    void assignGradeToStudent(Course &course, const std::string &studentID, double grade);
    void printStatistics() const;
};

#endif