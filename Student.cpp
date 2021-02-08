#include <string>
#include "Student.h"

Student::Student() : Student(-1, "") {} // Student::Student()

Student::Student(int id, std::string name) : studentID{id}, studentName{name} {} // Student::Student(int, std::string)

void Student::setStudentID(int id) {
    studentID = id;
} // Student::setStudentID(int)

void Student::setStudentName(std::string name) {
    studentName = name;
} // Student::setStudentName(std::string)

int Student::getStudentID() const {
    return studentID;
} // Student::getStudentID()

std::string Student::getStudentName() const {
    return studentName;
} // Student::getStudentName()

bool Student::operator==(const Student& otherStudent) {
    return this->studentID == otherStudent.studentID;
} // Studet::operator(Student&)

