#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

using namespace std;

void reverse_order(string date1, string date2){
  //initializing variables
  string date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;

  //Opening and reading tsv file
  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
   }

 //Skipping header line
 string junk;        // new string variable
 getline(fin, junk); // read one line from the file

 int flagger = 0;
 int counter = 0;
 string d[365];
 double elevation[365];
 //Reading line-by-line
 while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
  // this loop reads the file line-by-line
  // extracting 5 values on each iteration

  fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                            //ignorring the remaining columns

  if (date == date1){
    flagger = 1; //trigger flag
  }

  if (flagger == 1){
    // cout << date << " ";
    // cout << westEl;
    // cout << endl;
    d[counter] = date;
    elevation[counter] = westEl;
    counter += 1;

    if (date == date2){
      flagger = 0; //de-trigger flag
    }
  }

 }

 fin.close();

  // cout << counter;
  //int j = 0;
  for(int i = counter - 1; i >= 0; i--){
    cout << d[i] << " " << elevation[i] << endl;
    //j++;
  }

}
