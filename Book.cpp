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


Book::Book(const char* name, const char* author, int ISBN) {
	this->name = name;
	this->author = author;
	this->ISBN = ISBN;
}

const char* Book::getName() {
	return name;
}

const char* Book::getAuthor() {
	return author;
}

int Book::getISBN() {
	return ISBN;
}