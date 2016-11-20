#include <iostream>
#include <string>

int hamming_distance(std::string& fs, std::string& ss){
    int hm_distance = 0;
    
    if((fs.length() == ss.length())){
      
      for(int i = 0; i < fs.length(); i++){
        if(!(fs[i] == ss[i])){
          hm_distance++;
        }
      }
      
    }else{
      hm_distance = -1;  
    }
    cout<<hm_distance<<"\n";
}


