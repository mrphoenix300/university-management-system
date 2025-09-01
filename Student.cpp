#include "Student.hpp"

// Constructor without arguments
Student::Student()
    : Person(" "), studentID {" "}, semester {0}, ECTS{0} {
} 

// Constructor with arguments
Student::Student(std::string n, std::string am, unsigned y, unsigned p)
    : Person(n), studentID {am}, semester {y}, ECTS {p}, pending_graduation {(y > 8)} {
}

// Copy constructor 
Student::Student(const Student &source)
    : Person(source), studentID(source.studentID), semester(source.semester), ECTS(source.ECTS), pending_graduation(source.pending_graduation) {

        for (auto course : courses) {
            delete course;
        }
        courses.clear();

        for (auto course : source.courses) {
            courses.push_back(new Course(*course));
        }
}

// Destructor
Student::~Student() {
    for (auto course : courses) {
        delete course;
    }
    courses.clear();
}

// some functions to get information from student

std::string Student::get_studentID() const {
    return studentID;
}

unsigned Student::get_semester() const {
    return semester;
}

unsigned Student::get_ECTS() const {
    return ECTS;
}

bool Student::get_pending_graduation() const {
    return pending_graduation;
}

// some functions to set information to student
void Student::set_ID(std::string studentID) {
    this->studentID = studentID;
}

void Student::set_semester(unsigned semester) {
    this->semester = semester;
}

void Student::set_ECTS(unsigned ECTS) {
    this->ECTS = ECTS;
}

void Student::set_pending_graduation(bool pending_graduation) {
    this->pending_graduation = pending_graduation;
}

// overload the assignment operator
Student &Student::operator=(Student &rhs) {
    if (this == &rhs)
       return *this;
    
    name = rhs.name;
    studentID = rhs.studentID;
    semester = rhs.semester;
    pending_graduation = rhs.pending_graduation;

    courses.clear();
    for (size_t i {}; i < rhs.courses.size(); i++) {
        courses.push_back(rhs.courses[i]);
    }

    return *this;
}

// Description: Enrolls the student in a course.
// Parameters: course (Course*): Pointer to the course in which the student is to be enrolled.
// Functionality: Adds the student to the specified course.
void Student::enrollInCourse(Course* course) {
    courses.push_back(course);
}

// Description: Prints the grades for the current semester.
// Functionality: Iterates over the courses in which the student is enrolled, calculates and prints the grades for courses belonging to the current semester, and calculates the GPA for the semester.
void Student::printSemesterGrades() const
{
    double sum {};
    int semester_courses = 0;
    for (size_t i = 0; i < courses.size(); i++)
    {
        if (semester==courses[i]->get_semester())
        {
            std::cout << "Course name: " << courses[i]->get_name() << "\tGrade: " << courses[i]->getGrade(this->studentID); 
            sum += courses[i]->getGrade(this->studentID);
            semester_courses++;
        }
    }
    double GPA = sum / semester_courses;
    std::cout << "The student's GPA is: " << GPA << std::endl;
}

// Description: Prints grades for all semesters.
// Functionality: Iterates over all courses in which the student is enrolled, calculates and prints the grades for each course, and calculates the overall GPA.
void Student::printGrades() const {
    double sum {};
    int all_courses {};
    for (auto course : courses) {
        std::cout << "Course name: " << course->get_name() << "\tGrade: " << course->getGrade(this->studentID) << std::endl; 
        sum += course->getGrade(this->studentID);
        all_courses++;
    }

    double GPA = sum / all_courses;
    std::cout << "The student's GPA is: " << GPA << std::endl;

}