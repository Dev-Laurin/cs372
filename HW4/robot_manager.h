//robot_manager.h
//Laurin Fisher
//Software Construction: Assignment 4 
//Chain of Responsibility Design Pattern

#ifndef _ROBOT_MANAGER_H_INCLUDED_
#define _ROBOT_MANAGER_H_INCLUDED_


#include "chain_of_responsibility_base_classes.h"


class vacuum : public PerformAction{
public:
	void processRequest(Action request);
}; 


class move : public PerformAction{
public:
	void processRequest(Action request);
}; 


class controller : public PerformAction{
public:
	void processRequest(Action request); 
}; 





#endif /* _ROBOT_MANAGER_H_INCLUDED_ */ 