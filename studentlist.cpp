#include <iostream>
#include <cstring>

using namespace std;

const int MAX_NAMELEN = 41;
const int MAX_STUDENTS = 51;

typedef struct student_s {
  char firstname[MAX_NAMELEN];
  char lastname[MAX_NAMELEN];
  int id;
  float gpa;
} student_t;

static student_t student[MAX_STUDENTS];

static void student_add(student_t *new_student){
    int pos = 0;
    while((pos < MAX_STUDENTS) && (student[pos].id != 0)) pos++;
    if(pos >= MAX_STUDENTS){
        cout <<"student entries are full right now." << endl;
    }
    else{
        student[pos] = *new_student;
        cout<< "enrty had been successfully entered"<<endl;
    }
}

static void student_print(void){
    int pos = 0;
    
    for (pos = 0; pos < MAX_STUDENTS; pos++){
        if (student[pos].id > 0){
            cout << student[pos].firstname << ", ";
            cout << student[pos].lastname << ", ";
            cout << student[pos].id << ", ";
            cout << (int)student[pos].gpa << ".";
            cout << (int)((student[pos].gpa - (int)student[pos].gpa) * 100 + 0.9)<< endl;
            }
    }
}

static void student_del(int id){
    int pos = 0;
    while ((pos<MAX_STUDENTS) && (student[pos].id != id)) pos++; 
        if (pos >= MAX_STUDENTS){
            cout << "No student witht the id was found." << endl;
        }
        else{
            student[pos].id = 0;
            cout << "entry had been successfully deleted" << endl;
        }
    
}

int main(){
    student_t data;
    char input[10];
    
    for (int i=0; i<MAX_STUDENTS; i++){
        student[i]. firstname[0] = '\0';
        student[i]. lastname[0] = '\0';
        student[i]. id = 0;
        student[i]. gpa = 0.0;
    }
    
    do {
        cout << "ADD/PRINT/DELETE/QUIT: " << endl;
        cin.get(input,10);
        cin.get();
 
        if ((input[0] == 'A') || (input[0] == 'a')){
            cout << "First name:" << endl;
            cin.get(data.firstname, 10);
            cin.get();
            
            cout << "Last name:" << endl;
            cin.get(data.lastname, 10);
            cin.get();
            
            cout << "ID:" << endl;
            cin >> data.id;
            cin.get();
            
            cout << "GPA:" << endl;
            cin >> data.gpa;
            cin.get();
            
            student_add(&data);
        }
        
        if ((input[0] == 'P') || (input[0] == 'p')){
            student_print();
        }
        
        if((input[0] == 'D') || (input[0] == 'd')){
            cout << "Enter student id: " << endl;
            cin >> data.id;
            cin.get();
            student_del(data.id);
        }
        
    } while ((input[0] != 'Q') && (input[0] != 'q'));
}
