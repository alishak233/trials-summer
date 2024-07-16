//UWYO COSC 2030
//Lab 4
//Written by Danny Radosevich
//8-4-19

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


//function declarations
string stringReverse(string toReverse);
bool parenCheck(string toCheck);

/*DO NOT CHANGE MAIN OR THE FUNCTION DECLARATIONS*/
int main()
{
  //paren strings
  string paren1 = "(()((((()()()((()(((()()()()(((()(()()()(())()())()()))))()()()))()))()())())())))";
  string paren2 = "()((((((()(((((()((()()()()()(()))))))))()))()(())(())(((((()()(())))(()()())(()))";
  string paren3 = "(()((()(()()(()(((((()()(()()()((((()()(()()))()))))()()())))))()()())()()))())())";
  string paren4 = "(()()(((()()(()(()()(()()()()()()(()(((((((((())())))))()))))()()))()())()()))()))";
  string paren5 = "((())";
  string paren6 = ")))(((";

  string rev1 = "sekopog";
  string rev2 = "racecar";
  string rev3 = "regnolsignirtssiht";
  string rev4 = "wonybnwodsihtevahyllufepohdluohssyuguoy";

  //Ignore this for now, these vectors are just part of the program
  vector<string> parens;
  parens.push_back(paren1);
  parens.push_back(paren2);
  parens.push_back(paren3);
  parens.push_back(paren4);
  parens.push_back(paren5);
  parens.push_back(paren6);

  vector<string> rever;
  rever.push_back(rev1);
  rever.push_back(rev2);
  rever.push_back(rev3);
  rever.push_back(rev4);
  
  //call the parenCheck
  for(int i=0; i<6; i++)
  {
    cout<<"Checking string"<<i+1<<endl;
    if(parenCheck(parens.at(i)))
    {
      cout<<"String"<<i+1<<" is good"<<endl<<endl;
    }
    else
    {
      cout<<"String"<<i+1<<" is bad"<<endl<<endl;
    }
  }

  //now to reverse some strings
  for(int i =0; i<4; i++)
  {
    cout<<"Reversing string"<<i+1<<endl;
    cout<<stringReverse(rever.at(i))<<endl<<endl;
  }
}

//This function takes a string and reverses it using a stack
//it returns the reversed string
string stringReverse(string toReverse)
{
  stack<char> reverse; //declare the stack
  string newString = "";
  
  for (char ch:toReverse) {
    reverse.push(ch);
  }
  while (!reverse.empty()){
    newString = newString + reverse.top();
    reverse.pop();
  }  

  return newString;
}

//this function uses a queue to check if a string of parens is properly matched
bool parenCheck(string toCheck)
{
  int matched = 0;
  queue<char> checker; //declare my queue
  for (char ch:toCheck){
    if (ch == '(' ){
      checker.push(ch);
      matched = matched + 1;
      }

    else if (ch == ')'){ 
      if (matched == 0){
      return false;
      }
      checker.push(ch);
      matched = matched - 1;
      }
  }
  return matched == 0;
}
