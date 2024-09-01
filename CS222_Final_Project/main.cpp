//
//  main.cpp
//  CS222_Final_Project
//
//  Created by Assier Anteneh Alemu on 28/04/2022.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "/Users/triplea/Documents/HiLCoE/C++/CS222_Final_Project/admin_login.cpp"
#include "/Users/triplea/Documents/HiLCoE/C++/CS222_Final_Project/teacher_login_page.cpp"
#include "/Users/triplea/Documents/HiLCoE/c++/CS222_Final_Project/student_login_page.cpp"

using namespace std;



int main (){
    
    int login;
    
    bool error = false;
    
    string admin_username = "Admin", admin_password = "Admin", admin_username_login, admin_password_login;
    
    cout<<"Welcome to HiLCoE's Student Information Managment System!"<<endl<<endl;
    
    do {
        do {
            
            error = false;
            
            cout<<"1. Login as an Admin"<<endl;
            cout<<"2. Login as a Teacher"<<endl;
            cout<<"3. Login as a Student"<<endl;
            cout<<"4. Exit"<<endl;
            
            cin>>login;
            
            if (!(cin) || login < 1 || login > 4) {
                
                cout<<"Error - Invalid Input!"<<endl<<endl;
                
                error = true;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            
        } while (error);
        
        switch (login) {
                
            case 1:
                
                    admin_login_page();
                
                
                break;

            case 2:
                
                if (teacher_registered == true) {
                    
                    teacher_login_page();
                    
                } else{
                    
                    cout<<"Error - There are no teachers registred!"<<endl;
                    
                }
                
                break;
                
            case 3:
                
                if (student_registered == true) {
                    
                    student_login_page();
                    
                } else {
                    
                    cout<<"Error - There are no students registered!"<<endl;
                    
                }
                
                break;
          
        }
        
    } while (login != 4);
}
