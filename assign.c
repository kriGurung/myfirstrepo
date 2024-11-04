#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define USERNAME "Krishna"
#define PASSWORD "12345"
#define MAX_NOMINEES 150
#define MAX_ELECTOR 1500
// Storing election schedule info
struct schedule_table{
	char Constituency[70];
     char date[10];
}s1;
// Storing Nominee detail 
struct Nominee_table{
	char NomineeName[100];
	char PoliticalParty[50];
	char Nomineefrom[50];
}c1,c2;
// Elector registration detail
struct Elector_table{
	int ElectorsNo[150];
	char Electorname[150];
	char Dateofbirth[10];
	char Address[50];
	char password[15];
}v1,v2;
//function prototype
void schedule();
void Nominee();
void Elector();
void Adminstrator();
void Electors();
void System();
void MainSystem();


void Nomineereg();
void Nomineeview();
void deletenominee();
void Nomineeupdate();
void ViewelectorList();
void Electorreg();
void Electorsearch();
void Electordelete();
void Electorupdate();
void electionresult();

void viewschedule();
void viewnominee();
void searchNominee();
void updateelector();
void deleteelector();
void viewelector();

void viewelectorresult(){
	struct Nominee_table c;
	FILE *fp;
	int votecount = 0;
	fp = fopen("Electionresult.txt","r");
	if(fp == NULL){
		printf("Error while opening  a file");
	}
	
	//loop fom file
	while(fscanf(fp, "%s %s %s %d", c.NomineeName, c.PoliticalParty, c.Nomineefrom, &votecount) != EOF) {
		printf("%s %s %s %d\n",c.NomineeName,c.PoliticalParty,c.Nomineefrom,votecount);
	}
	fclose(fp);
}

void searchelectorresult(){
	struct Nominee_table c;
	FILE *fp;
	char searchKey[50], searchChoice;
	int votecount = 0, found = 0;
	
	fp = fopen("Electionresult.txt","r");
	if(fp == NULL){
		printf("error opening a file");
	}
	fflush(stdin);
	printf("What do you want to search?\n1.Nominee\n2.party\n3.place\nSelect any:");
	scanf("%c",&searchChoice);
	
	if(searchChoice != '1' && searchChoice != '2'&&searchChoice != '3'){
		printf("\nInvalid selection.");
		return;
	}
	
	fflush(stdin);
	printf("Search :");
	scanf("%s",&searchKey);
	
	//loops through file
	while(fscanf(fp, "%s %s %s %d", c.NomineeName, c.PoliticalParty, c.Nomineefrom, &votecount) != EOF) {
		
		if(searchChoice=='1'){
			if(strcmp(c.NomineeName, searchKey) == 0){
				found = 1;//found Nominee name  
		printf("%s %s %s %d\n", c.NomineeName, c.PoliticalParty, c.Nomineefrom, votecount);
			}
		}
		else if(searchChoice =='2'){
			if(strcmp(c.PoliticalParty, searchKey) == 0){
				found = 1;//found party and  of Nominee that party
		printf("%s %s %s %d\n", c.NomineeName, c.PoliticalParty, c.Nomineefrom, votecount);
			}
		}else if(searchChoice == '3'){
			if(strcmp(c.Nomineefrom, searchKey) == 0){
				found = 1;//found place and Nominee in that place
				printf("%s %s %s %d\n", c.NomineeName, c.PoliticalParty, c.Nomineefrom, votecount);
			}
		}
		
	}
	if(found != 1){
		printf("No matching Nominee Name and Party.");
	}
	fclose(fp);
}

