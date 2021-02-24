#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
using namespace std;

string find_duplicates(int size, int array[])
{
	unordered_map<int, int> occurrence;
	string result = "";
	for (int i = 0; i < size; i++)
		occurrence[array[i]]++;
	bool duplicate = false;
	unordered_map<int, int>::iterator itr;
	for (itr = occurrence.begin(); itr != occurrence.end(); itr++) {
		if (itr->second > 1) {
			duplicate = true;
			result += to_string(itr->first) + ":" + to_string(itr->second) + "\n";
		}
	}
	if (duplicate == false)
		return "";
	return result;
}

int main()
{
	string results = "";
	int i = 0;;
	int array[100] = {};
	ifstream infile;
	infile.open("input.txt");
	cout << "\nReading Input from file...";
	if (infile.is_open()) {
		while (!infile.eof())
		{
			infile >> array[i];
			i++;
		}
	}
	else
	{
		cout << "\nCould not open the file successfully";
	}
	cout << "\nInput array read from file:";
	for (int j = 0; j < i; j++)
		cout << array[j] << " ";
	infile.close();
	results = find_duplicates(i, array);
	ofstream outfile("output.txt");
	if (outfile.is_open())
	{
		if (results != "")
			outfile << "\nRepeating elements in the input array:\n" << "Number:Frequency\n" << results << endl;
		else
			outfile << "No repeating elements\n";
		cout << "\nOutput Written successfully!!";
	}
	else
		cout << "\nCould not write the output to file";
	outfile.close();
	return 0;
}
