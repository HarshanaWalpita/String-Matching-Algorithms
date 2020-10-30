#include<iostream>
#include<fstream>
#include<sstream>
#include <limits.h>
#include<string>
#include <bits/stdc++.h> 
#define noc 256 //noc is the number of characters

using namespace std;

int main() {
    int max(int a, int b);
    void bad_char_heuristic(char *str, int size, int badchar[noc]); 
	void search(char* pat, char* str);									   
    char temporary[100];//create temporary array
	char *str = new char[100000000]; //dynamically create 100 million array   
    string line;
    int i,space,Line,y;
    ifstream file("pi.txt");//open file										
	  
        while (getline(file,line)){		    
            Line++;//count line from the beging of the file
            strcpy(temporary, line.c_str());//copy line to temporary array

	        if(line.size()!=0 && Line>19){//skipping above lines in pi file		
      	        if(Line==21){      	
      		        space=0;
      		            for(y=0; y<line.size(); y++){
      			    if(temporary[y]==' '){
      				space++;
				  }
				if(space==2 && temporary[y]!=' '){				
					str[i]= temporary[y];                       //copy temporary array to str array
					i++;
				}
			  }
		  }
		  else{
		  	space=0;
			y=0;
		  	while(space<=4){
		  		if(temporary[y]!=' '){
		  			str[i]=temporary[y];                        //copy temporary array to str array
		  			i++;
					y++;
				  }
				  else{
				  	space++;
				  	y++;
				  }
			  }
		    }
	    }    
    }        
        char pat[] = "970618"; //pattern has to search
        search(pat, str);// function call 
        file.close();// close file
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
void bad_char_heuristic(char *str, int size, int badchar[noc])//preprocessing function for bad character heuristic
{
    int i;     
    for (i = 0; i < noc; i++)//initialize all occurrences as -1
        badchar[i] = -1;
    for (i = 0; i < size; i++)//fill the actual value of last occurrence of a character
        badchar[(int) str[i]] = i;
}
 
void search(char *pat, char *str)
{
    int m = strlen(pat);//get length of pattern
    int n = strlen(str);//get length of tex
    int a; 
    int badchar[noc]; 
    bad_char_heuristic(pat, m, badchar);
    string array1="Boyer Moore Pattern Searching Algorithm";
    string array2="Birthday: 970618";
    fstream myfile;
    myfile.open("results.txt", ios::out | ios::app);
    myfile<<endl;
    myfile<<array1<<endl;//write to results file
    myfile<<array2<<endl;
 
    int s = 0; //s is shift of the pattern with respect to text
    while (s <= (n - m))
    {
        int j = m - 1; 
        while (j >= 0 && pat[j] == str[s + j])
            j--; 
        if (j < 0)
        {
            myfile<<s<<endl; 
            s += (s + m < n) ? m - badchar[str[s + m]] : 1;
            a++; 
        } 
        else
            s += max(1, j - badchar[str[s + j]]);
    }
    cout<<pat<<" pattern found in "<<a<<" times"<<endl;
    cout<<"Indexes are successfully write to the file"<<endl;
    myfile.close();//close file
}
