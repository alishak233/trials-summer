//UWYO COSC 2030
//Lab 3 - Recursion
//Written by Danny Radosevich (9-11-19), Edited by Russell Todd (1-30-2024)

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//functions
/*
 For lab you will write the functions:
 findBinaryNotation
 isPalindrome
 recurSummation
 arrRev
*/

/*DO NOT CHANGE MAIN OR THE FUNCTION DEFINITIONS*/
string findBinaryNotation(int num);
bool isPalindrome(string palin);
int recurSummation(int bound);
void arrRev(char (&arr)[26], int low, int high);
string pad(string toPad);

int main()
{
  /*DO NOT CHANGE MAIN OR THE FUNCTION DEFINITIONS*/

  //variable declarations for the isPalindrome
  string palOne = "ppwtrrdooffffsmppnnvveeleewaszzpttmmrnhhnnmxbbvttauummkkbbvvjccjvvbbkkmmuuattvbbxmnnhhnrmmttpzzsaweeleevvnnppmsffffoodrrtwpp";
  string palTwo = "ffpmzaboodppvvvvwprryxzlluueffgghhdhehhdhgfjffeuullzxxyyymrpwwvwvpddoogbazznemsppf";
  string palThr = "tkkbbsbbgzaafwwhenttddccnnccbbelyyjjffkkjwewwjjkfjyleebcnnccdtnnehewwfgazgbsbkkktt";
  string palFou = "vjjuuqsvxxmfhwlluujjcjjffssggyxxaazppllysslxxoyttlllkaajxqqhhphhqqxjaaklllttyoxxlssyllppzaaxxyggssffjjcjjuullwhfmxxvsquujjv";
  string palFiv = "nkkgggnnghhdppccebbrrccceevvjjxxjdffyykkfejjgggkvyycssuubrqiistsiiqrbuusscyyvkgggjjefkkyyffdjxxjjvveecccrrbbeccppdhhgnngggkkn";
  string palSix = "ffkkrmrzzqggdkkddzkeemmttvtthsscmqqfcggggqqccccqiggggccfqjmcsshttvvtmmekzdkkddggqzzbvtrrmmrkff";

  //array for the reverse
  char alph[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  //checking your findBinaryNotation
  (pad(findBinaryNotation(1))=="00000001")?(cout<<"You matched 00000001 correctly for 1"<<endl):(cout<<"You didn't match 00000001 correctly for 1"<<endl);
  (pad(findBinaryNotation(15))=="00001111")?(cout<<"You matched 00001111 correctly for 15"<<endl):(cout<<"You didn't match 00001111 correctly for 15"<<endl);
  (pad(findBinaryNotation(72))=="01001000")?(cout<<"You matched 01001000 correctly for 72"<<endl):(cout<<"You didn't match 01001000 correctly for 72"<<endl);
  (pad(findBinaryNotation(91))=="01011011")?(cout<<"You matched 01011011 correctly for 91"<<endl):(cout<<"You didn't match 01011011 correctly for 91"<<endl);
  cout<<"--------------------------------------------------------------------"<<endl;

  //Checking your isPalindrome
  cout<<"Checking palOne: ";
  cout<<"Your function says that palOne ";
  (isPalindrome(palOne))?(cout<<"is a palindrome. Correct!"<<endl):(cout<<"isn't a palindrome. Incorrect."<<endl);
  cout<<"Checking palTwo: ";
  cout<<"Your function says that palTwo ";
  (isPalindrome(palTwo))?(cout<<"is a palindrome. Incorrect."<<endl):(cout<<"isn't a palindrome. Correct!"<<endl);
  cout<<"Checking palThree: ";
  cout<<"Your function says that palThree ";
  (isPalindrome(palThr))?(cout<<"is a palindrome. Incorrect."<<endl):(cout<<"isn't a palindrome. Correct!"<<endl);
  cout<<"Checking palFour: ";
  cout<<"Your function says that palFour ";
  (isPalindrome(palFou))?(cout<<"is a palindrome. Correct!"<<endl):(cout<<"isn't a palindrome. Incorrect."<<endl);
  cout<<"Checking palFive: ";
  cout<<"Your function says that palFive ";
  (isPalindrome(palFiv))?(cout<<"is a palindrome. Correct!"<<endl):(cout<<"isn't a palindrome. Incorrect."<<endl);
  cout<<"Checking palSix: ";
  cout<<"Your function says that palSix ";
  (isPalindrome(palSix))?(cout<<"is a palindrome. Incorrect."<<endl):(cout<<"isn't a palindrome. Correct!"<<endl);
  cout<<"--------------------------------------------------------------------"<<endl;

  //checking recurSummation
  cout<<"Your summation for 0-6 is ";
  (recurSummation(6)==21)?(cout<<recurSummation(6)<<", Correct"<<endl):(cout<<recurSummation(21)<<", incorrect"<<endl);
  cout<<"Your summation for 0-47 is ";
  (recurSummation(47)==1128)?(cout<<recurSummation(47)<<", Correct"<<endl):(cout<<recurSummation(47)<<", incorrect"<<endl);
  cout<<"Your summation for 0-100 is ";
  (recurSummation(100)==5050)?(cout<<recurSummation(100)<<", Correct"<<endl):(cout<<recurSummation(100)<<", incorrect"<<endl);
  cout<<"Your summation for 0-500 is ";
  (recurSummation(500)==125250)?(cout<<recurSummation(500)<<", Correct"<<endl):(cout<<recurSummation(500)<<", incorrect"<<endl);
  cout<<"--------------------------------------------------------------------"<<endl;

  //checking your arrRev
  arrRev(alph,0,25);
  cout<<"Here is your reversed array";
  for(int i = 0; i< 26; i++)
  {
    if(i%5==0) cout<<endl;
    cout<<alph[i]<<", ";
  }
  cout<<endl;

}

//This function will return the binary notation of a supplied integer
/*
Supply the decimal number.
Divide the number by 2.
Make the remainder the rightmost number of the string.
Divide the result of the division by 2 and again concatenate it on to the string, building from the right to left.
Continue dividing and concatenating remainders until the result of the division is 0.
The most significant bit (MSB) is left side of the string and the least significant bit (LSB) is the right.
Return the series of 1s and 0s on the right from the bottom up. This is the binary equivalent of the decimal number.
You do not need to pad this with 0s as this is done for you.
*/
string  findBinaryNotation(int num)
{
// divide num by 2 
// if the remainder is 1 then create a string 
string binary = "";
while (num != 0){
    int remainder = num % 2;
    binary = to_string(remainder) + binary ;
    num = num/2;
}
return binary;
}
//This function will return whether a string is a palindrome or not
/*
Starting with the base string check if the first and last characters match.
Recursively call the function on a substring without the first and last character if they match
If the characters do not match, return false.
Make sure you account for odd number strings, and when you are finished Checking
Return true when you get to the last 1 || 2 matching characters
*/
bool isPalindrome(string palin){
 int len = palin.length();
 if (len<=1){
    return true;
 }
 else if (palin[0] == palin[len - 1]){
   return isPalindrome(palin.substr(1,len-2));
 }
 else{
    return false;
 }
}

//This will form the summation of 0 to the supplied bound
/*
Starting with the bound work backwards towards zero
Recursively call the function on bound-1 and sum each result
Make sure you have an exit condition for the function
*/
int recurSummation(int bound)
{
if (bound == 0){
    return 0;
}
return bound + recurSummation(bound-1);

}

//This function will recursively swap an array until it has reversed its order
/*
Starting with the outer edges, recursively call the function to swap those elements then proceed to the next inner elements
Move the low, high variables on each call
Check for when those variables cross paths/collide to exit the recursion
*/
void arrRev(char (&arr)[26], int low, int high)
{
 if (low < high){
    swap(arr[low], arr[high]);
    arrRev(arr, low + 1, high - 1);
 }

}

//Don't change this. This function simply pads the results of the findBinaryNotation to 8 characters so that you don't have to.
string pad(string toPad)
{
  if(toPad.length()>=8)
  {
    return toPad;
  }
  else
  {
    toPad.insert(toPad.begin(),8-toPad.length(),'0');
    return toPad;
  }
}