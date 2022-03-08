#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void addstudent();
void searchstudent();
void studentrecord();
void delete();
void library();
void quantumlibrary();
struct student {
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[10];
     char vill[20];
    float per;
    char Book_name[20];
    int Book_ID;
    char Book_author[20];

};


void  main(){
    char s[20]={"abc"},s1[20];
int value=0,ch;
printf("\t\t*************Password protected**************\n\n\n");
printf("\n\tEnter the password:");
gets(s1);
value=strcmp(s,s1);
if(value==0)
    {
        printf("\n\t\t\t\tLogin Succesfully\n");
        system("cls");

       while(ch!=5)
        {
        printf("\t    ====Quantum University Management System====\n\n\n");
        printf("\n\n\n\t\t     1. Add Student\n");
    printf("\t\t     2. Students Records\n");
    printf("\t\t     3. Search Student\n");
    printf("\t\t     4. Delete Student\n");
    printf("\t\t     5. Exit\n");
    printf("\t\t    _____________________\n");
    printf("\t\t     ");

            scanf("%d",&ch);

   switch(ch){
       case 1:
system("cls");
system("cls");
        addstudent();
system("cls");
         break;
     case 2:
         system("cls");

          studentrecord();
          system("cls");
          printf("\t\t   press any key to exit..... \n");

         break;

     case 3:
         system("cls");

         searchstudent();
         system("cls");
         printf("\n\t\t\t  Press any key to exit.......\n");


         break;

     case 4:
system("cls");
        delete();
        system("cls");
        printf("\n\t\t\tPress any key to exit.......\n");

               break;
   /*  case 5:
system("cls");
system("cls");
quantumlibrary();
 printf("\n\t\t\t\tPress any key to exit.......\n");
*/

     case 5:
        system("cls");
          printf("\n\t\t\tThank you, for used this software.\n\n");
          exit(0);
        break;

     default :


         printf("\n\t\t\t\tEnter a valid number\n\n");
         printf("\t\t\tPress any key to continue.......");


         break;
        }

        }
}


    else
    {
        printf("\n\t\t\tWrong password\n");
        printf("\nEnter the right password\n");
        gets(s1);
    }
}
 void addstudent(){

     char another;
     FILE *fp;
     int n,i;
     struct student info;
   do{

       printf("\t\t=======Add Students Info=======\n\n\n");
       fp=fopen("information.txt","a"); //use can give any file name. Give the name with extention or without extention.

        printf("\n\t\tEnter First Name     : ");
          scanf("%s",&info.first_name);
          printf("\n\t\tEnter Last Name     : ");
          scanf("%s",&info.last_name);
          printf("\n\t\tEnter Roll-No       : ");
          scanf("%d",&info.roll_no);
          printf("\n\t\tEnter Class(course) : ");
          scanf("%s",&info.Class);
          printf("\n\t\tEnter Address       : ");
          scanf("%s",&info.vill);
          printf("\n\t\tEnter Percentage    : ");
          scanf("%f",&info.per);
          printf("\n\t\t______________________________\n");

      if(fp==NULL){
        fprintf(stderr,"can't open file");
    }else{
        printf("\t\tRecord stored successfuly\n");
    }

    fwrite(&info, sizeof(struct student), 1, fp);
    fclose(fp);

    printf("\t\tYou want to add another record?(y/n) : ");


    scanf("%s",&another);


   }while(another=='y'||another=='Y');
}
void studentrecord(){

     FILE *fp;

    struct student info;
    fp=fopen("information.txt","r");

     printf("\t\t=======STUDENTS RECORD=======\n\n\n");

    if(fp==NULL){

        fprintf(stderr,"can't open file\n");
        exit(0);
    }else{
        printf("\t\t\tRECORDS :\n");
        printf("\t\t\t___________\n\n");
    }

        while(fread(&info,sizeof(struct student),1,fp)){
        printf("\n\t\t Student Name  : %s %s",info.first_name,info.last_name);
        printf("\n\t\t Roll NO       : %d",info.roll_no);
        printf("\n\t\t Class         : %s",info.Class);
        printf("\n\t\t Village/City  : %s",info.vill);
        printf("\n\t\t Percentage    : %f%",info.per);


        printf("\n\t\t ________________________________\n");

         }
        fclose(fp);
getch();

  }
  void searchstudent(){
       struct student info;
      FILE *fp;
      int roll_no,found=0;

    fp=fopen("information.txt","r");
    printf("\t\t\t=======SEARCH STUDENTS RECORD=======\n\n\n");
    printf("\t\tEnter the roll no : ");

    scanf("%d",&roll_no);



    while(fread(&info,sizeof(struct student),1,fp)>0){

        if(info.roll_no==roll_no){

        found=1;
        printf("\n\n\t\tStudent Name : %s %s",info.first_name,info.last_name);
        printf("\n\t\tRoll NO        : %d",info.roll_no);
        printf("\n\t\tClass          : %s",info.Class);
        printf("\n\t\tAddress        : %s",info.vill);
        printf("\n\t\tPercentage     : %f%",info.per);
        printf("\n\t\t______________________________________\n");

         }

    }

    if(!found){
       printf("\n\t\tRecord not found\n");
    }

    fclose(fp);


}


 void delete(){
      struct student info;
      FILE *fp, *fp1;


    int roll_no,found=0;

       printf("\t\t\t=======DELETE STUDENTS RECORD=======\n\n\n");
    fp=fopen("information.txt","r");
    fp1=fopen("temp.txt","w");
    printf("\t\t\tEnter the roll no : ");
    scanf("%d",&roll_no);
    if(fp==NULL){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }

    while(fread(&info,sizeof(struct student),1,fp)){
        if(info.roll_no == roll_no){

            found=1;

        }else{
           fwrite(&info,sizeof(struct student),1,fp1);
        }

    }
     fclose(fp);
     fclose(fp1);

    if(!found){
          printf("\n\t\t\tRecord not found\n");
        }
      if(found){
    remove("information.txt");
        rename("temp.txt","information.txt");

        printf("\n\t\t\tRecord deleted succesfully\n");
        }

 }/*

 void quantumlibrary(){
 printf("\n\n\n\t\t\t\t     1. Add \n");
    printf("\t\t\t\t     2. Students Records\n");
    printf("\t\t\t\t     3. Search Student\n");
    printf("\t\t\t\t     4. Delete Student\n");
    printf("\t\t\t\t     5. Exit\n");
    printf("\t\t\t\t    _____________________\n");
    printf("\t\t\t\t     ");
    scanf("%d",&choice);

   switch(choice){
       case 1:
system("cls");
system("cls");
        booksrecord();
system("cls");
         break;
     case 2:
         system("cls");

          booksrecord();
          system("cls");
          printf("\t\t\t\t  press any key to exit..... \n");

         break;

     case 3:
         system("cls");

         searchbooks();
         system("cls");
         printf("\n\t\t\t\t  Press any key to exit.......\n");


         break;

     case 4:
system("cls");
        delete();
        system("cls");
        printf("\n\t\t\t\tPress any key to exit.......\n");

               break;

 }*/








