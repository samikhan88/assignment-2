#include<iostream>
using namespace std;

class Course {
public:
    Course(const string& courseName, int capacity);
    Course(Course& c);
    ~Course();
    string getCourseName() const;
    void addStudent(const string& name);
    void dropStudent(const string& name);
    string* getStudents() const;
    int getNumberOfStudents() const;
private:
    string courseName;
    string* students;
    int numberOfStudents;
    int capacity;
};

Course::Course(const string& courseName, int capacity) {
    numberOfStudents = 0;
    this->courseName = courseName;
    this->capacity = capacity;
    students = new string[capacity];
}

Course::~Course() {
    delete[] students;
}
Course::Course(Course& c) {
    courseName = c.courseName;
    students = c.students;
    numberOfStudents = c.numberOfStudents;
    capacity = c.capacity;

}

string Course::getCourseName() const {
    return courseName;
}
void Course::addStudent(const string& name) {
    students[numberOfStudents] = name;
    numberOfStudents++;
}
void Course::dropStudent(const string& name) {
    for (int i = 0; i < numberOfStudents; i++) {
        if (students[i] == name) {
            for (int j = i+1; j < numberOfStudents; j++) {
                students[i] = students[j];
                i++;
            }
            break;
        }
    }
    numberOfStudents--;
}

string* Course::getStudents() const {
    return students;
}

int Course::getNumberOfStudents() const {
    return numberOfStudents;
}

int main()
{
    Course course1("Data Structures", 10);
    Course course2("Database Systems", 15);
    
    course1.addStudent("Ali");
    course1.addStudent("Ahmed"); 
    course1.addStudent("Imran");
    course2.addStudent("Rizwan");
    course2.addStudent("Akeel");
    Course course3(course1);
    cout << "Number of students in course1: " << course1.getNumberOfStudents() << "\n";

    string* students = course1.getStudents();

    for (int i = 0; i < course1.getNumberOfStudents(); i++)
        cout << students[i] << ", ";
    
    cout << "\nNumber of students in course2: " << course2.getNumberOfStudents() << "\n";
    students = course2.getStudents();
    for (int i = 0; i < course2.getNumberOfStudents(); i++)
        cout << students[i] << ", ";
    
    cout << "\nNumber of students in course3: " << course3.getNumberOfStudents() << "\n";
     students = course3.getStudents();
    for (int i = 0; i < course3.getNumberOfStudents(); i++)
        cout << students[i] << ", ";

    course2.dropStudent("Rizwan");
    course1.dropStudent("Ali");
    course1.dropStudent("Imran");

    cout << "\nNumber of students in course1: " << course1.getNumberOfStudents() << "\n";

    students = course1.getStudents();

    for (int i = 0; i < course1.getNumberOfStudents(); i++)
        cout << students[i] << ", ";

    cout << "\nNumber of students in course2: " << course2.getNumberOfStudents() << "\n";
    students = course2.getStudents();
    for (int i = 0; i < course2.getNumberOfStudents(); i++)
        cout << students[i] << ", ";

    return 0;
}