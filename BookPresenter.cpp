#include "BookPresenter.h"
#include "Copy.h"
#include "Book.h"
#include <List>
#include "IView.h"
#include <iostream>
#include <string> 

BookPresenter::BookPresenter(IView* view) : m_view(view) {
	list<Book*> books;

	///*Libro 1*/
	//string s01 = "Narnia";
	//string s02 = "Juan";
	//int s03 = 1234;
	//setBooks(s01, s02, s03);

	///*Ejemplares del libro 1*/
	//int s04 = 1;
	//string s05 = "A550";
	//bool s06 = true;
	//setCopies(s03, s04, s05, s06);
	//int s07 = 1;
	//string s08 = "B550";
	//bool s09 = true;
	//setCopies(s03, s07, s08, s09);
	//int s10 = 1;
	//string s11 = "C550";
	//bool s12 = true;
	//setCopies(s03, s10, s11, s12);


	///*Libro 2*/
	//string s13 = "The Way of Kings";
	//string s14 = "Pablo";
	//int s15 = 5678;
	//setBooks(s13, s14, s15);

	///*Ejemplares del libro 2*/
	//int s16 = 1;
	//string s17 = "A440";
	//bool s18 = true;
	//setCopies(s15, s16, s17, s18);
	//int s19 = 1;
	//string s20 = "B440";
	//bool s21 = true;
	//setCopies(s15, s19, s20, s21);
}

void BookPresenter::setBooks(string name, string author, int ISBN) {
	try {
		if (getBook(ISBN)) {
			 throw ("Ya existe un Libro con el correspondiente ISBN");
		}
		else {
			this->books.push_back(new Book(name, author, ISBN));
		}
	}
	catch (const char* txtException) {
		m_view->showText(txtException);
	}
}		

void BookPresenter::setCopies(int ISBN, int editionNumber, string location, bool available) {
	try {
		if (getBook(ISBN)) {
			if (getCopy(location) != 0) {
				throw ("Ya existe un Ejemplar con la correspondiente locacion");
			}
			else {
				this->getBook(ISBN)->setCopyList(editionNumber, location, available);
			}
		}
		else {
			throw("No existe un Libro con el correspondiente ISBN");
		}
	}
	catch (const char* txtException) {
		m_view->showText(txtException);
	}

}

Copy* BookPresenter::getCopy(string location) {
	list<Copy*> copiesaux;
	for (Book* book : this->books) {
		copiesaux = book->getCopyList();
		for (Copy* copy : copiesaux) {
			if (copy->getLocation() == location) {
				return copy;
			}
		}
	}
	return 0;
}

Book* BookPresenter::getBook(int ISBN) {
	for (Book* book : this->books) {
		if (book->getISBN() == ISBN) {
			return book;
		}
	}
}

list<Book*>BookPresenter::getBooks() {
	return this->books;
}

bool BookPresenter::checkAvailableCopies(int ISBN) {
	for (Book* book : this->books) {
		if (book->getISBN() == ISBN) {
			if (book->getCopyList().empty()) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}


bool BookPresenter::checkAvailableBooks() {
	if (this->books.empty()) {
		return false;
	}
	else {
		return true;
	}
	
}


void BookPresenter::printBookList() {
	try {
		if (this->checkAvailableBooks() == true) {
			for (Book* book : this->books) {
				string s01 = book->getName();
				string s02 = book->getAuthor();
				string s03 = to_string(book->getISBN());
				m_view->showText("-----------------------------------------------");
				m_view->showText("El libro ingresado tiene los siguientes datos:");
				m_view->showText("	Nombre: " + s01);
				m_view->showText("	Autor: " + s02);
				m_view->showText("	ISBN: " + s03);
				m_view->showText("-----------------------------------------------");
			}
		}
		else {
			throw ("No hay Libros disponibles");
		}
	}
	catch (const char* txtException) {
		m_view->showText(txtException);
	}
}

void BookPresenter::printBook(int x) {
	for (Book* book : this->books) {
		if (book->getISBN() == x) {
			string s01 = book->getName();
			string s02 = book->getAuthor();
			string s03 = to_string(book->getISBN());
			m_view->showText("-----------------------------------------------");
			m_view->showText("El libro ingresado tiene los siguientes datos:");
			m_view->showText("	Nombre: " + s01);
			m_view->showText("	Autor: " + s02);
			m_view->showText("	ISBN: " + s03);
			m_view->showText("-----------------------------------------------");
		}
	}
}

void BookPresenter::printCopyList(int ISBN) {
	try {
		for (Book* book : this->books) {
			if ( this->getBook(ISBN)) {
				if (book->getISBN() == ISBN) {
					if (this->checkAvailableCopies(ISBN) == true) {
						for (Copy* copy : book->getCopyList()) {
							if (copy->getAvailable() == true) {
								string s01 = copy->getName();
								string s02 = copy->getAuthor();
								string s03 = to_string(copy->getISBN());
								string s04 = to_string(copy->getEditionNumber());
								string s05 = copy->getLocation();
								m_view->showText("--------------------------------------------------");
								m_view->showText("El Ejemplar ingresado tiene los siguientes datos:");
								m_view->showText("	Nombre: " + s01);
								m_view->showText("	Autor: " + s02);
								m_view->showText("	ISBN: " + s03);
								m_view->showText("	Numero de Edicion: " + s04);
								m_view->showText("	Locacion: " + s05);
								m_view->showText("--------------------------------------------------");
							}
						}
					}
					else {
						throw ("No hay ejemplares disponibles del libro seleccionado");
					}
				}
			}
			else {
				throw ("No se encontro el libro con el correspondiente ISBN");
			}
		}
	}
	catch (const char* txtException) {
		m_view->showText(txtException);
	}
}

void BookPresenter::printCopy(int ISBN, string location) {
	try {
		for (Book* book : this->books) {
			if (book->getISBN() == ISBN) {
				for (Copy* copy : book->getCopyList()) {
					if (copy->getLocation() == location) {
						string s01 = copy->getName();
						string s02 = copy->getAuthor();
						string s03 = to_string(copy->getISBN());
						string s04 = to_string(copy->getEditionNumber());
						string s05 = copy->getLocation();
						m_view->showText("-------------------------------------------------");
						m_view->showText("El Ejemplar ingresado tiene los siguientes datos:");
						m_view->showText("	Nombre: " + s01);
						m_view->showText("	Autor: " + s02);
						m_view->showText("	ISBN: " + s03);
						m_view->showText("	Numero de Edicion: " + s04);
						m_view->showText("	Locacion: " + s05);
					}
					else {
						throw ("Este ejemplar no esta disponible");
					}
				}
			}
		}
	}
	catch (const char* txtException) {
		m_view->showText(txtException);
	}
}
