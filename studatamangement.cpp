#include <iostream>
#include<string>
using namespace std;

class student{
    public:
    string name;
    int roll;
    float cgpa;
    student *next;
    student(string name ,int roll,float cgpa){
        this->name=name;
        this->roll=roll;
        this->cgpa=cgpa;
        next =nullptr;
    }

};

class studentlist{
    private:
    student *head;
    public:
    
    studentlist(){
        head=nullptr;
    }
    void addstudent(){
        string name;
        int roll;
        float cgpa;
        cout<<" enter name:  "<<endl;
        cin>>name;
        cout<<" enter roll number : "<<endl;
        cin>>roll;
        cout<<" enter CGPA : "<<endl;
        cin>>cgpa;
        student * newnode=new student(name,roll,cgpa);
        if(head==nullptr){
            head=newnode;
        }
        else{
            student *temp=head;
            while(temp->next!=nullptr){
                
                temp=temp->next;
                
            }
            temp->next=newnode;
            
        }
        cout<<" student data added successfully !\n";
    }

    void displaydata(){
        cout<<"\n------student details-------\n";
        
        if (head==nullptr){
            cout<<"No student records found.\n";
            return ;
        }
        student* temp=head;
        int i=1;
        
            while(temp!=nullptr){
                cout<<"\n student "<<i++<<" : \n";
                cout<<"NAME: "<<temp->name<<endl;
                cout<<"roll number  : "<<temp->roll<<endl;
                cout<<"CGPA: "<<temp->cgpa<<endl;
                temp=temp->next;
            }

        
    }

    void search_data(){
        if(head==nullptr){
            cout<<" no record found .\n ";
            return;
        } 
        int key;
        cout<<" enter roll number to search: "<<endl;
        cin>>key;

        student *temp=head;
        while(temp!=nullptr){
            if(temp->roll==key){
                cout<<"\n student found\n";
                 cout<<"NAME: "<<temp->name<<endl;
                cout<<"roll number  : "<<temp->roll<<endl;
                cout<<"CGPA: "<<temp->cgpa<<endl;
                return ;
            }
             temp=temp->next;
        }
        cout<<"student with roll number "<<key<< " is not found./n";

    }
     ~studentlist(){
            student *current=head;
            while(current!=nullptr){
                student *newnode=current->next;
                delete current;
                current=newnode;
            }
        }



};

int main(){
    studentlist list;
    int  choice;
    cout<<"-----STUDENT DATA MANGEMENT----- \n";
    cout<<"I. Add student \n";
    cout<<"II. Dispaly All Data\n";
    cout<<"III. search data of any student using roll number\n";
    cout<<"IV. Exit\n";
      
    do{
        cout<<"Enter your choice: \n";
        cin>>choice;
        switch(choice){
        case 1:
        list.addstudent();
        break;
        case 2:
        list.displaydata();
        break;
        case 3:
        list.search_data();
        break;
        case 4:
        cout<<"---exiting---\n";
        break;
        default:
        cout<<" Invalid choice !\n enter the valid choice.\n";
        break;
    }
       
    }while(choice!=4);

  
    return 0;
}
