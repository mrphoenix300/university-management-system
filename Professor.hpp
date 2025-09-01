#ifndef _PROFESSOR_H_
#define _PROFESSOR_H_

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include "Person.hpp"
#include "Course.hpp"
#include "Student.hpp"
#include "Secretary.hpp"

// define classes
class Course;
class Secretary;

class Professor : public Person {
private:
    std::string professorID;
    std::vector<Course*> courses_taught;
public:
    Professor(); // Constructor without arguments
    Professor(std::string n, std::string id); // Constructor with arguments
    Professor(const Professor &source); // Copy constructor
    ~Professor(); // Destructor
    
    // get information about professor
    std::string get_professorid() const;
    
    // overload assignment operator
    Professor &operator=(Professor &rhs);
    
    // overload insertion operator 
    friend std::istream &operator>>(std::istream &is, Professor &professor) {
        getline(is, professor.professorID, ',');
        getline(is, professor.name);
        return is;
    }
    
    // overload extraction operator
    friend std::ostream &operator<<(std::ostream &os, const Professor &professor) {
        os << professor.professorID << "," << professor.name;
        return os;
    }
    
    // assign course to the professor (add a course to the vector courses_taught)
    void assignCourse(Course* course); 
    // assign grade to student 
    void assignGradeToStudent(Course &course, const std::string &studentID, double grade);
    // prints the statistics for each course's grades
    void printStatistics() const;
};

#endif