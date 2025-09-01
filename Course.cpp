#include "Course.hpp"

// Constructor without arguments
Course::Course()
    : courseID(" "), name(" "), units(0), type(" "), semester(0) {
}

// Constructor with arguments
Course::Course(std::string c,std::string n, int u, std::string t, unsigned s)
    : courseID(c), name(n), units(u), type(t), semester(s) {
}

// Copy Constructor
Course::Course(const Course &source)
    : courseID(source.courseID), name(source.name), units(source.units), type(source.type), semester(source.semester) {
}

// Destructor
Course::~Course() {
    for (auto student : enrolled_students) {
        delete student;
    }
    for (auto professor : professors) {
        delete professor;
    }

    studentGrades.clear();
}


// just some functions to get information about course
std::string Course::get_courseid() const {
    return courseID;
}

std::string Course::get_name() const {
    return name;
}

int Course::get_units() const {
    return units;
}

std::string Course::get_type() const {
    return type;
}

unsigned Course::get_semester() const {
    return semester;
}

std::vector<Professor*> Course::get_professors() const {
    return professors;
}

std::vector<Student*> Course::get_enrolled_students() const{
    return enrolled_students;
}


// just some functions to set information to course
void Course::set_courseid(std::string course_id) {
    courseID = course_id;
}

void Course::set_name(std::string course_name) {
    name = course_name;
}

void Course::set_units(int course_units) {
    units = course_units;
}

void Course::set_type(std::string course_type) {
    type = course_type;
}

void Course::set_semester(unsigned course_semester) {
    semester = course_semester;
}


// Overload assignment operator
Course &Course::operator=(Course &rhs) {
    if (this == &rhs)
        return *this;
    
    name = rhs.name;
    units = rhs.units;
    type = rhs.type;
    semester = rhs.semester;
    
    enrolled_students.clear();
    for (size_t i {}; i < rhs.enrolled_students.size(); i++) {
        enrolled_students.push_back(rhs.enrolled_students[i]);
    }
    professors.clear();
    for (size_t i {}; i < rhs.professors.size(); i++) {
        professors.push_back(rhs.professors[i]);
    }
    
    return *this;
}

// Description: Adds a professor to the course.
// Parameters: prof (Professor): The professor to add to the course.
void Course::add_professors(Professor prof) {
    Professor *temp {new Professor()};
    *temp = prof;
    professors.push_back(temp);
}

// Description: Enrolls a student in the course.
// Parameters: student (Student*): Pointer to the student to enroll in the course.
void Course::enrollStudent(Student* student) {
    enrolled_students.push_back(student);
}

// Description: Assigns a grade to a student in the course.
// Parameters:
// studentID (const std::string&): The ID of the student.
// grade (double): The grade to assign.
void Course::assignGrade(const std::string& studentID, double grade) {
    studentGrades[studentID] = grade;
}

// Description: Returns the grade of an enrolled student.
// Parameters: studentID (const std::string&): The ID of the student.
// Functionality: Searches for the student's grade using their ID and returns it. If the student's grade is not found, an exception is thrown.
double Course::getGrade(const std::string& studentID) const {
    auto it = studentGrades.find(studentID);
    if (it != studentGrades.end()) {
        return it->second;
    }
    throw std::runtime_error("Grade not found for student ID " + studentID);
}

// Description: Prints out the enrolled students for the course.
// Functionality: Iterates over the list of enrolled students and prints their names.
void Course::printEnrolledStudents() const {
    std::cout << "Enrolled Students for " << name << ":\n";
    for (const auto& student : enrolled_students) {
        std::cout << student->get_name() << "\n";
    }
}

// Description: Prints out the statistics of students' grades in the course.
// Functionality: Calculates and prints the statistical information (like average grade) of the students enrolled in the course.
void Course::printStatistics() const {
    double sum {};
    double statistics {};
    for (auto i {studentGrades.cbegin()}; i != studentGrades.cend(); i++) {
        sum += i->second;
    }
    statistics = sum/static_cast<int>(studentGrades.size());

    std::cout << "Course Name: " << name << "Course_Statistics: " << statistics << std::endl;
}

// Description: Determines if a student has passed the course.
// Parameters: studentID (const std::string&): The ID of the student.
// Functionality: Checks the student's grade and returns true if the grade is above a passing threshold (5.0 in this case), otherwise returns false. If the student's grade is not found, an exception is thrown.
bool Course::checkIfPassed(const std::string &studentID) const {
    auto it = studentGrades.find(studentID);
    if (it != studentGrades.end())
    {
        if(it->second>5.0) return true;
        else return false;
    }
    throw std::runtime_error("Grade not found for student ID " + studentID);
}

