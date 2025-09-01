// the implementaton of Secretary class  
#include <iostream>
#include "Secretary.hpp"


// Constructor with no arguments implementation
Secretary::Secretary() {
}

// Copy Constructor Secretary implementation
Secretary::Secretary(const Secretary &source) {
    for (const auto& course : source.courses) {
        courses.push_back(new Course(*course)); // Duplicate each Course object
    }
    for (const auto& student : source.students) {
        students.push_back(new Student(*student)); // Duplicate each Student object
    }
    for (const auto& professor : source.professors) {
        professors.push_back(new Professor(*professor)); // Duplicate each Professor object
    }
}

// Destructor Secretary implementation
Secretary::~Secretary() {
    // Clean up memory allocated for pointers
    for (auto course : courses) {
        delete course;
    }
    for (auto student : students) {
        delete student;
    }
    for (auto professor : professors) {
        delete professor;
    }
}

// Description: Adds a student to the system.
// Parameters: student (Student&): The student to be added.
void Secretary::add_student(Student &student) {
    Student *temp {new Student(student)};
    students.push_back(temp);
}

// Description: Adds a professor to the system.
// Parameters: professor (Professor&): The professor to be added.
void Secretary::add_professor(Professor &professor) {
    Professor *temp {new Professor(professor)};
    professors.push_back(temp);
}

// Description: Adds a course to the system.
// Parameters: course (Course&): The course to be added.
void Secretary::add_course(Course &course) {
    Course *temp {new Course(course)};
    courses.push_back(temp);
}

// Description: Modifies a student's details.
// Parameters: student_id (const std::string&), choice_attribute (unsigned): The attribute to modify.
Student* Secretary::modify_student(const std::string &student_id, const unsigned choice_attribute) {
    for (auto student : students) {
        if (student->get_studentID() == student_id) {
            if (choice_attribute == 1) {
                std::string temp;
                std::cin.ignore();
                getline(std::cin, temp);
                student->set_name(temp);
            } else if (choice_attribute == 2) {
                unsigned temp;
                std::cin.ignore();
                std::cin >> temp;
                student->set_semester(temp);
            } else if (choice_attribute == 3) {
                unsigned temp;
                std::cin.ignore();
                std::cin >> temp;
                student->set_ECTS(temp);
            } else 
                std::cout << "Wrong attribute choice" << std::endl;
            return student;
        }
    }
    return nullptr;
}

// Description: Modifies a professor's details.
// Parameters: professor_id (const std::string&): The ID of the professor to modify.
Professor* Secretary::modify_professor(const std::string &professor_id) {
    for (auto professor : professors) {
        if (professor->get_professorid() == professor_id) {
            std::string temp;
            std::cout << "Enter a name: ";
            std::cin.ignore();
            getline(std::cin, temp);
            professor->set_name(temp);
            return professor;
        }
    }
    return nullptr;
}

// Description: Modifies a course's details.
// Parameters: course_id (const std::string&), choice_attribute (unsigned): The attribute to modify.
Course* Secretary::modify_course(const std::string &course_id, const unsigned choice_attribute) {
    for (auto course : courses) {
        if (course->get_courseid() == course_id) {
            if (choice_attribute == 1) {
                std::string temp;
                std::cin.ignore();
                getline(std::cin, temp);
                course->set_name(temp);
            } else if (choice_attribute == 2) {
                unsigned temp;
                std::cin.ignore();
                std::cin >> temp;
                course->set_units(temp);
            } else if (choice_attribute == 3) {
                std::string temp;
                std::cin.ignore();
                getline(std::cin, temp);
                course->set_type(temp);
            } else if (choice_attribute == 4) {
                unsigned temp;
                std::cin.ignore();
                std::cin >> temp;
                course->set_semester(temp);
            } else 
                std::cout << "Wrong attribute choice" << std::endl;
            return course;
        }
    }
    return nullptr;
}


// Description: Deletes a student from the system.
// Parameters: student_id (const std::string&): The ID of the student to delete.
void Secretary::delete_student(const std::string &student_id) {
    for (auto student : students) {
        if (student->get_studentID() == student_id) {
            delete student;
            break;
        }
    }
}

// Description: Deletes a professor from the system.
// Parameters: professor_id (const std::string&): The ID of the professor to delete.
void Secretary::delete_professor(const std::string &professor_id) {
    for (auto professor : professors) {
        if (professor->get_professorid() == professor_id) {
            delete professor;
            break;
        }
    }
}

// Description: Deletes a course from the system.
// Parameters: course_id (const std::string&): The ID of the course to delete.
void Secretary::delete_course(const std::string &course_id) {
    for (auto course : courses) {
        if (course->get_courseid() == course_id) {
            delete course;
            break;
        }
    }
}

// Description: Finds a professor in the system.
// Parameters: professor_id (const std::string&): The ID of the professor to find.
Professor* Secretary::find_professor(const std::string &professor_id) {
    for (auto professor : professors) {
        if (professor->get_professorid() == professor_id) {
            return professor;
        }
    }
    return nullptr;
}

