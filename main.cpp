#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "Secretary.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Professor.hpp"
#include "Course.hpp"
#include <cstdio>

using namespace std;

void addStudentToFile(const Student &student, const string &filename) {
   ofstream outFile(filename, ios::app);
   if (outFile.is_open()) outFile << student << endl;
}

void modifyStudentInFile(const string &studentID, const Student &updatedStudent, const string &filename) {
   vector<Student> students;
   Student temp;
   ifstream inFile(filename);
   ofstream outFile("temp.csv");
   while (inFile >> temp) {
      if (temp.get_studentID() == studentID) students.push_back(updatedStudent);
      else students.push_back(temp);
   }
   inFile.close();
   for (const auto &student : students) outFile << student << endl;
   outFile.close();
   remove(filename.c_str());
   rename("temp.csv", filename.c_str());
}

void deleteStudentFromFile(const string &studentID, const string &filename) {
   ifstream inFile(filename);
   ofstream outFile("temp.csv");
   Student temp;
   if (!inFile.is_open() || !outFile.is_open()) return;
   while (inFile >> temp) {
      if (temp.get_studentID() != studentID) outFile << temp << endl;
   }
   inFile.close();
   outFile.close();
   remove(filename.c_str());
   rename("temp.csv", filename.c_str());
}

void addProfessorToFile(const Professor &professor, const string &filename) {
   ofstream outFile(filename, ios::app);
   if (outFile.is_open()) outFile << professor << endl;
}

void modifyProfessorInFile(const string &professorid, const Professor &updatedProfessor, const string &filename) {
   vector<Professor> professors;
   Professor temp;
   ifstream inFile(filename);
   ofstream outFile("temp.csv");
   while (inFile >> temp) {
      if (temp.get_professorid() == professorid) professors.push_back(updatedProfessor);
      else professors.push_back(temp);
   }
   inFile.close();
   for (const auto &professor : professors) outFile << professor << endl;
   outFile.close();
   remove(filename.c_str());
   rename("temp.csv", filename.c_str());
}

void deleteProfessorFromFile(const string &professorid, const string &filename) {
   ifstream inFile(filename);
   ofstream outFile("temp.csv");
   Professor temp;
   if (!inFile.is_open() || !outFile.is_open()) return;
   while (inFile >> temp) {
      if (temp.get_professorid() != professorid) outFile << temp << endl;
   }
   inFile.close();
   outFile.close();
   remove(filename.c_str());
   rename("temp.csv", filename.c_str());
}

void addCourseToFile(const Course &course, const std::string &filename) {
   ofstream outFile(filename, ios::app);
   if (outFile.is_open()) outFile << course << endl;
}

void modifyCourseInFile(const string &course_name, const Course &updatedCourse, const string &filename) {
   vector<Course> courses;
   Course temp;
   ifstream inFile(filename);
   ofstream outFile("temp.csv");
   while (inFile >> temp) {
      if (temp.get_name() == course_name) courses.push_back(updatedCourse);
      else courses.push_back(temp);
   }
   inFile.close();
   for (const auto &course : courses) outFile << course << endl;
   outFile.close();
   remove(filename.c_str());
   rename("temp.csv", filename.c_str());
}

void deleteCourseFromFile(const string &course_name, const string &filename) {
   ifstream inFile(filename);
   ofstream outFile("temp.csv");
   Course temp;
   if (!inFile.is_open() || !outFile.is_open()) return;
   while (inFile >> temp) {
      if (temp.get_name() != course_name) outFile << temp << endl;
   }
   inFile.close();
   outFile.close();
   remove(filename.c_str());
   rename("temp.csv", filename.c_str());
}

void loadStudentsforSecretatry(Secretary &sec, const string filename) {
   ifstream inFile(filename);
   Student temp;
   while (inFile >> temp) sec.add_student(temp);
   inFile.close();
}

void loadProfesssorsforSecretary(Secretary &sec, const string filename) {
   ifstream inFile(filename);
   Professor temp;
   while (inFile >> temp) sec.add_professor(temp);
   inFile.close();
}

void loadCoursesforSecretary(Secretary &sec, const string filename) {
   ifstream inFile(filename);
   Course temp;
   while (inFile >> temp) sec.add_course(temp);
   inFile.close();
}

