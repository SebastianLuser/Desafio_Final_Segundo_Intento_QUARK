#include <iostream>
#include "View.h"
#include "MemberPresenter.h"
#include "BookPresenter.h"
#include "LoanPresenter.h"
#include "MemberVIP.h"
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>

View::View() {
	memberPresenter = new MemberPresenter(this);
	bookPresenter = new BookPresenter(this);
	loanPresenter = new LoanPresenter(this);
	startMenu();
}

void View::showText(const char* text) {
	cout << text << endl;
};

void View::showText(const string& text) {
	cout << text << endl;
};

void View::startMenu() {
	string input;
	try {
		/*system("cls");*/
		showText("Bienvenido seleccione una de las siguientes opciones:");
		showText("	1. Crear un Socio.");
		showText("	2. Crear un Libro.");
		showText("	3. Crear un Ejemplar.");
		showText("	4. Registrar accion de un Socio.");
		showText("	5. Mostrar Libros.");
		showText("	6. Mostrar historial de Prestamos");
		showText("	7. Mostrar ejemplares de un Libro");
		showText("	8. Salir.");
		cin >> input;
		this->inputI = stoi(input);
		switch (this->inputI) {
		case 1:
			system("cls");
			memberCreateMenu();
			break;
		case 2:
			system("cls");
			bookCreateMenu();
			break;
		case 3:
			system("cls");
			copyCreateMenu();
			break;
		case 4:
			system("cls");
			memberLoginMenu();
			break;
		case 5:
			system("cls");
			bookListMenu();
			break;
		case 6:
			system("cls");
			loanListMenu();
			startMenu();
			break;
		case 7:
			system("cls");
			copyListMenu();
			break;
		case 8:
			exit(EXIT_SUCCESS);
			break;
		default:
			throw this->inputI;
		}
	}
	catch (const invalid_argument& e) {
		system("cls");
		startMenu();
	}
	catch (int inputI) {
		system("cls");
		showText("----------------");
		showText("Opcion no valida");
		showText("----------------");
		startMenu();
	}
}

void View::memberCreateMenu() {
	string mName;
	string mLastName;
	string input;
	int mID;
	int num;
	float mFee = 0;
	try {
		cin.clear();
		system("cls");
		showText("Ingrese el nombre del socio: (Solo letras)");
		cin >> mName;
		if(any_of(mName.begin(), mName.end(), [](char c) { return isdigit(c); }) || mName.empty()) {
			throw invalid_argument("");
		}
		system("cls");
		showText("Ingrese el apellido del socio: (Solo letras)");
		cin >> mLastName;
		if (any_of(mLastName.begin(), mLastName.end(), [](char c) { return isdigit(c); }) || mLastName.empty()) {
			throw invalid_argument("");
		}
		system("cls");
		showText("Ingrese el ID del socio: (Solo numeros)");
		cin >> input;
		mID = stoi(input);

		while(memberPresenter->verifyAvailable(mID) != 0 || mID == 0) {
			system("cls");
			showText("--------------------------------------------------------------------------------------------------------------");
			showText("El ID ingresado ya esta registrado, porfavor ingrese un ID diferente o ingrese 0 para volver al menu de inicio");
			showText("--------------------------------------------------------------------------------------------------------------");
			cin >> mID;
			if (mID == 0) {
				system("cls");
				startMenu();
			}
		}
		system("cls");
		showText("Ingrese si el socio es VIP: (Solo numeros)");
		showText("1.No");
		showText("2.Si");
		cin >> input;
		inputI = stoi(input);

		if (this->inputI == 1 || this->inputI == 2) {
			if (this->inputI == 1) {
				system("cls");
				memberPresenter->setMembers(mName.c_str(), mLastName.c_str(), mID);
				startMenu();
			}
			if (this->inputI == 2) {
				system("cls");
				system("cls");
				showText("Ingrese el costo mensual de la membresia VIP:");
				cin >> input;
				mFee = stoi(input);

				memberPresenter->setMembersVIP(mName.c_str(), mLastName.c_str(), mID, mFee);
				system("cls");
				startMenu();
			}
		}
	}
	catch (const invalid_argument& e) {
		system("cls");
		cin.clear();
		memberCreateMenu();
	}
};

