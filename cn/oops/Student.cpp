class Student
{
public:
    int rollNumber; // by default properties are non-static
    int age;
    char *name;

    static int totalStudents; // This property ideally should belong to Student class instead of Objects
    // For properties which don't want to be created for each object seperately we declare them as static.
    // As this property belongs to class we need to initialize outside of the class

    Student()
    {
        cout << "constructor 1 called" << endl;
        totalStudents++;
    }

    Student(int age, int rollNumber)
    {
        cout << "constructor 2 called" << endl;
        this->age = age;
        this->rollNumber = rollNumber;
    }

    Student(int age, char *name)
    {
        cout << "constructor 3 called" << endl;
        totalStudents++;
        this->age = age;
        // shallow copy
        // this->name = name;

        // deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    ~Student()
    {
        cout << "Destructor called" << endl;
    }

    void display()
    {
        cout << name << " " << age << endl;
    }

    void display2()
    {
        cout << age << " " << rollNumber << endl;
    }

    int getRollNumber() { return rollNumber; }

    // static functions can only access static properties whether they are data members or functions
    // static functions don't have this keyword although all functions have this keyword which holds
    // address of the current object
    static int getTotalStudents() { return totalStudents; }
};

int Student ::totalStudents = -2;
//:: this is called scope resolution operator

// classes are also called user defined datatypes