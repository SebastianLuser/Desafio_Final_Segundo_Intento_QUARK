#include <iostream>
#include "View.h"
#include "MemberPresenter.h"
#include "BookPresenter.h"
#include "MemberVIP.h"

View::View() {
	memberPresenter = new MemberPresenter(this);
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
		system("cls");
		showText("Bienvenido seleccione una de las siguientes opciones:");
		showText("	1. Crear un Socio.");
		showText("	2. Crear un Libro.");
		showText("	3. Registrar accion de un Socio.");
		showText("	4. Salir.");
		cin >> this->inputI;
		if (this->inputI == 1 || this->inputI == 2 || this->inputI == 3 || this->inputI == 4) {
			if (this->inputI == 1) {
				system("cls");
				memberCreateMenu();
			}
			if (this->inputI == 2) {
				system("cls");
				bookCreateMenu();
			}
			if (this->inputI == 3) {
				system("cls");
				memberLoginMenu();
			}
			if (this->inputI == 4) {
				EXIT_SUCCESS;
			}
		}
		else {
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
	bool mVIP;
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
				mVIP = true;
				system("cls");
				showText("Ingrese el costo mensual de la membresia VIP:");
				cin >> mFee;
				memberPresenter->setMembers(mName.c_str(), mLastName.c_str(), mID, mVIP, mFee);
				startMenu();
			}
			if (this->inputI == 2) {
				system("cls");
				mVIP = false;
				memberPresenter->setMembers(mName.c_str(), mLastName.c_str(), mID, mVIP, 0);
				memberPresenter->printMemberList();
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
	string bEditionNumber;
	string bLocation;
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
		system("cls");
		showText("Ingrese el numero de edicion del libro:");
		cin >> bEditionNumber;
		system("cls");
		showText("Ingrese la locacion del libro:");
		cin >> bLocation;
		bookPresenter->setBooks(bName.c_str(), bAuthor.c_str(), bISBN, bEditionNumber.c_str(), bLocation.c_str());
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
	system("cls");
	showText("Desea ingrear a un socio Clasico o VIP:");
	showText("	1.Clasico");
	showText("	2.VIP");
	cin >> inputI;
	if (this->inputI == 1 || this->inputI == 2) {
		if (this->inputI == 1) {
			system("cls");
			showText("Ingrese el numero de socio Clasico al que se desea ingresar:");
			cin >> inputI;
			memberMenu(inputI);
		}
		if (this->inputI == 2) {
			system("cls");
			/*Imprimir lista de miebros VIP*/
			showText("Ingrese el numero de socio VIP al que se desea ingresar:");
			cin >> inputI;
			/*
			get member of list
			memberMenu(member);
			*/
		}
	}
};

void View::memberMenu(int x) {
	memberPresenter->printMember(x);
	showText("");
	showText("Elija una de las siguientes acciones: ");
	showText("	1. Realizar un prestamo");
	showText("	2. Mostrar historial de prestamos");
	showText("	3. Devolver un libro");
	cin >> this->inputI;
	if (this->inputI == 1 || this->inputI == 2 || this->inputI == 3) {
		if (this->inputI == 1) {
			system("cls");
			bookMenu();
		}
		if (this->inputI == 2) {
			system("cls");

		}
		if (this->inputI == 3) {
			system("cls");

		}
	}
};

void View::bookMenu() {
	system("cls");
	/*Mostrar libros disponibles*/
	showText("Ingrese el numero de libro que desea retirar:");
	cin >> inputI;
	/*
	get libro of list de libros dispoibles
	member register in listOfPrestamos
	actualizar cantidad de ejemplares del libro seleccionado
	*/
};