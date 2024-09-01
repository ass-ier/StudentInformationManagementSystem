//
//  teacher_login_page.cpp
//  CS222_Final_Project
//
//  Created by Assier Anteneh Alemu on 28/04/2022.
//

#include "teacher_login_page.hpp"
#include <fstream>

using namespace std;

fstream notice;

extern bool all_teacher_submitted_mark = false;

extern int inum = 0, teacher_login_times = 0, j = 0;

void writing_notice (string teacher_notice, string teacher_name){
    
    notice.open("Notice.txt", ios::in | ios::out | ios::trunc);
    
    if (notice.is_open()) {
        
        notice<<teacher_name<<" posted a notice: "<<endl;
        notice<<teacher_notice<<endl;
        
        cout<<"File written successfully!"<<endl;
        
        notice.close();
        
    } else {
        
        cout<<"Error - File couldn't be opened!"<<endl;
        
    }
}



void teacher_login_page (){

    
    char ans;
    
    int operation, update_id = 0, idnum2 = 0;
    
    string teacher_username_login, teacher_password_login, teacher_password_confirm, student_name, teacher_notice[number_of_teacher];
    
    bool teacher_login = false, teacher_username_match = false, teacher_password_match = false, teacher_password_change = false, error = false;
    
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    
    do {
        
        cout<<"Enter your username: ";
        getline(cin, teacher_username_login);
        
        inum = 0; teacher_username_match = false;
        
        for (int i = 0; i < number_of_teacher; i++, inum++) {
           
            if (teacher_username_login == teacher[i].username) {
                 
                teacher_username_match = true;
                
                break;
                
            } else {
                
            }
        }
        
        cout<<"Enter you password: ";
        getline(cin, teacher_password_login);
            
            if (teacher_password_login == teacher[inum].password) {
                
                teacher_password_match = true;
            }
        
        if (teacher_username_match == true && teacher_password_match == true) {
            
            cout<<"Login Successful"<<endl;
            
            teacher_login = true;
            
            teacher[inum].login_times++;
            
        } else{
            cout<<"Error - Invalid username or password!"<<endl;
            
            teacher_login = false;
        }
        
    } while (!teacher_login);
    
    if (teacher[inum].login_times > 1) {
        
        goto teacher_start_1;
        
    }
    
    do {
        cout<<"Enter new passwrod: ";
        getline(cin, teacher[inum].password);
        
        cout<<"Confirm password: ";
        getline(cin, teacher_password_confirm);
        
        if (teacher[inum].password == teacher_password_confirm) {
            
            cout<<"Password changed successfully"<<endl;
            
            teacher_password_change = true;
            
        }
        else{
            cout<<"Error - Passowrd doesn't match!"<<endl;
            teacher_password_change = false;
        }
        
    } while (!teacher_password_change);
    
    teacher_start_1:
    
    cout<<"Welcome to your page "<<teacher[inum].name<<"!"<<endl;
    
    teacher_start:
    
    do {
        
        error = false;
        
        cout<<"1. Post notice for students"<<endl;
        cout<<"2. Enter Mark for students"<<endl;
        cout<<"3. Update Mark for students"<<endl;
        cout<<"4. Go Back"<<endl;
        
        cin>>operation;
        
        if (!(cin) || operation < 1 || operation > 4) {
            
            cout<<"Error - Invalid operation!"<<endl;
            
            error = true;
            
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            
        }
        
    } while (error);
    
    switch (operation) {
            
        case 1:
            
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            
            cout<<"Post your notice here: "<<endl;
            getline(cin, teacher[inum].notice);
            
            teacher[inum].notice_posted = true;
            
            writing_notice(teacher[inum].notice, teacher[inum].name);
            
            goto teacher_start;
          
        case 2:
            
            //Accepts exam result for each students
            if (student_registered == true) {
                
                
                cout<<"Enter "<<teacher[inum].course<<" mark for students"<<endl;
                
                for (int i = 0; i < number_of_student; i++) {
                    
                        do {
                            
                            if (inum == 1) {
                                j = 1;
                            } else if (inum == 2) {
                                j = 2;
                            } else if (inum == 3) {
                                j = 3;
                            } else if (inum == 4) {
                                j = 4;
                            }
                            
                            error = false;
                            
                            cout<<"Enter mark for "<<student[i].name<<": ";
                            cin>>student[i].mark[j];
                            
                            if (student[i].mark[j] < 0 || student[i].mark[j] > 100) {
                                
                                cout<<"Error - Invalid Mark amount!"<<endl;
                                
                                error = true;
                                
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                
                            }
                            
                        } while (error);
                        
                }

                teacher[inum].mark_submitted = true;
                
            } else{
                
                cout<<"Error - There are no registered students!"<<endl;
                
            }
            
            goto teacher_start;
            
        case 3:
            
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            
            cout<<"Enter the name of the student you want to update the mark of: ";
            getline(cin, student_name);
            
            for (int i = 0, update_id = 0, idnum2 = 0; i < number_of_student; i++, update_id++, idnum2++) {
                
                if (student_name == student[i].name) {
                    
                    cout<<"You are trying to update the mark of "<<student[i].name<<endl;
                    
                    break;
                }
            }
            
            cout<<"Are you sure you want to continue? (Y/N)"<<endl;
            cin>>ans;
            
            if (ans == 'y' || ans == 'Y') {
                do {
                    
                    error = false;
                    
                    cout<<"Enter the new mark for "<<student[update_id].name<<" "<<teacher[inum].course<<endl;
                    cin>>student[idnum2].mark[j];
                    
                    if (student[idnum2].mark[j] < float(0) || student[idnum2].mark[j] > float(100.0)) {
                        
                        cout<<"Error - Invalid Mark amount!"<<endl;
                        
                        error = true;
                        
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    
                } while (error);
                
                teacher[inum].mark_submitted = true;
                
            } else {
                
                goto teacher_start;
                
            }
            
            goto teacher_start;
            
        case 4:
            
            break;
    }
    
    
}
