//
//  admin_login.cpp
//  CS222_Final_Project
//
//  Created by Assier Anteneh Alemu on 28/04/2022.
//

#include "admin_login.hpp"
#include "/Users/triplea/Documents/HiLCoE/C++/CS222_Final_Project/teacher_registration_page.cpp"
#include "/Users/triplea/Documents/HiLCoE/C++/CS222_Final_Project/student_registration_page.cpp"

#include <string>

extern string admin_username = "Admin", admin_password = "Admin";
extern int login_times = 0;
extern bool teacher_registered = false;
extern bool student_registered = false;

using namespace std;

string teacher_username[MAX_TEACHER], teacher_password[MAX_TEACHER], student_username[MAX_STUDENT], student_password[MAX_STUDENT];

void admin_login_page(){
    
    int registration_choice;
    
    bool error = false, admin_login = false, admin_password_change = false;
    
    string admin_username_login, admin_password_login, admin_password_confirm;
    
    char ans;
    
    
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    
    if (admin_login == false) {
        
            do {
                admin_login = false;
                
                cout<<"Please enter username: ";
                getline(cin, admin_username_login);
                cout<<"Please enter password: ";
                getline(cin, admin_password_login);
                
                if (admin_username == admin_username_login && admin_password == admin_password_login) {
                    
                    cout<<"Login Successful!"<<endl;
                    admin_login = true;
                    login_times++;
                    
                }
                else{
                    
                    cout<<"Error - Invalid uername or password!"<<endl;
                    admin_login = false;
                    
                    
                }
            } while (!admin_login);
            
        if (login_times > 1) {
            
            goto admin_start_1;
            
        }
        
        
        do {
            
            cout<<"Please enter new password: ";
            getline(cin, admin_password);
            
            cout<<"Pleas confirm you password: ";
            getline(cin, admin_password_confirm);
            
            if (admin_password == admin_password_confirm) {
                
                cout<<"Password changed successfully!"<<endl;
                admin_password_change = true;
                
                admin_login = true;
            }
            else{
                
                cout<<"Error - Password doesn't macth!"<<endl;
                
                admin_password_change = false;
                
            }
        } while (!admin_password_change);
    }
    
    
    admin_start_1:
    
    cout<<"Welcome to Admin Page!"<<endl<<endl;
    
    admin_start:
    
    do {
        error = false;
        cout<<"1. Register Teacher"<<endl;
        cout<<"2. Register Student"<<endl;
        cout<<"3. Add courses"<<endl;
        cout<<"4. Go Back"<<endl;
        
        cin>>registration_choice;
        
        if (!(cin) || registration_choice < 1 || registration_choice > 4) {
            
            cout<<"Error - Invalid Input"<<endl;
            
            error = true;
            
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            
        }
        
    } while (error);
    
    switch (registration_choice) {
            
        case 1:

            if (course_created == true) {
                
                if (teacher_registered == false) {
                   
                    overwrite_teacher:
                    
                    number_of_teacher = 0;
                    
                    teacher_registered = true;
                    
                    teacher_registration_page();
                    
                    for (int i = 0; i < number_of_teacher; i++) {
                        
                        teacher[i].username = teacher[i].name;
                        
                    }
                    
                    for (int i = 0; i < number_of_teacher; i++) {
                        
                        teacher[i].password = teacher[i].name + "P@$$";
                        
                    }
                    
                } else {
                    
                    cout<<"Are you sure you want to overwrite registered teachers?! (Y/N)"<<endl;
                    cin>>ans;
                    
                    if (ans == 'y' || ans == 'Y') {
                        
                        goto overwrite_teacher;
                        
                    } else {
                        
                        goto admin_start;
                    }
                }

            } else {
                
                cout<<"You have to add the courses before registering teachers!"<<endl;
                
            }
            goto admin_start;
            
        case 2:
            
            if (student_registered == false) {
               
                overwrite_student:
                
                number_of_student = 0;
                
                student_registered = true;
                
                student_registration_page();
                
                for (int i = 0; i < number_of_student; i++) {
                    
                    student[i].username = student[i].name;
                    
                }
                
                for (int i = 0; i < number_of_student; i++) {
                    
                    student[i].password = student[i].name + "P@$$";
                    
                }
                
            } else {
                
                cout<<"Are you sure you want to overwrite registered students? (Y/N)"<<endl;
                cin>>ans;
                
                if (ans == 'y' || ans == 'Y') {
                    
                    goto overwrite_student;
                    
                } else {
                    
                    goto admin_start;
                }
            }
            
            goto admin_start;
            
        case 3:
            
            if (course_created == false) {
                
                overwrite_courses:
                
                course_add_page();
                
                course_created = true;
                
            } else {
                
                cout<<"Are you sure you want to overwrite added courses? (Y/N)"<<endl;
                cin>>ans;
                
                if (ans == 'y' || ans == 'Y') {
                    
                    goto overwrite_courses;
                    
                } else {
                    
                    goto admin_start;
                }
            }
            
            goto admin_start;
            
        case 4:
            
            break;
            
    }
    
    
    
}
