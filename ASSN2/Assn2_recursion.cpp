#include <iostream>
#include <vector>
#include <string>

using namespace std;

//1 
int Add_Between (const vector<int>& v)
  {
    int j=0;
    for (int i = 0; i < v.size(); i++)
    {
      j = j + v[i];
    }
    return j;
  }



//2
void Print_Divisors (int n, int max_factor)
{
  for(int i = 0; i < max_factor+1; i++)
  {
    if(n%i == 0)
    {
      cout << i;
    }
  }
}


//3
int Count_Less_Than(const vector<int> v, int key, int start)
{
  for(int i = start; i < v.size()-1; i++)
    if(v[i] < key)
      cout << v[i]; 
}


//4
void My_Substr(const string& s, int start, int end)
{
  for(int i = start; i < end+1; i++)
    cout << s[i];
}


//5
bool Is_Alphabetical(const string& s, int start)
{
  bool j = true;
  for(int i = start; i < s.size(); i++)
    if(s[i] < s[i+1])
      j = true;
    else
      j = false;
  return j;
}


int main()
{
  //Test for Function 1
  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  cout << Add_Between(v) << endl;


  //Test for Function 2
  int n = 30;
  int max_factor = 10;
  Print_Divisors(n, max_factor);

  //Test for Function 3
  cout << "Count_Less_Than: " << Count_Less_Than({1,2,3,4,5,6}, 5, 1);

  //Test for Function 4
  My_Substr("abcdefghi", 2, 6);

  //Test for Function 5
  cout << "Is_Alphabetical: " << Is_Alphabetical("abcdefg", 2);
  
}


HW2-Loop.txt
Displaying HW2-Recursion.txt.