void showStudentsThatPassedInFile(const Course &course, const string &filename) {
   ofstream outFile(filename);
   if (!outFile.is_open()) return;
   for (size_t i = 0; i < course.get_enrolled_students().size(); i++) {
      if (course.checkIfPassed(course.get_enrolled_students()[i]->get_studentID())) {
         outFile << course.get_enrolled_students()[i]->get_studentID() << " " << course.get_enrolled_students()[i]->get_name() << endl;
      }
   }
   outFile.close();
}

void printMenu() {
   cout << "\n---------- Academic Management System Menu ----------" << endl;
   cout << "1. Add/modify/delete a professor." << endl;
   cout << "2. Add/modify/delete a student." << endl;
   cout << "3. Add/modify/delete a course." << endl;
   cout << "4. Assign professors to a course." << endl;
   cout << "5. Enroll a student in a course." << endl;
   cout << "6. Assign course's grade to students by professor." << endl;
   cout << "7. Display and save the list of students who passed a specific course in a file for an academic semester." << endl;
   cout << "8. Enable a professor to print semester statistics for all their courses." << endl;
   cout << "9. Allow a student to print detailed grades for the current semester and all past years." << endl;
   cout << "10. Print a list of students eligible to graduate." << endl;
   cout << "11. Exit" << endl;
   cout << "----------------------------------------------------" << endl;
   cout << "Enter your choice: ";
}

