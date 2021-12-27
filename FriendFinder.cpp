/*****************************************                                                                                                                                                                                                                                                                                                       
** File:    Proj2.cpp                                                                                                                                                                                                                                                                                                                            
** Project: CMSC 202 Project 2, Fall 2021                                                                                                                                                                                                                                                                                                        
** Author:  Malcolm Gilbert                                                                                                                                                                                                                                                                                                                      
** Date:    10/12/21                                                                                                                                                                                                                                                                                                                             
** Section: 14                                                                                                                                                                                                                                                                                                                                   
** E-mail:  malcolm7@gl.umbc.edu                                                                                                                                                                                                                                                                                                                 
**                                                                                                                                                                                                                                                                                                                                               
** This file contains the friendFinder.cpp file for Project 2.                                                                                                                                                                                                                                                                                   
*/

#include "Organization.h"
#include "FriendFinder.h"
#include "Person.h"

// FriendFinder constructor                                                                                                                                                                                                                                                                                                                      
// Default constructor for application for finding friends                                                                                                                                                                                                                                                                                       
FriendFinder::FriendFinder(){
  // Creates a Person and an organization                                                                                                                                                                                                                                                                                                        
  Person m_me;
  Organization m_organization;

  //Welcomes user and calls Start()                                                                                                                                                                                                                                                                                                              
  cout << "*****************************" << endl;
  cout << "Welcome to UMBC Friend Finder" << endl;
  cout << "*****************************" << endl;
  Start();
}

//GetDetails                                                                                                                                                                                                                                                                                                                                     
//Asks user for their first name, last name, age, and ID to populate m_me                                                                                                                                                                                                                                                                        
void FriendFinder::GetDetails(){
  string myfName, mylName, myOrg;
  int myAge, myID;
  cout << "What is your first name?" << endl;
  cin >> myfName;
  cout << "What is your last name?" << endl;
  cin >> mylName;
  cout << "What is your age?" << endl;
  cin >> myAge;
  cout << "What is your ID?" << endl;
  cin >> myID;
  m_me.SetDetails(myfName, mylName, myAge, myID);
  cout << "You are " <<  myfName << " " << mylName << " " << myOrg << " " << myAge << " " <<  myID << endl;
  cout << "40 people loaded into the roster" << endl;
}

//DisplayMenu                                                                                                                                                                                                                                                                                                                                    
//Dispays Main menu for application                                                                                                                                                                                                                                                                                                              
void FriendFinder::DisplayMenu(int &userInput){
  cout << "What would you like to do?" << endl;
  cout << "1. Display Entire Organization" << endl;
  cout << "2. Display Friend List" << endl;
  cout << "3. Search for a friend" << endl;
  cout << "4. Remove Friend" << endl;
  cout << "5. Exit" << endl;
  cin >> userInput;
}

//Start                                                                                                                                                                                                                                                                                                                                          
//Main function running FriendFinder                                                                                                                                                                                                                                                                                                             
void FriendFinder::Start(){
  int userInput;
  GetDetails();
  m_organization.LoadRoster();
  do{
    DisplayMenu(userInput);
    if(userInput == 1){
      m_organization.DisplayRoster();
    }
    if(userInput == 2){
      m_me.DisplayFriends();
    }

    if(userInput == 3){
      m_organization.DisplayRoster();
      cout << "Who would you like to friend?" << endl;
      m_me.AddFriend(m_organization.GetPerson());
    }

    if(userInput == 4){
      m_me.RemoveFriend();
    }

  }while(userInput != 5);


  cout << "Thanks for using UMBC's Friend Finder!" << endl;
}



