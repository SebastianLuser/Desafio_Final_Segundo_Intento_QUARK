#include <iostream>
#include "View.h"
#include "MemberPresenter.h"
#include "BookPresenter.h"
#include "LoanPresenter.h"
#include "MemberVIP.h"
#include <string>

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
	try {
		/*system("cls");*/
		showText("Bienvenido seleccione una de las siguientes opciones:");
		showText("	1. Crear un Socio.");
		showText("	2. Crear un Libro.");
		showText("	3. Crear un Ejemplar.");
		showText("	4. Registrar accion de un Socio.");
		showText("	5. Mostrar Libros.");
		showText("	7. Mostrar historial de Prestamos");
		showText("	8. Mostrar ejemplares de un Libro");
		showText("	9. Salir.");
		cin >> this->inputI;
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
			bookPresenter->printBookList();
			startMenu();
			break;
		case 6:
			system("cls");
			int isbn;
			cin >> isbn;
			bookPresenter->printCopyList(isbn);
			startMenu();
			break;
		case 7:
			system("cls");
			loanPresenter->printLoanList();
			startMenu();
			break;
		case 8:
			system("cls");
			showText("Ingrese el ISBN del Libro del cual quiere ver sus Ejemplares");
			cin >> isbn;
			bookPresenter->printCopyList(isbn);
			cin >> isbn;
			startMenu();
			break;
		case 9:
			EXIT_SUCCESS;
			break;
		default:
			throw this->inputI;
		}
	}

	catch (...) {
		system("cls");
		showText("----------------------------------------------------------------------");
		showText("Input invalido, porfavor ingrese caulquier numero para volver.");
		showText("----------------------------------------------------------------------");
		cin.clear();
		cin.ignore(500, '\n');
		cin >> this->inputI;
		/*menuInicio();*/
	}
}

void View::memberCreateMenu() {
	string mName;
	string mLastName;
	int mID;
	int mVIPInput;
	float mFee = 0;
	try {
		system("cls");
		showText("Ingrese el nombre del socio:");
		cin >> mName;
		system("cls");
		showText("Ingrese el apellido del socio:");
		cin >> mLastName;
		system("cls");
		showText("Ingrese el ID del socio:");
		cin >> mID;
		while(memberPresenter->verifyAvailable(mID) != 0 || mID == 0) {
			system("cls");
			showText("--------------------------------------------------------------------------------------------------------------");
			showText("El ID ingresado ya esta registrado, porfavor ingrese un ID diferente o ingrese 0 para volver al menu de inicio");
			showText("--------------------------------------------------------------------------------------------------------------");
			cin >> mID;
			if (mID == 0) {
				startMenu();
			}
		}
		system("cls");
		showText("Ingrese si el socio es VIP:");
		showText("1.No");
		showText("2.Si");
		cin >> inputI;
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
				cin >> mFee;
				memberPresenter->setMembersVIP(mName.c_str(), mLastName.c_str(), mID, mFee);
				startMenu();
			}
		}
	}
	catch (...) {
		system("cls");
		showText("----------------------------------------------------------------------");
		showText("Input invalido, porfavor ingrese caulquier numero para volver.");
		showText("----------------------------------------------------------------------");
		cin.clear();
		cin.ignore(500, '\n');
		cin >> this->inputI;
		/*menuInicio();*/
	}
};

void View::bookCreateMenu() {
	string bName;
	string bAuthor;
	int bISBN;
	try {
		system("cls");
		showText("Ingrese el nombre del libro:");
		cin >> bName;
		system("cls");
		showText("Ingrese el autor del libro:");
		cin >> bAuthor;
		system("cls");
		showText("Ingrese el codigo ISBN del libro:");
		cin >> bISBN;
		bookPresenter->setBooks(bName.c_str(), bAuthor.c_str(), bISBN);
		startMenu();
	}
	catch (...) {
		system("cls");
		showText("----------------------------------------------------------------------");
		showText("Input invalido, porfavor ingrese caulquier numero para volver.");
		showText("----------------------------------------------------------------------");
		cin.clear();
		cin.ignore(500, '\n');
		cin >> this->inputI;
		/*menuInicio();*/
	}
};

void View::copyCreateMenu() {
	int cISBN;
	int cEditionNumber;
	string cLocation;
	int cStock;
	try {
		system("cls");
		showText("Ingrese el codigo ISBN del Libro:");
		cin >> cISBN;
		system("cls");
		showText("Ingrese el numero de edicion del Ejemplar:");
		cin >> cEditionNumber;
		system("cls");
		showText("Ingrese la locacion del Ejemplar:");
		cin >> cLocation;
		system("cls");
		showText("Ingrese stock del Ejemplar:");
		cin >> cStock;
		bookPresenter->setCopies(cISBN, cEditionNumber, cLocation.c_str(), cStock);
		startMenu();
	}
	catch (...) {
		system("cls");
		showText("----------------------------------------------------------------------");
		showText("Input invalido, porfavor ingrese caulquier numero para volver.");
		showText("----------------------------------------------------------------------");
		cin.clear();
		cin.ignore(500, '\n');
		cin >> this->inputI;
		/*menuInicio();*/
	}
};

