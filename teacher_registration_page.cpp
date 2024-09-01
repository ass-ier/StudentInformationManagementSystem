//
//  teacher_registration_page.cpp
//  CS222_Final_Project
//
//  Created by Assier Anteneh Alemu on 28/04/2022.
//

#include "teacher_registration_page.hpp"
#include "/Users/triplea/Documents/HiLCoE/c++/CS222_Final_Project/course_add_page.cpp"

#include <string>
#include <fstream>

using namespace std;



fstream teacher_file;

const int MAX_TEACHER = 50;

int number_of_teacher = 0;



struct teachers {
    
    string name, username, password, notice;
    
    string course;
    
    bool mark_submitted, notice_posted;
    
    int login_times = 0;
    
    int login[MAX_TEACHER];
    
} teacher[MAX_TEACHER];


//Function that sorts teachers' name alphabetically

string sort_alphabetically_teacher (string teacher_name[]){
    
    string temp;
    
    for (int i = 0; i < number_of_teacher; i++) {
        
        for (int j = i + 1; j < number_of_teacher; j++) {
            
            if (strcasecmp(teacher_name[i].c_str(), teacher_name[j].c_str()) > 0) {
                
                temp = teacher_name[i];
                teacher_name [i] = teacher_name[j];
                teacher_name[j] = temp;
                
            }
        }
    }
    
    return teacher_name[number_of_teacher];
}


//Function that backup registered teachers to a file
void writing_registered_teachers (string teacher_name[number_of_teacher], string teacher_course[number_of_teacher]){
    
    teacher_file.open("Registered_Teachers", ios::in | ios::out | ios::trunc);
    
    if (teacher_file.is_open()) {
        
        cout<<"File opend successfully!"<<endl;
        
        teacher_file<<left<<setw(25)<<"Name"<<setw(15)<<"Course"<<endl;
        teacher_file<<"==============================================="<<endl;
        for (int i = 0; i < number_of_teacher; i++) {
            teacher_file<<left<<setw(25)<<teacher[i].name<<setw(15)<<teacher[i].course<<endl;
        }
        
        cout<<"File written successfully!"<<endl;
        
        teacher_file.close();
        
    } else{
        
        cout<<"Error openning the file!"<<endl;
        
    }
    
    for (int i = 0; i < number_of_teacher; i++) {
        teacher[i].mark_submitted = false;
    }
    
}



string teacher_registration_page (){
    
    string end = "DONE";
    
    bool error = false;
    
    cout<<"Welcome to teacher registration page!"<<endl;
    
    cout<<"Enter full name of each teacher and enter \"done\" when you are done!"<<endl;
    
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    
    //Accepts full name of the teachers
    for (int i = 0; i < MAX_TEACHER; i++) {
        
        getline(cin, teacher[i].name);
        
        if (strcasecmp(teacher[i].name.c_str(), end.c_str()) == 0) {
            
            break;
            
        }
        
        number_of_teacher++;
        
    }
    
    //Assignes each teacher a course
    for (int i = 0; i < number_of_teacher; i++) {
        
            do {
        
                error = false;
                
                cout<<"Assign "<<teacher[i].name<<" a course: ";
                getline(cin, teacher[i].course);
                
                if (teacher[i].course != course[0].title && teacher[i].course != course[1].title && teacher[i].course != course[2].title && teacher[i].course != course[3].title) {
                    
                    cout<<"There is no such course registred!"<<endl;
                    
                    error = true;
                }
                
            } while (error);
        
    }
    
    sort_alphabetically_teacher(&teacher[number_of_teacher].name);
    
    writing_registered_teachers(&teacher[number_of_teacher].name, &teacher[number_of_teacher].course);
    
    for (int i = 0; i < number_of_teacher; i++) {
        teacher[i].login[i] = i;
    }
    
    return teacher[number_of_teacher].name;
    
}
