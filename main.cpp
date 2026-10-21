//Code created by James Lambros. Sources at the end of the file
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Student{
private:
    double gpa;
    int graduationYear;
    std::string graduationSemester;
    int enrolledYear;
    std::string enrolledSemester;
    std::string undergradGrad;
    std::string nameFirst;
    std::string nameLast;
public:
    //Default constructor for each student.
    Student(){
        gpa = 0.0;
        graduationYear = 1990; //Setting to an obviously bad values so that errors can be detected easier
        graduationSemester = "Undefined";
        enrolledYear = 1990;
        enrolledSemester = "Undefined";
        nameFirst = "Undefined";
        nameLast = "Undefined";
    }
    //Getters for the various variables, done by calling their respective functions with no arguments and just returning the variable.
    std::string getFirstName(){
        return(nameFirst);
    }
    std::string getLastName(){
        return(nameLast);
    }
    int getGradYear(){
        return(graduationYear);
    }
    std::string getGradSemester(){
        return(graduationSemester);
    }
    int getEnrolledYear(){
        return(enrolledYear);
    }
    std::string getEnrolledSemester(){
        return(enrolledSemester);
    }
    std::string getStatus(){
        return(undergradGrad);
    }
    double getGPA(){
        return(gpa);
    }
    //Setters. We call the function with an argument and set the variable to that value.
    void setName(std::string x, std::string y){
        nameFirst = x;
        nameLast = y;
    }
    void setGradYear(int x){
        graduationYear = x;
    }
    void setGradSemester(std::string x){
        graduationSemester = x;
    }
    void setEnrolledYear(int x){
        enrolledYear = x;
    }
    void setEnrolledSemester(std::string x){
        enrolledSemester = x;
    }
    void setStatus(std::string x){ //Maybe I could have it chose between 1 and 0, setting either grad or undergrad?
        undergradGrad = x;
    }
    void setGPA(double x){
        gpa = x;
    }
    //Destructor
    ~Student(){}
};

class Art_Student: public Student{
private:
    std::string art_emphasis;
public:
    //I am using numbers to set the art concentration, since the user could input the value incorrectly
    void setArt(int x){
        if(x == 1){
            art_emphasis = "Art Studio";
        }
        else if(x == 2){
            art_emphasis = "Art History";
        }
        else if(x == 3){
            art_emphasis = "Art Education";
        }
        else
            std::cout << "Invalid" << std::endl;
    }
    //Getter for the major
    std::string getArtMajor(){
        return(art_emphasis);
    }
};

class Physics_Student: public Student{
private:
    std::string concentration;
public:
    //I am using numbers to set the physics concentration. This makes it easy to set values
    void setPhysics(int x){
        if(x == 1){
            concentration = "Biophysics";
        }
        else if(x == 2){
            concentration = "Earth and Planetary Sciences";
        }
        else
            std::cout << "Invalid" << std::endl;
    }
    //getter
    std::string getPhysicsMajor(){
        return(concentration);
    }
};

