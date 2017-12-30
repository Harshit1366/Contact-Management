#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define p printf
#define s scanf
void con();
void exitz();
void add();
void option(int ch);
void lists();
void search();
void edit();
void delete();
void new();
void all();
void ema();
struct contact
{
long unsigned int ph;
unsigned int add;
char name[20],email[30];
}list;
char query[20],nam[20],aim[20],em[20];
FILE *fp,*ft;
int i,n,ch,l,found=0;
void main()
{
p("\n\t\t\t\t\t\t ***** Welcome to Contact Manager *****");
p("\n\n\n\n");
lists();
p("\n\n\n\n\t\t\t\t\t\t\t        MAIN MENU\n\t\t\t\t\t\t=======================================\n\t\t\t\t\t\t [1] Add a new contact\n\t\t\t\t\t\t [2] Search for contact\n\t\t\t\t\t\t       -> By Contact Name\n\t\t\t\t\t\t       -> By Contact Number\n\t\t\t\t\t\t [3] Edit a contact \n\t\t\t\t\t\t       -> By Contact Name\n\t\t\t\t\t\t       -> By Contact Number\n\t\t\t\t\t\t [4] Delete a contact \n\t\t\t\t\t\t       -> By Contact Name\n\t\t\t\t\t\t       -> By Contact Number\n\t\t\t\t\t\t [5] Delete all contacts\n\t\t\t\t\t\t [0] Exit\n\t\t\t\t\t\t=======================================\n\n\n\t\t");
p("Please select any one of the above choices!");
option(ch);
}

void con()
{
char c;
p("\n\n\tDo you want to continue (y/n)? ");
s(" %c",&c);
if(c=='y'||c=='Y')
{
p("\n\n\n\n\t\t\t\t\t\t\t        MAIN MENU\n\t\t\t\t\t\t=======================================\n\t\t\t\t\t\t [1] Add a new contact\n\t\t\t\t\t\t [2] Search for contact\n\t\t\t\t\t\t       -> By Contact Name\n\t\t\t\t\t\t       -> By Contact Number\n\t\t\t\t\t\t [3] Edit a contact \n\t\t\t\t\t\t       -> By Contact Name\n\t\t\t\t\t\t       -> By Contact Number\n\t\t\t\t\t\t [4] Delete a contact\n\t\t\t\t\t\t        -> By Contact Name\n\t\t\t\t\t\t       -> By Contact Number\n\t\t\t\t\t\t [5] Delete all contacts \n\t\t\t\t\t\t [0] Exit\n\t\t\t\t\t\t=======================================\n\n\n\t\t");
return option(ch);
}
else if (c=='n'||c=='N')
{
p("Thanks for accessing our contact Manager!");
return exit(1);
}
else
{
p("INVALID OPTION!\n");
return con();
}
}

void option(int ch)
{
p("\n\n\t\tEnter the choice : ");
s("%u",&ch);
switch(ch)
{
case 0 : exitz();
break;
case 1 : add();
break;
case 2 : search();
break;
case 3 : edit();
break;
case 4 : delete();
break;
case 5 : all();
break;
default :
{
p("INVALID CHOICE!");
return option(ch);
}
}
}

void ema(){
int i,l=0,j,c,flag=0,fla=0;
char n[50],*e;
p("\nEnter valid e-mail address : ");
fflush(stdin);
s(" %[^\n]s",n);
e=n;
while(n[l]!='\0')
++l;
while(c)
{
for(i=0;i<l;i++)
{
if(*(e+i)=='@')
{
flag==1;
for(j=i+1;j<l;j++)
{
if(*(e+j)=='.'){
fla=1;
}}
}}
c=0;
}
if (flag!=1 && fla!=1)
{
p("Invalid E-mail! Please add '@' and '.'\t");
return ema(n);}

strcpy(list.email,n);

}

void exitz()
{
char a;
int f;
p("Are you sure you want to exit (y/n) ?");
s(" %c",&a);
if(a=='y'||a=='Y')
{
p("THANKYOU FOR ACCESING OUR contact MANAGER!");
return exit(1);
}
else if(a=='n'||'N')
{
if(fp==NULL)
{
p("\nDo you wish to add a new contact (1/0)? \n\n\t[1] YES \t [0] NO\n");
s("%d",&f);
switch(f)
{
case 1 :
add();
break;
default :
{
p("THANKYOU FOR ACCESSING!");
return exit(1);
}
}
}
else
return main();
}
else
{
p("INVALID!");
return exitz();
}
}

