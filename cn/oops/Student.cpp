class Student{
    public:
    int rollNumber; //by default properties are non-static
    int age;

    static int totalStudents; //This property ideally should belong to Student class instead of Objects
    //For properties which don't want to be created for each object seperately we declare them as static.
    //As this property belongs to class we need to initialize outside of the class
};

int Student :: totalStudents = -2;