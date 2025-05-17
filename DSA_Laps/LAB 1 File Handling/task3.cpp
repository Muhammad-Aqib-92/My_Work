#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream file("input.txt");
	if (!file.is_open()){
		cerr<< "Unable to open file.";
		return 1;
	}
	while (!file.eof())
	{
		int rollno;
		int marks[10];
		int max = 0;
		int min = 1000;

		file >> rollno;
		for (int i = 0; i < 10; i++){
			file >> marks[i];
			if (marks[i] > max)
			{
				max = marks[i];
			}
			
			if (marks[i] < min) {

				min = marks[i];
			}
			
		}
		cout << rollno << " ";
		for (int i = 0; i < 10; i++)
		{
			cout << marks[i] << " ";
		}
		cout << max - min;
		cout << endl;
	}
	return 0;
}