#include <iostream>
#include "Secretary.hpp"

Secretary::Secretary() {}

Secretary::Secretary(const Secretary &source) {
    for (const auto& course : source.courses) { courses.push_back(new Course(*course)); }
    for (const auto& student : source.students) { students.push_back(new Student(*student)); }
    for (const auto& professor : source.professors) { professors.push_back(new Professor(*professor)); }
}

Secretary::~Secretary() {
    for (auto course : courses) { delete course; }
    for (auto student : students) { delete student; }
    for (auto professor : professors) { delete professor; }
}

bool Secretary::add_student(Student &student) {
    if (this->find_student(student.get_studentID()) != nullptr) return false;
    students.push_back(new Student(student));
    return true;
}

bool Secretary::add_professor(Professor &professor) {
    if (this->find_professor(professor.get_professorid()) != nullptr) return false;
    professors.push_back(new Professor(professor));
    return true;
}

bool Secretary::add_course(Course &course) {
    if (this->find_course(course.get_courseid()) != nullptr) return false;
    courses.push_back(new Course(course));
    return true;
}

Student* Secretary::modify_student_name(const std::string &student_id, const std::string &new_name) {
    for (auto student : students) {
        if (student->get_studentID() == student_id) {
            student->set_name(new_name);
            return student;
        }
    }
    return nullptr;
}

Student* Secretary::modify_student_semester(const std::string &student_id, unsigned new_semester) {
    for (auto student : students) {
        if (student->get_studentID() == student_id) {
            student->set_semester(new_semester);
            return student;
        }
    }
    return nullptr;
}

Student* Secretary::modify_student_ects(const std::string &student_id, unsigned new_ects) {
    for (auto student : students) {
        if (student->get_studentID() == student_id) {
            student->set_ECTS(new_ects);
            return student;
        }
    }
    return nullptr;
}

Professor* Secretary::modify_professor_name(const std::string &professor_id, const std::string &new_name) {
    for (auto professor : professors) {
        if (professor->get_professorid() == professor_id) {
            professor->set_name(new_name);
            return professor;
        }
    }
    return nullptr;
}

Course* Secretary::modify_course_name(const std::string &course_id, const std::string &new_name) {
    for (auto course : courses) {
        if (course->get_courseid() == course_id) {
            course->set_name(new_name);
            return course;
        }
    }
    return nullptr;
}

Course* Secretary::modify_course_units(const std::string &course_id, int new_units) {
    for (auto course : courses) {
        if (course->get_courseid() == course_id) {
            course->set_units(new_units);
            return course;
        }
    }
    return nullptr;
}

Course* Secretary::modify_course_type(const std::string &course_id, const std::string &new_type) {
    for (auto course : courses) {
        if (course->get_courseid() == course_id) {
            course->set_type(new_type);
            return course;
        }
    }
    return nullptr;
}

Course* Secretary::modify_course_semester(const std::string &course_id, unsigned new_semester) {
    for (auto course : courses) {
        if (course->get_courseid() == course_id) {
            course->set_semester(new_semester);
            return course;
        }
    }
    return nullptr;
}

void Secretary::delete_student(const std::string &student_id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if ((*it)->get_studentID() == student_id) {
            delete *it;
            students.erase(it);
            break;
        }
    }
}

void Secretary::delete_professor(const std::string &professor_id) {
    for (auto it = professors.begin(); it != professors.end(); ++it) {
        if ((*it)->get_professorid() == professor_id) {
            delete *it;
            professors.erase(it);
            break;
        }
    }
}

void Secretary::delete_course(const std::string &course_id) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if ((*it)->get_courseid() == course_id) {
            delete *it;
            courses.erase(it);
            break;
        }
    }
}

Professor* Secretary::find_professor(const std::string &professor_id) {
    for (auto professor : professors) {
        if (professor->get_professorid() == professor_id) return professor;
    }
    return nullptr;
}

Student* Secretary::find_student(const std::string &student_id) {
    for (auto student : students) {
        if (student->get_studentID() == student_id) return student;
    }
    return nullptr;
}

Course* Secretary::find_course(const std::string &course_id) {
    for (auto course : courses) {
        if (course->get_courseid() == course_id) return course;
    }
    return nullptr;
}

bool Secretary::reg_stud_to_course(const std::string course_id, Student &student) {
    Course* coursePtr = this->find_course(course_id);
    if (coursePtr == nullptr) return false;
    student.enrollInCourse(coursePtr);
    coursePtr->enrollStudent(this->find_student(student.get_studentID()));
    return true;
}

bool Secretary::set_professor(const std::string course_id, Professor &prof) {
    Professor* profPtr = this->find_professor(prof.get_professorid());
    Course* coursePtr = this->find_course(course_id);
    if (coursePtr == nullptr || profPtr == nullptr) return false;
    profPtr->assignCourse(coursePtr);
    coursePtr->add_professors(profPtr);
    return true;
}

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

bool Secretary::isProfessorAssignedToCourse(const std::string professor_id, const std::string course_id) {
    for (auto course : courses) {
        if (course->get_courseid() == course_id) {
            for (auto professor : course->get_professors()) {
                if (professor->get_professorid() == professor_id) return true;
            }
        }
    }
    return false;
}

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

void Secretary::printStudents() const {
    std::cout << "List of Students:" << std::endl;
    for (const Student* student : students) {
        std::cout << "ID: " << student->get_studentID() << ", Name: " << student->get_name() << ", Semester: " << student->get_semester() << ", ECTS: " << student->get_ECTS() << std::endl;
    }
}

void Secretary::printProfessors() const {
    std::cout << "List of Professors:" << std::endl;
    for (const Professor* professor : professors) {
        std::cout << "ID: " << professor->get_professorid() << ", Name: " << professor->get_name() << std::endl;
    }
}

void Secretary::printCourses() const {
    std::cout << "List of Courses:" << std::endl;
    for (const Course* course : courses) {
        std::cout << "ID: " << course->get_courseid() << ", Name: " << course->get_name() << ", ECTS: " << course->get_units() << ", Type: " << course->get_type() << ", Semester: " << course->get_semester() << std::endl;
    }
}

void Secretary::change_students_semester() {
    for (auto student : students) {
        if (student->get_semester() < 8) student->set_semester(student->get_semester() + 1);
        else student->set_pending_graduation(true);
    }
}

void Secretary::printStatistics(Professor &professor) const { professor.printStatistics(); }

bool Secretary::checkpassedmandatory(const Student &student) const {
    for (auto course : courses) {
        if (course->get_type() == "Compulsary" && course->getGrade(student.get_studentID()) < 5) return false;
    }
    return true;
}

void Secretary::printGraduates() const {
    for (auto student : students){
        if (student->get_semester() >= semesters && student->get_ECTS() >= ECTS_required_to_gradaute && checkpassedmandatory(*student)){
            std::cout << "Name: " << student->get_name() << std::endl;
        }
    }    
}