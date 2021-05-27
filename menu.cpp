#include <iostream>
#include "menu.h"

using namespace std;

Menu::Menu() {
	cout << "Welcome! This is a prototype of the Steam library" << endl;
}

Menu::~Menu() {
	cout << "Good luck!)" << endl;
}

void Menu::Start(Core &obj) {
	bool flag = true;
	int sw = 0;
	while (flag) {
		switch (sw) {
			case 0:
				cout << "This is a short guide how to use this programm" << endl;
				cout << "There are you can perform some of the operations below on the library of game associated with the file" << endl;
				cout << "You should select an action from the list:" << endl;
				cout << "When working with the program, the format is used: Name,Price,Developer,Weight,Discount,Year" << endl;
				cout << "0. See this instruction again" << endl;
				cout << "1. Display the current list of games and their description" << endl;
				cout << "2. Add the game to the list" << endl;
				cout << "3. Remove the game from the list" << endl;
				cout << "4. Change the game from the list" << endl;
				cout << "5. Search the game by name" << endl;
                                cout << "6. Search the game by developer" << endl;
                                cout << "7. Search the game by price" << endl;
                                cout << "8. Search the game by discount" << endl;
				cout << "Enter any number to exit" << endl;
				break;
			case 1:
				obj.sizef();
				obj.sizef();
				obj.f_to_arr();
				obj.output();
				obj.clear();
				break;
			case 2:
				obj.sizef();
				obj.sizef();
				obj.f_to_arr();
				obj.add();
				obj.clear();
				break;
			case 3:
				obj.sizef();
				obj.sizef();
				obj.f_to_arr();
				obj.remove();
				obj.clear();
				break;
			case 4:
				obj.sizef();
				obj.sizef();
				obj.f_to_arr();
				obj.change();
				obj.clear();
				break;
			case 5:
				obj.sizef();
				obj.sizef();
				obj.f_to_arr();
				obj.search_name();
				obj.clear();
				break;
			case 6:
                                obj.sizef();
                                obj.sizef();
                                obj.f_to_arr();
                                obj.search_developer();
                                obj.clear();
                                break;

			case 7:
                                obj.sizef();
                                obj.sizef();
                                obj.f_to_arr();
                                obj.search_price();
                                obj.clear();
                                break;

			case 8:
                                obj.sizef();
                                obj.sizef();
                                obj.f_to_arr();
                                obj.search_discount();
                                obj.clear();
                                break;

			default:
				flag = false;
				continue;
		}
		cout << "Please choose your action: ";
		cin >> sw;
		cin.get();
	}
}
