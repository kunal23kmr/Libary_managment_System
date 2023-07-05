#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void register_student(int n, string name);

class student
{
    string name, roll, branch, fathers_name, city, phone_number;

public:
    student()
    {
    }

    student(
        string name,
        string roll,
        string branch,
        string fathers_name,
        string city,
        string phone_number)
    {
        this->name = name;
        this->roll = roll;
        this->branch = branch;
        this->fathers_name = fathers_name;
        this->city = city;
        this->phone_number = phone_number;
    }
    friend void add(student &s);
    friend void delete_wala_function();
};

void add(student &s)
{
    ofstream fout;
    fout.open("Student.txt", ios::app);
    fout << std::setw(8) << s.roll;
    fout << std::setw(12) << s.name;
    fout << std::setw(10) << s.branch;
    fout << std::setw(15) << s.fathers_name << " ";
    fout << std::setw(15) << s.city << " ";
    fout << std::setw(13) << s.phone_number << "\n";
    fout.close();
    std::cout << "Added successfuly...!!" << endl;
}

class faculty
{
    string id, name, qualification, branch, phone_number, designation;

public:
    faculty()
    {
    }

    faculty(
        string id,
        string name,
        string qualification,
        string branch,
        string phone_number,
        string designation)
    {
        this->id = id;
        this->name = name;
        this->qualification = qualification;
        this->branch = branch;
        this->phone_number = phone_number;
        this->designation = designation;
    }
    friend void add(faculty &f);
    friend void delete_wala_function();
};

void add(faculty &f)
{
    ofstream fout;
    fout.open("Faculty.txt", ios ::app);
    fout << std::setw(5) << f.id << " ";
    fout << std::setw(11) << f.name << " ";
    fout << std::setw(15) << f.qualification << " ";
    fout << std::setw(8) << f.branch << " ";
    fout << std::setw(17) << f.phone_number << " ";
    fout << std::setw(12) << f.designation << "\n";
    fout.close();
    std::cout << "Added successfuly...!!" << endl;
}

class branch
{

    string name, number_of_student, number_of_faculty;

public:
    branch()
    {
    }
    branch(
        string name,
        string number_of_student,
        string number_of_faculty)
    {
        this->name = name,
        this->number_of_student = number_of_student,
        this->number_of_faculty = number_of_faculty;
    }
    friend void add(branch &b);
    friend void delete_wala_function();
};

void add(branch &b)
{
    ofstream fout;
    fout.open("Branch.txt", ios ::app);
    fout << std::setw(5) << b.name;
    fout << std::setw(17) << b.number_of_student;
    fout << std::setw(20) << b.number_of_faculty << "\n";
    fout.close();
    std::cout << "Added successfuly...!!" << endl;
}

void display()
{
    int a;
    cout << endl
         << "1.Student\n2.Faculty\n3.Branch\n4.Registerd students" << endl;
    cin >> a;
    if ((a > 4) || (a < 1))
    {
        cout << "Invalid selection.(select between 1-4)" << endl;
        return;
    }
    a--;
    string s[] = {"Student", "Faculty", "Branch", "Registerd_student"};
    string s1[] = {"    Roll        Name    Branch    Fathers_name      City_name    Phone_number\n=============================================================================",
                   "  Id        Name      Qualification   Branch    Phone_number    Designation\n============================================================================",
                   "Name  Number_of_student   Number_of_faculty\n===========================================",
                   " Roll    Branch"};
    ifstream f;
    f.open(s[a] + ".txt");
    string word;
    cout << s1[a] << endl;
    while (getline(f, word))
    {
        cout << word << endl;
    }
    cout << "\n\n\n";
    f.close();
}

void register_student(int n, string name)
{
    ofstream fout;
    fout.open("Registerd_student.txt", ios ::app);
    fout << std::setw(5) << n << "\t";
    fout << std::setw(7) << name << "\n";
    fout.close();
    std::cout << "Registered successfully." << endl;
}

string checkBranch()
{
    ifstream f;
    f.open("Branch.txt");
    string w1, w2, w3;
    cout << "\nBranch list." << endl;
    int i = 0;
    vector<string> v;
    f >> w1 >> w2 >> w3;
    while (f)
    {
        v.push_back(w1);
        i++;
        cout << i << " " << w1 << endl;
        f >> w1 >> w2 >> w3;
    }
    cout << endl;
    f.close();
    int x;
    cout << "\nEnter the branch number: ";
    cin >> x;
    if (x <= v.size() && x >= 0)
    {
        return v[x - 1];
    }
    else
    {
        cout << "Invalid input.";
        exit(0);
    }
}