// Description: Finds a student in the system.
// Parameters: student_id (const std::string&): The ID of the student to find.
Student* Secretary::find_student(const std::string &student_id) {
    for (auto student : students) {
        if (student->get_studentID() == student_id) {
            return student;
        }
    }
    return nullptr;
}

// Description: Finds a course in the system.
// Parameters: course_id (const std::string&): The ID of the course to find.
Course* Secretary::find_course(const std::string &course_id) {
    for (auto course : courses) {
        if (course->get_courseid() == course_id) {
            return course;
        }
    }
    return nullptr;
}

// Description: Registers a student to a course.
// Parameters: course_id (const std::string), student (Student&): The course and student involved.
bool Secretary::reg_stud_to_course(const std::string course_id, Student &student) {
    student.enrollInCourse(this->find_course(course_id));
    for (auto course : courses) {
        if (course->get_courseid() == course_id){
            course->enrollStudent(this->find_student(student.get_studentID()));
            return true;
        }
    }
    return false;
}

// Description: Assigns a professor to a course.
// Parameters: course_id (const std::string), prof (Professor&): The course and professor involved.
bool Secretary::set_professor(const std::string course_id, Professor &prof) {
    prof.assignCourse(this->find_course(course_id));
    for (auto course : courses) {
        if (course->get_courseid() == course_id) {
            course->add_professors(prof);
            return true;
        }
    }
    return false;
}

// get the vector of enrolled students of the course
std::vector<Student*> Secretary::getStudentsInCourse(const std::string course_id) const {
    std::vector<Student*> enrolledStudents;

    for (auto course : courses) {
        if (course->get_courseid() == course_id) {
            enrolledStudents = course->get_enrolled_students();
            break;
        }
    }

    return enrolledStudents;
}

// Description: Checks if a professor is assigned to a specific course.
// Parameters: professor_id (const std::string), course_id (const std::string): The professor and course IDs.
bool Secretary::isProfessorAssignedToCourse(const std::string professor_id, const std::string course_id) {
    for (auto course : courses) {
        if (course->get_courseid() == course_id) {
            for (auto professor : course->get_professors()) {
                if (professor->get_professorid() == professor_id) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Description: Allows a professor to give a grade to a student in a course.
// Parameters: given_course (Course&), student_id (const std::string), professor_id (const std::string), grade (double): The course, student ID, professor ID, and grade.
bool Secretary::professor_give_grade(Course &given_course, const std::string student_id, const std::string professor_id, double grade) {
    for (auto course : courses) {
        for (auto professor : course->get_professors()) {
            if (professor->get_professorid() == professor_id) {
                professor->assignGradeToStudent(given_course, student_id, grade);
                return true;
            }
        }
    }
    return false;
}

// prints out the students of the vector students
void Secretary::printStudents() const {
    std::cout << "List of Students:" << std::endl;
    for (const Student* student : students) {
        std::cout << "ID: " << student->get_studentID() 
                  << ", Name: " << student->get_name() 
                  << ", Semester: " << student->get_semester()
                  << ", ECTS: " << student->get_ECTS()
                  << std::endl;
    }
}

// prints out the professors of the vector professors
void Secretary::printProfessors() const {
    std::cout << "List of Professors:" << std::endl;
    for (const Professor* professor : professors) {
        std::cout << "ID: " << professor->get_professorid() 
                  << ", Name: " << professor->get_name() 
                  << std::endl;
    }
}

// prints out the courses of the vector courses
void Secretary::printCourses() const {
    std::cout << "List of Courses:" << std::endl;
    for (const Course* course : courses) {
        std::cout << "ID: " << course->get_courseid()
                  << ", Name: " << course->get_name()
                  << ", ECTS: " << course->get_units()
                  << ", Type: " << course->get_type()  // Assuming getType returns a string like "Compulsory" or "Elective"
                  << ", Semester: " << course->get_semester()
                  << std::endl;
    }
}

// just change the students semester 
void Secretary::change_students_semester() {
    for (auto student : students) {
        if (student->get_semester() < 8)
           student->set_semester(student->get_semester() + 1);
        else 
           student->set_pending_graduation(true);
    }
}

// prints the statistics of each course's grade of professor
void Secretary::printStatistics(Professor &professor) const {
    professor.printStatistics();
}

// return true if the student passed all the mandatory courses
bool Secretary::checkpassedmandatory(const Student &student) const {
    for (auto course : courses) {
        if (course->get_type() == "Compulsary" && course->getGrade(student.get_studentID()) < 5){
            return false;
        }
    }
    return true;
}

// prints out the graduates
void Secretary::printGraduates() const {
    for (auto student : students){
        if (student->get_semester() >= semesters && student->get_ECTS() >= ECTS_required_to_gradaute && checkpassedmandatory(*student)){
            std::cout << "Name: " << student->get_name() << std::endl;
        }
    }    
}