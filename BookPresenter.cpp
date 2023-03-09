#include "BookPresenter.h"
#include "Copy.h"
#include "Book.h"
#include <List>
#include "IView.h"
#include <iostream>
#include <string> 

BookPresenter::BookPresenter(IView* view) : m_view(view) {
	list<Book*> books;
}

void BookPresenter::setBooks(string name, string author, int ISBN) {

	if (getBook(ISBN)) {
		m_view->showText("Ya existe un Libro con el correspondiente ISBN");
	}
	else {
		this->books.push_back(new Book(name, author, ISBN));
	}
}		

void BookPresenter::setCopies(int ISBN, int editionNumber, string location, bool available) {
	if (getBook(ISBN)) {
		if (getCopy(location)) {
			m_view->showText("Ya existe un Ejemplar con la correspondiente locacion");
		}
		else {
			Book* bookaux;
			bookaux = this->getBook(ISBN);
			auto copyaux = bookaux->getCopyList();
			copyaux.push_back(new Copy(bookaux->getName(), bookaux->getAuthor(), bookaux->getISBN(), editionNumber, location, available));
			bookaux->getCopyList().push_back(new Copy(bookaux->getName(), bookaux->getAuthor(), bookaux->getISBN(), editionNumber, location, available));
		}
	}
	else {
		m_view->showText("No existe un Libro con el correspondiente ISBN");
	}

}

Copy* BookPresenter::getCopy(string location) {
	list<Copy*> copiesaux;
	for (Book* book : this->books) {
		copiesaux = book->getCopyList();
		for (Copy* copy : this->copies) {
			if (copy->getLocation() == location) {
				return copy;
			}
		}
	}
	/*for (Copy* copy : this->copies) {
		if (copy->getLocation() == location) {
			return copy;
		}
	}*/
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

list<Copy*>BookPresenter::getCopies() {
	return this->copies;
}


void BookPresenter::printBookList() {
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
void BookPresenter::printBook(int x) {
	for (Book* book : this->books) {
		if (book->getISBN() == x) {
			string s01 = book->getName();
			string s02 = book->getAuthor();
			string s03 = to_string(book->getISBN());
			m_view->showText("El libro ingresado tiene los siguientes datos:");
			m_view->showText("	Nombre: " + s01);
			m_view->showText("	Autor: " + s02);
			m_view->showText("	ISBN: " + s03);
		}
	}
}

void BookPresenter::printCopyList(int ISBN) {
	for (Book* book : this->books) {
		if (book->getISBN() == ISBN) {
			auto copies = book->getCopyList();
			for (Copy* copy : copies) {
				string s01 = copy->getName();
				string s02 = copy->getAuthor();
				string s03 = to_string(copy->getISBN());
				string s04 = to_string(copy->getEditionNumber());
				string s05 = copy->getLocation();
				m_view->showText("El Ejemplar ingresado tiene los siguientes datos:");
				m_view->showText("	Nombre: " + s01);
				m_view->showText("	Autor: " + s02);
				m_view->showText("	ISBN: " + s03);
				m_view->showText("	Numero de Edicion: " + s04);
				m_view->showText("	Locacion: " + s05);
			}
		}
	}
}

void BookPresenter::printCopy(int ISBN, int edNr) {
	for (Book* book : this->books) {
		if (book->getISBN() == ISBN) {
			for (Copy* copy : this->copies) {
				if (copy->getEditionNumber() == edNr) {
					string s01 = book->getName();
					string s02 = book->getAuthor();
					string s03 = to_string(book->getISBN());
					string s04 = to_string(copy->getEditionNumber());
					string s05 = copy->getLocation();
					m_view->showText("El Ejemplar ingresado tiene los siguientes datos:");
					m_view->showText("	Nombre: " + s01);
					m_view->showText("	Autor: " + s02);
					m_view->showText("	ISBN: " + s03);
					m_view->showText("	Numero de Edicion: " + s04);
					m_view->showText("	Locacion: " + s05);
				}
			}
		}
	}
}
