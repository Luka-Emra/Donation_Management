#include<stdio.h>

void Create_File() {
  int check, IDNumber, Donation;
  char FirstName[30], LastName[30], Country[30];
   FILE *fptr;
   system ("cls");
  fptr = (fopen("charityinfo.txt","a"));
  if(fptr == NULL){
       printf("Error!\n");
       exit(1);
   }
   printf("\033[0;31m");
   printf("\n\n\t|------------------------- WELCOME TO THE GLOBAL CHARITY ORGANISATION -------------------------|\n\t|");
   printf("\033[0;33m");
   printf("--------- GIVING IS NOT JUST ABOUT MAKING A DONATION, IT'S ABOUT MAKING A DIFFERENCE ---------");
   printf("\033[0;31m");
   printf("|\n\t|-------- IF YOU WANT TO DONATE TODAY, FILL FREE TO PROVIDE A LITTLE INFORMATION BELOW --------|\n\n");
   printf("\033[1;34m");
   printf("\t____________\n\tFirst Name;\n\t___________\n\tLast Name;\n\t__________\n\tCountry;\n\t________\n");
   printf("\tID Number;\n\t__________\n\tDonation in $;\n\t______________\n\n");
   printf("\033[0m");
  check = 1;
  while(check){
       printf("\033[0;32m");
       printf("\t");
       scanf("%s",&FirstName);
       printf("\t");
       scanf("%s",&LastName);
       printf("\t");
       scanf("%s",&Country);
       printf("\t");
       scanf("%d",&IDNumber);
       printf("\t");
       scanf("%d",&Donation);
  fprintf(fptr,"%s %s %s %d %d\n",FirstName,LastName,Country,IDNumber,Donation);
  printf("\033[0;33m");
  printf("\n\tThank You %s For Your Generosity! :)))\n", FirstName);
  printf("\033[1;34m");
  printf("\n\tEnter 1 to continue, 0 to exit:");
  scanf("%d",&check);
  printf("\033[0m");
  }
   fclose(fptr) ;
}

int Donate_sort(int Donation[],int n){
int i, j, temp;
int flag = 1;
 for(i = 0; i < n-1 && flag == 1; i++){
  flag = 0;
  for (j = 0; j < n-1-i; j++){
   if (Donation[j] > Donation[j+1]){
    flag = 1;
    temp = Donation[j];
    Donation[j] = Donation[j+1];
    Donation[j+1] = temp;
    }
   }
  }
return(0);
}
void File_Printer()
{
  int donations[200],idNum[200],i;
  char FName[200][100], LName[200][100], Country[200][100];
  FILE *fptr;
  system ("cls");
  fptr = (fopen("charityinfo.txt","r"));
  if(fptr == NULL){
       printf("Error!");
       exit(1);
   }
   i = 0;
   printf("\033[0;34m");
   printf("\t    _____________________________________________________________________________________________\n");
   printf("\t    |                |                |              |                |                         |\n");
   printf("\t    |   FIRST NAME   |   LAST NAME    |   COUNTRY    |   ID NUMBER    |   DONATION IN DOLLARS   |\n");
   printf("\t    |________________|________________|______________|________________|_________________________|\n");
   printf("\033[1;34m");

   while(!feof(fptr)){
     fscanf(fptr,"%s %s %s %d %d\n",&FName[i],&LName[i],&Country[i],&idNum[i],&donations[i]);
     printf("\t    |    %s\t\t%s\t  %s\t  %d\t\t$%d\n",FName[i],LName[i],Country[i],idNum[i],donations[i]);
   printf("\t    |----------------|----------------|--------------|----------------|-------------------------|\n");
     i = i + 1;
   }
   fclose(fptr);
   printf("\n\n\t PRESS ANY KEY TO CONTINUE:");
   printf("\033[0m");
   getch();
  }
