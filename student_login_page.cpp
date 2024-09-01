//
//  student_login_page.cpp
//  CS222_Final_Project
//
//  Created by Assier Anteneh Alemu on 01/05/2022.
//

#include "student_login_page.hpp"
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int idnum = 0;

//Function that backup students' grade report to a file
void writing_grade_report (string name, string course[], float mark[], char grade[], float cgpa) {


    student[idnum].report.open("Student_Report", ios::in | ios::out | ios::trunc);
    
    if (student[idnum].report.is_open()) {
        
        student[idnum].report<<setw(25)<<name<<"'s"<<" Grade Report"<<endl;
        
        student[idnum].report<<"=========================================================="<<endl;
        
        student[idnum].report<<left<<setw(45)<<"Course"<<setw(7)<<"Score"<<setw(7)<<"Grade"<<endl;
        
        student[idnum].report<<"=========================================================="<<endl;
        
        for (int i = 0; i < NUMBER_OF_COURSES; i++) {
            
            student[idnum].report<<left<<setw(45)<<course[i]<<setw(7)<<mark[i]<<setw(7)<<grade[i]<<endl;
            
        }
        
        student[idnum].report<<"=========================================================="<<endl;
        
        student[idnum].report<<setw(60)<<right<<"GPA: "<<cgpa<<endl;
        
                
        cout<<"File Written Successfully!"<<endl;

        student[idnum].report.close();
        
    } else {

        cout<<"Error - File couldn't be opened!"<<endl;

    }

}


//Fucntion That calculates GPA of each student
float gpa_calculation (char grade) {
    
    int i;
    
    float gpa = 0;
        
        for (i = 0; i < NUMBER_OF_COURSES; i++) {
            if (grade == 'A') {

                gpa = gpa + (course[i].crdhr * 4);
            }
            if (grade == 'B') {
                
                gpa = gpa + (course[i].crdhr * 3);
            }
            if (grade == 'C') {

                gpa = gpa + (course[i].crdhr * 2);
            }
            if (grade == 'D') {

                gpa = gpa + (course[i].crdhr * 1);
            }
            if (grade == 'F') {

               gpa = gpa + (course[i].crdhr * 0);
            }
        }

    return gpa;
    
}

//Fucntion that calculates grades of each student
char grade_calculation (int mark) {
    
    char grade[NUMBER_OF_COURSES];
    
    int i;
    
        for (i = 0; i < NUMBER_OF_COURSES; i++) {
            if (mark >= 80) {
                grade[i] = 'A';
            } else if (mark >= 70) {
                grade[i] = 'B';
            } else if (mark >= 60) {
                grade[i] = 'C';
            } else if (mark >= 50) {
                grade[i] = 'D';
            } else if (mark < 50) {
                grade[i] = 'F';
            }
            return grade[i];
        }
    
    return grade[NUMBER_OF_COURSES];

}

