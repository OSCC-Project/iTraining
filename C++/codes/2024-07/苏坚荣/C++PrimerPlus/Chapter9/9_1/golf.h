#pragma once
#include<iostream>


const int Len = 40;
struct Golf {
	char _fullname[Len];
	int _handicap;
};

// non-interactive version:
// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
void setGolf(Golf& g, const char* name, int hc);

// interactive version:
// function solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
int setGolf(Golf& g);

// function resets handicap to new value
void handicap(Golf& g, int hc);

// function displays contents of golf structure
void showGolf(const Golf& g);