void Donation_Sorter(){
    int i, j, donations[200], idNum[200], donationsSort[200], numDonors;
    char FName[200][100], LName[200][100], Country[200][100];
    FILE *fptr,*fd;
    fptr = (fopen("charityinfo.txt","r"));
    if(fptr == NULL){
       printf("Error!");
       exit(1);
   }
    fd = (fopen("donations.txt","w"));
    if(fd == NULL){
       printf("Error!");
       exit(1);
   }
    i = 0;
   while(! feof(fptr)) {
     fscanf(fptr,"%s %s %s %d %d\n",&FName[i],&LName[i],&Country[i],&idNum[i],&donations[i]);
     donationsSort[i] = donations[i];
     i = i + 1;
      }
    numDonors = i;
       Donate_sort(donationsSort,numDonors);
       Find_MAX(donationsSort,numDonors);
       Find_MIN(donationsSort,numDonors);
    printf("\033[1;33m");
    printf("\n\n\t __________________________________________\n");
    printf("\t| MINIMUM AMOUNT OF DONATION: $%d      \n",Find_MIN(donationsSort,numDonors));
    printf("\t|__________________________________________\n");
    printf("\t| MAXIMUM AMOUNT OF DONATION: $%d      \n",Find_MAX(donationsSort,numDonors));
    printf("\t|__________________________________________\n\n\n");
    printf("\t ______________________________________________________________\n");
    printf("\t|           AMOUNTS OF DONATION IN ASCENDING ORDER:            \n");
    printf("\t|______________________________________________________________\n");
    printf("        |");
    for(i = 0; i < numDonors; i++){
    printf(" $%d ",donationsSort[i]);
    }
    printf("\n\t|______________________________________________________________\n");
 for(i = 0;i < numDonors; i++){
   for (j = 0; j < numDonors; j++){
   if(donationsSort[i] == donations[j]){
      fprintf(fd,"%s %s %s %d %d\n",FName[i],LName[i],Country[i],idNum[i],donations[i]);
     }
   }
 }
  fclose(fd);
  fclose(fptr);
  printf("\n\n\n\n\t\tPRESS ANY KEY TO CONTINUE");
  printf("\033[0m");
  getch();
}
void ID_Searcher(){
    int i, idNumber, check, donation, idSearched;
    char FirstName[50], LastName[50], country[50];
    FILE *fd;
    check = 1;
  while(check){
    system ("cls");
    printf("\033[1;31m");
    fd = (fopen("donations.txt","r"));
    if(fd == NULL){
       printf("Error!");
       exit(1);
   }
    printf("________________________________________________________________________________________________________");
    printf("\n\t\t| ENTER DONOR ID NUMBER: ");
    printf("\033[0;31m");
    scanf("%d", &idSearched);
      i = 0;
    printf("\033[1;31m");
   while(!feof(fd)) {
     fscanf(fd,"%s %s %s %d %d\n",&FirstName,&LastName,&country,&idNumber,&donation);
     if(idSearched == idNumber){
     printf("\n");
     printf("\t    |   FIRST NAME   /   LAST NAME    /   COUNTRY    /   ID NUMBER    /   DONATION IN DOLLARS   |\n");
     printf("\t         %s\t\t%s\t  %s\t  %d\t\t$%d\n",FirstName,LastName,country,idNumber,donation);
     printf("________________________________________________________________________________________________________");
     break;
     }
     else
     i = i + 1;
    }
  printf("\n\n\tPRESS 1 TO SEE ANOTHER DONOR INFO, 0 TO GO BACK: ");
  scanf("%d",&check);
  printf("\033[0;33m");
  fclose(fd);
  }
 }
void Calc_AVG()
 {
    int n,i, sum = 0, donations[200],idNum[200];
    float avg;
    char FName[200][100], LName[200][100], Country[200][100];
    FILE *fd;
    printf("\033[0;36m");
    fd = (fopen("donations.txt","r"));
    if(fd == NULL){
       printf("Error!");
       exit(1);
   }
    i=0;
   while(!feof(fd)) {
     fscanf(fd,"%s %s %s %d %d\n",&FName[i],&LName[i],&Country[i],&idNum[i],&donations[i]);
     sum = sum + donations[i];
     i=i+1;
    }
     n = i;
     avg = sum/n;
  printf("\t ______________________________________________________________\n");
  printf("\t|\n");
  printf("\t|  AVERAGE AMOUNT OF DONATION FROM");
  printf("\033[0;31m");
  printf(" %d ",n);
  printf("\033[0;36m");
  printf("DONORS:");
  printf("\033[0;31m");
  printf("\t$%.2f \n",avg);
  printf("\033[0;36m");
  printf("\t|______________________________________________________________\n");
  fclose(fd);
  printf("\n\n\n\t  PRESS ANY KEY TO CONTINUE");
  printf("\033[0m");
  getch();
 }
 int Find_MAX(int donations[], int n) {
  int i, max;
  max = donations[0];
  for (i = 1; i < n; i++) {
    if (donations[i] > max) {
       max = donations[i];
    }
  }
  return max;
}

int Find_MIN(int donations[], int n) {
  int i, min;
  min = donations[0];
  for (i = 1; i < n; i++) {
    if (donations[i] < min) {
       min = donations[i];
    }
  }
  return min;
}
void main()
{
  int Number;
  while(Number != 6)
   {
     system ("cls");
     printf("\033[0;32m");
     printf("\t____________________________________________________________________________________________\n");
     printf("\t\\__________\\                                                                    /__________/\n");
     printf("\t   \\________\\  CHOOSE ONE OF THE OPTIONS BELOW & ENTER AN APPROPRIATE INTEGER  /________/\n");
     printf("\t      \\______\\________________________________________________________________/______/\n\n");
     printf("\t ______________________________________________________________________________________\n");
     printf("\t|1|INSERT YOUR INFORMATION INTO CHARITY ORGANISATION DATABASE --------------------(1)--|\n");
     printf("\t|_|____________________________________________________________________________________|\n");
     printf("\t|2|SHOW THE DONOR DATABASE -------------------------------------------------------(2)--|\n");
     printf("\t|_|____________________________________________________________________________________|\n");
     printf("\t|3|SHOW MAX & MIN AMOUNTS OF DONATIONS AND PUT THEM IN ASCENDING ORDER -----------(3)--|\n");
     printf("\t|_|____________________________________________________________________________________|\n");
     printf("\t|4|SHOW THE AVERAGE OF DONATIONS -------------------------------------------------(4)--|\n");
     printf("\t|_|____________________________________________________________________________________|\n");
     printf("\t|5|FIND THE DONOR INFORMATION BY HIS/HER ID --------------------------------------(5)--|\n");
     printf("\t|_|____________________________________________________________________________________|\n");
     printf("\t|6|EXIT --------------------------------------------------------------------------(6)--|\n");
     printf("\t|_|____________________________________________________________________________________|\n");
     printf("\n\n\t ENTER HERE:");
     scanf("%d",&Number);
     printf("\033[0m");
     system ("cls");
     switch(Number)
     {
     case 1:
          Create_File();
          break;
     case 2:
          File_Printer();
         break;
     case 3:
          Donation_Sorter();
         break;
     case 4:
          Calc_AVG();
         break;
     case 5:
          ID_Searcher();
         break;
     case 6:
         break;
     default:
         break;
     }
    }
return 0;
  }
