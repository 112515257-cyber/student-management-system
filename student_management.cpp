#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class student{
    public :
    int roll;
    string name;
    int age;
    string course;
};

void addstudent(){
    student s;
    ofstream file("students.txt", ios::app);

    cout<<"enter roll no:";
    cin>>s.roll;
    cin.ignore();
    cout<<"enter course :";
    getline(cin,s.course);

    file<<s.roll<<"|"<<s.name<<"|"<<s.age<<"|"<<s.course<<endl;

    cout<<"student added succesfully";
}

void displaystudent(){
    ifstream file("student.txt");
    string line;

    cout<<"student records";

    while(getline(file,line)){
        cout<<line<<endl;
    }

    file.close();
}


void searchstudent(){
    int rollno;
    cout<<"enter rollno to search :";
    cin>>rollno;

    ifstream file("student.txt");
    string line;
    bool found = false;

    while(getline(file,line)){
        int roll  =  stoi(line.substr(0,line.find("|")));


        if(roll==rollno){
            cout<<"record found";
            cout<<line<<endl;
            found = true;
            break;
        }
    }

    if(!found){
        cout<<"student not found";

        file.close();
    }
}

void deletestudent(){
    int rollno;
    cout<<"enter rollno to delete:";
    cin>>rollno;

    ifstream file("student.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;
    while(getline(file,line)){
        int roll = stoi(line.substr(0,line.find("|")));

        if(roll != rollno){
            temp<<line<<endl;

        }
        else{
            found  = true;
        }
    }
    file.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt","student.txt");

    if(found){
        cout<<"student deleted successfully";
    }
    else{
    cout<<"student not found";
    }

}

int main(){
    int choice;

    do{
        cout<<"student management system";
        cout<<"1. add student\n";
        cout<<"2. display student\n";
        cout<<"3.search student\n";
        cout<<"4.delete student";
        cout<<"5.exit\n";
        cout<<"enter choice :";
        cin>>choice;

        switch(choice){
            case 1 : addstudent();
            break;

            case 2 : 
            displaystudent();
            break;

            case 3 : 
            searchstudent();
            break;

            case 4: 
            deletestudent();
            break;

            case 5:
            cout<<"exiting";
            break;

            default : 
            cout<<"invalid choice";
        }
    }
    while(choice!=5);

    return 0;
}