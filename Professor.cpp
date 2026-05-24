#include "Professor.hpp"
#include "Course.hpp"

Professor::Professor() : Person(" "), professorID(" ") {}

Professor::Professor(std::string n, std::string id) : Person(n), professorID(id) {}

Professor::Professor(const Professor &source) : Person(source), professorID(source.professorID) {
    courses_taught = source.courses_taught;
}

Professor::~Professor() {
    courses_taught.clear();
}

std::string Professor::get_professorid() const { return professorID; }

Professor &Professor::operator=(const Professor &rhs) {
    if (this == &rhs) return *this;
    name = rhs.name;
    professorID = rhs.professorID;
    courses_taught = rhs.courses_taught;
    return *this;
}

std::istream &operator>>(std::istream &is, Professor &professor) {
    std::string idStr, nameStr;
    if (!getline(is, idStr, ',') || !getline(is, nameStr)) {
        is.setstate(std::ios::failbit);
        return is;
    }
    professor.professorID = idStr;
    professor.name = nameStr;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Professor &professor) {
    os << professor.professorID << "," << professor.name;
    return os;
}

void Professor::assignGradeToStudent(Course &course, const std::string &studentID, double grade) {
    course.assignGrade(studentID, grade);
}

void Professor::assignCourse(Course* course) {
    courses_taught.push_back(course);
}

void Professor::printStatistics() const {
    for (auto course : courses_taught) {
        course->printStatistics();
    }
}