void new()
{
char y;
p("\n\n\tDo you want to see the new list (y/n) ?");
s(" %c",&y);
if(y=='y'||y=='Y')
return lists();
else if (y=='n'||y=='N')
p("OK!");
else
{
p("INVALID!");
return new();
}
}

void lists()
{
char t[20],n[20][20];
int i=0,j,l=0,flag;
fp=fopen("file.txt","r");
if(fp!=NULL)
{
ft=fopen("filed.txt","w+");
while(fread(&list,sizeof(list),1,fp)==1)
{
 strcpy(*(n+i),list.name);
 ++l;
 ++i;
 }
 
 for(i=0;i<l;i++){
 for(j=i+1;j<l;j++){
            if (strcmp(*(n+i),*(n+j)) > 0) {
            strcpy(t,*(n+i));
            strcpy(*(n+i),*(n+j));
            strcpy(*(n+j),t);
         }
      }
}
rewind(fp);
i=0;
while(i<l){
while(fread(&list,sizeof(list),1,fp)==1)
{if(strcmp(list.name,*(n+i))==0){
fwrite(&list,sizeof(list),1,ft);
}}
rewind(fp);
++i;
}
rewind(ft);
p("\n\t\t\t\t================================\n\t\t\t\t\tLIST OF CONTACTS\n\t\t\t\t================================\n\n\t\tName\t\tPhone No.\t      Address\t\tE-mail add.\n\t\t=====================================================================\n\n");
while(fread(&list,sizeof(list),1,ft)==1)
{
p("\n\t\tName : %s\n\t\tcontact No. : %lu\n\t\tAddress : %u\n\t\tE-mail Address : %s\n",list.name,list.ph,list.add,list.email);
flag=1;
}
if(flag!=1)
p("\n\n\t\t\t\t           EMPTY!\n\n");
p("\n\t\t=====================================================================\n\n\n");
fclose(ft);
fclose(fp);
remove("file.txt");
rename("filed.txt","file.txt");
}
else
{
p("\n\t\t\t\t================================\n\t\t\t\t\tLIST OF contactS\n\t\t\t\t================================\n\n\t\tName\t\tPhone No.\t      Address\t\tE-mail add.\n\t\t=====================================================================\n\n");
p("\n\n\t\t\t\t       THE LIST IS EMPTY!\n\n");
p("\n\t\t=====================================================================\n\n\n");}
}

void add()
{
int flag,k;
long unsigned int a;
found=0;
char b,l[50];
fp=fopen("file.txt","a+");
p("\n\nName (Use a unique identity) : ");
fflush(stdin);
s(" %[^\n]s",aim);

if(fp!=NULL)
{
rewind(fp);
while(fread(&list,sizeof(list),1,fp)==1)
{
if(strcmp(list.name,aim)==0)
{
flag=1;
p("\n\tcontact name already exists!\tChoose another name!");
return add();
found++;
}
}
}
if (flag!=1)
{
if(aim[0]>='a'&&aim[0]<='z')
aim[0]=aim[0]-32;
for(i=0;aim[i]!='\0';i++)
{
if(aim[i]==' '){
if(aim[i+1]>='a'&&aim[i+1]<='z')
aim[i+1]=aim[i+1]-32;}}
strcpy(list.name,aim);
mob : p("\nEnter the Mobile number : ");
s("%lu",&a);
k=a/1000000000;
if(k<1||k>=10)
{
p("INVALID MOBILE NUMBER!\nPlease ensure that number contains 10 digits...");
goto mob;}
else
list.ph=a;
fflush(stdin);
p("\nEnter address : ");
s("%u",&list.add);
fflush(stdin);
ema();

}
p("\n");
fwrite(&list,sizeof(list),1,fp);
fclose(fp);
p("\nContact added to list!\n");
lists();
p("\nDo you wish to add another record (y/n)? ");
s(" %c",&b);
if(b=='y'||b=='Y')
return add();
else
return con();
}

