#include<stdio.h>
#include<string.h>
typedef struct customer{
    long phno;
    char name[20];
    char status[20];
    char type[20];
    char selection[20];
}customer;


void display();
void registration();
void activateDND();
void deactivateDND();
void dial();
void changeDndService();

int main(){
    int service;
    do
    {
        printf("\n ........Welcome to Capegimini....... \n");
        printf("\n Press 1. Registration \n Press 2. Activate DND\n Press 3. Dial");
        printf("\n Press 4. Change DND Service");
        printf("\n Press 5. Display Record");
        printf("\n Press 6. Deactivate DND");
        printf("\n Press 7. Exit \n");
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

        case 4:
            changeDndService();
            break;

        case 5:
            display();
            break;

        case 6:
            deactivateDND();
            break;

        case 7:
            printf("\n\nThanks.....\n\n");
            break;

        default:
            printf("Error! choice is not correct");
        }
    }
    while(service != 7);
    return 0;
}

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

void changeDndService() {
    void activateDND();
    int search(long uphno);
    int check;
    long uphno;
    printf("****Welcome to Update DND Service****");
    printf("\n Enter your PhoneNo : ");
    scanf("%ld",&uphno);
    check = search(uphno);
    if (check == 2 ){
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
            printf("\n DND deactivated now you can change the type of dnd from next menu");
            activateDND();
        }
        else{
            printf("\n Data Not Found.....\n");
        }
    }
    else{
        printf("\n No DND service is activated on your number.");
    }

}

void dial(){
    int gs,found;
    long uphno;
    printf("****  Dial  Number ****");
    printf("\n Enter your PhoneNo : ");
    scanf("%ld",&uphno);
    printf("Select Call Type\n");
    printf("\n Press 1.Promotion Call\n Press 2. Feedback call\n Press 3. Company call\n Press 4. Normal\nPress 5. Exit\n");
    scanf("%d", &gs);
    customer s1;
    FILE *fp;
    fp = fopen("mydata.txt","r");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno)
            {
                found = 1;
                if(strcmp(s1.status,"Enable") == 0)
                {
                    if(strcmp(s1.type, "Selective") == 0)
                    {
                        switch(gs) {
                        case 1:
                            if(strcmp(s1.selection,"Promotional_Call") == 0) {
                                found = 6;
                                break;
                            }else {
                                found = 7;
                                break;
                            }
                        case 2:
                            if(strcmp(s1.selection,"Feedback_Call")==0) {
                                found = 6;
                                break;
                            }else {
                                found = 7;
                                break;
                            }
                        case 3:
                            if(strcmp(s1.selection,"Company_Call")==0) {
                                found = 6;
                                break;
                            }else {
                                found = 7;
                                break;
                            }
                        case 4:
                                found = 7;
                        }
                    }
                    else{
                        found = 3; // if global
                    }
                }else
                {
                   found =2; // is disable in data
                }
            }
        }
        if(!found){
        printf("\n Not Found.....\n");
        }
        fclose(fp);
    // decision logic
    if (found == 3 || found == 6){
        printf("User has opt for DND, Your call will not connect on this number");
    }
    else{
        printf("....... Call is Connecting ......\n\n");
    }
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
    int search_deactivate(long uphno);
    int gs,check;
    long uphno;
    printf("****Welcome to Deactive DND Service***");
    printf("\n Enter your PhoneNo : ");
    scanf("%ld",&uphno);
    check = search_deactivate(uphno);
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
    else if ( check == 0){
        printf(" User is not registered. Do Registration by entering choice no 1.\n\n");
    }
    else{
        printf("\n Thank you");
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
                if(strcmp(s1.status,"Enable") == 0){
                    printf("%s DND is already activated", s1.type);
                    found = 2;
                }
                else{
                    found = 1;
                }
            //printf("\n%ld--%s--%s",s1.phno,s1.name,s1.status);
            }
        }
        if(!found){
        printf("\n Data Not Found.....\n");}
        fclose(fp);
        return found;

}

int search_deactivate(long uphno){
    customer s1;
        FILE *fp;
        int found = 0;
        fp = fopen("mydata.txt","r");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == uphno){
                if(strcmp(s1.status,"Disable") == 0){
                    printf("\n No DND service is activated on your number");
                    found = 2;
                    break;
                }
                else{
                    found = 1;
                }
            //printf("\n%ld--%s--%s",s1.phno,s1.name,s1.status);
            }
        }
        if(!found){
        printf("\n Data Not Found.....\n");}
        fclose(fp);
        return found;

}

void global() {
    void Active_globaldnd(long uphno);
    int search(long uphno);
    int gs,check;
    long uphno;
    printf("****Welcome to Global Service****");
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
    else if( check == 0){
        printf(" User is not registered. Do Registration by entering choice no 1.\n\n");
    }
    else{
        printf("\nThank you");
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
printf("**Welcome to Selective Service*");
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
else if( check == 0){
        printf(" User is not registered. Do Registration by entering choice no 1.\n\n");
    }
    else{
        printf("\nThank you");
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
            printf("\n Press 1. Promotional Call\n Press 2. Feedback call\n Press 3. Company call\n");
            printf("\nEnter Your Choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                strcpy(s1.selection, "Promotional_Call");
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
