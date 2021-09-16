// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

#include "reservoir.h"

double get_east_storage(std::string date){
  using namespace std;
  string fileDate;
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

  //Reading line-by-line
  while(fin >> fileDate >> eastSt >> eastEl >> westSt >> westEl) {
   // this loop reads the file line-by-line
   // extracting 5 values on each iteration

   fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                             //ignorring the remaining columns

   // for example, to print the date and East basin storage:
   if (fileDate == date){
      return eastSt;
   }

  }
  //cout << "" << endl;
  fin.close();
  return 0.0;
 }

double get_min_east(){
  using namespace std;
   //initializing variables
   string date;
   double eastSt;
   double eastEl;
   double westSt;
   double westEl;

   double minStorage;
   //Opening and reading tsv file
   ifstream fin("Current_Reservoir_Levels.tsv");
   if (fin.fail()) {
     cerr << "File cannot be opened for reading." << endl;
     exit(1); // exit if failed to open the file
    }

  //Skipping header line
  string junk;        // new string variable
  getline(fin, junk); // read one line from the file

  int i = 0; //To check for first iteration

  //Reading line-by-line
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
   // this loop reads the file line-by-line
   // extracting 5 values on each iteration

   fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                             //ignorring the remaining columns

   if (i == 0){ //if first iteration, initialize both variables
     minStorage = eastSt;
     i++; //increment i
   }
   //all other iterations
   if (eastSt < minStorage){
     minStorage = eastSt;
   }

  }

  fin.close();
  return minStorage;

}

double get_max_east(){
  using namespace std;
   //initializing variables
   string date;
   double eastSt;
   double eastEl;
   double westSt;
   double westEl;

   double maxStorage;

   //Opening and reading tsv file
   ifstream fin("Current_Reservoir_Levels.tsv");
   if (fin.fail()) {
     cerr << "File cannot be opened for reading." << endl;
     exit(1); // exit if failed to open the file
    }

    //Skipping header line
    string junk;        // new string variable
    getline(fin, junk); // read one line from the file

    int i = 0; //To check for first iteration
    //Reading line-by-line
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
     // this loop reads the file line-by-line
     // extracting 5 values on each iteration

     fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                               //ignorring the remaining columns

     if (i == 0){ //if first iteration, initialize both variables
       maxStorage = eastSt;
       i++; //increment i
     }

     //all other iterations
     if (eastSt > maxStorage){
       maxStorage = eastSt;
     }

    }

   fin.close();
   return maxStorage;
 }

std::string compare_basins(std::string date){
  using namespace std;
   //initializing variables
   string fileDate;
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
    //Reading line-by-line
    while(fin >> fileDate >> eastSt >> eastEl >> westSt >> westEl) {
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration

    fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                              //ignorring the remaining columns

    if (date == fileDate){
      if (eastEl > westEl){
        return "East";
      } else if (westEl > eastEl){
        return "West";
      } else {
        return "Equal";
      }
    }

    // if (flagger == 1){
    //   if (eastEl > westEl){
    //     cout << date << " East" << endl;
    //   } else if (westEl > eastEl){
    //     cout << date << " West" << endl;
    //   } else {
    //     cout << date << " Equal" << endl;
    //   }
    //
    //   if (date == secondDate){
    //     flagger = 0; //de-trigger flag
    //   }
    // }

    }

    fin.close();
    return "";
 }
