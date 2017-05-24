#include <iostream>
#include <string>
#include "Graph.h"
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
  Graph g;
  string temp, main;
  int iter = 0;
  bool done;
  ifstream data;

  data.open("data.dat");
  if(!data.is_open()){ //make sure it opened
    cout << "ERROR: FILE DID NOT OPEN" << endl;
    return 0;
  }

  cout << "-----INSERT DATA INTO GRAPH-----" <<  endl;
  data >> temp; //prime read
  while(!data.eof()){
    cout << "Inserting Main Course: " << temp << endl;
    g.insert_first(temp);
    main = temp;
    temp.erase(temp.begin(), temp.end()); //delete temporary c-string
    data >> temp; //read in next word
    while(temp != "#"){
      cout << "Inserting Prerequisite: " << temp << endl;
      g.insert_rest(main, temp);
      temp.erase(temp.begin(), temp.end()); //delete temporary c-string
      data >> temp;
    }
    data >> temp;
    cout << endl;
  }

  cout << "\n-----DISPLAY DETAILS OF NEWLY FORMED GRAPH-----\n";
  g.get_details();

  cout << "\n-----OUTPUT WHAT IS IN GRAPH USING A TOPOLOGICAL SORT METHOD-----\n";
  g.topo_sort();

  data.close();

//uncomment following to see prerequisites for a specific course
/*
  string choice;
  cout << "Which courses' prerequisites would you like to see? ";
  cin >> choice;
  g.search(choice);
  if(found == false){
    cout << "Invalid input!" << endl;
  }
*/
  return 0;
}
