#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

class doublevector {
	// class and constructors specified for lab6 (template)
	static constexpr double DOUBLE_DEFAULT_VALUE = -5.55;
	double* mValues;
	int mNumValues;

	public:
	doublevector();
	~doublevector();
	void resize(int new_size, double initial_value = DOUBLE_DEFAULT_VALUE);
	void push_back(double value);
	double& at(int index);
	const double& at(int index) const;
	unsigned long size() const;
};

void print_all(const doublevector& v) {
	// constructors specified for lab6 (template)
	if (v.size() == 0) {
		cout << "Vector is empty.\n";
	}
	else {
		unsigned long i;
		for (i = 0; i < v.size(); i++) {
			cout << "[" << setfill('0') << right << setw(3) << i << "] = " << fixed
				<< setprecision(4) << v.at(i) << '\n';
		}
	}
}

int main() {
	// int main specified for lab6 (template)
	doublevector v;
	do {
		string command;
		cout << "Enter a command ('quit' to quit): ";
		if (!(cin >> command) || command == "quit") {
			break;
		}

		else if (command == "push_back") {
			double value;
			cin >> value;
			v.push_back(value);
			cout << "Pushed back " << fixed << setprecision(4) << value << '\n';
		}

		else if (command == "resize") {
			string line;
			int new_size;
			double initial;
			cin >> new_size;
			getline(cin, line);
			istringstream sin(line);

			if (sin >> initial) {
				v.resize(new_size, initial);
			}

			else {
				v.resize(new_size);
			}
		}

		else if (command == "size") {
			cout << v.size() << '\n';
		}

		else if (command == "print") {
			print_all(v);
		}

		else if (command == "get") {
			int index;
			cin >> index;

			try {
				cout << "Value at " << index << " = " << setprecision(4) << fixed
					<< v.at(index) << '\n';
			}

			catch (out_of_range& err) {
				cout << err.what() << '\n';
			}
		}

		else if (command == "set") {
			double d;
			int index;
			cin >> index >> d;

			try {
				v.at(index) = d;
				cout << "SET: " << index << " = " << setprecision(4) << fixed
					<< v.at(index) << '\n';
			}

			catch (out_of_range& err) {
				cout << err.what() << '\n';
			}
		}

		else if (command == "clear") {
			v.resize(0);
		}

		else {
			cout << "Invalid command '" << command << "'\n";
		}

	} while (true);

	cout << '\n';

	return 0;
}
doublevector::doublevector() {
	// initiationg mValues and mNumValues
	mValues = nullptr;
	mNumValues = 0;

}
doublevector::~doublevector() {
	// delete mValues
	delete[] mValues;
}
void doublevector::resize(int new_size, double initial_value) {
	// dynamic allocated class
	double* Array = new double[new_size];

	for (int i = 0; i < new_size; i++) {

		// once i > initial value, the new initial value will be allocated(for pus_back)
		if (i > mNumValues - 1) {

			Array[i] = initial_value;

		}
		// if else, the original value or the default value will be allocated
		else {
			Array[i] = mValues[i];
		}
	}

	// the mValues is not equal to nullptr delete[]
	if (mValues != nullptr) {

		delete[] mValues;

	}
	// set mNumValues to new size
	mNumValues = new_size;
	// point Mvaluse to the new set of allocate values
	mValues = Array;





}
void doublevector::push_back(double value) {
	// push_back calls resize(adding 1 to mNumValues and using the value user specified)
	resize(mNumValues + 1, value);
}
double& doublevector::at(int index) {
	// returning value at the given index
	if (index >= mNumValues) {
		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	}
	return mValues[index];
}
const double& doublevector::at(int index) const {
	// returning read-only reference to the value at the given index
	if (index >= mNumValues) {
		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	}
	return mValues[index];
}
unsigned long doublevector::size() const {
	// size of the vector
	return mNumValues;
}
