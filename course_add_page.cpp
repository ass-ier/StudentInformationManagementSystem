//
//  course_add_page.cpp
//  CS222_Final_Project
//
//  Created by Assier Anteneh Alemu on 28/04/2022.
//

#include "course_add_page.hpp"

#include <string>

using namespace std;

extern int total_crdhr = 0;

extern bool course_created = false;

const int NUMBER_OF_COURSES = 4;

struct courses {
    
    string title;
    
    int crdhr;

} course[NUMBER_OF_COURSES];

void course_add_page () {
    
    bool error = false;
    
    
    cout<<"Please enter title of the courses"<<endl;
    
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    
    for (int i = 0; i < NUMBER_OF_COURSES; i++) {
        
        getline(cin, course[i].title);
        
    }
    
    for (int i = 0; i < NUMBER_OF_COURSES; i++) {
        
        do {
            
            error = false;
            
            cout<<"Enter Credit hour for "<<course[i].title<<": ";
            cin>>course[i].crdhr;
            
            if (!(cin)) {
                cout<<"Error - Invalid input"<<endl;
                
                error = true;
                
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                
            }
            
        } while (error);
    }
    
    for (int i = 0; i < NUMBER_OF_COURSES; i++) {
        total_crdhr += course[i].crdhr;
    }

}
