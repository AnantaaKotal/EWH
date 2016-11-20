#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "table.cpp"
#include "ham_dist.cpp"
using namespace std;

const int ERROR = 1;
const int DATA_size = 1000;


string* generate_array(){
	srand((unsigned)time(0));
	string* arr = new string[DATA_size];	
	for(int j=0;j<DATA_size;j++){
		for(int i=0;i<STRING_SIZE;i++){		
			int z=int (rand()%2); 
			string s = to_string(z);
			arr[j]+=s;
		}
	};		

	
	return arr;
}


int main(){
	int* index = new int[DATA_size];
	
	for(int i=0;i<DATA_size;i++){
		index[i]=0;
	};
	//Create Table	
	table t;
	//Entering random Binary values for purpose of illustration
	string* arr = new string[DATA_size];
	arr = generate_array();
	for(int j=0;j<DATA_size;j++){
		t.InsertInTable(arr[j],j);;
	};
	
	string Query;
	cout<<"Enter binary fingerprint of length 64:\n";
	cin>>Query; 
	
	for(int i=0;i<COL_NUM;i++){
			int* z=new int[KEY_SIZE];
			z=t.column[i].getKey();
			//generate hash value for query
			int hquery=hashf(Query,z);
			int x=convert(hquery);
			
			//for r=0, add score(a0)=2
			t.column[i].row[x].setScore(2);

			//for r=1, add score(a1)=1
			int q;
			q = x+1;
			if (q>=0 && q<TABLE_SIZE)
				t.column[i].row[q].setScore(1);
			q = x+2;
			if (q>=0 && q<TABLE_SIZE)
				t.column[i].row[q].setScore(1);
			q = x+4;
			if (q>=0 && q<TABLE_SIZE)
				t.column[i].row[q].setScore(1);
			q = x+8;
			if (q>=0 && q<TABLE_SIZE)
				t.column[i].row[q].setScore(1);
			q = x-1;
			if (q>=0 && q<TABLE_SIZE)
				t.column[i].row[q].setScore(1);
			q = x-2;
			if (q>=0 && q<TABLE_SIZE)
				t.column[i].row[q].setScore(1);
			q = x-4;
			if (q>=0 && q<TABLE_SIZE)
				t.column[i].row[q].setScore(1);
			q = x-8;
			if (q>=0 && q<TABLE_SIZE)
				t.column[i].row[q].setScore(1);
			
			
	};
	
	//choosing the fingerprints whose score is greater than threshold(s0)=0
	for(int i=0;i<COL_NUM;i++){
			for (int j=0;j<TABLE_SIZE;j++){
				int x = t.column[i].row[j].score();
				if (x>0){
					t.column[i].row[j].changeIndex(index);
				};
			};
	};	
	
	//an exhaustive search upon chosen candidates
	int max = 0;
	int max_pos = 0;
	for(int i=0;i<DATA_size;i++){
		if (index[i]>max){ 
			max = index[i];
			max_pos = i;
		};
	};
	cout<<"\n---------------------------------------------------------------------------\n";
	cout<<Query;
	cout<<"\n---------------------------------------------------------------------------\n";
	cout<<max_pos<<":";
	cout<<arr[max_pos];
	cout<<"\n---------------------------------------------------------------------------\n";
	cout<<"Hamming Distance:";
	hamming_distance(arr[max_pos],Query);

	//for(int j=0;j<DATA_size;j++){
	//	cout<<j<<":";
	//	hamming_distance(arr[j],Query);
	//};
};