int main() {
   const string students_filename{"Students.csv"};
   const string professors_filename{"Professors.csv"};
   const string courses_filename{"Courses.csv"};
   unsigned choice{};
   unsigned subchoice{};
   char end_semester;

   Secretary sec;
   loadStudentsforSecretatry(sec, students_filename);
   loadProfesssorsforSecretary(sec, professors_filename);
   loadCoursesforSecretary(sec, courses_filename);

   do {
      printMenu();
      choice = 0;
      if (!(cin >> choice)) break;
      Professor temp, *temptr{nullptr};
      Student temp1, *temptr1{nullptr};
      Course temp2, *temptr2{nullptr};
      string professorID, studentID, courseID;
      switch (choice) {
      case 1:
         cout << "1. Add a professor." << endl;
         cout << "2. Modify a professor." << endl;
         cout << "3. Delete a professor." << endl;
         cout << "Enter your choice: ";
         cin >> subchoice;
         switch (subchoice) {
         case 1: {
            cout << "ProfessorID, Name: ";
            cin.ignore();
            cin >> temp;
            if (sec.add_professor(temp)) {
               addProfessorToFile(temp, professors_filename);
               cout << "Professor added successfully." << endl;
            } else {
               cout << "Error: A professor with ID '" << temp.get_professorid() << "' already exists!" << endl;
            }
         }
         break;
         case 2: {
            sec.printProfessors();
            cout << "Enter the ID of the professor to modify: ";
            cin >> professorID;
            string new_name;
            cout << "Enter a name: ";
            cin.ignore();
            getline(cin, new_name);
            temptr = sec.modify_professor_name(professorID, new_name);
            if (temptr != nullptr) {
               modifyProfessorInFile(professorID, *temptr, professors_filename);
               cout << "Professor modified successfully." << endl;
            } else {
               cout << "Professor not found." << endl;
            }
         }
         break;
         case 3: {
            sec.printProfessors();
            cout << "Enter the ID of the professor to delete: ";
            cin >> professorID;
            sec.delete_professor(professorID);
            deleteProfessorFromFile(professorID, professors_filename);
            cout << "Professor deleted successfully." << endl;
         }
         break;
         default:
            cout << "Invalid choice. Please try again." << endl;
         }
         break;
      case 2: {
         cout << "1. Add a student." << endl;
         cout << "2. Modify a student." << endl;
         cout << "3. Delete a student." << endl;
         cout << "Enter your choice: ";
         cin >> subchoice;
         switch (subchoice) {
         case 1: {
            cout << "StudentID, Name, Semester(number), ECTS(number): ";
            cin.ignore();
            cin >> temp1;
            if (sec.add_student(temp1)) {
               addStudentToFile(temp1, students_filename);
               cout << "Student added successfully." << endl;
            } else {
               cout << "Error: A student with ID '" << temp1.get_studentID() << "' already exists!" << endl;
            }
         }
         break;
         case 2: {
            sec.printStudents();
            unsigned atr_choice;
            cout << "Enter the ID of the student to modify: ";
            cin >> studentID;
            cout << "Choose (number) the attribute to modify: 1. Name, 2. Semester, 3. ECTS: ";
            while (1) {
               cin >> atr_choice;
               if (atr_choice != 1 && atr_choice != 2 && atr_choice != 3)
                  cout << "Invalid choice. Please try again." << endl;
               else break;
            }
            if (atr_choice == 1) {
               string new_name;
               cout << "Enter new name: ";
               cin.ignore();
               getline(cin, new_name);
               temptr1 = sec.modify_student_name(studentID, new_name);
            } else if (atr_choice == 2) {
               unsigned new_semester;
               cout << "Enter new semester: ";
               cin >> new_semester;
               temptr1 = sec.modify_student_semester(studentID, new_semester);
            } else if (atr_choice == 3) {
               unsigned new_ects;
               cout << "Enter new ECTS: ";
               cin >> new_ects;
               temptr1 = sec.modify_student_ects(studentID, new_ects);
            }
            if (temptr1 != nullptr) {
               modifyStudentInFile(studentID, *temptr1, students_filename);
               cout << "Student modified successfully." << endl;
            } else {
               cout << "Student not found." << endl;
            }
         }
         break;
         case 3: {
            sec.printStudents();
            cout << "Enter the ID of the student to delete: ";
            cin >> studentID;
            sec.delete_student(studentID);
            deleteStudentFromFile(studentID, students_filename);
            cout << "Student deleted successfully." << endl;
         }
         break;
         default:
            cout << "Invalid choice. Please try again." << endl;
         }
      }
      break;
      case 3: {
         cout << "1. Add a course." << endl;
         cout << "2. Modify a course." << endl;
         cout << "3. Delete a course." << endl;
         cout << "Enter your choice: ";
         cin >> subchoice;
         switch (subchoice) {
         case 1: {
            cout << "CourseID, Name, Units(number), Type, Semester(number): ";
            cin.ignore();
            cin >> temp2;
            if (sec.add_course(temp2)) {
               addCourseToFile(temp2, courses_filename);
               cout << "Course added successfully." << endl;
            } else {
               cout << "Error: A course with ID '" << temp2.get_courseid() << "' already exists!" << endl;
            }
         }
         break;
         case 2: {
            sec.printCourses();
            unsigned atr_choice;
            cout << "Enter the ID of the course to modify: ";
            cin >> courseID;
            cout << "Choose (number) the attribute to modify: 1. Name, 2. Units(number), 3. Type, 4. Semester(number): ";
            while (1) {
               cin >> atr_choice;
               if (atr_choice != 1 && atr_choice != 2 && atr_choice != 3 && atr_choice != 4)
                  cout << "Invalid choice. Please try again." << endl;
               else break;
            }
            if (atr_choice == 1) {
               string new_name;
               cout << "Enter new name: ";
               cin.ignore();
               getline(cin, new_name);
               temptr2 = sec.modify_course_name(courseID, new_name);
            } else if (atr_choice == 2) {
               int new_units;
               cout << "Enter new units: ";
               cin >> new_units;
               temptr2 = sec.modify_course_units(courseID, new_units);
            } else if (atr_choice == 3) {
               string new_type;
               cout << "Enter new type: ";
               cin.ignore();
               getline(cin, new_type);
               temptr2 = sec.modify_course_type(courseID, new_type);
            } else if (atr_choice == 4) {
               unsigned new_semester;
               cout << "Enter new semester: ";
               cin >> new_semester;
               temptr2 = sec.modify_course_semester(courseID, new_semester);
            }
            if (temptr2 != nullptr) {
               modifyCourseInFile(courseID, *temptr2, courses_filename);
               cout << "Course modified successfully." << endl;
            } else {
               cout << "Course not found." << endl;
            }
         }
         break;
         case 3: {
            sec.printCourses();
            cout << "Enter the ID of the course to delete: ";
            cin >> courseID;
            sec.delete_course(courseID);
            deleteCourseFromFile(courseID, courses_filename);
            cout << "Course deleted successfully." << endl;
         }
         break;
         default:
            cout << "Invalid choice. Please try again." << endl;
         }
      }
      break;
      case 4: {
         sec.printProfessors();
         cout << "Enter the ID of professor to assign the course: ";
         cin >> professorID;
         sec.printCourses();
         cout << "Enter the ID of the course: ";
         cin >> courseID;
         temptr = sec.find_professor(professorID);
         if (temptr == nullptr) {
            cout << "Professor not found." << endl;
         } else {
            if (sec.set_professor(courseID, *temptr)) {
               cout << "Professor assigned to course successfully." << endl;
            } else {
               cout << "Course not found. Failed to assign professor." << endl;
            }
         }
      }
      break;
      case 5: {
         sec.printStudents();
         cout << "Enter the ID of student to enrolling in a course: ";
         cin >> studentID;
         sec.printCourses();
         cout << "Enter the ID of course: ";
         cin >> courseID;
         temptr1 = sec.find_student(studentID);
         if (temptr1 == nullptr) {
            cout << "Student not found." << endl;
         } else {
            if (sec.reg_stud_to_course(courseID, *temptr1)) {
               cout << "Student enrolled in course successfully." << endl;
            } else {
               cout << "Course not found. Failed to enroll student." << endl;
            }
         }
      }
      break;
      case 6: {
         sec.printCourses();
         cout << "Enter Course ID: ";
         cin >> courseID;
         sec.printProfessors();
         cout << "Enter Professor ID: ";
         cin >> professorID;
         temptr2 = sec.find_course(courseID);
         if (temptr2 == nullptr) {
            cout << "Course not found." << endl;
            break;
         }
         if (!sec.isProfessorAssignedToCourse(professorID, courseID)) {
            cout << "This professor is not assigned to the course." << endl;
            break;
         }
         vector<Student *> students = sec.getStudentsInCourse(courseID);
         double grade;
         for (Student *student : students) {
            cout << "Enter grade for Student ID " << student->get_studentID() << " (" << student->get_name() << "): ";
            while (true) {
               cin >> grade;
               if (grade > 10.0 || grade < 0.0)
                  cout << "Grade must be between 0.0 and 10.0. Please try again." << endl;
               else break;
            }
            sec.professor_give_grade(*temptr2, student->get_studentID(), professorID, grade);
         }
         cout << "Grades assigned successfully." << endl;
      }
      break;
      case 7: {
         string tempfile("StudentsPassed.csv");
         sec.printCourses();
         cout << "Enter the ID of course: ";
         cin >> courseID;
         temptr2 = sec.find_course(courseID);
         if (temptr2 != nullptr) {
            showStudentsThatPassedInFile(*temptr2, tempfile);
            cout << "Passed students list saved to StudentsPassed.csv." << endl;
         } else {
            cout << "Course not found." << endl;
         }
      }
      break;
      case 8: {
         sec.printProfessors();
         cout << "Please enter the ID of professor: ";
         cin >> professorID;
         temptr = sec.find_professor(professorID);
         if (temptr != nullptr) {
            sec.printStatistics(*temptr);
         } else {
            cout << "Professor not found." << endl;
         }
      }
      break;
      case 9: {
         unsigned sem;
         sec.printStudents();
         cout << "Enter the ID of student: ";
         cin >> studentID;
         temptr1 = sec.find_student(studentID);
         if (temptr1 != nullptr) {
            cout << "Choose (number) between 1. Current Semester, 2. All Semesters: ";
            cin >> sem;
            if (sem == 1) temptr1->printSemesterGrades();
            else if (sem == 2) temptr1->printGrades();
            else cout << "Invalid choice. Please try again." << endl;
         } else {
            cout << "Student not found." << endl;
         }
      }
      break;
      case 10: {
         sec.printGraduates();
      }
      break;
      case 11: {
         cout << "Exiting the program..." << endl;
      }
      break;
      default:
         cout << "Invalid choice. Please try again." << endl;
      }
      if (choice != 11) {
         cout << "Do you want to end this semester (Y OR N): ";
         while (true) {
            cin >> end_semester;
            if (end_semester != 'Y' && end_semester != 'N')
               cout << "Invalid choice. Please try again by typing either Y or N." << endl;
            else break;
         }
         if (end_semester == 'Y') {
            sec.change_students_semester();
         } else if (end_semester == 'N')
            continue;
      }
   } while (choice != 11);
   return 0;
}