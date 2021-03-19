/*
---------------------------------------------------
---------------------------------------------------
----This code was written on Dev-C++ 5.11----------
---------------------------------------------------
---------------------------------------------------
*/

#include<stdio.h>
int stringLen(char *str){ // calculate string length
	int i;
	for(i = 0; str[i]!=NULL; i++);
	return i;
}


int searchInFile(FILE *fp, char*str){
	char fChar; // store characters from file
	int index = 0;//string index
	
	while(fChar != EOF){
		fChar = getc(fp); // read a character from file
		if(str[index] == fChar){ // character match
			
			index++;
			if(index == stringLen(str)){
				return 1; // means string match
			}
		}	
		else{
			index = 0;
		}
	}
	return 0; // means string not match
}

int main() {

	FILE *fp = malloc(1*sizeof(fp));// point file pointer
	char fName[100] = {0}; // File name
	char subStr[100];
	
	//take input file path plus name
	printf("\nEnter file name with path : ");
	gets(fName);
	
	fp = fopen(fName , "r"); // open file in read mode
	
	if (fp != NULL ) {// check is file open
		//substring that you wan'na search
		printf("\nstring that you want to search from file : ");
		gets(subStr);
		
		if(searchInFile(fp,subStr)){ // is string found
			printf("\nSub string present :)");	
		}
		else{
			printf("\nSub string not present :(");
		}
	}
	else {
		printf("\nFile not found :(");
	}

	return 0;
}
