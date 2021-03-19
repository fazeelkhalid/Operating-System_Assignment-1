/*
---------------------------------------------------
---------------------------------------------------
----This code was written on Dev-C++ 5.11----------
---------------------------------------------------
---------------------------------------------------
*/


#include<stdio.h>

void takeWord(FILE *fp, char *fWord){ // take just one word from file
	int index = 0;
	char fChar = fgetc(fp);//store character from file line by line
	
	while(fChar!=' ' && fChar != '\n' && fChar != EOF){
		fWord[index] = fChar;
		fChar= fgetc(fp); // read char from file
		index++;
	}
	fWord[index] = '\0'; // terminate string
}

int checkVowel(char t) { // check is given char is a vowel or not
	if (t == 'a' || t == 'A' || t == 'e' || t == 'E' || t == 'i' || t == 'I' || t =='o' || t=='O' || t == 'u' || t == 'U'){
		return 1;
	}
	else{
		return 0;
	}
}

void copyString(char *str1, char *str2){ //copy string of str2 into str1
	int index = 0;
	while(*str2 != '\0'){
		str1[index] = *str2;
		index++;
		str2++;
	}
	str1[index] = '\0';
}

int stringSize(char* str){ // calculate string size
	int size = 0;
	while(str[size]!='\0'){
		size++;
	}
	return size;
}

void removeVowels(char * str){ // remove vowel from a string
	int index = 0;
	char temp[36];
	int tempIndex = 0;

	while(str[index] !='\0'){ // copy actual array into temp accept vowels
		if (checkVowel(str[index]) == 0) {     // If not a vowel
			temp[tempIndex] = str[index];
			tempIndex++;
		}
		index++;
	}
	temp[tempIndex] = '\0' ;
	copyString(str,temp); // copy temp array in actual array
}

void reverseString(char*str){ // reverse string
	int size = stringSize(str) - 1; // return string size
	char temp[36];
	int tempIndex = 0;
	while(size != -1){ // reverse string 
		temp[tempIndex] = str[size];
		tempIndex++;
		size--;
	}
	temp[tempIndex] = '\0';
	copyString(str, temp);
}

void reversesNonVowelChar(char *str){ // reverses all the characters of words that are not vowels
	char temp[36];
	int tempIndex = 0; // control temp array index
	int index = 0;//control actual arrray index
	int strSize = stringSize(str);

	copyString(temp,str); // copy actual array in tem array
	removeVowels(temp); // remove vowels from temp array
	reverseString(temp); // reverse temp array

	while(index != strSize){ // overright non vowels alphabet in actual array
		if(checkVowel(str[index]) == 0){ // if char are not vowel then overRight 
			str[index] = temp[tempIndex];
			tempIndex++;
		}
		index++;
	}

}

void reverseCharacter(FILE *fp, char *fileName){ // reverse character of whole file
	FILE *fTemp = malloc(1*sizeof(fTemp));// point file pointer
	char str[36];//store file words line one by one;
	char fChar;
	
	fTemp = fopen("temp.txt","w");
	
	while(!feof(fp)){
		takeWord(fp,str);
		reversesNonVowelChar(str);
		fputs(str,fTemp);//put string in temp file for further processing
		fputs(" ",fTemp); // put space in file
	}
	
	fclose(fTemp); // close temp file
	fclose(fp); // close actual file;
	
	//now copy data from temp file to actual file
	fp = fopen(fileName,"w");
	fTemp = fopen("temp.txt","r");

	fChar = ' ';// reset variable
	while(fChar!=EOF){
		fChar = getc(fTemp);
		if(fChar!=EOF){ // not enter EOf character in temp file
			fputc(fChar,fp);
		}
	}
	fclose(fp);
	fclose(fTemp);
	remove("temp.txt"); 	
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
		reverseCharacter(fp, fName);
	}
	else {
		printf("\nFile not found :(");
	}

	return 0;
}
