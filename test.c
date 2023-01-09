// Code for saving data in csv file
#include <stdio.h>

int main(){
    // file pointer
    FILE *ptr;
    // open file in writing mode
    ptr = fopen("data.csv", "w");
    // total no of customer declaration
    int total;

    printf("Enter Total no. of customers: ");
    scanf("%d", &total);
    // declaration of variable to store name and phone no
    char name[20];
    int phno;
    char status[20] = "default";
    // write header in file
    fprintf(ptr, "name,phone_no,status \n");
    //loop for storing individual customer
    for (int i=0; i < total; i++)
    {
    printf("Enter recipient's name: \n"); 
    scanf("%s", &name[0]); 
    printf("Enter phone no: \n");
    scanf("%d", &phno);
    // write data in file in comma format
    fprintf(ptr, "%s,%d,%s\n", name, phno,status);
    }
    return 0;
}