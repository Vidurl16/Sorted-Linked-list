/*
    Question 2
    Author: Vidur Lutchminarain
    student Number: 401914025

    Description: A list consists of many nodes, each node consisting of two parts: A link and data.


*/
#include <iostream>

using namespace std;

struct Person
{
    int age;
    string name;
    string surname;
    char gender;
    Person *next;
    Person* prev;
};


bool isEmpty(Person *head);
char menu();
void insertAsFirst(Person *&head, Person *&last, int age, string name, string surname, char gender);
void insert(Person *&head, Person *&last, int age, string name, string surname, char gender);
void remove(Person *&head, Person *&last, int age);
void printList();



bool isEmpty(Person *head)
{
    if(head == NULL)
        {
            return true;
        }else
        {
            return false;
        }

}

char menu()
{
    char choice;
    cout<<"Menu"<<endl;
    cout<<"1. Add item"<<endl;
    cout<<"2. Remove item"<<endl;
    cout<<"3. Print list"<<endl;
    cout<<"4. Exit"<<endl;

    cin>> choice;
    return choice;
}

void insertAsFirst(Person *&head, Person *&last, int age, string name, string surname, char gender)
{
    Person *temp = new Person;
    temp ->age = age;
    temp -> surname = surname;
    temp -> name = name;
    temp -> gender = gender;
    temp->next = NULL;
    head = temp;
    last = temp;
}

void insert(Person *&head, Person *&last, int age, string name, string surname, char gender)
{

    if(isEmpty(head))
        {
            insertAsFirst(head, last, age, name, surname, gender);
        }else
        {


        Person *temp = new Person;

         temp ->age = age;

         temp -> surname = surname;
         temp -> name = name;
         temp -> gender = gender;

        if (age <= head->age) {
    temp->next = head;
    head = temp;
    return;
}
Person *curr = head;
// Find insertion point
while (curr->next != nullptr && age > curr->next->age) {
    curr = curr->next;
}
// Insert new node after curr
temp->next = curr->next;
curr->next = temp;
if (temp->next == NULL) {
    last = temp;
}
            }
}

void remove(Person *&head, Person *&last, int age, string name, string surname, char gender)
{
    if(isEmpty(head))
        {
            cout<<"The list is empty"<<endl;
        }else if(head == last)
        {
            delete head;
            head == NULL;
            last = NULL;
        }else
        {
            Person *temp = head;
            head = head->next;
            delete temp;
        }
}

void printList(Person *current)
{
    if(isEmpty(current))
        {
            cout<<"The list is empty"<<endl;
        }else
        {
            cout<<"The list contains"<<endl;
            while(current !=NULL)
                {
                  //  cout<<current->age <<" " current->name <<" "<< current->surname<<endl;

                  cout<<"Name: "<<current->name<<endl;
                  cout<<"Surname: "<<current->surname<<endl;
                  cout<<"Age: "<<current-> age<<endl;
                  cout<<"Gender:"<<current->gender<<endl;

                  current = current->next;
                  cout<<endl;
                }
        }

}

int main()
{
    Person *head = NULL;
    Person *last = NULL;
    char choice;
    char gender;
    int age;
    string name;
    string surname;

    do{
        choice = menu();

    switch(choice){
         case '1':
        cout<<"Please enter your first name: ";
        cin>> name;
        cout<<endl;
        cout<<"please enter your last name: ";
        cin>>surname;
        cout<<"please enter your age: ";
        cin>>age;
        cout<<"Please enter 'M' or 'F' for your gender: ";
        cin>> gender;

        insert(head, last, age, name, surname, gender);

        break;

         case '2':
        remove(head, last, age, name, surname, gender);
        break;

         case '3':
            printList(head);
            break;
        default: cout<<"system exit"<<endl;
    }



    }while(choice != '4');
    return 0;
}