void student_login_page (){
    
    string student_username_login, student_password_login, student_password_confirm;
    
    int operation;
    
    bool student_username_match = false, student_password_match = false, student_login = false, student_password_change = false, notice_posted = false, mark_submitted = false, gpa_calc = false;
    
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    
    do {
        
        student_login = false; student_username_match = false; student_password_match = false;
        
        cout<<"Enter your username: ";
        getline(cin, student_username_login);
        
        idnum = 0;
        
        
        //Checks if the username exists
        for (int i = 0; i < number_of_student; i++, idnum++) {
            
            if (student_username_login == student[i].username) {
                
                student_username_match = true;
                
                break;
                
            }
        }
        
        cout<<"Enter your password: ";
        getline(cin, student_password_login);
            
            if (student_password_login == student[idnum].password) {
                
                student_password_match = true;
                
            }
        
        if (student_username_match == true && student_password_match == true) {
            
            cout<<"Login Successful!"<<endl;
            
            student_login = true;
            
            student[idnum].login_times++;
            
        } else {
            
            cout<<"Error - Invalid username or password!"<<endl;
            
            student_login = false;
            
        }
        
    } while (!student_login);
    
    if (student[idnum].login_times > 1) {
        
        goto student_start_1;
    
    }
    
    do {
        
        cout<<"Enter new password: ";
        getline(cin, student[idnum].password);
        
        cout<<"Confirm your password: ";
        getline(cin, student_password_confirm);
        
        if (student[idnum].password == student_password_confirm) {
            
            student_password_change = true;
            
        } else {
            
            student_password_change = false;
            
        }
        
    } while (!student_password_change);
    
    
    student_start_1:
    
    cout<<"Welcome to your page "<<student[idnum].name<<"!"<<endl;
    
    student_start:
    
    cout<<"1. Check for notices"<<endl;
    cout<<"2. Check courses mark"<<endl;
    cout<<"3. Check grade"<<endl;
    cout<<"4. Go back"<<endl;
    
    cin>>operation;
    
    switch (operation) {
            
        case 1:
            
            //Checks if the teachers have posted a notice and displays it here!
            for (int i = 0; i < number_of_teacher; i++) {
                
                if (teacher[i].notice_posted == true) {
                    
                    notice_posted = true;
                    
                    cout<<teacher[i].name<<" posted a notice!"<<endl;
                    
                    cout<<"\""<<teacher[i].notice<<"\""<<endl;
                }
                
            }
            
            if (notice_posted == false) {
                
                cout<<"There is no notice posted!"<<endl;
                
            }
            
            goto student_start;
            
        case 2:
            
            mark_submitted = false;
            
            //checks if teachers have submitted exam scores
            for (int i = 0; i < number_of_teacher; i++) {
                
                if (teacher[i].mark_submitted == true) {
                    
                    mark_submitted = true;
                    
                    for (int i = 0; i < NUMBER_OF_COURSES; i++) {
                        
                        cout<<"Score result for "<<course[i].title<<": "<<student[idnum].mark[i]<<endl;
                    }
        
                }
                
            }
            
            // if they didnt submit the score this displays it
            if (mark_submitted == false) {
                
                cout<<"There are no exam scores released yet!"<<endl;
                
            }
            
            goto student_start;
            
        case 3:
            
            
            //checks if all teachers have submitted score
            for (int i = 0; i < number_of_teacher; i++) {
                
                if (teacher[i].mark_submitted == false) {
                    
                    all_teacher_submitted_mark = false;
                    
                    break;
                    
                } else {
                    
                    all_teacher_submitted_mark = true;
                }
            }
            //Grade calculation
            for (int i = 0; i < NUMBER_OF_COURSES; i++) {
                
                student[idnum].grade[i] = grade_calculation(student[idnum].mark[i]);
                
            }
            //GPA calculation
            for (int i = 0; i < NUMBER_OF_COURSES; i++) {
                
                student[idnum].gpa = gpa_calculation(student[idnum].grade[i]);
                
            }
            
            student[idnum].cgpa = student[idnum].gpa / total_crdhr;
            
            
            if (all_teacher_submitted_mark == true) {
                
                gpa_calc = true;
                
            } else {
                
                gpa_calc = false;
                
            }
            
            if (gpa_calc == true) {
                
                cout<<setw(25)<<student[idnum].name<<"'s"<<" Grade Report"<<endl;
                
                cout<<"=========================================================="<<endl;
                
                cout<<left<<setw(45)<<"Course"<<setw(7)<<"Score"<<setw(7)<<"Grade"<<endl;
                
                cout<<"=========================================================="<<endl;
                
                for (int i = 0; i < NUMBER_OF_COURSES; i++) {
                    
                    cout<<left<<setw(45)<<teacher[i].course<<setw(7)<<student[idnum].mark[i]<<setw(7)<<student[idnum].grade[i]<<endl;
                    
                }
                
                cout<<"=========================================================="<<endl;
                
                cout<<setw(60)<<right<<"GPA: "<<student[idnum].cgpa<<endl;
                
                
                
                writing_grade_report(student[idnum].name, &teacher[NUMBER_OF_COURSES].course, &student[idnum].mark[NUMBER_OF_COURSES], &student[idnum].grade[NUMBER_OF_COURSES], student[idnum].cgpa);

            
            } else {
                
                cout<<"Error - All teachers must submit scores for grade calculation!"<<endl;
                
            }
            
            goto student_start;
            
        case 4:
            
            break;
    }
    
    
}