void search()
{
int flag;
long unsigned int no;
unsigned int n;
char x;
fp=fopen("file.txt","r");
if (fp==NULL)
{
p("The file does not exist!");
return exitz();
}
rewind(fp);
p("\n\n\t..:: SEARCH\n\t===========================\n\t..::Press any one\t[1] Name of contact \t[2] Mobile no. : ");
s("%u",&n);
switch (n)
{
case 1 :
found = 0;
p("\n\n\t..::Contact SEARCH\n\t===========================\n\t..::Name of contact to search: ");
fflush(stdin);
s(" %[^\n]s",query);
p("\n\n..::Search result for '%s' \n===================================================\n",query);
while(fread(&list,sizeof(list),1,fp)==1)
{
if(strcmp(list.name,query)==0)
{
p("Yes, the contact is present!\nFollowing are the details : ");
p("\n..::Name\t: %s\n..::Phone\t: %lu\n..::Address\t: %u\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);
found++;
}
}
if(found == 0)
p("\n..::No match found!");
else
p("\n..::%u match(s) found!",found);
fclose(fp);
p("\n\n\n ..::Wanna Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
s("%d",&ch);
if(ch==1)
return search();
break;
case 2 :
found=0;
p("Enter the contact number : ");
s("%lu",&no);
p("\n\n..::Search result for '%lu' \n===================================================\n",no);
while(fread(&list,sizeof(list),1,fp)==1)
{
if(list.ph==no)
{
flag=1;
p("\nYes, the contact is present!\n\nThe details are as follows : \n");
p("\n..::Name\t: %s\n..::Phone\t: %lu\n..::Address\t: %u\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);
}
found++;
}
if(flag!=1)
p("\n..::The contact is not present!");
p("\n\n\n\tDo you wish to search again (y/n) ?");
s(" %c",&x);
if (x=='y'||x=='Y')
return search();
break;
default :
p("INVALID!");
return search();
}
con();
}

void edit()
{
int flag,x;
long unsigned int no;
unsigned int m,n,z;
fp=fopen("file.txt","r");
if (fp==NULL)
{
p("The file does not exist!");
return exitz();
}
ft=fopen("filed.txt","a+");
if (ft==NULL)
{
p("The file does not exist!");
return exitz();
}
rewind(fp);
p("..::Edit contact\n===============================\n\n\t..::Press any one \t[1] Name of contact \t[2] Mobile no. : ");
s("%u",&m);
      switch (m)
       {
               case 1 :
p("Enter contact name : ");
s(" %[^\n]s",nam);
      while(fread(&list,sizeof(list),1,fp)==1)
{
       if(strcmp(nam,list.name)!=0)
{
        fwrite(&list,sizeof(list),1,ft);
}
fflush(stdin);
         if(strcmp(nam,list.name)==0)
{
//flag=1;
p("\n..::Name\t: %s\n..::Phone\t: %lu\n..::Address\t: %u\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);
p("Are you sure you want to edit something ?\n\t\t[1]YES \t\t[2]NO\n");
scanf("%u",&z);
switch(z)
{
case 1:
p("\n\n..::Editing '%s'\n\n",nam);
p("============================================\n\n");
p("\n\nEnter detail which you want to edit : \n\t[1] Name\t[2]Phone\t[3]Address\t[4]Email address\n");
s("%u",&n);
switch(n)
{
case 1 :
p("..::Name (Use identical) : ");
s(" %[^\n]s",list.name);
fflush(stdin);
break;
case 2 :
p("..::Phone : ");
s("%lu",&list.ph);
fflush(stdin);
break;
case 3 :
p("..::address : ");
s("%u",&list.add);
fflush(stdin);
break;
case 4 :
p("..::email address : ");
s(" %[^\n]s",list.email);
fflush(stdin);
break;
default :
p("INVALID");}
fwrite(&list,sizeof(list),1,ft);
p("The contact list has been updated!");

p("\n");
fclose(fp);
fclose(ft);
remove("file.txt");
rename("filed.txt","file.txt");
con();
break;
default :
return main();
}}
else
{
p("No such contact found!");
p("\n\n\n\tWanna try again?\n\n\t\t[1]YES\t\t[2]NO\n");
s(" %d",&x);
if (x==1)
return edit();
else
return exitz();
}}
break;
case 2 :
p("Enter Contact number : ");
s("%lu",&no);
      while(fread(&list,sizeof(list),1,fp)==1)

{
       if(no!=list.ph)
{
        fwrite(&list,sizeof(list),1,ft);
}
fflush(stdin);
         if(no==list.ph)
{
p("\n..::Name\t: %s\n..::Phone\t: %lu\n..::Address\t: %u\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);
p("Are you sure you want to edit something ?\n\t\t[1]YES \t\t[2]NO\n");
scanf("%u",&z);
switch(z)
{
case 1:
p("\n\n..::Editing '%s' (%lu)\n\n",list.name,no);
p("============================================\n\n");
p("\n\nEnter detail which you wish to edit : \n\t[1] Name\t[2]Phone\t[3]Address\t[4]Email address\n");
s("%u",&n);
switch(n)
{
case 1 :
p("..::Name (Use identical) : ");
s(" %[^\n]s",list.name);
fflush(stdin);

break;
case 2 :
p("..::Phone : ");
s("%lu",&list.ph);
fflush(stdin);

break;
case 3 :
p("..::address : ");
s("%u",&list.add);
fflush(stdin);

break;
case 4 :
p("..::email address : ");
s(" %[^\n]s",list.email);
fflush(stdin);

break;
default :
p("INVALID");}
fwrite(&list,sizeof(list),1,ft);
p("The contact list has been updated!");

p("\n");
fclose(fp);
fclose(ft);
remove("file.txt");
rename("filed.txt","file.txt");
con();
break;
default :
return main();
}}
else
{
p("The contact does not exist!");
p("\n\n\n\tWanna try again?\n\n\t\t[1]YES\t\t[2]NO\n");
s("%d",&x);
if (x==1)
return edit();
else
return exitz();
}}
break;
default :
p("\tINVALID OPERATION!\tACCESS DENIED...");
return edit();
}}



void delete()
{
int flag,a;
long unsigned int no;
do{fflush(stdin);
p("..::DELETE A contact\n\t==========================\n\n\t..::Click any one \t[1] Name of contact \t[2] Mobile no. : ");
s("%d",&a);
switch(a)
{
case 1 :
p("Enter name : ");
s(" %[^\n]s",nam);
fp=fopen("file.txt","r");
if (fp==NULL)
{
p("The file does not exist!");
return exitz();
}
ft=fopen("filed.txt","w");
if (ft==NULL)
{
p("The file does not exist!");
return exitz();
}
rewind(fp);
if(fp!=NULL)
{
/*while(fread(&list,sizeof(list),1,fp)==1)
{
if(strcmp(nam,list.name)==0)
{
p("The contact list has been updated!");
new();}
else
p("Contact is not present!");*/
//if(strcmp(nam,list.name)!=0)
//fwrite(&list,sizeof(list),1,ft);
//if(strcmp(nam,list.name)==0)
//flag=1;
//found++;
//}
while(fread(&list,sizeof(list),1,fp)==1)
{
if(strcmp(nam,list.name)!=0)
fwrite(&list,sizeof(list),1,ft);}
}
/*if (flag==1)
{
p("The contact list has been updated!");
new();}
else
p("Contact is not present!");*/
fclose(fp);
fclose(ft);
remove("file.txt");
rename("filed.txt","file.txt");

break;
case 2:
p("Enter phone number : ");
s("%lu",&no);
fp=fopen("file.txt","r");
if (fp==NULL)
{
p("The file does not exist!");
return exitz();
}
ft=fopen("filed.txt","w");
if (ft==NULL)
{
p("The file does not exist!");
return exitz();
}
rewind(fp);
if(fp!=NULL)
{
while(fread(&list,sizeof(list),1,fp)==1)
{
/*if(list.ph==no)
{
p("The Contact list has been updated!");
new();}
else
p("Contact does not exist!");*/
if(list.ph!=no)//{
fwrite(&list,sizeof(list),1,ft);
//flag=1;}
//if(list.ph==no)
//flag=1;
}}
/*if (flag==1)
{
p("The Contact list has been updated!");
new();}
else
p("Contact does not exist!");*/
fclose(fp);
fclose(ft);
remove("file.txt");
rename("filed.txt","file.txt");
//new();
break;
default :
{
p("INVALID!");
return delete();
}
}
if(fp!=NULL){
p("\n\n\n\tWanna try once more?\n\n\t[1] YES \t [0] NO : ");
s("%d",&ch);}}while(ch==1);
con();
}

void all()
{
ft=fopen("filed.txt","a");
fclose(ft);
remove("file.txt");
rename("filed.txt","file.txt");
p("\n\t\tLIST CLEARED!");
lists();
return option(ch);
}
