#include <stdio.h>   /* printf, scanf, puts, NULL */
#include <stdlib.h>  /* srand, rand */
#include <iostream>  /* cout, cin*/
#include <string>    /* string*/
using namespace std; /* getline*/

// List partaining to different modes for the simulation (undecisive, positive, negative)
string unclear[10] = {"\n~Beats me", "\n~I am not sure","\n~Let me think about it","\n~Why are you asking me",
"\n~Dunno","\n~Let me sleep on it","\n~Try again","\n~This doesn't sound like it concerns me",
"\n~Type it louder, I could not hear you","\n~What"};

string positive[7] = {"\n~You got this!", "\n~Do not let anything keep you down","\n~I believe in you",
"\n~Someone like you could never fail","\n~You are in control of your life","\n~You can handle anything",
"\n~Winning does not always mean being first. Winning means you are doing better than you have done before. \n~Bonnie Blair"};

string negative[10] = {"\n~Give up", "\n~You will never win","\n~You should stop trying",
"\n~I do not think you can do it either","\n~Please stop asking","\n~You type worst than you look",
"\n~Just stop","\n~I could pretend that I care but I do not","\n~I lost interest in what you were saying",
"\n~Shhhhhhh"};

// funtion to provide uncertain answers
void unclear_func() {

  // Set the variable type
  int iSecret;

  // Generate secret number between 1-10
  iSecret = rand() % 10;

  // Set iGuess to a string
  string iGuess;

  // Start the simulation
  do {
    cout << "\n\n(0 to end)WHAT DO YOU NEED ADVICE ON: ";

    // Take in the response from the user (it doesn't do anyhting with it unless they type '0')
    getline (cin, iGuess);

    // Only print the response if the user did not type '0'
    while (iGuess!="0"){
      cout << unclear[iSecret];
      break;
    } 

    // Generate a new random number before it grabs the users next input
    iSecret = rand() % 10;

  // end the simulation if a zero is inputed
  } while (iGuess!="0");
}

void good_func() {

  int iSecret;

  iSecret = rand() % 7;
  string iGuess;
  do {
    
    cout << "\n\n(0 to end)WHAT DO YOU NEED ADVICE ON: ";
    getline (cin, iGuess);

    while (iGuess!="0"){

      cout << positive[iSecret];

      break;
    } 
    iSecret = rand() % 7;

  } while (iGuess!="0");
}

void bad_func() {

  int iSecret;
   
  iSecret = rand() % 10;
  string iGuess;

  do {
    
    cout << "\n\n(0 to end)WHAT DO YOU NEED ADVICE ON: ";
    getline (cin, iGuess);

    while (iGuess!="0"){

      cout << negative[iSecret];

      break;
    } 
    iSecret = rand() % 10;

  } while (iGuess!="0");
}

int main ()
{
  // Set the variable type for user input
  int adv_type;

  // Ask the user for type of response
  cout << "1 for Possitive responses\n2 for Negative responses\n3 for Unceartain responses: ";

  // Grab the users input
  cin >> adv_type;

  // Call the functions here
  if (adv_type == 1) good_func();
  if (adv_type == 2) bad_func();
  if (adv_type == 3) unclear_func();
  return 0;
}