// Program DND
#include <stdio.h>
#include<stdbool.h>  
void global();
void selective();

bool x = false;

int main() {
 // file pointer
 FILE *ptr;
 // open file in writing mode
 ptr = fopen("data.csv", "a+");
char name[20];
int phone,service;

 // write header in file
//fprintf(ptr, "name, phone_no \n");

printf("\n Enter your name:");
scanf("%s",&name[0]);
printf("\n Enter your phone number:");
scanf("%d",&phone);

 
 
printf("\n Select your choice from the two options:");
printf("\n Press 1. Global Service\n Press 2. Selective Service\n");
scanf("%d",&service);

    switch(service)
    {
        case 1:
           global();
            service = 1;
            // write data in file in comma format
            fprintf(ptr, "%s,%d,%d\n", name, phone,service);
            break;

        case 2:
           selective();
            break;

        default:
            printf("Error! choice is not correct");
    }
    return 0;
}


void global() {
    //printf("hii");
void Active_dnd();
void change_service();
bool x=false; // variable initialization.  
int gs;
printf("\n Select your choice from the two options:");
printf("\n Press 1. Activated DND\n Press 2. Change Services\n");
scanf("%d",&gs);

switch(gs)
{
    case 1:
    Active_dnd();
    break;
    
    case 2:
    change_service();
    break;
    
    default:
    printf("Error! choice is not correct");
}
}



void Active_dnd() 
{
if(x==false) // conditional statements  
{  
    bool x = true;
    printf("DND service Activated \n");
    printf("All Calls and SMS are blocked");
}
}


void change_service()
{
    bool x = false;
    printf("DND service Deactivated\n");
    //printf("Call Connecting..............");
}

 
void selective(){
     printf("bye");
}