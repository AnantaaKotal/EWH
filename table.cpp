#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

#include "column.cpp"

using namespace std;

const int KEY_SIZE = 4;
const int STRING_SIZE =64;
//generates 4 random keys
int* gen_Key(){
	int * key= new int[KEY_SIZE];	
	for(int j=0;j<KEY_SIZE;j++){
			int z=int (rand()%STRING_SIZE); 
			key[j]=z;
	};
	return key;		
}

//get bits from the positions in string as indicated by key
int hashf(string bin, int key[4]){
	string s;
	int x;
	for(int i=0;i<KEY_SIZE;i++){
		int z = key[i];
		s+=bin[z];
	}
	x=stoi(s);
	return x;
}
const int COL_NUM = 8;
class table {
public:
	      
	Column *column;
	
public:
     	table() {
			column = new Column[COL_NUM]; 
			//generate key for each table
			srand((unsigned)time(0));
			for(int i=0;i<COL_NUM;i++){
				column[i].key=gen_Key();
			};
     	 };
	
	//generates hashtable for each key
	void InsertInTable(string bin, int index){
		for (int i=0;i<COL_NUM;i++){
			int *key;
			key=column[i].getKey();
			int hvalue=hashf(bin,key);
			column[i].put(hvalue,index);
			//cout<<"column"<<i<<"\n";
		};
	};
	
};






