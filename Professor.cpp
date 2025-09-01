#include "Professor.hpp"

// Constructor without arguments
Professor::Professor() 
    : Person(" "), professorID(" ") {
}

// Constructor with arguments
Professor::Professor(std::string n, std::string id)
    : Person(n), professorID(id) {
}

// Copy constructor
Professor::Professor(const Professor &source)
    : Person(source), professorID(source.professorID) {

        for (auto course : courses_taught) {
            delete course;
        }
        courses_taught.clear();

        for (auto course : source.courses_taught) {
            courses_taught.push_back(new Course(*course));
        }
}

Professor::~Professor() {
    for (auto course : courses_taught) {
        delete course;
    }
    courses_taught.clear();
}

// get information about professor
std::string Professor::get_professorid() const {
    return professorID;
}

// overload assignment operator
Professor &Professor::operator=(Professor &rhs) {

    if (this == &rhs)
        return *this;
    name = rhs.name;
    professorID = rhs.professorID;

    for (auto course : courses_taught) {
        delete course;
    }
    courses_taught.clear();

    for (auto course : rhs.courses_taught) {
        courses_taught.push_back(course);
    }
    
    return *this;
}

// Description: Assigns a grade to a student in a specific course.
// Parameters:
// course (Course&): The course in which the grade is to be assigned.
// studentID (const std::string&): The ID of the student receiving the grade.
// grade (double): The grade to be assigned.
// Functionality: Assigns the specified grade to the student in the given course.
void Professor::assignGradeToStudent(Course &course, const std::string &studentID, double grade) {
    course.assignGrade(studentID, grade);
}

// Description: Assigns a new course to the professor.
// Parameters:
// course (Course*): Pointer to the course to be assigned.
// Functionality: Adds the specified course to the list of courses taught by the professor.
void Professor::assignCourse(Course* course) {
    courses_taught.push_back(course);
}

// Description: Prints the statistics for each course's grades.
// Functionality: Iterates over the courses taught by the professor and calls the printStatistics method for each course to display its grade statistics.
void Professor::printStatistics() const {
    for (auto course : courses_taught) {
        course->printStatistics();
    }
}