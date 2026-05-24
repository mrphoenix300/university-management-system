#ifndef _SECRETARY_H_
#define _SECRETARY_H_

#include <iostream>
#include <vector>
#include <string>
#include "Person.hpp"
#include "Student.hpp"
#include "Professor.hpp"
#include "Course.hpp"

class Secretary {
private:
    const unsigned ECTS_required_to_gradaute {240}; 
    const unsigned semesters {8}; 
    bool is_semester_end {false};
    std::vector<Course*> courses;
    std::vector<Student*> students;
    std::vector<Professor*> professors;
public:
    Secretary(); 
    Secretary(const Secretary &source); 
    ~Secretary(); 
    
    bool add_student(Student &student); 
    bool add_professor(Professor &professor); 
    bool add_course(Course &course); 
    
    Student* modify_student_name(const std::string &student_id, const std::string &new_name);
    Student* modify_student_semester(const std::string &student_id, unsigned new_semester);
    Student* modify_student_ects(const std::string &student_id, unsigned new_ects);
    
    Professor* modify_professor_name(const std::string &professor_id, const std::string &new_name); 
    
    Course* modify_course_name(const std::string &course_id, const std::string &new_name);
    Course* modify_course_units(const std::string &course_id, int new_units);
    Course* modify_course_type(const std::string &course_id, const std::string &new_type);
    Course* modify_course_semester(const std::string &course_id, unsigned new_semester);
    
    void delete_student(const std::string &student_id);
    void delete_professor(const std::string &professor_id);
    void delete_course(const std::string &course_id);
    
    Professor* find_professor(const std::string &professor_id);
    Student* find_student(const std::string &student_id);
    Course* find_course(const std::string &course_id);
    
    bool reg_stud_to_course(const std::string course_id, Student &student);
    bool set_professor(const std::string course_id, Professor &prof);
    
    std::vector<Student*> getStudentsInCourse(const std::string course_id) const;
    bool isProfessorAssignedToCourse(const std::string professor_id, const std::string course_id);
    bool professor_give_grade(Course &given_course, const std::string student_id, const std::string professor_id, double grade);
    void change_students_semester();
    
    void printStudents() const;
    void printProfessors() const;
    void printCourses() const;
    void printStatistics(Professor &professor) const;
    void printGraduates() const;
    bool checkpassedmandatory(const Student &student) const;
};

#endif