void castvote(){
	struct Nominee_table c;
	FILE *fp,*ft;
	char Electornomineename[50], Electornomineeparty[50];
	int votecount = 0, found = 0;
	fp = fopen("Electionresult.txt","r");
	if(fp == NULL){
		printf("Error opening a file");
	}
	ft = fopen("temp.txt","w");
	if(ft == NULL){
		printf("Error opening a file");
	}
	Nomineeview(); //displays list of Nominess
	
	printf("Enter the name of Nominee to vote:");
	scanf("%s",Electornomineename);
	printf("Enter the political party of Nominee to vote:");
	scanf("%s",Electornomineeparty);
	
	//loops through file
	while(fscanf(fp, "%s %s %s %d", c.NomineeName, c.PoliticalParty, c.Nomineefrom, &votecount) != EOF) {
	
		if(strcmp(c.NomineeName, Electornomineename) == 0 && strcmp(c.PoliticalParty, Electornomineeparty) == 0){
			votecount++;
			found = 1;//matched and Nominee found
		}
		fprintf(ft,"%s %s %s %d\n",c.NomineeName,c.PoliticalParty,c.Nomineefrom,votecount);
	}
	if(found != 1){
		printf("No matching Nominee Name and Party.");
	}
	fclose(fp);
	fclose(ft);
	remove("Electionresult.txt");
	rename("temp.txt","Electionresult.txt");
}

int main(){
	int b;
	system("color a");
	system("cls");
    printf("\n\n\t\t\t----------------------------------------------------------------------------\n");
    printf("\t\t\t\t                  ONLINE VOTING MANAGEMENT SYSTEM\n");
    printf("\t\t\t----------------------------------------------------------------------------\n");
    printf("\t\t\t**\n");
    printf("\t\t\t\t                     SELCT ANY YOU WOULD LIKE:\n");
    printf("\t\t\t**\n\n\n");
	printf("\t\t\t1.Administrator");
	printf("\n                        2.Electors");

	printf("\t\t\t\n                        Enter Choice>:-");
	scanf("%d",&b);
	switch (b){
	case 1:
		Adminstrator();
		break;
	case 2:
		Electors();
		break;
}
}
void Adminstrator()
{
	char username[50],password[50];

	ADMINISTRATOR:
	printf("\n enter the username:");
	scanf("%s",username);
	printf("enter the password:");
	scanf("%s",password);
	
	if(strcmp(username,USERNAME)==0 && strcmp(password,PASSWORD)==0)
	{
		printf("sign in sucess");
	
	
	}
		else
		{
			printf("invalid userId or passsword\n");
			goto ADMINISTRATOR;
		}

int b;
	 system("color a");
	 system("cls");
	  	printf("\n\t\t\t\t\t**");
	printf("\n\t\t\t\t\t#          WELCOME TO\t\t\t  #");
	printf("\n\t\t\t\t\t#   ONLINE VOTING MANAGEMENT SYSTEM           #");
	printf("\n\t\t\t\t\t**\n");
      printf("\t\t\t**\n");
      printf("\t\t\t\t                     CHOOSE ANYTHING YOU LIKE :\n");
      printf("\t\t\t**\n\n\n");
     printf("\n1.System");
     printf("\n2.MainSystem");
     printf("\n3.Exit");
     printf("\nEnter your choice>:-");
scanf("%d",&b);

switch (b){
	case 1:System();break;
	case 2:MainSystem();break;
		case 3:
		break;
}}
void System(){
	int a;
	system("color a");
	system("cls");
    printf("\n1.Election Schedule");
    printf("\n2.Nominee registration");
    printf("\n3.Elector Registration");
    printf("\n4.Elector Exit");

printf("\nEnter Your Choice>:-");
scanf("%d",&a);
switch(a)
{
	case 1:schedule();break;
	case 2:Nominee();break;
	case 3:Elector();break;
	case 4:
		break;
		
}
}
void MainSystem(){
 int ch;
 	system("color a");
 	system("cls");
    printf("\t\t\t1:AddNewNominee\n");
    printf("\t\t\t2:Nomineeview\n");
    printf("\t\t\t3:DeleteNominee\n");
    printf("\t\t\t4:UpdatenomineeDetails\n");
    printf("\t\t\t5:ViewelectorList\n");
    printf("\t\t\t6:AddNewelectorData\n");
    printf("\t\t\t7:SearchforElectors\n");
    printf("\t\t\t8:DeleteElectordetail\n");
    printf("\t\t\t9:UpdateElectordetail\n");
    printf("\t\t\t10:Viewresult\n\n");
   

    printf("\t\t\tEnter your choice>:-");
    scanf("%d",&ch);
    switch(ch){
	case 1: Nomineereg();break;
	case 2:Nomineeview();break;
    case 3:deletenominee();break;
	case 4:Nomineeupdate();break;
    case 5:ViewelectorList();break;
	case 6:Electorreg();break;
	case 7:Electorsearch();break;
	case 8:Electordelete();break;
	case 9:Electorupdate();break;
	case 10:break;
	default:printf("!!Out Of choice!!");break;
    }
}

