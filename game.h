#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Game {

private:

	string name;
	float price;
	string developer;
	float weight;
	float discount;
	int year;

public:

	string getName() {return name; }
	void setName(string name_x) { name = name_x; }

	float getPrice() {return price; }
	void setPrice(float price_x) { price = price_x; }

	string getDeveloper() {return developer; }
	void setDeveloper(string developer_x) {developer = developer_x; }

	float getWeight() {return weight; }
	void setWeight(float weight_x) {weight = weight_x; }

	float getDiscount() {return discount; }
	void setDiscount(float discount_x) {discount = discount_x; }

	int getYear() {return year; }
	void setYear(int year_x) {year = year_x; }

	friend ostream &operator<<(ostream &out, Game &obj) {
		out << obj.getName() << ",";
                out << obj.getPrice() << ",";
                out << obj.getDeveloper() << ",";
                out << obj.getWeight() << ",";
                out << obj.getDiscount() << ",";
                out << obj.getYear() << "\n";

		return out;
	};

	friend istream &operator>>(istream &in, Game &obj) {

		string _buf;

	        string _name;
        	float _price;
        	string _developer;
        	float _weight;
        	float _discount;
        	int _year;

		getline(in, _name, ',');
		in >> _price;
		getline(in, _buf, ',');
		getline(in, _developer, ',');
		in >> _weight;
		getline(in, _buf, ',');
		in >> _discount;
		getline(in, _buf, ',');
		in >> _year;
		in.get();

		obj.setName(_name);
		obj.setPrice(_price);
		obj.setDeveloper(_developer);
		obj.setWeight(_weight);
		obj.setDiscount(_discount);
		obj.setYear(_year);

		return in;
	};
};

