#include "Student.hpp"
#include "Course.hpp"

Student::Student() : Person(" "), studentID(" "), semester(0), ECTS(0), pending_graduation(false) {} 

Student::Student(std::string n, std::string am, unsigned y, unsigned p)
    : Person(n), studentID(am), semester(y), ECTS(p), pending_graduation(y > 8) {}

Student::Student(const Student &source)
    : Person(source), studentID(source.studentID), semester(source.semester), ECTS(source.ECTS), pending_graduation(source.pending_graduation) {
    courses = source.courses;
}

Student::~Student() {
    courses.clear();
}

std::string Student::get_studentID() const { return studentID; }
unsigned Student::get_semester() const { return semester; }
unsigned Student::get_ECTS() const { return ECTS; }
bool Student::get_pending_graduation() const { return pending_graduation; }

void Student::set_ID(std::string studentID) { this->studentID = studentID; }
void Student::set_semester(unsigned semester) { this->semester = semester; }
void Student::set_ECTS(unsigned ECTS) { this->ECTS = ECTS; }
void Student::set_pending_graduation(bool pending_graduation) { this->pending_graduation = pending_graduation; }

Student &Student::operator=(const Student &rhs) {
    if (this == &rhs) return *this;
    name = rhs.name;
    studentID = rhs.studentID;
    semester = rhs.semester;
    ECTS = rhs.ECTS;
    pending_graduation = rhs.pending_graduation;
    courses = rhs.courses;
    return *this;
}

std::ostream &operator<<(std::ostream& os, const Student& student) {
    os << student.studentID << "," << student.name << "," << student.semester << "," << student.ECTS;
    return os;
}

// Διορθώθηκε: Try-catch block για ασφαλή μετατροπή std::stoi
std::istream &operator>>(std::istream& is, Student& student) {
    std::string idStr, nameStr, semStr, ectsStr;
    if (!getline(is, idStr, ',') || !getline(is, nameStr, ',') || !getline(is, semStr, ',') || !getline(is, ectsStr)) {
        is.setstate(std::ios::failbit);
        return is;
    }
    try {
        student.studentID = idStr;
        student.name = nameStr;
        student.semester = std::stoi(semStr);
        student.ECTS = std::stoi(ectsStr);
        student.pending_graduation = (student.semester > 8);
    } catch (...) {
        is.setstate(std::ios::failbit);
    }
    return is;
}

void Student::enrollInCourse(Course* course) {
    courses.push_back(course);
}

void Student::printSemesterGrades() const {
    double sum = 0;
    int semester_courses = 0;
    for (size_t i = 0; i < courses.size(); i++) {
        if (semester == courses[i]->get_semester()) {
            std::cout << "Course name: " << courses[i]->get_name() << "\tGrade: " << courses[i]->getGrade(this->studentID) << std::endl; 
            sum += courses[i]->getGrade(this->studentID);
            semester_courses++;
        }
    }
    if (semester_courses > 0) {
        double GPA = sum / semester_courses;
        std::cout << "The student's GPA is: " << GPA << std::endl;
    } else {
        std::cout << "No courses enrolled in this semester." << std::endl;
    }
}

void Student::printGrades() const {
    double sum = 0;
    int all_courses = 0;
    for (auto course : courses) {
        std::cout << "Course name: " << course->get_name() << "\tGrade: " << course->getGrade(this->studentID) << std::endl; 
        sum += course->getGrade(this->studentID);
        all_courses++;
    }
    if (all_courses > 0) {
        double GPA = sum / all_courses;
        std::cout << "The student's GPA is: " << GPA << std::endl;
    } else {
        std::cout << "No grades recorded." << std::endl;
    }
}