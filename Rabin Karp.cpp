#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <bits/stdc++.h> 
#define noc 256 //noc is the number of characters in the input alphabet

using namespace std;

int main() {
	void search(char pat[], char str[], int q);
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
        int q = 101;
        search(pat, str, q);// function call         
        file.close();// close file  
}

void search(char pat[], char str[], int q)  
{  
    int m = strlen(pat);  //get the length of pattern
    int n = strlen(str);  //get the length of text
    int i,j;  
    int p = 0; // hash value for pattern  
    int t = 0; // hash value for txt  
    int h = 1; 
	int a=0; 
	string array1="Rabin-Karp Pattern Searching Algorithm";
	string array2="Birthday: 970618";
    fstream myfile;
    myfile.open("results.txt", ios::out | ios::app);
    myfile<<endl;
    myfile<<array1<<endl;//write to results file
    myfile<<array2<<endl;
     
    for (i = 0; i < m - 1; i++) // The value of h = [pow(d, M-1)%q]  
        h = (h * noc) % q;  

    for (i = 0; i < m; i++) //calculate hash value 
    {  
        p = (noc * p + pat[i]) % q;  
        t = (noc * t + str[i]) % q;  
    }  
    for (i = 0; i <= n - m; i++)  
    {  
        if ( p == t )  
        {              
            for (j = 0; j < m; j++)  //Check for characters one by one 
            {  
                if (str[i+j] != pat[j])  
                    break;  
            }  
            if (j == m){
            	myfile<<i<<endl;
            	a++;
			}                    
        }             
        if (i < n-m)  // Calculate hash value for next window of text 
        {  
            t = (noc*(t - str[i]*h) + str[i+m])%q;  
            if (t < 0)  //negative value of t convert into positive value
            t = (t + q);  
        }  
    }
	cout<<pat<<" pattern found in "<<a<<" times"<<endl;
    cout<<"Indexes are successfully write to the file"<<endl;
    myfile.close();//close file  
} 
