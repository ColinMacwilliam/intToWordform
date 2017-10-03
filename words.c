
/* Colin Macwilliam
 This program converts a users integer into its respective word form until the program reaches the end of the file.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int negToPos(int num);

void numToWords(int userNum, char* userString);


int negToPos(int num) {
int posNum = 0;

num = num * -1;

posNum = num;

return posNum;
}





void numToWords(int userNum, char* userString) {



char *onesPlace[10] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
char *tensPlace[10] = { "", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char *teens[10] = { "", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
int temp; //variable that determines which word to add to string



int neg = 0;
if (userNum < 0) {
userNum = negToPos(userNum);
neg = 1;
}

temp = (userNum / 1000000000);
if (userNum != 0) {

int y;
y = userNum / 1000000000;


if (y != 0) {
strcpy(userString, onesPlace[temp]);
strcat(userString, " billion");
}

int temp2; //variable that also determines which word to add to string
userNum = userNum % (1000000000);
if ((userNum != 0)&& (temp!=0)) {
strcat(userString, ", ");
}
temp2 = (userNum / 100000000);

if (userNum > 99999999) {
strcat(userString, onesPlace[temp2]);
strcat(userString, " hundred ");
}

int addMillion;
int j;
int x;

addMillion = userNum / 1000000;

userNum = userNum % 100000000;
temp2 = (userNum / 10000000);

if (addMillion != 0) {

j = userNum / 1000000;
if ((j >10) && (j <20)) {
j = j % 10;

strcat(userString, teens[j]);
}
else if (j < 10) {
strcat(userString, onesPlace[j]);
}
else if (j == 10) {
strcat(userString, "ten ");
}
else if (j >= 20) {
temp2 = j / 10;
strcat(userString, tensPlace[j]);

if ((j % 10) != 0) {
strcat(userString, "-");
}

x = j % 10;
strcat(userString, onesPlace[x]);
}
strcat(userString, " million");
}


userNum = userNum % 10000000;
temp2 = (userNum / 1000000);





userNum = userNum % 1000000;

if ((userNum != 0)&& (addMillion!=0)) {	
strcat(userString, ", ");
}
temp2 = (userNum / 100000);

int realthousand;
int i;

realthousand = userNum / 1000;


if (realthousand != 0) {
temp2 = realthousand / 100;
if (temp2 != 0) {
strcat(userString, onesPlace[temp2]);
strcat(userString, " hundred ");
}
realthousand = realthousand % 100;
if ((realthousand >=10) && (realthousand <=20)) {
realthousand = realthousand % 10;
strcat(userString, teens[realthousand]);
i = 1;
}




if ((realthousand < 10)&& (i != 1)) {

strcat(userString, onesPlace[realthousand]);
}
else if (realthousand > 20) {

temp2 = realthousand / 10;
strcat(userString, tensPlace[temp2]);

if ((realthousand % 10) != 0) {
strcat(userString, "-");
}

temp2 = realthousand % 10;
strcat(userString, onesPlace[temp2]);


}
strcat(userString, " thousand");
i = 2;
}


int last=0;

if (userNum > 1000) {
last = 1;
}

userNum = userNum % 1000;
if (last == 1) {
strcat(userString, ", ");
}
temp2 = (userNum / 100);

if (temp2 != 0) {
strcat(userString, onesPlace[temp2]);
strcat(userString, " hundred ");
}
userNum = userNum % 100;
temp2 = userNum / 10;


if (userNum == 10) {
strcat(userString, "ten");
}



if (temp2 != 1) {
strcat(userString, tensPlace[temp2]);
userNum = userNum % 10;
if ((userNum != 0) && (temp2 != 0)) {
strcat(userString, "-");
}
if (userNum > 0) {
strcat(userString, onesPlace[userNum]);
}
}

else {
userNum = userNum % 10;
strcat(userString, teens[userNum]);
}

char negString[150];
strcpy(negString, "negative ");
strcat(negString, userString);

if (neg == 1) {
printf("%s\n", negString);
}

else if (neg == 0) {
printf("%s\n", userString);
}
strcpy(userString, "");
strcpy(negString, "");
}
else {
strcpy(userString, "zero");
printf("%s\n", userString);
strcpy(userString, "");
}

return;
}


int main(void) {
int userNum;
char userString[150];

printf("Enter any integer: ");
scanf("%d", &userNum);

while(!feof(stdin)) {
(numToWords(userNum, userString));
printf("Enter another integer: ");
scanf("%d", &userNum);
}


return 0;
}
