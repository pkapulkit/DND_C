#include<stdio.h>
#include<string.h>
typedef struct customer{
    long phno; 
    char name[20]; 
    char status[20];
    char type[20];
    char selection[20];
}customer;

void registration(){
        customer s;
        FILE *fp;
        fp = fopen("mydata.txt","a+");
        printf("Enter PhoneNo : ");
        scanf("%ld",&s.phno);
        printf("Enter Name : ");
        scanf("%s",s.name);
        strcpy(s.status, "Disable");
        strcpy(s.type, "None");
        strcpy(s.selection, "None");
        fwrite(&s,sizeof(customer),1,fp);
        fclose(fp);
}
void display(){
     customer s1;
        FILE *fp;
        int j;
        fp = fopen("mydata.txt","r");
        printf("\nPhone_No--Name--Status--Type--Selection");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            printf("\n%ld--%s--%s--%s--%s",s1.phno,s1.name,s1.status,s1.type,s1.selection);
        }
        fclose(fp);
}
void display();
void registration();
void activateDND();
void deactivateDND();
void dial();

int main(){
    int service;
    do{
    printf("\n ........Welcome to Capegimini....... \n");
    printf("\n Press 1. Registration \n Press 2. Activate DND\n Press 3. Dial");
    printf("\n Press 4. Change DND Service");
    printf("\n Press 5. Display Record");
    printf("\n Press 9. Deactivate DND");
    printf("\n Press 6. Exit \n");
    printf("\nEnter Your Choice : ");
    scanf("%d",&service);

    switch(service)
    {
        case 1:
            registration();
            break;

        case 2:
            activateDND();
            break;

        case 3:
            dial();
            break;

        case 5:
            display();
            break;
        case 6:
            printf("\n\nThanks.....\n\n");
            break;
        case 9:
            deactivateDND();
            break;

        default:
            printf("Error! choice is not correct");
    }
    }while(service != 6);
    return 0;
}

void dial(){
    // void deactive_dnd(long uphno);
    // int search(long uphno);
    // int gs,check;
    // long uphno;
    // printf("**********  Dial  Number **********");
    // printf("\n Enter your PhoneNo : ");
    // scanf("%ld",&uphno);
    // printf("Select Call Type\n");
    // printf("\n Press 1.Promotion Call\n Press 2. Feedback call\n Press 3. Company call\n Press 4. Normal\nPress 5. Exit\n")
    // scanf("%d", &gs)

    //     customer s1;
    //     FILE *fp;
    //     int found = 0;
    //     fp = fopen("mydata.txt","r");
    //     while(fread(&s1,sizeof(customer),1,fp))
    //     {
    //         if(s1.phno == uphno){
    //         found = 1;
    //          if(s1.status == "Enable")
    //          {
    //             if(s1.type == "Selective")
    //             {
    //                 switch(gs) {
    //                   case 1:
    //                   if(s1.selection == "Promotional_Call") {
    //                     found = 6;
    //                    break;
    //                   }else {
    //                     found = 7;
    //                     break;
    //                   }
    //                   case 2:
    //                    if(s1.selection == "feedback_Call") {
    //                     found = 6;
    //                    break;
    //                   }else {
    //                     found = 7;
    //                     break;
    //                   }
    //                    case 3:
    //                    if(s1.selection == "company_Call") {
    //                     found = 6;
    //                    break;
    //                   }else {
    //                     found = 7;
    //                     break;
    //                   }
    //                    case 4:
    //                    found = 7;
    //                   }

    //                 }
    //             }else
    //             {
    //                found =3;
    //             }
    //          else{
    //             found = 2;
    //          }


    //         //printf("\n%ld--%s--%s",s1.phno,s1.name,s1.status);
    //         }
    //     }
    //     if(!found){
    //     printf("\n Not Found.....\n");}
    //     fclose(fp);



    // check = search(uphno);


    // if (check == 1){
     

    //  switch(gs)
    //     {
    //         case 1:
    //         //deactive_dnd(uphno);
    //         break;
    
    //         case 5:
    //         printf("Thanks for choosing us, Enter choice from main menu\n\n");
    //         break;
    
    //         default:
    //         printf("Error! choice is not correct");
    //     }
    
    // }
    // else{
    //     printf(" User is not registered. Do Registration by entering choice no 1.\n\n");
    // }
}

void activateDND(){
    void global();
    void selective();
    int dnd;
    printf("\n Select your DND choice from the two options:");
    printf("\n Press 1. Global Service\n Press 2. Selective Service\n");
    printf("\nEnter Your Choice : ");
    scanf("%d",&dnd);
    switch(dnd)
    {
        case 1:
            global();
            break;

        case 2:
            selective();
            break;

        default:
            printf("Error! choice is not correct");
    }

}

void deactivateDND(){
    void deactive_dnd(long uphno);
    int search(long uphno);
    int gs,check;
    long uphno;
    printf("***********Welcome to Deactive DND Service**********");
    printf("\n Enter your PhoneNo : ");
    scanf("%ld",&uphno);
    check = search(uphno);
    if (check == 1){
        printf("\n Press 1. Deactivate DND\n Press 2. Exit\n");
        printf("\nEnter Your Choice : ");
        scanf("%d",&gs);

        switch(gs)
        {
            case 1:
            deactive_dnd(uphno);
            break;
    
            case 2:
            printf("Thanks for choosing us, Enter choice from main menu\n\n");
            break;
    
            default:
            printf("Error! choice is not correct");
        }
    
    }
    else{
        printf(" User is not registered. Do Registration by entering choice no 1.\n\n");
    }
}

