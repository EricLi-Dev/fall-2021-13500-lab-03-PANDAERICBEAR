/*

Author: Eric Li

Course: CSCI-135

Instructor: Zamansky

Assignment: Lab 3

Purpose:
Task A gets the east storage space on a specific date.
Task B gets the minimum and maximum east storage space.
Task C compares the East and West basin storage on a given date, and returns which one was larger.
Task D returns the reverse order of a given range of dates and their storage spaces.
*/
#include <iostream>
#include <string>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  using namespace std;
  //Part A
  cout << "--------------------------Task A--------------------------" << endl;
  cout << "Test 1: (09/13/2018)\n" << get_east_storage("09/13/2018") << " billion gallons" << endl;
  cout << "Test 2: (05/29/2018)\n" << get_east_storage("05/29/2018") << " billion gallons" << endl;
  cout << endl;

  //Part B
  cout << "--------------------------Task B--------------------------" << endl;
  cout << "The minimum storage is: " << get_min_east() << " billion gallons" << endl;
  cout << "The maximum storage is: " << get_max_east() << " billion gallons" << endl;
  cout << endl;
  //Part C
  cout << "--------------------------Task C--------------------------" << endl;
  cout << "Test 1: (07/13/2018)\n" << compare_basins("07/13/2018") << endl;
  cout << "Test 2: (05/29/2018)\n" << compare_basins("05/29/2018") << endl;
  cout << endl;

  //Part D
  cout << "--------------------------Task D--------------------------" << endl;
  cout << "Test 1: (09/13/2018 - 09/17/2018)\n";
  reverse_order("09/13/2018", "09/17/2018");
  cout << "Test 2: (05/29/2018 - 06/02/2018)\n";
  reverse_order("05/29/2018", "06/02/2018");
  return 0;
}
