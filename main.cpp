#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {

	if (argc != 2) {
		cout << "Incorrect arguments, enter only one file like ./Steam steam.txt" << endl;
		return 1;
	}

	Core base(argv[1]);
	if (!base.isitokay()) {
		cout << "Some troble with the file " << argv[1] << endl;
		cout << "The program can't open this :(" << endl;
		return 2;
	}

	Menu ura;
	ura.Start(base);

	return 0;
}
