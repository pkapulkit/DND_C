#include<stdio.h>
typedef struct customer{
    int phno; //Member of structure
    char name[20]; //Pointer within structure
    char status[20];
}customer;

void create(){
        customer s;
        FILE *fp;
        // s = (customer*)calloc(n,sizeof(customer));
        fp = fopen("mydata.txt","w+");

        // for(i=0;i<n;i++){
        //     s[i].total=0;
        //     s[i].per=0;
            printf("Enter PhoneNo : ");
            scanf("%d",&s.phno);
            fflush(stdin);
            printf("Enter Name : ");
            scanf("%s",s.name);
            printf("Enter Status : ");
            scanf("%s",s.status);
            // for(j=0;j<3;j++){
            //     printf("Enter Marks of Sub%d : ",j+1);
            //     scanf("%d",&s[i].sub[j].mark);
            //     s[i].total += s[i].sub[j].mark;
            // }
            // s[i].per = s[i].total / 3.0;

            fwrite(&s,sizeof(customer),1,fp);
        fclose(fp);
}

void display(){
     customer s1;
        FILE *fp;
        int j;
        fp = fopen("mydata.txt","r");
        printf("\nPhone_No--Name--Status");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            printf("\n%d--%s--%s",s1.phno,s1.name,s1.status);
        }
        fclose(fp);
}

void append(){
        customer s;
        FILE *fp;
        // s = (customer*)calloc(n,sizeof(customer));
        fp = fopen("mydata.txt","a+");

        // for(i=0;i<n;i++){
        //     s[i].total=0;
        //     s[i].per=0;
            printf("Enter PhoneNo : ");
            scanf("%d",&s.phno);
            fflush(stdin);
            printf("Enter Name : ");
            scanf("%s",s.name);
            printf("Enter Status : ");
            scanf("%s",s.status);
            // for(j=0;j<3;j++){
            //     printf("Enter Marks of Sub%d : ",j+1);
            //     scanf("%d",&s[i].sub[j].mark);
            //     s[i].total += s[i].sub[j].mark;
            // }
            // s[i].per = s[i].total / 3.0;

            fwrite(&s,sizeof(customer),1,fp);
        fclose(fp);
}

void count(){
        customer s1;
        FILE *fp;
        fp = fopen("mydata.txt","r");
        fseek(fp,0,SEEK_END);
        int n = ftell(fp)/sizeof(customer);
        printf("\nNo of Records = %d\n",n);
        fclose(fp);
}

void search(){
    customer s1;
        FILE *fp;
        int phno, found = 0;
        fp = fopen("mydata.txt","r");
        printf("Enter the phone no: ");
        scanf("%d",&phno);
        printf("\nPhone_No--Name--Status");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == phno){
            found = 1;
            printf("\n%d--%s--%s",s1.phno,s1.name,s1.status);
            }
        }
        if(!found){
        printf("\nNot Found.....\n");}
        fclose(fp);
}

void update(){
    customer s1;
        FILE *fp, *fp1;
        int phno, found = 0;
        fp = fopen("mydata.txt","r");
        fp1 = fopen("temp.txt","w");
        printf("Enter the phone no: ");
        scanf("%d",&phno);
        // printf("\nPhone_No--Name--Status");
        while(fread(&s1,sizeof(customer),1,fp))
        {
            if(s1.phno == phno){
            found = 1;
            //printf("\n%d--%s--%s",s1.phno,s1.name,s1.status);
            printf("Enter new Status : ");
            scanf("%s",s1.status);
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
            printf("\nSuccessful.....\n");
        }
        else{
            printf("\nNot Found.....\n");
        }
        
}

void create();
void display();
void append();
void count();
void search();
void update();

int main(){
    int ch;
    do{
        printf("\n1.CREATE");
        printf("\n2.APPEND");
        printf("\n3.DISPLAY");
        printf("\n4.NO OF RECORDS");
        printf("\n5.SEARCH");
        printf("\n6.UPDATE");
        // printf("\n7.DELETE");
        // printf("\n8.SORT IN FILE BY TOTAL DESC");
        // printf("\n9.SORT ON SCREEN BY TOTAL DESC");
        // printf("\n10.SORT ON SCREEN BY NAME");
        printf("\n0.EXIT");
        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
                create();
            break;
        case 2:
                append();
            break;
        case 3:
                display();
            break;
        case 4:
                count();
        break;
        case 5:
                search();
        break;
        case 6:
                update();
            break;
        //     case 7:
        //         delete_rec();
        //     break;
        //     case 8:
        //         sort_in_file();
        //         break;
        //     case 9:
        //         sort_on_screen();
        //     break;
        //     case 10:
        //         sort_by_name();
        //     break;
        case 0:
                printf("\n\nThanks.....\n\n");
        }
        }while(ch!=0);

    return 0;
}