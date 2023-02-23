// Sean McCulloch
// CS210: Lab2, Program 2
// Implementation of the towers of Hanoi.
// A graphical set of towers can be found at
// http://www.mathsisfun.com/games/towerofhanoi.html

#include <iostream>

using namespace std; //introduces namespace std

int num_calls; // a global counter


//Recursive Towers of Hanoi solution.  Just prints to the screen the discs 
// you should move
void Hanoi(int num_discs, char source, char dest, char spare){
	num_calls++;
	if(num_discs == 1)
		cout << "Move from " << source << " to " << dest << endl;
	else{
		Hanoi(num_discs-1,source,spare,dest);
		cout << "Move from " << source << " to " << dest << endl;
		Hanoi(num_discs-1,spare,dest,source);
	}
}
int main ( void )
{
	num_calls = 0;
	
	cout << "What number would you like Hanoi solution to? " << endl;
	int num;
	cin >> num;
	
	Hanoi(num,'A','B','C');
	cout << "There were " << num_calls << " function calls" << endl;
	
	return 0;
}
