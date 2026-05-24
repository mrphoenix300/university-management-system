#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <vector>
#include <string>
#include "Person.hpp"

class Course;

class Student : public Person {
private:
    std::string studentID;
    unsigned semester;
    unsigned ECTS;
    bool pending_graduation;
    std::vector<Course*> courses;
public:
    Student();
    Student(std::string n, std::string am, unsigned y, unsigned p);
    Student(const Student &source);
    ~Student();
    
    std::string get_studentID() const;
    unsigned get_semester() const;
    unsigned get_ECTS() const;
    bool get_pending_graduation() const;
    
    void set_ID(std::string studentID);
    void set_semester(unsigned semester);
    void set_ECTS(unsigned ECTS);
    void set_pending_graduation(bool pending_graduation);
    
    Student &operator=(const Student &rhs);
    
    friend std::ostream &operator<<(std::ostream& os, const Student& student);
    friend std::istream &operator>>(std::istream& is, Student& student);
    
    void enrollInCourse(Course* course);
    void printGrades() const;
    void printSemesterGrades() const;
};

#endif