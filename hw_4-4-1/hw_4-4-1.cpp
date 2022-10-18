#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class Address {
private:
	std::string city;
	std::string street;
	int building;
	int flat;

public:
	Address(std::string city, std::string street, int building, int flat) {
		this->city = city;
		this->street = street;
		this->building = building;
		this->flat = flat;
	}

	Address() {
		city = "n/a";
		street = "n/a";
		building = 0;
		flat = 0;
	}

	std::string get_output_addreess() {
		std::stringstream building_ss;
		building_ss << building;
		std::string building_str;
		building_ss >> building_str;
		
		std::stringstream flat_ss;
		flat_ss << flat;
		std::string flat_str;
		flat_ss >> flat_str;
		
		std::string output = "\n" + city + ", " + street + ", " + building_str + ", " + flat_str;
		return output;
	}

};

int main()
{
	std::ifstream in ("in.txt");
	std::ofstream out ("out.txt");

	std::cout << in.is_open() << " " << out.is_open();


	int size = 0;
	in >> size;
	out << size;

	std::string city;
	std::string street;
	int building = 0;
	int flat = 0;

	//int size = 3;
	Address* adr_arr = new Address[size];

	for (int i = 0; i < 3; i++) {
		in >> city >> street >> building >> flat;
		adr_arr[i] = Address(city, street, building, flat);
	}

	for (int i = 0; i < 3; i++) {
		out << adr_arr[i].get_output_addreess();
	}

	in.close();
	out.close();
	delete[] adr_arr;
	return 0;
}