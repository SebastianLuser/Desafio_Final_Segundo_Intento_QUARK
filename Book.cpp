#include "Book.h"
#include<iostream>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <typeinfo>  
#include <List>
#include <ctime>


Book::Book(string name, string author, int ISBN) {
	this->name = name;
	this->author = author;
	this->ISBN = ISBN;
}

string Book::getName() {
	return this->name;
}

string Book::getAuthor() {
	return this->author;
}

int Book::getISBN() {
	return this->ISBN;
}