/*
---------------------------------------------------
---------------------------------------------------
----This code was written on visual studio 2012----
----Version number = 11.0 -------------------------
---------------------------------------------------
---------------------------------------------------
---------------------------------------------------
*/
#include<conio.h>
#include<stdio.h>
int stringLen(char *str){ // calculate string length
	int i;
	for(i = 0; str[i]!=NULL; i++);
	return i;
}


int searchInFile(FILE *fp, char*str){
	char fChar = ' '; // store characters from file
	int index = 0;//string index
	
	while(fChar != EOF){

		if(str[index] == fChar){ // character match	
			index++;
			if(index == stringLen(str)){
				return 1; // means string match
			}
			fChar = getc(fp); 
		}
		else{
			index = 0;
			if(str[index] != fChar){
				fChar = getc(fp); // read a character from file
			}
		}
	}
	return 0; // means string not match
}

int main() {

	FILE *fp;// point file pointer
	char fName[100] = {0}; // File name
	char subStr[100];
	int count = 0; // count how many time s string match
	
	//take input file path plus name
	printf("\nEnter file name with path : ");
	gets_s(fName,100);
	
	fopen_s(&fp,fName , "r"); // open file in read mode
	
	if (fp != NULL ) {// check is file open
		//substring that you wan'na search
		printf("\nstring that you want to search from file : ");
		gets_s(subStr,100);
		
		while(searchInFile(fp,subStr)){ // is string found or untill file not read completely
			count++;
		}
		printf("\nNumber of occurrences of substring : %d",count);
	}
	else {
		printf("\nFile not found :(");
	}
	fclose(fp);
	_getch();
	return 0;
}
