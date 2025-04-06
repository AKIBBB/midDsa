#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

struct Student {
    string name;
    int id;
    float cgpa;

    Student(string n, int i, float c) : name(n), id(i), cgpa(c) {}
};

Student findHighestCGPA(const vector<Student>& students, int low, int high) {
    if (low == high) {
        return students[low];
    }

    int mid = low + (high - low) / 2;

    Student leftHighest = findHighestCGPA(students, low, mid);
    Student rightHighest = findHighestCGPA(students, mid + 1, high);

    if (leftHighest.cgpa >= rightHighest.cgpa) {
        return leftHighest;
    } else {
        return rightHighest;
    }
}

int main() {
    vector<Student> students = {
        Student("Alice", 1, 3.6),
        Student("Bob", 2, 3.9),
        Student("Charlie", 3, 3.8),
        Student("David", 4, 3.7)
    };

    Student topStudent = findHighestCGPA(students, 0, students.size() - 1);

    cout << "Student with highest CGPA:" << endl;
    cout << "Name: " << topStudent.name << ", ID: " << topStudent.id << ", CGPA: " << topStudent.cgpa << endl;

    return 0;
}
