#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <vector>
#include <string>
#include "Person.hpp"
#include "Course.hpp"
#include "Secretary.hpp"

class Student : public Person {
private:
    std::string studentID;
    unsigned semester;
    unsigned ECTS;
    bool pending_graduation {(semester > 8)};
    std::vector<Course*> courses;
public:
    Student();
    Student(std::string n,std::string am, unsigned y, unsigned p);
    Student(const Student &source);
    ~Student();
    
    // some functions to get information from student
    std::string get_studentID() const;
    unsigned get_semester() const;
    unsigned get_ECTS() const;
    bool get_pending_graduation() const;
    
    // some functions to set information to student
    void set_ID(std::string studentID);
    void set_semester(unsigned semester);
    void set_ECTS(unsigned ECTS);
    void set_pending_graduation(bool pending_graduation);
    
    // overload assignment operator
    Student &operator=(Student &rhs);
    
    // overload the operator of extraction
    friend std::ostream &operator<<(std::ostream& os, const Student& student) {
        os << student.studentID << "," << student.name << "," << student.semester << "," << student.ECTS;
        return os;
    }
    
    // overload the operator of insertion
    friend std::istream &operator>>(std::istream& is, Student& student) {
        getline(is, student.studentID, ',');
        getline(is, student.name, ',');
        std::string semesterStr;
        getline(is, semesterStr, ',');
        student.semester = std::stoi(semesterStr); // Convert string to int
        std::string ectsStr;
        getline(is, ectsStr);
        student.ECTS = std::stoi(ectsStr);
        return is;
    }
    // some functions about students
    void enrollInCourse(Course* course);
    void printGrades() const;
    void printSemesterGrades() const;
};

#endif