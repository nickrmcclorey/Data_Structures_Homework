#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string fileName;
	string fileName2;
	ifstream data;
	ofstream outputData;
	string line;

	cout << "Enter the name of your file: ";
	cin >> fileName;

	data.open(fileName, ios::in);

	while (data.fail()) {
		cout << "File does not exist. Please enter another file name: ";
		cin >> fileName;
		data.open(fileName, ios::in);
	}

	cout << "Enter the name of the file you want to output to: ";
	cin >> fileName2;
	outputData.open(fileName2, ios::out | ios::app);

	for (int i = 0; i < 10; ++i) {
		if (getline(data, line)) {
			outputData << line << endl;
		}
	}
	return 0;
}
