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

// Description: Adds a student's details to a file.
// Parameters:
// student: A Student object containing the student's information.
// filename: Name of the file where the student's details will be appended.
// Functionality: Opens the specified file in append mode and writes the student's details using the overloaded << operator.
void addStudentToFile(const Student &student, const string &filename) {
   ofstream outFile(filename, ios::app); // Open file in append mode
   if (outFile.is_open()) {
      outFile << student << endl; // Use overloaded << operator
   }
}

// Description: Modifies an existing student's details in a file.
// Parameters:
// studentID: Identifier of the student to be updated.
// updatedStudent: A Student object containing the updated information.
// filename: Name of the file where the modification will take place.
// Functionality: Reads students from the file, replaces the student with the given ID with updated information, and then writes back all the student details to the file.
void modifyStudentInFile(const string &studentID, const Student &updatedStudent, const string &filename) {
   vector<Student> students;
   Student temp;
   ifstream inFile(filename);
   ofstream outFile("temp.csv"); // Temporary file

   while (inFile >> temp) {
      if (temp.get_studentID() == studentID) {
         students.push_back(updatedStudent); // Replace with updated student
      } else {
         students.push_back(temp);
      }
   }

   inFile.close();
   for (const auto &student : students) {
      outFile << student << endl;
   }

   outFile.close();
   if (remove(filename.c_str()) != 0) {
      std::cerr << "Error deleting old file\n";
   }

   if (rename("temp.csv", filename.c_str()) != 0) {
      std::cerr << "Error renaming new file\n";
   }
}

// Description: Deletes a student's details from a file.
// Parameters:
// studentID: Identifier of the student to be deleted.
// filename: Name of the file from which the student's details will be removed.
// Functionality: Reads and writes all student details except the one to be deleted into a temporary file, then replaces the original file with this temporary file.
void deleteStudentFromFile(const string &studentID, const string &filename) {
   ifstream inFile(filename);
   ofstream outFile("temp.csv");
   Student temp;

   if (!inFile.is_open() || !outFile.is_open()) {
      return;
   }

   while (inFile >> temp) {
      if (temp.get_studentID() != studentID) {
         outFile << temp << endl; // Write all students except the one to delete
      }
   }

   inFile.close();
   outFile.close();
   if (remove(filename.c_str()) != 0) {
      std::cerr << "Error deleting old file\n";
   }

   if (rename("temp.csv", filename.c_str()) != 0) {
      std::cerr << "Error renaming new file\n";
   }
}

// Description: Adds a professor's details to a file.
// Parameters:
// professor: A Professor object containing the professor's information.
// filename: Name of the file where the professor's details will be appended.
// Functionality: Similar to addStudentToFile, but for a Professor object.
void addProfessorToFile(const Professor &professor, const string &filename) {
   ofstream outFile(filename, ios::app);
   if (outFile.is_open()) {
      outFile << professor << endl;
   }
}

// Description: Modifies an existing professor's details in a file.
// Parameters: Similar to modifyStudentInFile, but for a Professor object.
// Functionality: Similar to modifyStudentInFile, but for a Professor object.
void modifyProfessorInFile(const string &professorid, const Professor &updatedProfessor, const string &filename) {
   vector<Professor> professors;
   Professor temp;
   ifstream inFile(filename);
   ofstream outFile("temp.csv");

   while (inFile >> temp) {
      if (temp.get_professorid() == professorid) {
         professors.push_back(updatedProfessor);
      } else {
         professors.push_back(temp);
      }
   }

   inFile.close();
   for (const auto &professor : professors) {
      outFile << professor << endl;
   }

   outFile.close();
   if (remove(filename.c_str()) != 0) {
      std::cerr << "Error deleting old file\n";
   }

   if (rename("temp.csv", filename.c_str()) != 0) {
      std::cerr << "Error renaming new file\n";
   }
}

// Description: Deletes a professor's details from a file.
// Parameters: Similar to deleteStudentFromFile, but for a Professor object.
// Functionality: Similar to deleteStudentFromFile, but for a Professor object.
void deleteProfessorFromFile(const string &professorid, const string &filename) {
   ifstream inFile(filename);
   ofstream outFile("temp.csv");
   Professor temp;

   if (!inFile.is_open() || !outFile.is_open()) {
      return;
   }

   while (inFile >> temp) {
      if (temp.get_professorid() != professorid) {
         outFile << temp << endl;
      }
   }

   inFile.close();
   outFile.close();
   if (remove(filename.c_str()) != 0) {
      std::cerr << "Error deleting old file\n";
   }

   if (rename("temp.csv", filename.c_str()) != 0) {
      std::cerr << "Error renaming new file\n";
   }
}

