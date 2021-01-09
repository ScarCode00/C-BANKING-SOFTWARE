#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <limits>
using namespace std;

#define L "BankingSoftware"

struct userDataBank {
	string name;
	string surname;
	string bornDate;
	string bornPlace;
	string residence;
} USER;

void menuUser() {
	system("CLS");
	cout << L << " MENU AREA" << endl << endl << endl << endl << endl;
	cout << "1) CREATE ACCOUNT" << endl;
	cout << "2) UPDATE INFORMATIONS ABOUT YUOR ACCOUNT" << endl;
	cout << "3) TRANSACTION OF MONEY" << endl;
	cout << "4) DEPOSIT MONEY" << endl;
	cout << "5) CHECK YOUR ACCOUNT DETAILS" << endl;
	cout << "6) REMOVE ACCOUNT" << endl;
	cout << "7) EXIT" << endl;
}

void menuChoose() {
	string nameDate, answer, answer1, answer2 = "yes", pass;     
	ofstream UserFile; 
	int numeroArea, numeroCompilazione;
	cout << "Enter number: ";
	cin >> numeroArea;
	switch (numeroArea)
	{
	case 1:
		system("CLS");
		cout << L << " CREATE ACCOUNT AREA" << endl;
		cout << "Are you sure you want to continue?[yes/no]: ";
		cin >> answer;
		system("CLS");
		if (answer == "yes") {
			cout << "Enter name: ";
			cin.ignore();
			getline(cin, USER.name);
			cout << "Enter surname: ";
			getline(cin, USER.surname);
			cout << "Enter your Birth Day Date [ex: 05/12/2001- In this Order]: ";
			getline(cin, USER.bornDate);
			cout << "Enter your birth place[ex: Milan - Italy]: ";
			getline(cin, USER.bornPlace);
			cout << "Enter your residence [Milan , Street Name and number]: ";
			getline(cin, USER.residence);
			cout << "Name: " << USER.name << endl;
			cout << "Surname: " << USER.surname << endl;
			cout << "Birth Date: " << USER.bornDate << endl;
			cout << "Birth Place: " << USER.bornPlace << endl;
			cout << "Residence: " << USER.residence<< endl;
			cout << "Are the information correct?[yes/no]: ";
			getline(cin, answer1);
			if (answer1 == "no") {
				while (answer2 == "yes") {
					cout << "What do you want to change?\n1)Name\n2)Surname\n3)Birth Date\n4)Birth Place\n5)Residence\n";
					cout << "Enter Number: ";
					cin >> numeroCompilazione;
					cin.ignore();
					switch (numeroCompilazione)
					{
					case 1:
						cout << "Enter name: ";
						getline(cin, USER.name);
						break;
					case 2:
						cout << "Enter surname: ";
						getline(cin, USER.surname);
						break;
					case 3:
						cout << "Enter your Birth Day Date [ex: 05/12/2001- In this Order]: ";
						getline(cin, USER.bornDate);
						break;
					case 4:
						cout << "Enter your birth place[ex: Milan - Italy]: ";
						getline(cin, USER.bornPlace);
						break;
					case 5:
						cout << "Enter your actual residence: ";
						getline(cin, USER.residence);
						break;
					default:
						break;
					}
					cout << "Do you want to change other?[yes/no]?: ";    // END SWITCH NUMERO COMPILAZIONE
					getline(cin, answer2);
					cin.ignore();
				} // END WHILE ANSWER2 == "YES"
				UserFile.open("C:\\Users\\myl1978\\Desktop\\FILEACCOUNT\\" + USER.name + "_" + USER.surname + ".txt");
				UserFile << "Name: " << USER.name << endl;
				UserFile << "Surname: " << USER.surname << endl;
				UserFile << "Birth Date: " << USER.bornDate << endl;
				UserFile << "Birth Place: " << USER.bornPlace << endl;
				UserFile << "Residence: " << USER.residence << endl;
				Sleep(2000);
				cout << "ACCOUNT SUCCESFULY CREATED";
				cout << "PLEASE , WAIT";
				Sleep(5000);
				system("CLS");
				menuUser();
				menuChoose();
			}
			else {
				UserFile.open("C:\\Users\\myl1978\\Desktop\\FILEACCOUNT\\" + USER.name + "_" + USER.surname + ".txt");
				UserFile << "Name: " << USER.name << endl;
				UserFile << "Surname: " << USER.surname << endl;
				UserFile << "Birth Date: " << USER.bornDate << endl;
				UserFile << "Birth Place: " << USER.bornPlace << endl;
				UserFile << "Residence: " << USER.residence << endl;
				Sleep(2000);
				cout << "ACCOUNT SUCCESFULY CREATED";
				cout << "PLEASE , WAIT";
				Sleep(5000);
				system("CLS");
				menuUser();
				menuChoose();
			}  // END ELSE
		}  // END ANSWER = "YES"     
		else {
			menuUser();
			menuChoose();
		}
		break;
	}
}
int main() {
	ofstream UserFile;
	cout << "Welcome to " << L << " \n\n\n\nMADE BY HAMMAD...";
	Sleep(5000);
	system("CLS");
	cout << "WHO ARE YOU[USER/ADMINISTRATOR]: ";
	string userORadministrator;
	cin >> userORadministrator;
	system("CLS");
	if (userORadministrator == "USER" || userORadministrator == "user") {
		menuUser();
		menuChoose();
	}
}
