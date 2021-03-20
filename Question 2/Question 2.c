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

void enterData(char*fileName){
	
	char data[100] = {0};//take data(name rollNumber and Email) from user
	FILE *fp;
	fopen_s(&fp,fileName,"a");
	
	printf("Enter student Name: ");
	gets_s(data,100);
	fputs("\nName : ",fp);
	fputs(data,fp); // write name in file

	printf("\nEnter student rollNumber: ");
	gets_s(data,100);
	fputs("\nRoll Number: ",fp);
	fputs(data,fp); // write rollNumber in file

	printf("Enter student Email: ");
	gets_s(data,100);
	fputs("\nEmail: ",fp);
	fputs(data,fp); // write rollNumber in file
	fputs("\n",fp);	
	fclose(fp);
}

int totalStudents(char*fileName){
	char fChar = ' ';// take character from file for further processing
	int size =0;// count total number of rows
	FILE *fp;
	fopen_s(&fp,fileName,"r");
	
	while(fChar != EOF){
		fChar = fgetc(fp);
		if(fChar == '\n'){
			size++;
		}
	}
	fclose(fp);
	size++;
	return(size/3);
}


void printString(char*str){ // print string on counsole
	int index = 0;
	printf("\n");
	while(str[index] !='\0'){
		printf("%C",str[index]);
		index++;
	}
}

void PrintStudentRecord(char*fileName){
	int studentNumber = -1; // store which student record user can see
	char fChar = ' ';// take character from file for further processing
	int size =0;// count total number of rows
	char data[100];//store student name,rollNumber and email from file
	FILE *fp;
	fopen_s(&fp,fileName,"r");
	
	while(studentNumber <0 || studentNumber >= totalStudents(fileName)){
		printf("Enter student number whose record you want to see: ");
		scanf_s("%d",&studentNumber);
	}
	
	//check which student record is required
	while(fChar != EOF && (size/3) != studentNumber){
		fChar = fgetc(fp);
		if(fChar == '\n'){
			size++;
		}
	}
	
	fgets(data,100,fp); // get student name from file
	printString(data); // print student name on counsole
	
	fgets(data,100,fp); // get student rollNumber from file
	printString(data); // print student rollNumber on counsole

	fgets(data,100,fp); // get student email from file
	printString(data); // print student email on counsole

	fclose(fp);
}

void deleteStudentRecord(char *fileName){
	char fChar = ' ';// take character from file for further processing
	int studentNumber = -1; // store which student record user can see
	int size =0;// count total number of rows
	char data[100];//store student name,rollNumber and email from file
	FILE *fp; // actual File
	FILE *fT; // temp File or empty File
	fopen_s(&fp,fileName,"r");
	fopen_s(&fT,"temp.txt","w");

	while(studentNumber <0 || studentNumber >= totalStudents(fileName)){
		printf("Enter student number whose record you want to delete: ");
		scanf_s("%d",&studentNumber);
	}

	while(fChar != EOF){ // untill file not null copy all data of actual file except deleted one
		if(fChar == '\n'){//count lines
			size++;	
		}
		if((size/3) != studentNumber){ // check is student data need to enter in tem file or not	
			fChar = fgetc(fp);
			fputc(fChar,fT);
		}
		else{// point file pointer to the next char
			fChar = fgetc(fp);
		}

	}
	fclose(fp);
	fclose(fT);


	//Now move data from temp file to the actual file
	fopen_s(&fp,fileName,"w");
	fopen_s(&fT,"temp.txt","r");

	fChar = ' ';// reset variable
	while(fChar!=EOF){
		fChar = getc(fT);
		if(fChar!=EOF){ // not enter EOf character in temp file
			fputc(fChar,fp);
		}
	}
	fclose(fp);
	fclose(fT);
	remove("temp.txt"); 
}

int menu(){
	int operation = -1;
	printf("\n0 : Exit");
	printf("\n1 : Enter student record");
	printf("\n2 : Delete student record");
	printf("\n3 : Print student record");
	
	while(operation<0 || operation >=4){ // take opetion from user
		printf("\n....> Select opetion <....\n");
		operation = _getche() - 48;
		printf("\n\n");
		_getch(); // wait for pressing of any key
	}

	return operation;
}
int main(){
	char fileName[100] = "input.txt";
	int opetion = -1;
	while(opetion !=0){
		opetion = menu();
		if(opetion == 1){
			enterData(fileName);
		}
		else if(opetion == 2){
			deleteStudentRecord(fileName);
		} 
		else if(opetion == 3){
			PrintStudentRecord(fileName);
		} 
		
	}


	return 0;
}
