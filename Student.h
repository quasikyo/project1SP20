#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int studentID;
    std::string studentName;
public:
    /**
     * Default constructor.
     *
     * Provided so that this class can work
     * with the ADT as `Class[int]` attempts
     * to invoke the default constructor for Class.
     */
    Student();

    /**
     * Specifies a new Student.
     *
     * @param id   the student's ID
     * @param name the student's name
     */
    Student(int id, std::string name);

    /**
     * Sets the student's ID.
     *
     * @param id the new student ID
     */
    void setStudentID(int id);

    /**
     * Sets the student's name.
     *
     * @param name the new student name
     */
    void setStudentName(std::string name);

    /**
     * Returns the student's ID.
     *
     * @return the student's ID
     */
    int getStudentID() const;

    /**
     * Returns the student's name.
     *
     * @return the student's name
     */
    std::string getStudentName() const;

    /**
     * Determines whether or not Student objects are equal.
     *
     * @return true if they have the same ID, false otherwise
     */
    bool operator==(const Student& otherStudent);
}; // Student

#endif