// Description: Adds a course's details to a file.
// Parameters: Similar to addStudentToFile, but for a Course object.
// Functionality: Similar to addStudentToFile, but for a Course object.
void addCourseToFile(const Course &course, const std::string &filename) {
   ofstream outFile(filename, ios::app);
   if (outFile.is_open()) {
      outFile << course << endl;
   }
}

// Description: Modifies an existing course's details in a file.
// Parameters: Similar to modifyStudentInFile, but for a Course object.
// Functionality: Similar to modifyStudentInFile, but for a Course object.
void modifyCourseInFile(const string &course_name, const Course &updatedCourse, const string &filename) {
   vector<Course> courses;
   Course temp;
   ifstream inFile(filename);
   ofstream outFile("temp.csv");

   while (inFile >> temp) {
      if (temp.get_name() == course_name) {
         courses.push_back(updatedCourse);
      } else {
         courses.push_back(temp);
      }
   }

   inFile.close();
   for (const auto &course : courses) {
      outFile << course << endl;
   }

   outFile.close();
   if (remove(filename.c_str()) != 0) {
      std::cerr << "Error deleting old file\n";
   }

   if (rename("temp.csv", filename.c_str()) != 0) {
      std::cerr << "Error renaming new file\n";
   }
}

// Description: Deletes a course's details from a file.
// Parameters: Similar to deleteStudentFromFile, but for a Course object.
// Functionality: Similar to deleteStudentFromFile, but for a Course object.
void deleteCourseFromFile(const string &course_name, const string &filename) {
   ifstream inFile(filename);
   ofstream outFile("temp.csv");
   Course temp;

   if (!inFile.is_open() || !outFile.is_open()) {
      return;
   }

   while (inFile >> temp) {
      if (temp.get_name() != course_name) {
         outFile << temp << endl;
      }
   }

   inFile.close();
   outFile.close();
   if (remove(filename.c_str()) != 0) {
      std::cerr << "Error deleting old file\n";
   }

   if (rename("temp.csv", filename.c_str()) != 0) {
      std::cerr << "Error renaming new file\n";
   }
}

// Description: Loads student information for a secretary from a file.
// Parameters:
// sec: A Secretary object to which the student information will be added.
// filename: Name of the file containing student information.
// Functionality: Reads student information from the file and adds each student to the Secretary object.
void loadStudentsforSecretatry(Secretary &sec, const string filename) {
   ifstream inFile(filename);
   Student temp;

   while (!(inFile.eof())) {
      inFile >> temp;
      sec.add_student(temp);
   }

   inFile.close();
}

// Description: Similar to loadStudentsforSecretary, but for loading professor information.
void loadProfesssorsforSecretary(Secretary &sec, const string filename) {
   ifstream inFile(filename);
   Professor temp;

   while (!(inFile.eof())) {
      inFile >> temp;
      sec.add_professor(temp);
   }

   inFile.close();
}

// Description: Similar to loadStudentsforSecretary, but for loading course information.
void loadCoursesforSecretary(Secretary &sec, const string filename) {
   ifstream inFile(filename);
   Course temp;

   while (!(inFile.eof())) {
      inFile >> temp;
      sec.add_course(temp);
   }

   inFile.close();
}

// Description: Shows details of students who passed a course in a file.
// Parameters:
// course: A Course object containing information about the course and enrolled students.
// filename: Name of the file where details of passing students will be written.
// Functionality: Checks each enrolled student's passing status in the course and writes the details of those who passed to the specified file.
void showStudentsThatPassedInFile(const Course &course, const string &filename) {
   ofstream outFile(filename);
   if (!outFile.is_open())
      return;
   for (size_t i = 0; i < course.get_enrolled_students().size(); i++) {
      if (course.checkIfPassed(course.get_enrolled_students()[i]->get_studentID())) {
         outFile << course.get_enrolled_students()[i]->get_studentID() << " " << course.get_enrolled_students()[i]->get_name() << endl;
      }
   }
   outFile.close();
}

