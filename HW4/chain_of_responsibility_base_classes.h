//chain_of_responsibility_base_classes.h
//Laurin Fisher
//Software Construction: Assignment 4 
//Chain of Responsibility Design Pattern

#include <iostream>
#include <string>
using std::string; 
#include <sstream>
using std::ostringstream; 

//An action, something the robot is told to do
class Action{
public:
	Action(string c):command_(c){}
	Action(string c, int x, int y):command_(c),x_coord_(x),y_coord_(y){}

	string command_; 
	int x_coord_; 
	int y_coord_; 
}; 

//The base class for the chain of responsibility design pattern
class PerformAction{
public:
	void setSuccessor(PerformAction* successor){
		successor_ = successor;
	}

	virtual void processRequest(Action request) = 0; 

	virtual ~PerformAction(){}; 

	//status of the robot for viewing purposes
	ostringstream status; 

protected:
	PerformAction* successor_; 
}; 