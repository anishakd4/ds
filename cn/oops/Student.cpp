class Student
{
public:
    int rollNumber; // by default properties are non-static
    int age;
    char *name;
    const int x;
    int &y;

    static int totalStudents; // This property ideally should belong to Student class instead of Objects
    // For properties which don't want to be created for each object seperately we declare them as static.
    // As this property belongs to class we need to initialize outside of the class

    Student() : x(1), y(this->age)
    {
        cout << "constructor 1 called" << endl;
        totalStudents++;
    }

    Student(int age, int rollNumber) : x(1), y(this->age)
    {
        cout << "constructor 2 called" << endl;
        this->age = age;
        this->rollNumber = rollNumber;
    }

    Student(int age, char *name) : x(1), y(this->age)
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

    // Here to avoid infinite loop we need to pass by reference.
    Student(Student const &s) : x(1), y(this->age)
    {
        this->age = s.age;
        // this->name = s.name; shallow copy
        this->rollNumber = s.rollNumber;
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void operator=(const Student &other)
    {
        this->age = other.age;
        this->rollNumber = other.rollNumber;
        this->name = other.name;
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

int Student ::totalStudents = 0;
//:: this is called scope resolution operator

// classes are also called user defined datatypes