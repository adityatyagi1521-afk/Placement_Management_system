#include <iostream>
#include <fstream>
using namespace std;

// Student Class
class Student {
public:
    int roll;
    char name[50], course[30], college[50];
    int year;

    void input() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Course: ";
        cin.getline(course, 30);

        cout << "Enter College: ";
        cin.getline(college, 50);

        cout << "Enter Year: ";
        cin >> year;
    }

    void display() {
        cout << "\nRoll: " << roll
             << "\nName: " << name
             << "\nCourse: " << course
             << "\nCollege: " << college
             << "\nYear: " << year << endl;
    }
};

// Company Class
class Company {
public:
    char name[50], post[50];
    float salary;
    char eligibility[50];

    void input() {

        cout << "Enter Company Name: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter Job Post: ";
        cin.getline(post, 50);

        cout << "Enter Salary: ";
        cin >> salary;
        cin.ignore();

        cout << "Enter Eligibility (%): ";
        cin.getline(eligibility,50);
    }

    void display() {
        cout << "\nName: " << name
             << "\nPost: " << post
             << "\nSalary: " << salary
             << "\nEligibility: " << eligibility << "%" << endl;
    }
};

// Application Class
class Application {
public:
    int roll;
    char post[50],companyname[100];

    void input() {
        cout << "Enter Student Roll No: ";
        cin >> roll;

        cout << "Enter Company name:";
        cin.ignore();
        cin.getline(companyname,50);

        cout << "Enter Post Applied: ";
        cin.getline(post, 50);
    }

    void display() {
        cout << "\nRoll No: " << roll
             << "\nCompany name: " << companyname
             << "\nPost: " << post << endl;
    }
};

// Add Student
void addStudent() {
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);
    s.input();
    file.write((char*)&s, sizeof(s));
    file.close();
    cout<<"\n Student data saved successfully!\n";
}

// Add Company
void addCompany() {
    Company c;
    ofstream file("company.dat", ios::binary | ios::app);
    if(!file){
        cout<<"error opening file!\n";
        return ;
    }
    c.input();
    file.write((char*)&c, sizeof(c));
    file.close();
    cout<<"\n Company added successfully!\n";
    system("pause");
}

// Apply for Job
void applyJob() {
    Application a;
    ofstream file("application.dat", ios::binary | ios::app);
    a.input();
    file.write((char*)&a, sizeof(a));
    file.close();
    cout<<"\n Thanks for visiting! \n";
}

// Show Applications
void showApplications() {
    Application a;
    ifstream file("application.dat", ios::binary);

    while (file.read((char*)&a, sizeof(a))) {
        a.display();
    }
    file.close();

}

// MAIN
int main() {
    int choice;

    do {
        cout << "\n\n--- Placement Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Add Company\n";
        cout << "3. Apply for Job\n";
        cout << "4. Show Applications\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2:
            cout<<" add details..\n";
                   addCompany(); break;
            case 3: applyJob(); break;
            case 4: 
            cout<<"list of candidates..\n";
                   showApplications(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}