/*
  Copyright (c) 2019
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2019
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

int main(int argc, char** argv) {
    //plays the movie regularly
    if (argc == 2) {
      string file = argv[1];
      List<pair<int, string>>* list = loadMovie(file); //loads movie for playMovie
      playMovie(list);
      delete list;
    //plays the movie in reverse
    } if (argc == 3) {
      string reverse = argv[1];
      string file = argv[2];
      List<pair<int, string>>* list = loadMovie(file);
      List<pair<int, string>>* reverseList = new LinkedList<pair<int, string>>(); //creates a new list for the reverse list
      int size = list->getSize(); //initializes the size of the list
      for (int i = 0; i < size; i++) {
          pair <int, string> last = list->getLast(); //saves last value of original list
          reverseList->insertLast(last); //takes the value of the last node and puts in the first node of the new list
          list->removeLast(); //removes last node of original list
      }
      playMovie(reverseList);
      delete list;
      delete reverseList;
    } else {
      throw runtime_error("Invalid command-line arguments.");
    }
    return 0;
}
