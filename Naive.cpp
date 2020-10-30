#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <bits/stdc++.h> 

using namespace std;

int main(){
	
	void search(char* pat, char* str);									   
    char temporary[100];//create temporary array
	char *str = new char[100000000]; //dynamically create 100 million array   
    string line;
    int i,space,Line,a;
    ifstream file("pi.txt");//open file										
	  
        while (getline(file,line)){		    
            Line++;//count line from the beging of the file
            strcpy(temporary, line.c_str());//copy line to temporary array

	        if(line.size()!=0 && Line>19){//skipping above lines in pi file		
      	        if(Line==21){      	
      		        space=0;
      		            for(a=0; a<line.size(); a++){
      			    if(temporary[a]==' '){
      				space++;
				  }
				if(space==2 && temporary[a]!=' '){				
					str[i]= temporary[a];                       //copy temporary array to str array
					i++;
				}
			  }
		  }
		  else{
		  	space=0;
			a=0;
		  	while(space<=4){
		  		if(temporary[a]!=' '){
		  			str[i]=temporary[a];                        //copy temporary array to str array
		  			i++;
					a++;
				  }
				  else{
				  	space++;
				  	a++;
				  }
			  }
		    }
	    }    
    }        
        char pat[] = "970618"; //pattern has to search
        search(pat, str);// function call 
        file.close();// close file
}

void search(char* pat, char* str){
    int m = strlen(pat); //get pattern length
    int n = strlen(str); //get text length
    int times;
    string array1="Naive Pattern Searching Algorithm";
    string array2="Birthday: 970618";
    fstream myfile;
    myfile.open("results.txt",ios::out | ios::app);
    myfile<<endl;
    myfile<<array1<<endl;//write to results file
    myfile<<array2<<endl;
    
    for (int i = 0; i <= n - m; i++) { //search for pattern
        int j; 
  
        for (j = 0; j < m; j++){
        	 if (str[i + j] != pat[j]){
            	break; 
			}
		}                            
        if (j == m){
        	myfile<<i<<endl;//write indexes to the results file
        	times++;//count times
		}            
    } 
        cout<<pat<<" pattern found in "<<times<<" times"<<endl;
        cout<<"Indexes are successfully write to the file"<<endl;
        myfile.close();//close file
}
