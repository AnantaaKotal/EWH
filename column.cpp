#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "linkedlist.cpp"
#include "convert.cpp"

class HashEntry {
public:
      Linklist M;
public:
      	void createEntry(int val){
		M.createEntry(val);
      	}
	
	void setScore(int score){
		M.setScore(score);
	};
	
	int score(){
		return M.score;
	};
 	
	void changeIndex(int *index){
		M.changeIndex(index);
	};
};

const int TABLE_SIZE = 16;
 
class Column {
public:
	int *key;
	HashEntry *row;
public:
      Column() {
            row = new HashEntry[TABLE_SIZE];
            key = new int[4];      
      }
      int* getKey(){
		return key;
      }
      
      void put(int value, int index) {
            	int i=convert(value);
	    	row[i].createEntry(index);
		//cout<<"row"<<i<<"\n";
      }     
 
      void setScore(int hvalue, int score){
		int i=convert(hvalue)%128;
     		row[i].setScore(score);
		//cout<<"Row"<<i<<"score="<<row[i].score();
       }
	
      
};