void schedule()
{
	struct schedule_table s1;{
	FILE* file = fopen("schedule.txt", "w+");
		 char a='y';
		 while(a=='y')
{

printf("\nEnter Constituency:");
scanf("%s",s1.Constituency);
printf("\n Enter date:");
scanf("%s",s1.date);
printf("%s\t%s",s1.Constituency,s1.date);
printf("\nDo you want to Continue (y/n)?");
a=getche();

	fprintf(file,"%s\t%s\n",&s1.Constituency,s1.date);
		if(a=='y')
				{
					continue;
				}
				System(); 
	}
		fclose(file);
}
	
	};


void Nominee()
{
	struct Nominee_table c1;{
		FILE* file = fopen("Nomineelist.txt", "a");
		FILE* file2 = fopen("Electionresult.txt", "a");
		char a='y';
		while (a=='y'){
			printf("\nenter name of Nominee:");
			scanf("%s",&c1.NomineeName);
			printf("enter political party:");
			scanf("%s",&c1.PoliticalParty);
			printf("enter Nominee from:");
			scanf("%s",&c1.Nomineefrom);
			printf("%s\t\t\t\t%s\t\t\t\t%s\n",&c1.NomineeName, &c1.PoliticalParty, &c1.Nomineefrom);
			printf("you want to enter more(y/n):\n");
			a=getche();
			fprintf(file,"%s\t\t\t\t%s\t\t\t\t%s\n",&c1.NomineeName,&c1.PoliticalParty,&c1.Nomineefrom);
//			Take a new eletor to  register  initial with 0 electorcount 
			fprintf(file2,"%s\t\t\t\t%s\t\t\t\t%s\t\t\t%d\n",&c1.NomineeName,&c1.PoliticalParty,&c1.Nomineefrom,0);
				if(a=='y')
				{
					continue;
				}
				System(); 
			}
			
					 fclose(file);	
		}
	};

void Elector()

