#include<stdio.h>
int stringLen(char *str){ // calculate string length
	int i;
	for(i = 0; str[i]!='\0'; i++);
	return i;
}

int stringSize(char* str){ // calculate string size
	int size = 0;
	while(str[size]!='\0'){
		size++;
	}
	return size;
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
	fgets(fName,100,stdin);
	
	int size = stringSize(fName);
	fName[size - 1] = '\0'; 
	
	fp = fopen(fName , "r"); // open file in read mode
	
	if (fp != NULL ) {// check is file open
		//substring that you wan'na search
		printf("\nstring that you want to search from file : ");
		fgets(subStr,100,stdin);
		
		int size = stringSize(subStr);
		subStr[size - 1] = '\0'; 
		
		while(searchInFile(fp,subStr)){ // is string found or untill file not read completely
			count++;
		}
		printf("\nNumber of occurrences of substring : %d",count);
	}
	else {
		printf("\nFile not found :(");
	}
	fclose(fp);
	return 0;
}
