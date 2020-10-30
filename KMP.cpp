#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <bits/stdc++.h> 

using namespace std;
void prefix_suffix_array(char* pat, int M, int* lps);//function to hold the longest prefix suffix values for pattern 

int main() {
	
	void prefix_suffix_array(char* pat, int M, int* lps);
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
 
void search(char* pat, char* str) 
{ 
    int m = strlen(pat); //get pattern length
    int n = strlen(str); //get text length
    int a;
    string array1="KMP Pattern Searching Algorithm";
    string array2="Birthday: 970618";
    fstream myfile;
    myfile.open("results.txt", ios::out | ios::app);
    myfile<<endl;
    myfile<<array1<<endl;//write to results file
    myfile<<array2<<endl;
	
    int pre_suf[m];//hold the longest prefix suffix value for pattern 

    prefix_suffix_array(pat, m, pre_suf); //calculate pre_suf array
  
    int i = 0;// index for text 
    int j = 0;// index for pattern
    while (i < n) { 
        if (pat[j] == str[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == m){ 
            myfile<<i-j<<endl;
            j = pre_suf[j - 1];
			a++; 
        } 

        else if (i < n && pat[j] != str[i]) { //mismatch after j match

            if (j != 0) 
                j = pre_suf[j - 1]; 
            else
                i = i + 1; 
        } 
    }
	cout<<pat<<" pattern found in "<<a<<" times"<<endl;
    cout<<"Indexes are successfully write to the file"<<endl;
    myfile.close();//close file
} 

void prefix_suffix_array(char* pat, int m, int* pre_suf) //fills pre_suf array
{ 
    
    int length = 0; // length of the previous longest prefix suffix 
  
    pre_suf[0] = 0; // pre_suf array 0 
  
    int i = 1; //calculate pre_suf[i]
    while (i < m) { 
        if (pat[i] == pat[length]) { 
            length++; 
            pre_suf[i] = length; 
            i++; 
        } 
        else // pat[i] != pat[length] 
        { 
 
            if (length != 0) { 
                length = pre_suf[length - 1]; 

            } 
            else // if (length == 0) 
            { 
                pre_suf[i] = 0; 
                i++; 
            } 
        } 
    } 
}
