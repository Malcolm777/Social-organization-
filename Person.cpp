/*****************************************                                                                                                                                                                                                                                                                                    
** File:    Proj2.cpp                                                                                                                                                                                                                                                                                                         
** Project: CMSC 202 Project 2, Fall 2021                                                                                                                                                                                                                                                                                     
** Author:  Malcolm Gilbert                                                                                                                                                                                                                                                                                                   
** Date:    10/12/21                                                                                                                                                                                                                                                                                                          
** Section: 14                                                                                                                                                                                                                                                                                                                
** E-mail:  malcolm7@gl.umbc.edu                                                                                                                                                                                                                                                                                              
**                                                                                                                                                                                                                                                                                                                            
** This file contains the person.cpp file  for Project 2.                                                                                                                                                                                                                                                                     
*/

//code simple function such as constructors                                                                                                                                                                                                                                                                                   
#include "Person.h"

//Person default constructor                                                                                                                                                                                                                                                                                                  
Person::Person(){
  SetDetails("Malcolm", "Gilbert", 1, 1);
  //DisplayDetails();                                                                                                                                                                                                                                                                                                         
  //CheckID(1);                                                                                                                                                                                                                                                                                                               
  m_friendCount = 0;
}


//Person overloaded constructor                                                                                                                                                                                                                                                                                               
//Creates a person with passed data                                                                                                                                                                                                                                                                                           
Person::Person(string fName, string lName, int age, int id){
  SetDetails(fName, lName, age, id);
  DisplayDetails();
  CheckID(id);
  m_friendCount = 0;
}

//AddFriend                                                                                                                                                                                                                                                                                                                   
// A person pointer is stored from the roster of people in an organization                                                                                                                                                                                                                                                    
void Person::AddFriend(Person* person){
  if(CheckID(person->m_ID)){
    cout << "You're already friends with this person" << endl;
    return;
  }
  //if not at max and not already in the array                                                                                                                                                                                                                                                                                
  for(int i = 0; i < MAX_FRIENDS; i++){
    if(m_friends[i] == nullptr){
      m_friends[i] = person; //stores person in the array                                                                                                                                                                                                                                                                     
      m_friendCount++;
      cout << "You are now friends with " << person->m_fName << "!" << endl;
      return;
    }
  }
}



//RemoveFriend                                                                                                                                                                                                                                                                                                                
//Removes a person pointer from this person's m_friend array                                                                                                                                                                                                                                                                  
void Person::RemoveFriend(){
  int userInput;
  if(m_friendCount == 0){
    cout << "You don't have any friends to remove" << endl;
  }
  if(m_friendCount > 0){
    cout << "What friend would you like to remove?" << endl;
    DisplayFriends();
    cin >> userInput;
    for(int i = userInput-1; i < m_friendCount; i++){
      m_friends[i] = m_friends[i+1];
    }
    m_friends[m_friendCount-1] = nullptr;
    m_friendCount--;
  }
}
  /*                                                                                                                                                                                                                                                                                                                          
  if(m_friendCount == 0){                                                                                                                                                                                                                                                                                                     
    cout << "You don't have any friends to remove" << endl;                                                                                                                                                                                                                                                                   
    return;                                                                                                                                                                                                                                                                                                                   
  }do{                                                                                                                                                                                                                                                                                                                        
    cout << "What friend would you like to remove?" << endl;                                                                                                                                                                                                                                                                  
    DisplayFriends();                                                                                                                                                                                                                                                                                                         
    cin >> userInput;                                                                                                                                                                                                                                                                                                         
  }while(userInput < 1 && userInput > m_friendCount);                                                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                                                                                              
  for(int i = userInput-1; i < m_friendCount-1; i++){                                                                                                                                                                                                                                                                         
    m_friends[i] = m_friends[i+1];                                                                                                                                                                                                                                                                                            
  }                                                                                                                                                                                                                                                                                                                           
  m_friends[userInput-1] = nullptr;                                                                                                                                                                                                                                                                                           
  m_friendCount--;                                                                                                                                                                                                                                                                                                            
}                                                                                                                                                                                                                                                                                                                             
  */

//CheckID                                                                                                                                                                                                                                                                                                                     
//Checks to see if a specific person ID exists in m_friends                                                                                                                                                                                                                                                                   
bool Person::CheckID(int userID){
  if(m_friendCount > 0){
    for(int  i = 0; i < m_friendCount; i++){
      if(userID == m_friends[i]->m_ID){
        return true;
      }
    }
  }
  return false;
}

//DisplayFriends                                                                                                                                                                                                                                                                                                              
//Displays information about each friend in the m_friend array                                                                                                                                                                                                                                                                
void Person::DisplayFriends(){
  if(m_friendCount == 0){
    cout << "You do not have any friends" << endl;
  }
  cout << "Friend List for " << m_fName << m_lName << endl;

  for(int i = 0; i < m_friendCount; i++){
    if(m_friends[i]!=nullptr){
      cout << i+1 << ". ";
      m_friends[i]->DisplayDetails();
    }
  }
}


//DisplayDetails                                                                                                                                                                                                                                                                                                              
//Displays information about this person                                                                                                                                                                                                                                                                                      
void Person::DisplayDetails(){
  cout << m_fName << " " << m_lName << " " << "(" <<m_age << "yrs" << ")" << " " << \
m_ID << endl;
}


//SetDetails                                                                                                                                                                                                                                                                                                                  
//Used as a setter for first name, last name, age, and id                                                                                                                                                                                                                                                                     
void Person::SetDetails(string fName, string lName, int age, int id){
    m_fName = fName;
    m_lName = lName;
    if(age > 0){
      m_age = age;
    }
    if(id > 0 && id < 10000000){
      m_ID = id;
    }
  }







