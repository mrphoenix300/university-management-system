# University Management System

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg)

A comprehensive C++ application for managing university academic operations, developed as a third-semester computer science project.

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Project Structure](#-project-structure)
- [Installation](#-installation)
- [Usage](#-usage)
- [Data Storage](#-data-storage)
- [Class Documentation](#-class-documentation)
- [Development Highlights](#-development-highlights)
- [Contributing](#-contributing)
- [License](#-license)

## 🎯 Overview

The University Management System is a console-based application designed to streamline university operations. It handles student enrollments, professor assignments, course management, and academic record keeping with a robust object-oriented architecture.

## ✨ Features

- **Student Management**: Complete CRUD operations for student records
- **Professor Management**: Add, modify, and remove professor profiles
- **Course Administration**: Create and manage courses with detailed attributes
- **Enrollment System**: Register students for courses and assign instructors
- **Grading System**: Professors can assign and manage student grades
- **Academic Analytics**:
  - Pass/fail reports for courses
  - Semester statistics for professors
  - Comprehensive grade transcripts for students
  - Graduation eligibility tracking
- **Data Persistence**: CSV-based storage for all academic records
- **Semester Management**: End-of-semester processing and student progression

## 📁 Project Structure

```
university-management-system/
│
├── main.cpp                 # Application entry point and UI
├── Person.hpp & Person.cpp  # Base class implementation
├── Student.hpp & Student.cpp # Student class implementation
├── Professor.hpp & Professor.cpp # Professor class 
implementation
├── Course.hpp & Course.cpp  # Course class implementation
├── Secretary.hpp & Secretary.cpp # Central management class
├── Students.csv            # Student data storage
├── Professors.csv          # Professor data storage
├── Courses.csv             # Course data storage
├── LICENSE                 # MIT LICENSE
└── README.md               # This file
```

## 🔧 Installation

### Prerequisites
- C++ compiler with C++11 support (GCC, Clang, or MSVC)
- Standard Template Library (STL)

### Compilation
```bash
# Clone the repository
git clone <repository-url>
cd Academic-Management-System

# Compile the project
g++ -std=c++11 main.cpp Person.cpp Student.cpp Professor.cpp Course.cpp Secretary.cpp -o university_system
```

### Execution
```bash
./university_system
```

## 🚀 Usage

Upon launching the application, you'll be presented with a comprehensive menu system:

1. **Professor Operations** - Manage professor records
2. **Student Operations** - Handle student information
3. **Course Operations** - Administer courses
4. **Course Assignments** - Assign professors to courses
5. **Student Enrollment** - Register students for courses
6. **Grade Management** - Input and modify student grades
7. **Academic Reports** - Generate pass/fail reports
8. **Course Statistics** - View professor teaching statistics
9. **Student Transcripts** - Access grade records
10. **Graduation Review** - Identify eligible graduates
11. **Exit** - Close the application

## 💾 Data Storage

The system uses CSV files for persistent data storage:

- `Students.csv`: Stores student ID, name, semester, and ECTS credits
- `Professors.csv`: Contains professor ID and name
- `Courses.csv`: Maintains course ID, name, units, type, and semester

Data is automatically loaded at startup and saved after modifications.

## 🏗️ Class Documentation

### Person (Base Class)
- Base class for all individuals in the system
- Implements core attributes and operations for people

### Student (Inherits from Person)
- Manages student academic information
- Tracks courses, grades, and academic progress
- Handles enrollment and graduation status

### Professor (Inherits from Person)
- Manages professor information and course assignments
- Handles grade assignment and course statistics

### Course
- Represents academic courses
- Manages enrollment, professors, and student grades
- Tracks course attributes (type, units, semester)

### Secretary
- Central management class coordinating all operations
- Handles relationships between students, professors, and courses
- Implements core business logic and academic rules

## 🎓 Development Highlights

This project demonstrates advanced C++ programming concepts:

- **Object-Oriented Design**: Inheritance, polymorphism, and encapsulation
- **Memory Management**: Proper use of pointers and dynamic allocation
- **STL Utilization**: Vectors, maps, and algorithms
- **File I/O Operations**: CSV reading and writing
- **Operator Overloading**: Custom stream operators for classes
- **Exception Handling**: Robust error management
- **Modular Architecture**: Clean separation of concerns

## 🤝 Contributing

This was a university project, but contributions and improvements are welcome

## 📜 License

This project is licensed under the MIT License - see the LICENSE file for details.

---

**Note**: This project was developed as part of a third-semester computer science curriculum and demonstrates foundational programming concepts in C++.