{	
	struct Elector_table v1;
	int b,age;

		FILE* file = fopen("Electorlist.txt", "w+");
		
		char in='y';	

			while(in=='y')
				{
				printf("\nEnter your date of birth:");
				scanf("%d",&b);
				age=2023-b;
					if(age>18)
					{
					printf("Congratulation you are eligible for voting\n");
						{
						printf("\nEnter Elector serial no:");
						scanf("%d",&v1.ElectorsNo);
						printf("Enter Elector Name:");
						scanf("%s",v1.Electorname);
						printf("Enter your date of birth:");
						scanf("%s",v1.Dateofbirth);
						printf("Enter the address:");
						scanf("%s",v1.Address);
						printf("\nEnter the password:");
						scanf("%s",v1.password);
						printf("%d\t\t%s\t%s\t%s\t\t%s\n",*v1.ElectorsNo,v1.Electorname,v1.Dateofbirth,v1.Address,v1.password);
						printf("\nDo you want to Continue(y/n):");
						
						fprintf(file,"%d\t\t%s\t%s\t%s\t\t%s\n",*v1.ElectorsNo,v1.Electorname,v1.Dateofbirth,v1.Address,v1.password);
						in=getche();
						if(in=='y')
						{
							continue;
						}}
						Adminstrator(); 
						}else{
			printf("not eligible to vote");break;

		}
				fclose(file);
		}
		
	}
	
	
	struct Nominee_table c2; 
	struct Nominee_table VoterList[MAX_NOMINEES];
	int numnominess = 0;
	
	void Nomineereg(){
		 {
    if (numnominess >= MAX_NOMINEES) {
        printf("Maximum number of Nominee reached!\n");
        return;}
    printf("Enter your name: ");
    scanf("%s", &c2.NomineeName);
    printf("Enter political party: ");
    scanf("%s", &c2.PoliticalParty);
    printf("Enter nomine from: ");
    scanf("%s", &c2.Nomineefrom);

    VoterList[numnominess++] = c2;

    FILE* file = fopen("Nomineelist.txt", "w+");
    fprintf(file, "%s,%s,%s\n", &c2.NomineeName, &c2.PoliticalParty, &c2.Nomineefrom);
    fclose(file);

    printf("Nominee added successfully!\n");
   
    
}

    }
		struct Nominee_table c2; 
	char NomineeName[100];
	char PoliticalParty[50];
	char Nomineefrom[50];

	void Nomineeview(){

  FILE* file = fopen("Nomineelist.txt", "r");
    if (file == NULL) {
        printf("Error while opening a file.");
        
    }
    printf("Nominee Name\t\tPolitical Party\t\tNominee From\n");
    while(fscanf(file, "%10s   %15s    %20s", c1.NomineeName, c1.PoliticalParty, c1.Nomineefrom) != EOF) {
        printf("%10s  \t\t\t%15s    \t\t\t%20s\n", c1.NomineeName, c1.PoliticalParty, c1.Nomineefrom);
    }
    fclose(file);
}

	
    void deletenominee(){
    char name[100];
	char PoliticalParty[50];
	char constituency[50];
    printf("Enter the details of Nominee you want to delete:\n");
    printf("Nominee name: ");
    scanf("%s", c1.NomineeName);
    printf("Political party: ");
    scanf("%s",c1.PoliticalParty);
    printf("Constituency: ");
    scanf("%s", s1.Constituency);
    
    // Open the list of Nominee file in read mode
    FILE* file = fopen("Nomineelist.txt", "r");
    // temporary file created to store the updated candidate list
    FILE* temp_file = fopen("temp_Nomineelist.txt", "w+");
    
    if (file == NULL || temp_file == NULL) {
        printf("unable to  open  a file(s).\n");
        return;
    }
    
    int found = 0; 
    struct Nominee_table c1;
    while (fscanf(file, "%s %s %s", c1.NomineeName, c1.PoliticalParty, c1.Nomineefrom) != EOF) {
        // Checking whether nominee match or not
        if (strcmp(c1.NomineeName, c1.NomineeName) == 0 && strcmp(c1.PoliticalParty, c1.PoliticalParty) == 0 && strcmp(c1.Nomineefrom, s1.Constituency) == 0) {
            found = 1;
            printf("Nominee deleted successfully.\n");
        } else {
            // the temporary file is for nominee details
            fprintf(temp_file, "%s\t\t\t\t%s\t\t\t\t%s\n", c1.NomineeName, c1.PoliticalParty, c1.Nomineefrom);
        }
    }
    
    // closing file
    fclose(file);
    fclose(temp_file);
    
    //temporary file is replaced by original file
    remove("Nomineelist.txt");
    rename("temp_Nomineelist.txt", "Nomineelist.txt");
    
    if (!found) {
        printf("Nominee not found.\n");
    }
}

    void Nomineeupdate(){
	        char name[70];
	char PoliticalParty[20];
	char constituency[40];
	
	  printf("Enter the name of the Nominee you want to update:\n");
    scanf("%s", name);
	  // Opening the nominee list 
    FILE* file = fopen("Nomineelist.txt", "r");
    // Creating a temporary file to store the Nominee update
    FILE* temp_file = fopen("temp_Nomineelist.txt", "w+");
    
    if (file == NULL || temp_file == NULL) {
        printf("Unable to open a file(s).\n");
        return;
    }
    
    int found = 0; // checking nominee whether is o
    struct Nominee_table c1;
    while (fscanf(file, "%s %s %s", c1.NomineeName, c1.PoliticalParty, c1.Nomineefrom) != EOF) {
        // Checking nominee match given by user
        if (strcmp(c1.NomineeName, name) == 0) {
            found = 1;
            printf("Enter the new details of the Nominee:\n");
            printf("Political party: ");
            scanf("%s", c1.PoliticalParty);
            printf("Constituency: ");
            scanf("%s", s1.Constituency);
            
            fprintf(temp_file, "%s\t\t\t\t%s\t\t\t\t%s\n", c1.NomineeName, c1.PoliticalParty, s1.Constituency);
            printf("Nominee info updated successfully.\n");
        } else {
            //nominee details storing in file
            fprintf(temp_file, "%s\t\t\t\t%s\t\t\t\t%s\n", c1.NomineeName, c1.PoliticalParty, c1.Nomineefrom);
        }
    }
    
    // Closing the files
    fclose(file);
    fclose(temp_file);
    
    // replacing old nominee file with new
    remove("Nomineelist.txt");
    rename("temp_Nomineelist.txt", "Nomineelist.txt");
    
    if (!found) {
        printf("Nominee was not found.\n");
    }
	}