void delete_wala_function()
{
    cout << "Select one for delete: " << endl;
    int a;
    cout << endl
         << "1.Student\n2.Faculty\n3.Branch" << endl;
    cin >> a;
    if ((a > 3) || (a < 1))
    {
        cout << "Invalid selection.(select between 1-3)" << endl;
        return;
    }
    a--;
    string s[] = {"Student", "Faculty", "Branch"};
    string s1[] = {"    Roll        Name    Branch    Fathers_name      City_name    Phone_number\n=============================================================================",
                   "  Id        Name      Qualification   Branch    Phone_number    Designation\n============================================================================",
                   "Name  Number_of_student   Number_of_faculty\n==========================================="};
    ifstream f;
    f.open(s[a] + ".txt");
    string word;
    cout << s1[a] << endl;
    while (getline(f, word))
    {
        cout << word << endl;
    }
    cout << "\n\n\n";
    f.close();
    ///////////////////////////////////////////
    string key;

    if (a == 0)
    {
        cout << "Enter the roll number of student: ";
        cin >> key;
        ///////////////////////////////////////////////
        ofstream fout("new_student_list.txt");
        ifstream fin("Student.txt");

        student s;

        fin >> s.roll >> s.name >> s.branch >> s.fathers_name >> s.city >> s.phone_number;
        while (fin)
        {
            if (key != s.roll)
            {
                fout << std::setw(12) << s.roll;
                fout << std::setw(8) << s.name;
                fout << std::setw(10) << s.branch;
                fout << std::setw(15) << s.fathers_name << " ";
                fout << std::setw(15) << s.city << " ";
                fout << std::setw(13) << s.phone_number << "\n";
            }
            fin >> s.roll >> s.name >> s.branch >> s.fathers_name >> s.city >> s.phone_number;
        }
        fout.close();
        fin.close();
        remove("Student.txt");
        rename("new_student_list.txt", "Student.txt");

        cout << "\nStudent deleted success\n";
    }
    else if (a == 1)
    {
        cout << "Enter the ID of faculty: ";
        cin >> key;

        ///////////////////////////////////////////////
        ofstream fout("new_faculty_list.txt");
        ifstream fin("Faculty.txt");

        faculty f;

        fin >> f.id >> f.name >> f.qualification >> f.branch >> f.phone_number >> f.designation;
        while (fin)
        {
            if (key != f.id)
            {
                fout << std::setw(5) << f.id << " ";
                fout << std::setw(11) << f.name << " ";
                fout << std::setw(15) << f.qualification << " ";
                fout << std::setw(8) << f.branch << " ";
                fout << std::setw(17) << f.phone_number << " ";
                fout << std::setw(12) << f.designation << "\n";
            }
            fin >> f.id >> f.name >> f.qualification >> f.branch >> f.phone_number >> f.designation;
        }
        fout.close();
        fin.close();
        remove("Faculty.txt");
        rename("new_faculty_list.txt", "Faculty.txt");
        cout << "Faculty deleted sucessfully" << endl;
    }
    else if (a == 2)
    {
        cout << "Enter the branch name: ";
        cin >> key;

        ///////////////////////////////////////////////
        ofstream fout("new_branch_list.txt");
        ifstream fin("Branch.txt");

        branch b;

        fin >> b.name >> b.number_of_student >> b.number_of_faculty;
        while (fin)
        {
            if (key != b.name)
            {
                fout << std::setw(5) << b.name;
                fout << std::setw(17) << b.number_of_student;
                fout << std::setw(20) << b.number_of_faculty << "\n";
            }
            fin >> b.name >> b.number_of_student >> b.number_of_faculty;
        }
        fout.close();
        fin.close();
        remove("Branch.txt");
        rename("new_branch_list.txt", "Branch.txt");

        cout << "Branch deleted sucessfully" << endl;
    }
}

void addList()
{
    int a;
    cout << "1.Add Student\n2.Add Faculty\n3.Add branch\n";
    cin >> a;
    if (a == 1)
    {
        string name;
        string roll;
        string branch;
        string fathers_name;
        string city;
        string phone_number;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll: ";
        cin >> roll;

        branch = checkBranch();

        cout << "Enter father's name: ";
        cin >> fathers_name;
        cout << "Enter city name: ";
        cin >> city;
        cout << "Enter phone number: ";
        cin >> phone_number;

        student s(name, roll, branch, fathers_name, city, phone_number);

        add(s);

        register_student(stoi(roll), name);
    }
    else if (a == 2)
    {
        string id;
        string name;
        string qualification;
        string branch;
        string phone_number;
        string designation;

        cout << "Enter id: ";
        cin >> id;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter qualification: ";
        cin >> qualification;

        branch = checkBranch();

        cout << "Enter phone number: ";
        cin >> phone_number;
        cout << "Enter designation: ";
        cin >> designation;

        faculty f(id, name, qualification, branch, phone_number, designation);

        add(f);
    }
    else if (a == 3)
    {
        string name;
        string number_of_student;
        string number_of_faculty;

        cout << "Enter Branch name: ";
        cin >> name;
        cout << "Enter number of students in branch: ";
        cin >> number_of_student;
        cout << "Enter number of faculty in branch: ";
        cin >> number_of_faculty;

        branch b(name, number_of_student, number_of_faculty);

        add(b);
    }
    else
    {
        cout << "Invalid Selection." << endl;
    }
}

int main()
{
    bool flag = true;
    while (flag)
    {
        int n;
        cout << "1.Display List\n2.Add\n3.Delete\n";
        cin >> n;
        if (n == 1)
        {
            display();
        }
        else if (n == 2)
        {
            addList();
        }
        else if (n == 3)
        {
            delete_wala_function();
        }
        else
        {
            cout << "Invalid input." << endl;
        }
        cout << "Press (y/Y) to continue" << endl;
        char a;
        cin.clear();
        fflush(stdin);
        cin >> a;
        if (a == 'y' || a == 'Y')
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }

    return 0;
}