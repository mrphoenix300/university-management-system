#ifndef _COURSE_H_
#define _COURSE_H_


#include <iostream>
#include <vector>
#include <string>
#include "Student.hpp"
#include "Professor.hpp"

class Student;
class Professor;

class Course {
private:
    std::string courseID;
    std::string name;
    int units;
    std::string type; // Compulsary or Elective
    unsigned semester ; 
    std::vector<Student*> enrolled_students;
    std::vector<Professor*> professors;
    std::map<std::string, double> studentGrades;
public:
    Course();
    Course(std::string c, std::string n, int u, std::string t, unsigned s);
    Course(const Course& other);
    ~Course();

    std::string get_courseid() const;
    std::string get_name() const;
    int get_units() const;
    std::string get_type() const;
    unsigned get_semester() const;
    std::vector<Professor*> get_professors() const;
    std::vector<Student*> get_enrolled_students() const;
    
    void set_courseid(std::string course_id);
    void set_name(std::string course_name);
    void set_units(int course_units);
    void set_type(std::string course_type);
    void set_semester(unsigned course_semester);

    Course &operator=(Course &rhs);
    friend std::ostream& operator<<(std::ostream& os, const Course& course) {
        os << course.courseID << "," << course.name << "," << course.type << "," << course.semester << "," << course.units;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Course& course) {
        getline(is, course.courseID, ',');
        getline(is, course.name, ',');
        std::string unitsStr;
        getline(is, unitsStr, ',');
        course.units = std::stoi(unitsStr);
        getline(is, course.type, ',');
        std::string semesterStr;
        getline(is, semesterStr);
        course.semester = std::stoi(semesterStr);
        return is;
    }
    
    void add_professors(Professor prof);
    void enrollStudent(Student* student);
    void printEnrolledStudents() const;
    
    
    void assignGrade(const std::string& studentID, double grade);
    double getGrade(const std::string& studentID) const;
    bool checkIfPassed(const std::string& studentID) const;
    void printStatistics() const;
};

#endif 