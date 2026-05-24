#include "Course.hpp"

Course::Course() : courseID(" "), name(" "), units(0), type(" "), semester(0) {}

Course::Course(std::string c, std::string n, int u, std::string t, unsigned s)
    : courseID(c), name(n), units(u), type(t), semester(s) {}

Course::Course(const Course &source)
    : courseID(source.courseID), name(source.name), units(source.units), type(source.type), semester(source.semester) {
    enrolled_students = source.enrolled_students;
    professors = source.professors;
    studentGrades = source.studentGrades;
}

Course::~Course() {
    enrolled_students.clear();
    professors.clear();
    studentGrades.clear();
}

std::string Course::get_courseid() const { return courseID; }
std::string Course::get_name() const { return name; }
int Course::get_units() const { return units; }
std::string Course::get_type() const { return type; }
unsigned Course::get_semester() const { return semester; }
std::vector<Professor*> Course::get_professors() const { return professors; }
std::vector<Student*> Course::get_enrolled_students() const { return enrolled_students; }

void Course::set_courseid(std::string course_id) { courseID = course_id; }
void Course::set_name(std::string course_name) { name = course_name; }
void Course::set_units(int course_units) { units = course_units; }
void Course::set_type(std::string course_type) { type = course_type; }
void Course::set_semester(unsigned course_semester) { semester = course_semester; }

Course &Course::operator=(const Course &rhs) {
    if (this == &rhs) return *this;
    courseID = rhs.courseID;
    name = rhs.name;
    units = rhs.units;
    type = rhs.type;
    semester = rhs.semester;
    enrolled_students = rhs.enrolled_students;
    professors = rhs.professors;
    studentGrades = rhs.studentGrades;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Course& course) {
    os << course.courseID << "," << course.name << "," << course.type << "," << course.semester << "," << course.units;
    return os;
}

std::istream& operator>>(std::istream& is, Course& course) {
    std::string idStr, nameStr, unitsStr, typeStr, semStr;
    if (!getline(is, idStr, ',') || !getline(is, nameStr, ',') || !getline(is, unitsStr, ',') || !getline(is, typeStr, ',') || !getline(is, semStr)) {
        is.setstate(std::ios::failbit);
        return is;
    }
    try {
        course.courseID = idStr;
        course.name = nameStr;
        course.units = std::stoi(unitsStr);
        course.type = typeStr;
        course.semester = std::stoi(semStr);
    } catch (...) {
        is.setstate(std::ios::failbit);
    }
    return is;
}

void Course::add_professors(Professor* prof) {
    if (prof != nullptr) {
        professors.push_back(prof);
    }
}

void Course::enrollStudent(Student* student) {
    enrolled_students.push_back(student);
}

void Course::assignGrade(const std::string& studentID, double grade) {
    studentGrades[studentID] = grade;
}

double Course::getGrade(const std::string& studentID) const {
    auto it = studentGrades.find(studentID);
    if (it != studentGrades.end()) {
        return it->second;
    }
    throw std::runtime_error("Grade not found for student ID " + studentID);
}

void Course::printEnrolledStudents() const {
    std::cout << "Enrolled Students for " << name << ":\n";
    for (const auto& student : enrolled_students) {
        std::cout << student->get_name() << "\n";
    }
}

void Course::printStatistics() const {
    double sum = 0;
    if (studentGrades.empty()) return;
    for (auto i = studentGrades.cbegin(); i != studentGrades.cend(); i++) {
        sum += i->second;
    }
    double statistics = sum / static_cast<int>(studentGrades.size());
    std::cout << "Course Name: " << name << " Course_Statistics: " << statistics << std::endl;
}

bool Course::checkIfPassed(const std::string &studentID) const {
    auto it = studentGrades.find(studentID);
    if (it != studentGrades.end()) {
        return (it->second >= 5.0);
    }
    throw std::runtime_error("Grade not found for student ID " + studentID);
}