#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
class Node{
    int value;
    
    Node* link;
    friend class Linklist;
};
class Linklist{
    
public:
    Node* start,*last;
    int score;
public :
    Linklist(){
        start=NULL;
        last=NULL;
	score=0;
};
public :
   
    void createEntry(int value){
    		Node* ptrsub;
    		ptrsub=new Node;
		
    		if(ptrsub==NULL){
        		printf("Not enough memory");
                return;
            	}
            	ptrsub->value=value;
		ptrsub->link=NULL;
    		if(start!=NULL){
        		last->link=ptrsub;
    		}else{
        		start=ptrsub;
    		}
    		last=ptrsub;
	}
    void setScore(int s){
		score=s;
		//cout<<"\nSet\n";
	}
   
    void changeIndex(int *index){
          Node* temp;
          temp=start;
          while(temp!=NULL){
               int k = temp->value;
		index[k] += score;
		temp = temp->link;
            }
	    
   }
    
};