void View::bookCreateMenu() {
	string bName;
	string bAuthor;
	int bISBN;
	string input;
	try {
		system("cls");
		showText("Ingrese el nombre del libro:");
		cin >> bName;
		/*if (any_of(bName.begin(), bName.end(), [](char c) { return isdigit(c); }) || bName.empty()) {
			throw invalid_argument("");
		}*/
		system("cls");
		showText("Ingrese el autor del libro:");
		cin >> bAuthor;
		if (any_of(bAuthor.begin(), bAuthor.end(), [](char c) { return isdigit(c); }) || bAuthor.empty()) {
			throw invalid_argument("");
		}
		system("cls");
		showText("Ingrese el codigo ISBN del libro:");
		cin >> input;
		bISBN = stoi(input);
		bookPresenter->setBooks(bName.c_str(), bAuthor.c_str(), bISBN);
		system("cls");
		startMenu();
	}
	catch (const invalid_argument& e) {
		system("cls");
		bookCreateMenu();
	}
};

void View::copyCreateMenu() {
	int cISBN;
	int cEditionNumber;
	string cLocation;
	string input;
	try {
		if (bookPresenter->checkAvailableBooks() == false) {
			throw ("No hay Libros disponibles para crear un Ejemplar");
		}
		else {
			system("cls");
			showText("Ingrese el codigo ISBN del Libro:");
			cin >> input;
			cISBN = stoi(input);
			if (bookPresenter->getBook(cISBN)) {
				system("cls");
				showText("Ingrese el numero de edicion del Ejemplar:");
				cin >> input;
				cEditionNumber = stoi(input);
				system("cls");
				showText("Ingrese la locacion del Ejemplar:");
				cin >> cLocation;
				bookPresenter->setCopies(cISBN, cEditionNumber, cLocation.c_str(), true);
				system("cls");
				startMenu();
			}
			else {
				throw ("No existe ningun libro con el correspondiente ISBN");
			}
		}
	}
	catch (const invalid_argument& e) {
		system("cls");
		copyCreateMenu();
	}
	catch (const char* txtException) {
		system("cls");
		showText(txtException);
		startMenu();
	}
};

void View::memberLoginMenu() {
	int mID;
	string input;
	try {
		system("cls");
		showText("Ingrese el ID al que se desea ingresar:");
		cin >> input;
		mID = stoi(input);
		while (memberPresenter->verifyAvailable(mID) == 0) {
			system("cls");
			showText("-----------------------------------------------------------------------------------");
			showText("El ID ingresado no existe o no esta registrado.");
			showText("Porfavor ingrese un ID diferente o ingrese 0 para volver al menu de inicio");
			showText("-----------------------------------------------------------------------------------");
			cin >> input;
			mID = stoi(input);
			if (mID == 0) {
				system("cls");
				startMenu();
			}
		}
		memberMenu(mID);
	}
	catch (const invalid_argument& e) {
		system("cls");
		memberLoginMenu();
	}
};

void View::memberMenu(int mID) {
	string input;
	try {
		system("cls");
		if (memberPresenter->verifyAvailable(mID) == 1) {
			memberPresenter->printMember(mID);
		}
		else if (memberPresenter->verifyAvailable(mID) == 2) {
			memberPresenter->printMemberVIP(mID);
		}
		showText("");
		showText("Elija una de las siguientes acciones: ");
		showText("	1. Realizar un prestamo");
		showText("	2. Mostrar ejemplares retirados");
		showText("	3. Devolver un Ejemplar");
		showText("	4. Volver al menu inicial");
		cin >> input;
		this->inputI = stoi(input);
		if (this->inputI == 1 || this->inputI == 2 || this->inputI == 3 || this->inputI == 4) {
			if (this->inputI == 1) {
				system("cls");
				if (memberPresenter->CheckAvailability(mID)) {
					bookMenu(mID);
				}
				else {
					while (input != "0") {
						system("cls");
						memberPresenter->CheckAvailability(mID);
						showText("----------------------------------");
						showText("Presiona 0 para elegir otra accion");
						showText("----------------------------------");
						cin >> input;
					}
					memberMenu(mID);
				}
			}
			if (this->inputI == 2) {
				system("cls");
				memberPresenter->printWithdrawnCopies(mID);
				while (this->inputI != 0) {
					showText("----------------------------------");
					showText("Presiona 0 para elegir otra accion");
					showText("----------------------------------");
					cin >> inputI;
				}
				memberMenu(mID);
			}
			if (this->inputI == 3) {
				system("cls");
				returnCopyMenu(mID);
			}
			if (this->inputI == 4) {
				system("cls");
				startMenu();
			}
		}
	}
	catch (const invalid_argument& e) {
		system("cls");
		memberMenu(mID);
	}
};

