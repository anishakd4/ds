class Student{
    public:
    int rollNumber; //by default properties are non-static
    int age;

    static int totalStudents; //This property ideally should belong to Student class instead of Objects
    //For properties which don't want to be created for each object seperately we declare them as static.
    //As this property belongs to class we need to initialize outside of the class

    Student(){
        totalStudents++;
    }

    int getRollNumber() { return rollNumber; }

    //static functions can only access static properties whether they are data members or functions
    //static functions don't have this keyword although all functions have this keyword which holds 
    //address of the current object
    static int getTotalStudents() { return totalStudents; }
};

int Student :: totalStudents = -2;
//:: this is called scope resolution operator