// Description: Prints a menu for user interaction.
// Functionality: Displays various options available to the user for interacting with the system.
void printMenu() {
   cout << "---------- Academic Management System Menu ----------" << endl;
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

// Description: The main function of the program.
// Functionality: Entry point of the program, where execution begins.
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

   do
   {
      printMenu();
      cin >> choice;
      Professor temp, *temptr{nullptr};
      Student temp1, *temptr1{nullptr};
      Course temp2, *temptr2{nullptr};
      string professorID, studentID, courseID;
      switch (choice)
      {
      case 1:
         cout << "1. Add a professor." << endl;
         cout << "2. Modify a professor." << endl;
         cout << "3. Delete a professor." << endl;
         cout << "Enter your choice: ";
         cin >> subchoice;
         switch (subchoice)
         {
         case 1:
         {
            cout << "Name, ProfessorID: ";
            cin >> temp;
            sec.add_professor(temp);
            addProfessorToFile(temp, professors_filename);
         }
         break;
         case 2:
         {
            sec.printProfessors();
            cout << "Enter the ID of the professor to modify: ";
            while (true)
            {
               cin >> professorID;
               if (professorID.at(0) == 'P')
                  break;
               else
                  cout << "Invalid input. Please try again." << endl;
            }
            temptr = sec.modify_professor(professorID);
            modifyProfessorInFile(professorID, *temptr, professors_filename);
         }
         break;
         case 3:
         {
            sec.printProfessors();
            cout << "Enter the ID of the professor to delete: ";
            while (1)
            {
               cin >> professorID;
               if (professorID.at(0) == 'P')
                  break;
               else
                  cout << "Invalid choice. Please try again." << endl;
            }
            sec.delete_professor(professorID);
            deleteProfessorFromFile(professorID, professors_filename);
         }
         break;
         default:
            cout << "Invalid choice. Please try again." << endl;
         }
         break;
      case 2:
      {
         cout << "1. Add a student." << endl;
         cout << "2. Modify a student." << endl;
         cout << "3. Delete a student." << endl;
         cout << "Enter your choice: ";
         cin >> subchoice;
         switch (subchoice)
         {
         case 1:
         {
            cout << "Name, StudentID, Semester(number), ECTS(number): ";
            cin >> temp1;
            sec.add_student(temp1);
            addStudentToFile(temp1, students_filename);
         }
         break;
         case 2:
         {
            sec.printStudents();
            unsigned atr_choice;
            cout << "Enter the ID of the student to modify: ";
            while (1)
            {
               cin >> studentID;
               if (studentID.at(0) == 'S')
                  break;
               else
                  cout << "Invalid choice. Please try again." << endl;
            }
            cout << "Choose (number) the attribute to modify: 1. Name, 2. Semester, 3. ECTS: ";
            while (1)
            {
               cin >> atr_choice;
               if (atr_choice != 1 && atr_choice != 2 && atr_choice != 3)
                  cout << "Invalid choice. Please try again." << endl;
            }
            temptr1 = sec.modify_student(studentID, atr_choice);
            modifyStudentInFile(studentID, *temptr1, students_filename);
         }
         break;
         case 3:
         {
            sec.printStudents();
            cout << "Enter the ID of the student to delete: ";
            while (1)
            {
               cin >> studentID;
               if (studentID.at(0) == 'S')
                  break;
               else
                  cout << "Invalid choice. Please try again." << endl;
            }
            sec.delete_student(studentID);
            deleteStudentFromFile(studentID, students_filename);
         }
         break;
         default:
            cout << "Invalid choice. Please try again." << endl;
         }
      }
      break;
      case 3:
      {
         cout << "1. Add a course." << endl;
         cout << "2. Modify a course." << endl;
         cout << "3. Delete a course." << endl;
         cout << "Enter your choice: ";
         cin >> subchoice;
         switch (subchoice)
         {
         case 1:
         {
            cout << "CourseID, Name, Units(number), Type, Semester(number): ";
            cin >> temp2;
            sec.add_course(temp2);
            addCourseToFile(temp2, courses_filename);
         }
         break;
         case 2:
         {
            sec.printCourses();
            unsigned atr_choice;
            cout << "Enter the ID of the course to modify: ";
            while (1)
            {
               cin >> courseID;
               if (courseID.at(0) == 'C')
                  break;
               else
                  cout << "Invalid choice. Please try again." << endl;
            }
            cout << "Choose (number) the attribute to modify: 1. Name, 2. Units(number), 3. Type, 4. Semester(number): ";
            while (1)
            {
               cin >> atr_choice;
               if (atr_choice != 1 && atr_choice != 2 && atr_choice != 3)
                  cout << "Invalid choice. Please try again." << endl;
            }
            temptr2 = sec.modify_course(courseID, atr_choice);
            modifyCourseInFile(courseID, *temptr2, courses_filename);
         }
         break;
         case 3:
         {
            sec.printCourses();
            cout << "Enter the ID of the course to delete: ";
            while (1)
            {
               cin >> courseID;
               if (courseID.at(0) == 'C')
                  break;
               else
                  cout << "Invalid choice. Please try again." << endl;
            }
            sec.delete_course(courseID);
            deleteStudentFromFile(courseID, courses_filename);
         }
         break;
         default:
            cout << "Invalid choice. Please try again." << endl;
         }
      }
      break;
      case 4:
      {
         sec.printProfessors();
         cout << "Enter the ID of professsor to assign the course: ";
         while (1)
         {
            cin >> professorID;
            if (professorID.at(0) == 'P')
               break;
            else
               cout << "Invalid choice. Please try again." << endl;
         }
         sec.printCourses();
         cout << "Enter the ID of the course: ";
         while (true)
         {
            cin >> courseID;
            if (courseID.at(0) == 'C')
               break;
            else
               cout << "Invalid choice. Please try again." << endl;
         }
         temptr = sec.find_professor(professorID);
         sec.set_professor(courseID, *temptr);
      }
      break;
      case 5:
      {
         sec.printStudents();
         cout << "Enter the ID of student to enrolling in a course: ";
         while (1)
         {
            cin >> studentID;
            if (studentID.at(0) == 'S')
               break;
            else
               cout << "Invalid choice. Please try again." << endl;
         }
         sec.printCourses();
         cout << "Enter the ID of course: ";
         while (1)
         {
            cin >> courseID;
            if (courseID.at(0) == 'C')
               break;
            else
               cout << "Invalid choice. Please try again." << endl;
         }
         temptr1 = sec.find_student(studentID);
         sec.reg_stud_to_course(courseID, *temptr1);
         // Logic for enrolling a student in a course
      }
      break;
      case 6:
      {
         sec.printCourses();
         cout << "Enter Course ID: ";
         while (true)
         {
            cin >> courseID;
            if (courseID.at(0) == 'C')
               break;
            else
               cout << "Invalid choice. Please try again." << endl;
         }
         sec.printProfessors();
         cout << "Enter Professor ID: ";
         while (true)
         {
            cin >> professorID;
            if (professorID.at(0) == 'P')
               break;
            else
               cout << "Invalid choice. Please try again." << endl;
         }
         temptr2 = sec.find_course(courseID);
         if (!sec.isProfessorAssignedToCourse(professorID, courseID))
         {
            cout << "This professor is not assigned to the course." << endl;
            break;
         }

         vector<Student *> students = sec.getStudentsInCourse(courseID);
         double grade;
         for (Student *student : students)
         {
            cout << "Enter grade for Student ID " << student->get_studentID() << ": ";
            while (true)
            {
               cin >> grade;
               if (grade > 10.0 || grade < 0.0)
                  cout << "Grade must be between 0.0 and 10.0. Please try again." << endl;
               else 
                  break;
            }
            sec.professor_give_grade(*temptr2, student->get_studentID(), professorID, grade);
         }
         cout << "Grades assigned successfully." << endl;
      }
      break;
      case 7:
      {
         // Logic for displaying and saving the list of students who passed a specific course
         string tempfile("StudentsPassed.csv");
         sec.printCourses();
         cout << "Enter the ID of course: ";
         while (true)
         {
            cin >> courseID;
            if (courseID.at(0) == 'C')
               break;
            else
               cout << "Invalid choice. Please try again." << endl;
         }
         temptr2 = sec.find_course(courseID);
         showStudentsThatPassedInFile(*temptr2, tempfile);
      }
      break;
      case 8:
      {
         sec.printProfessors();
         cout << "Please enter the ID of professor: ";
         while (true)
         {
            cin >> professorID;
            if (professorID.at(0) == 'P')
               break;
            else
               cout << "Invalid choice. Please try again." << endl;
         }
         temptr = sec.find_professor(professorID);
         sec.printStatistics(*temptr);
         // Logic for enabling a professor to print semester statistics
      }
      break;
      case 9:
      {
         unsigned sem;
         sec.printStudents();
         cout << "Enter the ID of student: ";
         while (true)
         {
            cin >> studentID;
            if (studentID.at(0) == 'S')
               break;
            else
               cout << "Invalid choice. Please try again." << endl;
         }
         temptr1 = sec.find_student(studentID);
         cout << "Choose (number) between 1. Current Semester, 2. All Semesters: ";
         cin >> sem;
         if (sem == 1)
            temptr1->printSemesterGrades();
         else if (sem == 2)
            temptr1->printGrades();
         else
            cout << "Invalid choice. Please try again." << endl;
         // Logic for allowing a student to print detailed grades
      }
      break;
      case 10:
      {
         sec.printGraduates();
         // Logic for printing a list of students eligible to graduate
      }
      break;
      case 11:
      {
         cout << "Exiting the program..." << endl;
      }
      break;
      default:
         cout << "Invalid choice. Please try again." << endl;
      }

      if (choice != 11)
      {
         cout << "Do you want to end this semester (Y OR N): ";
         while (true)
         {
            cin >> end_semester;
            if (end_semester != 'Y' && end_semester != 'N')
               cout << "Invalid choice. Please try again by typing either Y or N." << endl;
            else
               break;
         }
         if (end_semester == 'Y')
         {
            sec.change_students_semester();
         }
         else if (end_semester == 'N')
            continue;
      }

   } while (choice != 11);

   return 0;
}