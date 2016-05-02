//main.cpp
//Laurin Fisher
//Software Construction: Assignment 4 
//Chain of Responsibility Design Pattern

#include <iostream>
using std::cout; 
using std::endl; 
#include "robot_manager.h"

int main(){
	//Control a Roomba
	vacuum* vac = new vacuum(); 
	move* tires = new move(); 
	controller* cmdCenter = new controller(); 

	//Connect the Roomba parts hierarchy
		//The robot receives commands from the remote
		//in these states, each successor is more capable
	vac->setSuccessor(tires); 
	tires->setSuccessor(cmdCenter); 

	//Turn vacuum on and off
	Action on("vacuum on");
	vac->processRequest(on); 
	cout << "Status: " << vac->status.str() << endl;

	Action off("vacuum off");  
	vac->processRequest(off); 
	cout << "Status: " << vac->status.str() << endl; 

	//Tell the vacuum to move the Roomba to another location
	Action drive("move",1, 8); 
	vac->processRequest(drive); //The tires will handle the request
	cout << "Status: " << vac->status.str() << endl;

	//Make the command go all the way up
	Action cmd("destroy humans"); 
	vac->processRequest(cmd); 
	cout << "Status: " << vac->status.str() << endl; 

	return 0; 
}