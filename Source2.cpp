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

int main(int argc, char* argument[])
{
	char* fileEmpName = argument[1];
	char* fileReportName = argument[2];
	int payment_for_hour = atoi(argument[3]);

	ifstream in(fileEmpName, ios::binary);
	employee* temp = new employee[100];
	int size = 0;
	while (in.peek() != -1)
	{
		employee k;
		in.read((char*)&k, sizeof(employee));
		temp[size++] = k;
	}
	in.close();

	ofstream out(fileReportName);

	out << "Report about file \"" << fileEmpName << "\":\n";
	out << "EmpNum !! EmpName !! EmpHours !! EmpPayment" << "\n";

	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			out << temp[i].num << "  !!  " << temp[i].name
				<< "  !!  " << temp[i].hours
				<< "  !!  " << temp[i].hours * payment_for_hour
				<< endl;
		}
	}
	else
	{
		out << "-empty-\n";
	}

	out.close();

	return 1;
}