int main(){
    //Setting up the vectors using the example from the problem.
    std::vector<Physics_Student *> physics_students;
    std::vector<Art_Student *> art_students;
     //Loop to initialize 5 art students
    for (int i = 0; i < 5; i++) {
        art_students.push_back(new Art_Student);
        if(i == 0){
            art_students[i]->setArt(3);
            art_students[i]->setGPA(3.9);
            art_students[i]->setEnrolledYear(2000);
            art_students[i]->setEnrolledSemester("Summer");
            art_students[i]->setGradYear(2020);
            art_students[i]->setGradSemester("Winter");
            art_students[i]->setStatus("Grad");
        }
        else if(i % 2 == 0){
            art_students[i]->setArt(2);
            art_students[i]->setGPA(1.9);
            art_students[i]->setEnrolledYear(2004);
            art_students[i]->setEnrolledSemester("Spring");
            art_students[i]->setGradYear(2040);
            art_students[i]->setGradSemester("Fall");
            art_students[i]->setStatus("Undergrad");
        }
        else{
            art_students[i]->setArt(1);
            art_students[i]->setGPA(2.9);
            art_students[i]->setEnrolledYear(2020);
            art_students[i]->setEnrolledSemester("Fall");
            art_students[i]->setGradYear(2025);
            art_students[i]->setGradSemester("Summer");
            art_students[i]->setStatus("Grad");
        }
    }
    //I set the names outside the loop, it just didn't make sense otherwise
    art_students[0]->setName("Jeff","Smith");
    art_students[1]->setName("James","Lamb");
    art_students[2]->setName("Ivan","Painter");
    art_students[3]->setName("Picaso","Garcia");
    art_students[4]->setName("Plain","Jaine");
    //Loop for the physics students
    for (int k = 0; k < 5; k++){
        physics_students.push_back(new Physics_Student);
        if(k % 3 == 0){
            physics_students[k]->setPhysics(1);
            physics_students[k]->setGPA(4.0);
            physics_students[k]->setEnrolledYear(2010);
            physics_students[k]->setEnrolledSemester("Summer");
            physics_students[k]->setGradYear(2020);
            physics_students[k]->setGradSemester("Summer");
            physics_students[k]->setStatus("Undergrad");
        }
        else if(k == 1){
            physics_students[k]->setPhysics(2);
            physics_students[k]->setGPA(2.0);
            physics_students[k]->setEnrolledYear(2005);
            physics_students[k]->setEnrolledSemester("Winter");
            physics_students[k]->setGradYear(2055);
            physics_students[k]->setGradSemester("Winter");
            physics_students[k]->setStatus("Grad");
        }
        else{
            physics_students[k]->setPhysics(2);
            physics_students[k]->setGPA(3.0);
            physics_students[k]->setEnrolledYear(2011);
            physics_students[k]->setEnrolledSemester("Fall");
            physics_students[k]->setGradYear(2022);
            physics_students[k]->setGradSemester("Fall");
            physics_students[k]->setStatus("Undergrad");
        }
    }
    //Set names for the physics students
    physics_students[0]->setName("Albert", "Einstein");
    physics_students[1]->setName("Smart","Guy");
    physics_students[2]->setName("Galileo", "Galilei");
    physics_students[3]->setName("Jim","Bob");
    physics_students[4]->setName("Mr","Physics");
    //Now we output to a file
    std::ofstream outfile;
    outfile.open("students.dat");
    //Loop for the art students
    outfile << "----------------------" << std::endl;
    for (int i = 0; i < art_students.size(); i++){
        outfile << "Name: " << art_students[i]->getFirstName() << " " << art_students[i]->getLastName() << std::endl;
        outfile << "GPA: " << art_students[i]->getGPA() << std::endl;
        outfile << "Enrolled Year: " << art_students[i]->getEnrolledYear() << std::endl;
        outfile << "Enrolled Semester: " << art_students[i]->getEnrolledSemester() << std::endl;
        outfile << "Graduation Year: " << art_students[i]->getGradYear() << std::endl;
        outfile << "Graduation Semester: " << art_students[i]->getGradSemester() << std::endl;
        outfile << "Status: " << art_students[i]->getStatus() << std::endl;
        outfile << "Art Major: " << art_students[i]->getArtMajor() << std::endl;
        outfile << "----------------------" << std::endl;
    }
    //Loop for the physics students
    for (int k = 0; k < physics_students.size(); k++){
        outfile << "Name: " << physics_students[k]->getFirstName() << " " << physics_students[k]->getLastName() << std::endl;
        outfile << "GPA: " << physics_students[k]->getGPA() << std::endl;
        outfile << "Enrolled Year: " << physics_students[k]->getEnrolledYear() << std::endl;
        outfile << "Enrolled Semester: " << physics_students[k]->getEnrolledSemester() << std::endl;
        outfile << "Graduation Year: " << physics_students[k]->getGradYear() << std::endl;
        outfile << "Graduation Semester: " << physics_students[k]->getGradSemester() << std::endl;
        outfile << "Status: " << physics_students[k]->getStatus() << std::endl;
        outfile << "Physics Major: " << physics_students[k]->getPhysicsMajor() << std::endl;
        outfile << "----------------------" << std::endl;
    }
    outfile.close();
    //Free memory
    for(int i = 0; i < 5; i++){
        delete art_students[i];
        delete physics_students[i];
    }
    return 0;
}
//Sources
//https://www.geeksforgeeks.org/cpp/c-classes-and-objects/
//https://www.geeksforgeeks.org/cpp/constructors-c/
//https://cplusplus.com/doc/tutorial/files/
//https://www.geeksforgeeks.org/cpp/object-oriented-programming-in-cpp/