struct Elector_table v2; 
	int ElectorNO[120];
	char Electorname[100];
	int DOB[50];
	char Address[50];
	char password[15];
	
    void ViewelectorList(){
	FILE* file = fopen("Electorlist.txt", "r");
    if (file == NULL) {
        printf("Unable to  open a file.");
        
    }
    printf("ElectorsNO\t\tElectorname\t\tDOB\t\tAddress\t\tpassword\n");
    while(fscanf(file, "%d %s %d %s %s",v1.ElectorsNo,&v1.Electorname,v1.Dateofbirth,&v1.Address,&v1.password) != EOF) {
        printf("%d\t\t%s\t\t%d\t\t%s\t\t%s\n",v1.ElectorsNo,&v1.Electorname,v1.Dateofbirth,&v1.Address,&v1.password);
    }
    fclose(file);
}


    	struct Elector_table v2; 
		struct Elector_table  Electorlist[MAX_ELECTOR];
		int numElector = 0;
	
	void Electorreg() {
		 			int a='y';
		while (a=='y'){
    if (numElector >= MAX_ELECTOR) {
        printf("Maximum number of Electors reached!\n");
        return;}
		printf("\nEnter Elector serial no:");
		scanf("%d",&v1.ElectorsNo);
		printf("Enter Elector name:");
		scanf("%s",&v1.Electorname);
		printf("Enter date of birth:");
		scanf("%d",&v1.Dateofbirth);
		printf("Enter the address:");
		scanf("%s",&v1.Address);
		printf("Enter password:");
		scanf("%s",&v1.password);
		printf("Do you want to continue(y/n))");
			a=getche();
    Electorlist[numElector++] = v2;

    FILE* file = fopen("Electorlist.txt", "w+");
	fprintf(file,"%d\t%s\t%d\t%s\t%s\n",v1.ElectorsNo,&v1.Electorname,v1.Dateofbirth,&v1.Address,&v1.password);
    fclose(file);
}
    printf("Elector added successfully!\n");
}

    struct Elector_table v2;
	 struct Elector_table Electorlist[MAX_ELECTOR];
	
	void Electorsearch(){
		int idToSearch;

    FILE *file = fopen("Electorlist.txt", "r");
    if (file == NULL) {
        printf("Unable  to open a file.\n");
        exit(1);
    }


        // Reading elector info store in array
    while (fscanf(file, "%d [^\n] %[^\n]", &Electorlist[numElector].ElectorsNo, &Electorlist[numElector].Electorname, &Electorlist[numElector].Address) != EOF) {
        numElector++;
    }
    	
    
    printf("Enter ID of Elector to search: ");
    scanf("%d", &idToSearch);
    int z, found = 0;
    for (z = 0; z < numElector; z++) {
        if (Electorlist[z].ElectorsNo == &idToSearch) {
            printf("Elector found!\n");
            printf("Elector Serial No: %d\n", &Electorlist[z].ElectorsNo);
            printf("Elector  Name: %s\n", &Electorlist[z].Electorname);
            printf("Date of Birth: %d\n", &Electorlist[z].Dateofbirth);
            printf("Address: %s\n", &Electorlist[z].Address);
            found = 1;
            break;
        }
    }
        	fclose(file);
    if (!found) {
        printf("Elector with serial no %d not found!\n", ElectorNO);
    }

}
    void Electordelete(){
    int ElectorsNO;
    char Electorname[100];
    char DOB[10];
    char Address[60];
    char password[8];

    printf("Enter the details of Elector you want to delete:\n");
    printf("\nEnter Elector serial number:");
    scanf("%d",v1.ElectorsNo);
    printf("Enter Elector name:");
    scanf("%s",v1.Electorname);
    printf("Enter date of birth:");
    scanf("%s",v1.Dateofbirth);
    printf("Enter the Address:");
    scanf("%s",v1.Address);
    printf("Enter password:");
    scanf("%s",v1.password);

    // Opening a file
    FILE* file = fopen("Electorlist.txt", "r");
    // file is created to update 
    FILE* temp_file = fopen("temp_Electorlist.txt", "w+");

    if (file == NULL || temp_file == NULL) {
        printf("Unable to open a file(s).\n");
        return;
    }
    int found = 0; 
    struct Elector_table v1;
    while (fscanf(file, "%d\t%s\t%s\t%s\t%s\n",v1.ElectorsNo,v1.Electorname,v1.Dateofbirth,v1.Address,v1.password) != EOF) {
        // cross checking wheter nominee match or not
        if (v1.ElectorsNo == &ElectorsNO && strcmp(v1.Electorname, Electorname) == 0 && v1.Dateofbirth == DOB && strcmp(v1.Address, Address) == 0 && strcmp(v1.password, password) == 0)
        
        {
            found = 1;
            printf("Elector deleted successfull.\n");
			}
		else {
            
            fprintf(temp_file,"%d\t%s\t%d\t%s\t%s\n",v1.ElectorsNo,v1.Electorname,v1.Dateofbirth,v1.Address,v1.password);
        }
    

    // closing a file
    fclose(file);
    fclose(temp_file);

    //replacing with new file
    remove("Electorlist.txt");
    rename("temp_Electorlist.txt", "Electorlist.txt");

    if (!found) {
        printf("Elector not available.\n");
    }
}
   }
   
    void Electorupdate(){

	int ElectorsNO;
    char Electorname[100];
    int DOB;
    char Address[60];
    char password[8];
	
	  printf("Enter the name of the Elector you like to update:\n");
    scanf("%s", Electorname);
    
	  
    FILE* file = fopen("Electorlist.txt", "r");
    //storing a  new info 
    FILE* temp_file = fopen("temp_Electorlist.txt", "w+");
    
    if (file == NULL || temp_file == NULL) {
        printf("Unable to open a file(s).\n");
        return;
    }
    
    int found = 0; 
     struct Elector_table v2;
    while (fscanf(file, "%d\t%s\t%d\t%s\t%s\n",&v1.ElectorsNo,&v1.Electorname,&v1.Dateofbirth,&v1.Address,&v1.password) != EOF) {
        
        if (strcmp(v1.Electorname, v1.Electorname) == 0) {
            found = 1;
            printf("Enter the new details of the Nominee:\n");
            printf("Elector serial no: ");
            scanf("%d", v1.ElectorsNo);
            printf("Date of birth: ");
            scanf("%d", v1.Dateofbirth);
              printf("Address: ");
            scanf("%s", v1.Address);
            printf("password:");
            scanf("%s",v1.password);
            
            fprintf(temp_file,"%d\t%s\t%d\t%s\t%s\n",v1.ElectorsNo,v1.Electorname,v1.Dateofbirth,v1.Address,v1.password);
            printf("Nominee details updated successfully.\n");
        } else {
            
            fprintf(temp_file,"%d\t%s\t%d\t%s\t%s\n",v1.ElectorsNo,v1.Electorname,v1.Dateofbirth,v1.Address,v1.password);
        }
    }
    
    // Closing the files
    fclose(file);
    fclose(temp_file);
    
    // updating new file 
    remove("Electorlist.txt");
    rename("temp_Electorlist.txt", "Electorlist.txt");
    
    if (!found) {
        printf("Elector not Available.\n");
    }
	}

    void electionresult();
    
    
   void Electors()
   {
   	int a;
   	system("color a");
   	system("cls");
   	printf("\t\t\t\n1.View Nomination Schedule");
   	printf("\t\t\t\n2.View Nominee");
	printf("\n3.Search Nominee");
	printf("\t\t\t\n4.Update Elector");
	printf("\t\t\t\n5.Delete Elector");
	printf("\t\t\t\n6.View Elector");
	printf("\t\t\t\n7.Cast vote");
	printf("\t\t\t\n8.View result");	
	printf("\t\t\t\n9.Search result");
	printf("\t\t\t\n10.Exit");
   	printf("\t\t\t\nenter your choice:");
   	scanf("%d",&a);
   	switch (a){
   		case 1:viewschedule();break;
   		case 2:viewnominee();break;
   		case 3:searchNominee();break;
   		case 4:updateelector();break;
   		case 5:deleteelector();break;
   		case 6:viewelector();break;
   		case 7:castvote();break;
   		case 8:viewelectorresult();break;
   		case 9:searchelectorresult();break;
   		default:
   			printf("!!--Out Of Choices--!!");
		    break;
		    if (Electors == 0) 
	printf("\n\tNo such thing found  choose other!! Press Any Key To Continue\n");
    else printf("\n\t\t\tPress Any Key To Continue!");
	   }
	    
}
void viewschedule(){
    FILE *fc;
    char c;

    fc = fopen("schedule.txt", "r"); // opening a file 

    if(fc == NULL) { 
        printf("Unable to open a file.\n");
    }

    printf("Election schedule:\n\n");

    while((c = fgetc(fc)) != EOF) { 
        printf("%c", c);
    }

    fclose(fc); // closing file

}

