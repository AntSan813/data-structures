#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node{
  private:
    string course;
    bool m;
    int outdegree; //#of nodes this node is pointing to
    int out_list[500]; //list of nodes this node is pointing to

    int indegree; //how many are pointing to this node/vertice
    int in_list[500]; //keep track of those nodes pointing toward this node

  public:
    //default constructor
    Node(){
      outdegree = 0;
      indegree = 0;
      course = "FFFF";
      m = false;
    }

    //constructor that allows you to pass in course
    Node(string c){
      course = c;
      outdegree = 0;
      indegree = 0;
      m = false;
    }

    //check if this node is marked
    bool is_marked(){
      return m;
    }

    //update mark
    void mark(){
      m = true;
    }

    //insert into the indegree list
    void insert_in_list(int key){
      in_list[indegree] = key;
      indegree++;
    }

    //get list of keys that are pointing to this node
    int* get_in_list(){
      return in_list;
    }

    //get indegree
    int get_indegree(){
      return indegree;
    }

    //update indegree
    void set_indegree(int i){
      indegree = i;
    }

    //check if empty
    bool empty(){
      if(course == "FFFF"){
        return true;
      }
      else{
        return false;
      }
    }

    //insert into the outdegree list
    void insert_out_list(int key){
      out_list[outdegree] = key;
      outdegree++;
    }

    //get list of keys that this node is pointing to
    int* get_out_list(){
      return out_list;
    }

    //update outdegree
    void set_outdegree(int x){
      outdegree = x;
    }

    //get outdegree
    int get_outdegree(){
      return outdegree;
    }

    //set course
    void set_course(string c){
      course = c;
    }

    //get course
    string get_course(){
      return course;
    }
};

#endif
