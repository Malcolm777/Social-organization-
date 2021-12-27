/*****************************************                                                                                                                                                                                                                                                                                                                             
** File:    Proj2.cpp                                                                                                                                                                                                                                                                                                                                                  
** Project: CMSC 202 Project 2, Fall 2021                                                                                                                                                                                                                                                                                                                              
** Author:  Malcolm Gilbert                                                                                                                                                                                                                                                                                                                                            
** Date:    10/12/21                                                                                                                                                                                                                                                                                                                                                   
** Section: 14                                                                                                                                                                                                                                                                                                                                                         
** E-mail:  malcolm7@gl.umbc.edu                                                                                                                                                                                                                                                                                                                                       
**                                                                                                                                                                                                                                                                                                                                                                     
** This file contains the Organization.cpp file for project 2..                                                                                                                                                                                                                                                                                                        
*/

#include "Organization.h"
#include "Person.h"

//default constructor                                                                                                                                                                                                                                                                                                                                                  
Organization::Organization(){
}

//SetName                                                                                                                                                                                                                                                                                                                                                              
//Sets m_fileName by asking user. Then populates all of the people loaded from file                                                                                                                                                                                                                                                                                    
void Organization::SetName(){
  cout << "What is the name of your organization?" << endl;
  cin >> m_name;
}


//LoadRoster                                                                                                                                                                                                                                                                                                                                                           
//Creates a Person object first then assign that index with that object you created                                                                                                                                                                                                                                                                                    
void Organization::LoadRoster(){
  Person person;
  //Person person[4];                                                                                                                                                                                                                                                                                                                                                  
  fstream m_fileName;
  string myString, myString2, myString3, myString4;

  m_fileName.open(FILE_NAME);
  if(m_fileName.is_open()){
    int i = 0;
    while(getline(m_fileName, myString, ',') && getline(m_fileName, myString2, ',') && getline(m_fileName, myString3, ',') && getline(m_fileName, myString4, '\n')){

      person.SetDetails(myString, myString2, stoi(myString3), stoi(myString4));
      m_roster[i] = person;
      i++;

    }
  }
  m_fileName.close();
}


//DisplayRoster                                                                                                                                                                                                                                                                                                                                                        
//Displays a numbered list of everyone in the roster (starts at 1)                                                                                                                                                                                                                                                                                                     
void Organization::DisplayRoster(){
  Person person;
  cout << "****UMBC****" << endl;

  for(int i = 0; i < MAX_PEOPLE; i++){
    cout << i+1 << ". ";
    m_roster[i].DisplayDetails();
  }
}

//GetPerson                                                                                                                                                                                                                                                                                                                                                            
//Displays a list of people in m_roster and user enters number of desired person                                                                                                                                                                                                                                                                                       
Person* Organization::GetPerson(){
  int desired;
  cin >> desired;
  return &m_roster[desired-1];
}


