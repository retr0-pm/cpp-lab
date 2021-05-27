#include <iostream>
#include <fstream>
#include <string>
#include "game.h"

using namespace std;

class Core {
private:
	fstream f;
	char *fname;
	int size;
	Game *games;
public:
	Core(char *_fname);
	void sizef();
	void f_to_arr();
	void clear();
	void add();
	void output();
	void remove();
	void change();
	void search_name();
	void search_developer();
	void search_price();
	void search_discount();
	bool isitokay();
};
