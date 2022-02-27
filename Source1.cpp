#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std;

struct employee
{
	int num;
	char name[10];
	double hours;
};

int  main(int argc, char* argument[])
{
	char* filename = argument[1];

	ofstream out(filename, ios::binary);

	cout << "How many emps you want write?\n";
	int num = atoi(argument[2]);


	for (int i = 0; i < num; i++)
	{
		system("cls");
		employee temp;
		cout << "Enter employee num:\n";
		cin >> temp.num;

		cout << "Enter employee name:\n";
		cin >> temp.name;

		cout << "Enter employee hours:\n";
		cin >> temp.hours;

		out.write((char*)&temp, sizeof(struct employee));
	}

	out.close();

	return 1;
}