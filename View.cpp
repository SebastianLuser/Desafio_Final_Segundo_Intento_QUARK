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
		system("cls");
		showText("Ingrese si el socio es VIP:");
		showText("1.Si");
		showText("2.No");
		cin >> inputI;
		if (this->inputI == 1 || this->inputI == 2) {
			if (this->inputI == 1) {
				system("cls");
				system("cls");
				showText("Ingrese el costo mensual de la membresia VIP:");
				cin >> mFee;
				memberPresenter->setMembersVIP(mName.c_str(), mLastName.c_str(), mID, mFee);
				startMenu();
			}
			if (this->inputI == 2) {
				system("cls");
				memberPresenter->setMembers(mName.c_str(), mLastName.c_str(), mID);
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
	int typeM;
	int ID;
	system("cls");
	showText("Desea ingrear a un socio Clasico o VIP:");
	showText("	1.Clasico");
	showText("	2.VIP");
	cin >> typeM;
	if (typeM == 1 || typeM == 2) {
		if (typeM == 1) {
			system("cls");
			showText("Ingrese el ID Clasico al que se desea ingresar:");
			cin >> ID;
			memberMenu(typeM,ID);
		}
		if (typeM == 2) {
			system("cls");
			showText("Ingrese el ID VIP al que se desea ingresar:");
			cin >> ID;
			memberMenu(typeM, ID);
		}
	}
};

void View::memberMenu(int typeM, int ID) {
	system("cls");
	if (typeM == 1) {
		memberPresenter->printMember(ID);
	}
	else if(typeM == 2) {
		memberPresenter->printMemberVIP(ID);
	}
	showText("");
	showText("Elija una de las siguientes acciones: ");
	showText("	1. Realizar un prestamo");
	showText("	2. Mostrar ejemplares retirados");
	showText("	3. Devolver un libro");
	showText("	4. Volver al menu inicial");
	cin >> this->inputI;
	if (this->inputI == 1 || this->inputI == 2 || this->inputI == 3 || this->inputI == 4) {
		if (this->inputI == 1) {
			system("cls");
			bookMenu(typeM, ID);
		}
		if (this->inputI == 2) {
			system("cls");

		}
		if (this->inputI == 3) {
			system("cls");

		}
		if (this->inputI == 4) {
			system("cls");
			startMenu();
		}
	}
};

void View::bookMenu(int typeM, int ID) {
	int ISBN;
	int numE;
	string pos;
	string date = "Today";
	//system("cls");
	//showText("Ingrese el codigo ISBN del Libro que desea retirar:");
	//cin >> ISBN;
	//system("cls");
	//showText("Ingrese el numero de edicion del Ejemplar que desea retirar:");
	//cin >> numE;
	system("cls");
	showText("Ingrese la posicion en la biblioteca que tiene el ejemplar desea retirar:");
	cin >> pos;
	Copy* copyaux = bookPresenter->getCopy(pos);
	if (copyaux) {
		if(copyaux->getAvailable() == true){
			bookPresenter->getCopy(pos)->setAvailable(false);
			memberPresenter->setWithdrawnCopies(copyaux, ID, typeM);
			memberPresenter->printWithdrawnCopies();
			/*loanPresenter->setLoan(copyaux, memberPresenter->getMembers(ID), date);*/
		}
	}
};