void View::memberLoginMenu() {
	int mID;
	system("cls");
	showText("Ingrese el ID al que se desea ingresar:");
	cin >> mID;
	while (memberPresenter->verifyAvailable(mID) == 0) {
		system("cls");
		showText("-----------------------------------------------------------------------------------");
		showText("El ID ingresado no existe o no esta registrado.");
		showText("Porfavor ingrese un ID diferente o ingrese 0 para volver al menu de inicio");
		showText("-----------------------------------------------------------------------------------");
		cin >> mID;
		if (mID == 0) {
			startMenu();
		}
	}
	memberMenu(mID);
};

void View::memberMenu(int mID) {
	system("cls");
 	if (memberPresenter->verifyAvailable(mID) == 1) {
		memberPresenter->printMember(mID);
	}
	else if(memberPresenter->verifyAvailable(mID) == 2) {
		memberPresenter->printMemberVIP(mID);
	}
	showText("");
	showText("Elija una de las siguientes acciones: ");
	showText("	1. Realizar un prestamo");
	showText("	2. Mostrar ejemplares retirados");
	showText("	3. Devolver un Ejemplar");
	showText("	4. Volver al menu inicial");
	cin >> this->inputI;
	if (this->inputI == 1 || this->inputI == 2 || this->inputI == 3 || this->inputI == 4) {
		if (this->inputI == 1) {
			system("cls");
			if (memberPresenter->CheckAvailability(mID)) {
				bookMenu(mID);
			}
			else {
				showText("El socio no puede retirar mas ejemplares.");
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
};

void View::bookMenu(int mID) {
	int ISBN;
	int numE;
	string loc;
	string date = "Today";
	system("cls");
	showText("Ingrese la posicion en la biblioteca que tiene el ejemplar desea retirar:");
	cin >> loc;
	if (bookPresenter->getCopy(loc)) {
		if(bookPresenter->getCopy(loc)->getAvailable() == true){
			bookPresenter->getCopy(loc)->setAvailable(false);
			memberPresenter->setWithdrawnCopies(bookPresenter->getCopy(loc), mID);
			/*memberPresenter->printWithdrawnCopies(mID);*/
			if (memberPresenter->verifyAvailable(mID) == 1) {
				loanPresenter->setLoan(bookPresenter->getCopy(loc), memberPresenter->getMember(mID), date);
			}
			if (memberPresenter->verifyAvailable(mID) == 2) {
				loanPresenter->setLoan(bookPresenter->getCopy(loc), memberPresenter->getMemberVIP(mID), date);
			}
			/*loanPresenter->printLoanList();*/
		}
	}
	startMenu();
};

void View::returnCopyMenu(int mID) {
	int ISBN;
	int numE;
	string loc;
	string date = "Today";
	system("cls");
	memberPresenter->printWithdrawnCopies(mID);
	showText("Ingrese la locacion del Ejemplar que desea devolver:");
	cin >> loc;
	//while (bookPresenter->getCopy(loc) == 0) {
	//	system("cls");
	//	memberPresenter->printWithdrawnCopies(mID);
	//	showText("-----------------------------------------------------------------");
	//	showText("No se encontro ningun Ejemplar con esa locacion en la biblioteca");
	//	showText("-----------------------------------------------------------------");
	//	cin >> loc;
	//}
	while (bookPresenter->getCopy(loc) == 0) {
		system("cls");
		memberPresenter->printWithdrawnCopies(mID);
		showText("-----------------------------------------------------------------");
		showText("No se encontro ningun Ejemplar con esa locacion en la biblioteca");
		showText("-----------------------------------------------------------------");
		cin >> loc;
	}
	memberPresenter->removeWithdrawnCopies(bookPresenter->getCopy(loc), mID);
	bookPresenter->getCopy(loc)->setAvailable(true);
	if (memberPresenter->verifyAvailable(mID) == 1) {
		loanPresenter->setLoan(bookPresenter->getCopy(loc), memberPresenter->getMember(mID), date);
	}
	if (memberPresenter->verifyAvailable(mID) == 2) {
		loanPresenter->setLoan(bookPresenter->getCopy(loc), memberPresenter->getMemberVIP(mID), date);
	}	
	startMenu();
};