#include <iostream>
using namespace std;
class Person
{
	protected:
	    string name;
	    int age;
	    
	public:
	    Person(string name, int age)
		{
	        this->name = name;
	        this->age = age;
	    }
	    virtual void display()
		{
	        cout<<"Name: "<<name<<" Age: "<< age;
	    }
	    string getName()
	    {
	    	return name;
		}
	    int getAge()
	    {
	    	return age;
		}
};

class Student : public Person
{
	protected:
	    int rollNumber;
	    string branch;
	    float marks[5];
	    float cgpa;
	
	public:
	    Student(string name, int age, int rollNumber, string branch, float marks[5]) : Person(name, age), rollNumber(rollNumber), branch(branch) 
	    {
	        for(int i=0;i<5;i++)
			{
	            this->marks[i] = marks[i];
	        }
	        CGPA();
	    }
	
	    void CGPA()
		{
	        float sum = 0;
	        for (int i=0;i<5;i++)
			{
	            sum += marks[i];
	        }
	        cgpa = sum / 5.0;
	    }
	
	    void display()
		{
	        Person::display();
	        cout<<" Roll Number: "<<rollNumber<<" Branch: "<<branch<<" CGPA: "<< cgpa;
	    }
	    int getRollNumber()
	    {
	    	return rollNumber;
		}
	    string getBranch()
	    {
	    	return branch;
		}
	    float getCGPA()
	    {
	    	return cgpa;
		}
};

class Faculty : public Person 
{
	protected:
	    string facultyID;
	    string department;
	    float salary;
	
	public:
	    Faculty(string name, int age, string facultyID, string department, float salary) : Person(name, age), facultyID(facultyID), department(department), salary(salary) 
	    {
		
		}
	
	    void display()
		{
	        Person::display();
	        cout<<" Faculty ID: "<<facultyID<<" Department: "<<department<<" Salary: "<< salary;
	    }
	
	    string getFacultyID()
	    {
	    	return facultyID;
		}
	    string getDepartment()
	    {
	    	return department;
		}
	    float getSalary()
	    {
	    	return salary;
		}
};

class TeachingAssistant : public Student, public Faculty
{
	public:
	    TeachingAssistant(string name, int age, int rollNumber, string branch, float marks[5],string facultyID, string department, float salary) : Student(name, age, rollNumber, branch, marks), Faculty(name, age, facultyID, department, salary)             
	    {
		
		}
	
	    void display()
		{
	        Student::display();
	        Faculty::display();
	    }
};

class Administration
{
public:
    void displayDetails(Student &student, Faculty &faculty)
	{
        cout << "\nStudent Details (from Administration): \n";
        cout << "Name: " << student.getName() << " Age: " << student.getAge() << " Roll Number: "<< student.getRollNumber() << " Branch: " << student.getBranch() << " CGPA: " << student.getCGPA(); 
        cout << "\nFaculty Details (from Administration): \n";
        cout << "Name: " << faculty.getName() << " Age: " << faculty.getAge() << " Faculty ID: "<< faculty.getFacultyID() << " Department: " << faculty.getDepartment() << " Salary: " << faculty.getSalary();             
    }
};

int main()
{
    float studentMarks[5] = {85.0, 90.0, 88.0, 92.0, 89.0};
    Student student("John Doe", 21, 12345, "CSE", studentMarks);

    Faculty faculty("Dr. Smith", 45, "F001", "CSE", 70000.0);

    TeachingAssistant ta("Alice Johnson", 26, 67890, "AI-ML", studentMarks, "F002", "AI-ML", 60000.0);

    student.display();
    cout << endl;
    faculty.display();
    cout << endl;
    ta.display();
    cout << endl;

    Administration admin;
    admin.displayDetails(student, faculty);

}
