#include <iostream>
#include <fstream>
#include <string>
#include "core.h"

using namespace std;

Core::Core(char *_fname) {
	fname = _fname;
}

void Core::sizef(){
	f.open(fname,ios::in);
	size = 0;
	string buf;
	while(f.peek() != EOF){
		getline (f,buf);
		size++;
	}
	f.close();
}

void Core::f_to_arr() {
	games = new Game [size];
	f.open(fname,ios::in);
	for (int i = 0; i < size; i++) {
		f >> games[i];
	}
	f.close();
}

void Core::clear(){
	delete [] games;
}

void Core::add() {
	Game buf;
	cout << "Enter info about your game:";
	cin >> buf;
	cout << endl;
	f.open(fname,ios::out);
	for (int i = 0; i < size; i++) {
		f << games[i];
	}
	f << buf;
	f.close();
}

void Core::output() {
	cout << "Game list:" << "\n";
	if (size == 0) {cout << "Empty" << endl;}
	for (int i = 0; i < size; i++){
		cout << "Game id: " << i << ". ";
		if (games[i].getDiscount() != 0) {
			cout << games[i];
			cout << "Discount price: ";
			cout << (games[i].getPrice() * (100 - games[i].getDiscount()) / 100) << endl;
		}
		else {
			cout << games[i] << endl;
		}
	}
}

void Core::remove() {
	int n;
	cout << "Please enter game id that you want to remove: ";
	cin >> n; cout << endl;
	f.open(fname, ios::out);
	f.seekg(0);
	for (int i = 0; i < size; i++) {
		if (i != n) {
			f << games[i];
		}
	}
	f.close();
}

void Core::change() {
	int n;
	cout << "Please enter game id that you want to change: ";
	cin >> n;
	cin.get();
	cout << "\n" << games[n] << "\n" <<"Please enter a new info about this:" << endl;
	cin >> games[n];
	cout << endl;
	f.open(fname, ios::out);
	for (int i = 0; i < size; i++) {
		f << games[i];
	}
}

void Core::search_name() {
	string buf_name;
	cout << "Please enter a name of the game: ";
	cin.clear();
	getline(cin,buf_name);
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (games[i].getName() == buf_name) {
			cout << "Game id: " << i << ". ";
				if (games[i].getDiscount() != 0){
					cout << games[i];
					cout << "Discount price: " << (games[i].getPrice() * (100 - games[i].getDiscount()) / 100) << endl;
				}
				else {
					cout << games[i] << endl;
				}
	}	}

}

void Core::search_developer() {
	string buf_developer;
        cout << "Please enter a developer of the game: ";
	cin.clear();
        getline(cin,buf_developer);
        cout << endl;
        for (int i = 0; i < size; i++) {
        	if (games[i].getDeveloper() == buf_developer) {
                	cout << "Game id: " << i << ". ";
                        if (games[i].getDiscount() != 0){
                        	cout << games[i];
                                cout << "Discount price: " << (games[i].getPrice() * (100 - games[i].getDiscount()) / 100) << endl;
                        }
                        else {
                        	cout << games[i] << endl;
                        }
		}
	}

}

void Core::search_price() {
	int buf,from,to;
        cout << "Please enter a price of the game in format from to: ";
        cin >> from >> to;
        cout << endl;
        for (int i = 0; i < size; i++) {
		buf = (games[i].getPrice() * (100 - games[i].getDiscount()) / 100);
		if ((buf <= to) && (buf >= from)) {
			if (games[i].getDiscount() != 0) {
				cout << "Game id: " << i << ". ";
				cout << games[i] << "Discount price: " << buf << endl;
			}
			else {
				cout << "Game id: " << i << ". ";
				cout << games[i] << endl;
			}
		}
	}
}

void Core::search_discount() {
	cout << "The list of games with the discount: " << endl;
	for (int i = 0; i < size; i++) {
        	if (games[i].getDiscount() != 0) {
			int buf;
			buf = (games[i].getPrice() * (100 - games[i].getDiscount()) / 100);
                	cout << "Game id: " << i << ". ";
                	cout << games[i] << "Discount price : " << buf << endl;
                }
        }

}

bool Core::isitokay() {
	f.open(fname,ios::in);
	if (f) {
		f.close();
		return true;
	}
	else {
		return false;
	}
}
