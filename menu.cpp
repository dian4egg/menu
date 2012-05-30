// menu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
#include <string.h>
#include <iostream>
#include <conio.h> 

using namespace std;

int main() {
	system ("cls");
	int x=1;
	while (x!=0) {
		char s1[100]="one";
		char s2[100]="two";
		char s3[100]="three";
		char s4[100]="four";		
	
			if (x==1) { cout << "*" << s1 << "*" << endl << s2 << endl << s3 << endl << s4; }
			if (x==2) {cout <<s1 << endl<< "*" << s2 << "*" << endl << s3 << endl << s4; } 
			if (x==3) { cout << s1 << endl <<s2 << endl<< "*" << s3 << "*" << endl << s4; }
			if (x==4) { cout << s1 << endl << s2 << endl << s3<< endl<< "*" << s4 << "*"; }
			cin >> x; x=getch();
		
		system("cls");
	}
	return 0;
}