void deactive_dnd(long uphno){
    customer s1;
        FILE *fp, *fp1;
        int found = 0;
        fp = fopen("mydata.txt","r");
        fp1 = fopen("temp.txt","w");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno){
            found = 1;
            strcpy(s1.status, "Disable");
            strcpy(s1.type, "None");
            strcpy(s1.selection, "None");
            }
            fwrite(&s1,sizeof(customer),1,fp1);
        }
        fclose(fp);
        fclose(fp1);
        if(found){
            fp = fopen("mydata.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(customer),1,fp1)){
                fwrite(&s1,sizeof(customer),1,fp);
            }
            fclose(fp);
            fclose(fp1);
            printf("\n DND Service successfully deactivated on your number\n");
        }
        else{
            printf("\n Not Found.....\n");
        }
}

int search(long uphno){
    customer s1;
        FILE *fp;
        int found = 0;
        fp = fopen("mydata.txt","r");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno){
            found = 1;
            //printf("\n%ld--%s--%s",s1.phno,s1.name,s1.status);
            }
        }
        if(!found){
        printf("\n Not Found.....\n");}
        fclose(fp);
        return found;

}

void global() {
    void Active_globaldnd(long uphno);
    void change_service();
    int search(long uphno);
    int gs,check;
    long uphno;
    printf("***********Welcome to Global Service**********");
    printf("\n Enter your PhoneNo : ");
    scanf("%ld",&uphno);
    check = search(uphno);
    if (check == 1){
    printf("\n Press 1. Activate Global DND\n Press 2. Exit\n");
    printf("\nEnter Your Choice : ");
    scanf("%d",&gs);

    switch(gs)
        {
        case 1:
        Active_globaldnd(uphno);
        break;
    
        case 2:
        printf("Thanks for choosing us, Enter choice from main menu\n\n");
        break;
    
        default:
        printf("Error! choice is not correct");
        }
    
    }
    else{
        printf(" User is not registered. Do Registration by entering choice no 1.\n\n");
    }
}



void Active_globaldnd(long uphno) 
{
customer s1;
        FILE *fp, *fp1;
        int found = 0;
        fp = fopen("mydata.txt","r");
        fp1 = fopen("temp.txt","w");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno){
            found = 1;
            strcpy(s1.status, "Enable");
            strcpy(s1.type, "Global");
            }
            fwrite(&s1,sizeof(customer),1,fp1);
        }
        fclose(fp);
        fclose(fp1);
        if(found){
            fp = fopen("mydata.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(customer),1,fp1)){
                fwrite(&s1,sizeof(customer),1,fp);
            }
            fclose(fp);
            fclose(fp1);
            printf("\n Global DND Service successfully activated on your number\n");
        }
        else{
            printf("\n Not Found.....\n");
        }
}

void selective() {
void Selective_dnd(long uphno);
int search(long uphno);
int gs,check;
long uphno;
printf("***Welcome to Selective Service**");
printf("\n Enter your PhoneNo : ");
scanf("%ld",&uphno);
check = search(uphno);
if (check == 1){
printf("\n Press 1. Activate Selective DND\n Press 2. Exit\n");
printf("\nEnter Your Choice : ");
scanf("%d",&gs);

switch(gs)
{
    case 1:
    Selective_dnd(uphno);
    break;

    case 2:
    printf("Thanks for choosing us, Enter choice from main menu\n\n");
    break;

    default:
    printf("Error! choice is not correct");
}

}
else{
    printf(" User is not registered. Do Registration by entering choice no 1.\n\n");
}
}

void Selective_dnd(long uphno)
{
customer s1;
        FILE *fp, *fp1;
        int found = 0,choice;
        char uselection[20];
        fp = fopen("mydata.txt","r");
        fp1 = fopen("temp.txt","w");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno){
            found = 1;
            printf("\n Press 1. Promotion Call\n Press 2. Feedback call\n Press 3. Company call\n");
            printf("\nEnter Your Choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                strcpy(s1.selection, "Promotion_Call");
                break;

                case 2:
                strcpy(s1.selection, "Feedback_Call");
                break;

                case 3:
                strcpy(s1.selection, "Company_Call");
                break;

                //default:
               // printf("Error! choice is not correct");
            }
            strcpy(s1.status, "Enable");
            strcpy(s1.type, "Selective");
            }
            fwrite(&s1,sizeof(customer),1,fp1);
        }
        fclose(fp);
        fclose(fp1);
        if(found){
            fp = fopen("mydata.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(customer),1,fp1)){
                fwrite(&s1,sizeof(customer),1,fp);
            }
            fclose(fp);
            fclose(fp1);
            printf("\n Selective DND Service successfully activated on your number\n");
        }
        else{
            printf("\n Not Found.....\n");
            }
}