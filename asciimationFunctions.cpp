/*
  Copyright (c) 2019
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2019
  CPSC 035: Data Structures and Algorithms
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

List<pair<int, string>>* loadMovie(string filename) {
    List<pair<int, string>>* list = new LinkedList<pair<int, string>>();
    ifstream myFile;
    string data;
    myFile.open(filename);
    getline(myFile, data);
    int count = 0;
    string frame = ""; //string accumulator
    pair <int, string> p1; //initialize a pair of int and string
    while (!myFile.eof()) {
      if (count == 0) {
        p1.first = stoi(data); //converts the string data to an integer, assign it to the first of p1
        getline(myFile,data);
        count++;
      } else {
        for (int i = 0; i < 13; i++) {
          frame += (data+"\n"); //accumulate the concatenation of the 13 lines of string to a frame
          getline(myFile, data);
        }
        p1.second = frame;
        frame = "";
        count = 0;
        list->insertLast(p1);
      }

    }
    return list;
}

void playMovie(List<pair<int, string>>* list) {
  int size = list->getSize(); //initialize the size of the list
  for (int i = 0; i < size; i++) {
    cout << list->getFirst().second << endl;
    usleep((1000000/15)*list->getFirst().first);
    system("clear");
    list->removeFirst();
  }
}