void viewnominee(){
    FILE *fc;
    char c;

    fc = fopen("Nomineelist.txt", "r"); 
    if(fc == NULL) { // checking filed open or not
        printf("Unable to open a file.\n");
    }

    printf(" Nominee List:\n\n");

    while((c = fgetc(fc)) != EOF) { // Reading file until EOF
        printf("%c", c);
    }

    fclose(fc); // closing a file

}

struct Nominee_table Nomineelist[MAX_NOMINEES];

void searchNominee() {
    int numNominee = 0;

    FILE *file = fopen("Nomineelist.txt", "r");
    if (file == NULL) {
        printf("Unable to open a file.\n");
    }

    // Nominee file stored in a array
    while (fscanf(file, "%s %s %[^\n]", Nomineelist[numNominee].NomineeName, Nomineelist[numNominee].PoliticalParty, Nomineelist[numNominee].Nomineefrom) != EOF) {
        numNominee++;
    }

    // user are resquest to search nominee
    char nametosearch[100];
    printf("Enter Nominee you want to search: ");
    scanf("%s", nametosearch);

    int k, found = 0;
    for (k = 0; k < numNominee; k++) {
        if (strcmp(Nomineelist[k].NomineeName, nametosearch) == 0) {
            printf("Nominee found!\n");
            printf("Nominee name: %s\n", Nomineelist[k].NomineeName);
            printf("Political Party: %s\n", Nomineelist[k].PoliticalParty);
            printf("Nominee From: %s\n", Nomineelist[k].Nomineefrom);
            found = 1;
            break;
        }
    }
    fclose(file);
    if (!found) {
        printf("Nominee name of %s not found!\n", nametosearch);
    }
}
 
 void updateelector(){
    int ElectorsNO[100];
	char Electorname[100];
	int DOB[40];
	char Address[60];
	char password[8];
	
	printf("\nEnter the name of the Elector you like to update:");
    scanf("%s",Electorname);
	  
    FILE* file = fopen("Electorlist.txt", "r");
    // creating to store info 
    FILE* temp_file = fopen("temp_Electorlist.txt", "w+");
    
    if (file == NULL || temp_file == NULL) {
        printf("Unable to open a file(s).\n");
        return;
    }
    
    int found = 0; 
    struct Elector_table v1;
    while (fscanf(file, "%d\t%s\t%d\t%s\t%s\n",&v1.ElectorsNo,v1.Electorname,&v1.Dateofbirth,v1.Address,v1.password) != EOF) {
    
        if (strcmp(v1.Electorname,v1.Electorname) == 0) {
            found = 1;
            printf("\nEnter the new details of the Elector:");
            printf("Elector serial no: ");
            scanf("%d", v1.ElectorsNo);
            printf("Elector name: ");
            scanf("%s", &v1.Electorname);
            printf("Elector date of birth:");
            scanf("%d",v1.Dateofbirth);
            printf("Elector address:");
            scanf("%s",v1.Address);
            printf("Elector password:");
            scanf("%s",v1.password);
            
            fprintf(temp_file, "%d\t%s\t%d\t%s\t%s\n",v1.ElectorsNo,&v1.Electorname,v1.Dateofbirth,v1.Address,v1.password);
            printf("Elector details updated successfull.\n");
        } else {
            
            fprintf(temp_file,  "%d\t%s\t%d\t%s\t%s\n",v1.ElectorsNo,v1.Electorname,v1.Dateofbirth,v1.Address,v1.password);
        }
    }
    
    // Closing the files
    fclose(file);
    fclose(temp_file);
    
    // updating the nominee info
    remove("Electorlist.txt");
    rename("temp_Electorlist.txt", "Electorlist.txt");
    
    if (!found) {
        printf("Elector not available.\n");
    }
	}
