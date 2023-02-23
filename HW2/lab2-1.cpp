// Sean McCulloch
// CS210: Lab2, Program 1
// This demonstrates a simple recursive function

#include <iostream>

using namespace std; //introduces namespace std

int num_calls; // a global counter


//Recursive factorial function.  Returns n! by calling fact on smaller 
// versions until the base case (n<=1) is reached
//Pre: n is an integer
//Post: Returns n!  If n <=1, returns 1.
int fact(int n){
	num_calls++;  // update the count of the number of recursive calls
	
	if(n<=1) // the base case
		return 1;
	else{ // the recursive case
	   int result = n*fact(n-1);
	   return result;
        }

}
int main ( void )
{
	num_calls = 0;
	
	cout << "What number would you like the factorial of? " << endl;
	int num;
	cin >> num;
	
	cout << num << "! = " << fact(num) << endl;
	cout << "There were " << num_calls << " function calls" << endl;
	
	return 0;
}
