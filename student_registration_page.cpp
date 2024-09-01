//
//  student_registration_page.cpp
//  CS222_Final_Project
//
//  Created by Assier Anteneh Alemu on 28/04/2022.
//

#include "student_registration_page.hpp"

#include <fstream>
#include <string>

using namespace std;

const int MAX = 36;

fstream student_file;

const int MAX_STUDENT = 100;

int number_of_student = 0;

struct students {
    
    string name, id, username, password;
    
    float mark[4], gpa, cgpa;
    
    char grade[4];
    
    int login_times = 0;
    
    fstream report;
    
}student[MAX_STUDENT];

// A function that sorts students' name alphabetically
//string sort_alphabetically_student (string student_name[number_of_student]){
//
//    string temp;
//
//    for (int i = 0; i < number_of_student - 1; i++) {
//
//        for (int j = i + 1; j < number_of_student - 1; j++) {
//
//            if (strcasecmp(student_name[i].c_str(), student_name[j].c_str()) > 0) {
//
//                temp = student[i].name;
//                student[i].name = student[j].name;
//                student[j].name = temp;
//
//            }
//        }
//    }
//
//    return student_name[number_of_student];
//}

// Creates a file and write each students name and id number on that file
void writing_registered_students (string student_name[number_of_student]){
    
    student_file.open("Registered_Students.txt", ios::in | ios::out | ios::trunc);
    
    if (student_file.is_open()) {
        
        cout<<"File opend successfully!"<<endl;
        
        student_file<<left<<setw(25)<<"Name"<<setw(10)<<"ID"<<endl;
        
        student_file<<"=============================================="<<endl;
        
        for (int i = 0; i < number_of_student; i++) {
            
            student_file<<left<<setw(25)<<student[i].name<<setw(10)<<student[i].id<<endl;
        }
        
        cout<<"File written successfully!"<<endl;
        
        student_file.close();
        
    } else{
        
        cout<<"Error openning the file!"<<endl;
    }
}

//Generates random 5 letter ID number for each student
string generate_idnum(int n){
    char alphabet[MAX] = { 'A', 'B', 'B', 'D', 'E', 'F', 'G',
                          'H', 'I', 'K', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z', '0', '1',
                          '2', '3', '4', '5', '6', '7', '8', '9' };
 
    string id = "";
    for (int i = 0; i < n; i++){
        id = id + alphabet[rand() % MAX];
    }
     
    return id;
}

string student_registration_page (){
    
    string end = "DONE";
    
    cout<<"Welcome to student registration page!"<<endl;
    
    cout<<"Enter full name of each student and enter \"done\" when you are done!"<<endl;
    
    
    //Accepts name of each students
    
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    
    for (int i = 0; i < MAX_STUDENT; i++) {
        
        getline(cin, student[i].name);
        
        if (strcasecmp(student[i].name.c_str(), end.c_str()) == 0) {
            
            break;
            
        }
        
        number_of_student++;
        
    }
    
    //Gives ID number for eacher student uses first letter of their name and adds a number to it
    
    for (int i = 0; i < number_of_student; i++) {

        student[i].id =  generate_idnum(5);

    }
    
    writing_registered_students(&student[number_of_student].name);
    
//    sort_alphabetically_student(&student[number_of_student].name);
    
    return student[number_of_student - 1].name;
    
}
