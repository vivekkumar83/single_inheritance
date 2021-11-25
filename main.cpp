#include<iostream>
using namespace std;

class Vechile {
	protected:
		int price;
		string color;
	public:
		void set_value(int price, string color) {
			this->price = price;
			this->color = color;
		}
		void get_value() {
			cout << "price: " << price << endl;
			cout << "color: " << color << endl;
		}
};
class Safety {
	protected:
		int speed_limit;
	public:
		void set_value(int speed_limit){
			this->speed_limit = speed_limit;
		}
		void get_value() {
			cout << "speed_limit: " << speed_limit << endl;
		}
};
class Audi: public Vechile {
	public:
		string  model_name;

	void set_value(int price, string color, string model_name) {
		Vechile::set_value(price, color);
		this->model_name = model_name;
	}
	void get_value() {
		cout << "Description of Audi car: "<<endl;
		Vechile::get_value();
		cout << "model_name: " << model_name<<endl;
	}
};
class BMW: public Vechile, protected Safety {
	int break_second;
	public:
		void set_value(int price, string color,int speed_limit, int break_second) {
			Vechile::set_value(price, color);
			Safety::set_value(speed_limit);
			this->break_second = break_second;
		}
		void get_value(){
			cout << "Description of BMW car: " << endl;
			Vechile::get_value();
			Safety::get_value();
			cout << "break_second: " << break_second << endl;
		}

};
class NewAudi: public Audi {
	string design;
	public:
		void set_value(int price, string color, string model_name, string design) {
		Audi::set_value(price, color, model_name);
		this->design = design;
	};
	void get_value() {
		cout << "Description of newAudi car: " << endl;
		Audi::get_value();
		cout << "design: " << design << endl;
	}
};
int main() {
	Audi audi1;
	BMW bmw1;
	NewAudi audi2;
	audi1.set_value(2000,"green","Audi Q3");
	audi1.get_value();
	bmw1.set_value(5000,"grey",300,10);
	bmw1.get_value();
	audi2.set_value(10000,"black","Audi Q3","Sport");
	audi2.get_value();
}