void deleteelector(){
    int ElectorsNO;
    char Electorname[100];
    char DOB[10];
    char Address[60];
    char password[8];

    printf("Enter the details of Elector you like to delete:\n");
    printf("\nEnter Elector serial no:");
    scanf("%d",&v1.ElectorsNo);
    printf("Enter Elector name:");
    scanf("%s",&v1.Electorname);
    printf("Enter date of birth:");
    scanf("%s",&v1.Dateofbirth);
    printf("Enter the address:");
    scanf("%s",&v1.Address);
    printf("Enter password:");
    scanf("%s",&v1.password);

    // Opening a file
    FILE* file = fopen("Electorlist.txt", "r");
    // creating temp file to update info
    FILE* temp_file = fopen("temp_Electorlist.txt", "w+");

    if (file == NULL || temp_file == NULL) {
        printf("Unable to open a file(s).\n");
        return;
    }
    int found = 0; 
    struct Elector_table v1;
    while (fscanf(file, "%d\t%s\t%d\t%s\t%s\n",&v1.ElectorsNo,v1.Electorname,&v1.Dateofbirth,v1.Address,v1.password) != EOF) {
        
        if (v1.ElectorsNo == &ElectorsNO && strcmp(v1.Electorname, Electorname) == 0 && v1.Dateofbirth == DOB && strcmp(v1.Address, Address) == 0 && strcmp(v1.password, password) == 0)
        
        {
            found = 1;
            printf("Elector deleted successfull.\n");
			}
		else {
            
            fprintf(temp_file,"%d\t%s\t%d\t%s\t%s\n",v1.ElectorsNo,v1.Electorname,v1.Dateofbirth,v1.Address,v1.password);
        }
    

    //Closing a file
    fclose(file);
    fclose(temp_file);

    //replacing with orignal file
    remove("Electorlist.txt");
    rename("temp_Electorlist.txt", "Electorlist.txt");

    if (!found) {
        printf("Elector not found.\n");
    }
}
   }
   void viewelector(){
	FILE* file = fopen("Electorlist.txt", "r");
    if (file == NULL) {
        printf("Unable to  open a file.");
        
    }
    printf("ElectorsNO\t\tElectorname\t\tDOB\t\tAddress\t\tpassword\n");
    while(fscanf(file, "%d %s %d %s %s",v1.ElectorsNo,&v1.Electorname,v1.Dateofbirth,&v1.Address,&v1.password) != EOF) {
        printf("%d\t\t%s\t\t%d\t\t%s\t\t%s\n",v1.ElectorsNo,&v1.Electorname,v1.Dateofbirth,&v1.Address,&v1.password);
      }
     fclose(file);
   }
  Voidcastvote();