void View::bookMenu(int mID) {
	int ISBN;
	int numE;
	string loc;
	string date = "Today";
	try {
		system("cls");
		showText("Ingrese la posicion en la biblioteca que tiene el ejemplar desea retirar:");
		cin >> loc;
		if (bookPresenter->getCopy(loc)) {
			if (bookPresenter->getCopy(loc)->getAvailable() == true) {
				bookPresenter->getCopy(loc)->setAvailable(false);
				if (memberPresenter->verifyAvailable(mID) == 1) {
					loanPresenter->setLoan(bookPresenter->getCopy(loc), memberPresenter->getMember(mID), date);
				}
				if (memberPresenter->verifyAvailable(mID) == 2) {
					loanPresenter->setLoan(bookPresenter->getCopy(loc), memberPresenter->getMemberVIP(mID), date);
				}
				ISBN = bookPresenter->getCopy(loc)->getISBN();
				Copy* copy = bookPresenter->getBook(ISBN)->removeCopy(bookPresenter->getCopy(loc));
				memberPresenter->setWithdrawnCopies(copy, mID);
			}
		}
		system("cls");
		memberMenu(mID);
	}
	catch (const invalid_argument& e) {
		system("cls");
		bookMenu(mID);
	}
};

void View::returnCopyMenu(int mID) {
	int numE;
	string loc;
	string date = "Today";
	try {
		system("cls");
		memberPresenter->printWithdrawnCopies(mID);
		showText("Ingrese la locacion del Ejemplar que desea devolver o presione 0 para elegir otra accion:");
		cin >> loc;
		if (loc == "0") {
			memberMenu(mID);
		}
		while (memberPresenter->checkWithdrawCopy(loc, mID) == false) {
			system("cls");
			memberPresenter->printWithdrawnCopies(mID);
			showText("------------------------------------------------------------------------------------");
			showText("No se encontro ningun Ejemplar con esa locacion en la lista de Ejemplares retirados");
			showText("Ingrese la locacion del Ejemplar que desea devolver o 0 para elegir otra accion :");
			showText("------------------------------------------------------------------------------------");
			cin >> loc;
			if (loc == "0") {
				system("cls");
				memberMenu(mID);
			}
		}
		memberPresenter->getWithdrawnCopy(loc, mID)->setAvailable(true);
		if (memberPresenter->verifyAvailable(mID) == 1) {
			loanPresenter->setLoan(memberPresenter->getWithdrawnCopy(loc,mID), memberPresenter->getMember(mID), date);
		}
		if (memberPresenter->verifyAvailable(mID) == 2) {
			loanPresenter->setLoan(memberPresenter->getWithdrawnCopy(loc, mID), memberPresenter->getMemberVIP(mID), date);
		}
		memberPresenter->removeWithdrawnCopies(memberPresenter->getWithdrawnCopy(loc, mID), mID);
		system("cls");
		memberMenu(mID);
	}
	catch (const invalid_argument& e) {
		system("cls");
		returnCopyMenu(mID);
	}
};


void View::bookListMenu() {
	string input;
	try {
		bookPresenter->printBookList();
		showText("---------------------------------------");
		showText("Presiona 0 para volver al menu Inicial");
		showText("---------------------------------------");
		cin >> input;
		inputI = stoi(input);
		while (this->inputI != 0) {
			system("cls");
			bookPresenter->printBookList();
			showText("---------------------------------------");
			showText("Presiona 0 para volver al menu Inicial");
			showText("---------------------------------------");
			cin >> input;
			inputI = stoi(input);
		}
		system("cls");
		startMenu();
	}
	catch (const invalid_argument& e) {
		system("cls");
		bookListMenu();
	}
	
};
void View::copyListMenu() {
	int ISBN;
	string input;
	try {
		showText("Ingrese el ISBN del Libro del cual quiere ver sus Ejemplares");
		cin >> input;
		ISBN = stoi(input);
		bookPresenter->printCopyList(ISBN);
		showText("---------------------------------------");
		showText("Presiona 0 para volver al menu Inicial");
		showText("---------------------------------------");
		cin >> inputI;
		while (this->inputI != 0) {
			system("cls");
			bookPresenter->printCopyList(ISBN);
			showText("---------------------------------------");
			showText("Presiona 0 para volver al menu Inicial");
			showText("---------------------------------------");
			cin >> inputI;
		}
		system("cls");
		startMenu();
	}
	catch (const invalid_argument& e) {
		system("cls");
		copyListMenu();
	}
};

void View::loanListMenu() {
	string input;
	try{
		loanPresenter->printLoanList();
		showText("---------------------------------------");
		showText("Presiona 0 para volver al menu Inicial");
		showText("---------------------------------------");
		cin >> input;
		this->inputI = stoi(input);
		while (this->inputI != 0) {
			system("cls");
			loanPresenter->printLoanList();
			showText("---------------------------------------");
			showText("Presiona 0 para volver al menu Inicial");
			showText("---------------------------------------");
			cin >> this->inputI;
		}
		system("cls");
		startMenu();
	}
	catch (const invalid_argument& e) {
		system("cls");
		loanListMenu();
	}
};