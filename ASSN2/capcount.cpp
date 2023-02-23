#include <iostream>

using namespace std;

int counter = 0;
int j;
int j2;
char ch;
int Count_Caps(string a)
{
	for(int i = 0; i < a.size(); i++)
		ch = a.substr(i,1);
		ch = j;
		j2 = ch;
		if(j2 >= 65 & j <= 90)
			counter++;
		else
			continue;
	return counter;
}

int main()
{
	string x;
	cout << "Enter a string: ";
	cin >> x;
	
	cout << Count_Caps(x) << endl;
	
	return 0;
	
}
