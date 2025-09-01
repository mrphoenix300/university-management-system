#ifndef _SECRETARY_H_
#define _SECRETARY_H_

#include <iostream>
#include <vector>
#include "Person.hpp"
#include "Student.hpp"
#include "Professor.hpp"
#include "Course.hpp"

// define the classes
class Course; 
class Student;
class Professor;

class Secretary {
private:
    const unsigned ECTS_required_to_gradaute {240}; 
    const unsigned semesters {8}; 
    bool is_semester_end {false};
    std::vector<Course*> courses;
    std::vector<Student*> students;
    std::vector<Professor*> professors;
public:
    Secretary(); // Constructor with no arguments 
    Secretary(const Secretary &source); // Copy Constructor Secretary
    ~Secretary(); // Destructor Secretary
    
    void add_student(Student &student); // just add student to vector students
    void add_professor(Professor &professor); // just add professor to vector professors
    void add_course(Course &course); // just add course to vector courses
    // modify objects
    Student* modify_student(const std::string &student_id, const unsigned choice_attribute);  // choice_attribute is the variable which contains users attribute choice to modify
    Professor* modify_professor(const std::string &professor_id); 
    Course* modify_course(const std::string &course_id, const unsigned choice_attribute);
    
    // delele objects 
    void delete_student(const std::string &student_id);
    void delete_professor(const std::string &professor_id);
    void delete_course(const std::string &course_id);
    
    // find objects
    Professor* find_professor(const std::string &professor_id);
    Student* find_student(const std::string &student_id);
    Course* find_course(const std::string &course_id);
    
    // functions about student and professor
    bool reg_stud_to_course(const std::string course_id, Student &student);
    bool set_professor(const std::string course_id, Professor &prof);
    
    std::vector<Student*> getStudentsInCourse(const std::string course_id) const;
    bool isProfessorAssignedToCourse(const std::string professor_id, const std::string course_id);

    bool professor_give_grade(Course &given_course, const std::string student_id, const std::string professor_id, double grade);

    void change_students_semester();
    
    // some print functions about students, professors and courses
    void printStudents() const;
    void printProfessors() const;
    void printCourses() const;
    // prints out the grade statistics of each  professor's course 
    void printStatistics(Professor &professor) const;
    // prints out the graduates
    void printGraduates() const;
    // return true if student passed all the mandatory courses else false
    bool checkpassedmandatory(const Student &student) const;
};

#endif