//robot_manager.cpp
//Laurin Fisher
//Software Construction: Assignment 4 
//Chain of Responsibility Design Pattern

#include "robot_manager.h"
#include <iostream>
using std::cout; 
using std::endl; 

void controller::processRequest(Action request){
	//clear ostringstream of previous statuses
	status.str("");  

	if(request.command_ == "shut down"){
		status << "Powering Off." << endl; 
	}
	else if(request.command_ ==  "power on"){
		status << "Powering on. Ready." << endl;
	}
	else if(request.command_ == "clean"){
		status << "Beginning cleaning mode." << endl; 
	}
	else if(request.command_ == "destroy humans"){
		status << "I cannot hurt a human!" << endl; 
		status << "Well, maybe if I run into their foot.." << endl;
		status << "NO! The laws of Robotics!" << endl; 
	}
	else{
		status << "The command is unknown." << endl; 
	}
}

void move::processRequest(Action request){
	//clear ostringstream of previous statuses
	status.str("");  

	if(request.command_ == "move"){
		status << "moving up : " << request.x_coord_; 
		status << " , " << request.y_coord_ << endl; 
	}
	else if(request.command_ ==  "charge"){
		status << "returning to charging station" << endl;
	}
	else if(request.command_ == "stop"){
		status << "halting" << endl; 
	}
	else{
		successor_->processRequest(request); 
		status << successor_->status.str(); 
	}
}

void vacuum::processRequest(Action request){
	//clear ostringstream of previous statuses
	status.str(""); 

	if(request.command_ == "vacuum on"){
		status << "vacuuming" << endl;  
	}
	else if(request.command_ == "vacuum off"){
		status << "vacuum off" << endl; 
	} 
	//statement is not related to vacuuming, 
		//move up the chain
	else{ 
		successor_->processRequest(request);
		status << successor_->status.str(); 
	}
}
