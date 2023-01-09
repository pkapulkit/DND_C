/*Source Code of Video File Handling in C -
  INSERT, UPDATE, DELETE, SORT, SEARCH of STUDENT RECORD - IN FILE WITH STRUCTURE
*/
#include<stdio.h>
typedef struct student{
    int rno; //Member of structure
    char name[20]; //Pointer within structure
    struct subject{ //Structure within Structure
        int scode;
        char name[20]; //Array within structure
        int mark;
    }sub[3]; //Array of Structure
    int total;
    float per;
}student;

void create(){
        student *s;
        FILE *fp;
        int n,i,j;

        printf("Enter how many students : ");
        scanf("%d",&n);
        s = (student*)calloc(n,sizeof(student));
        fp = fopen("mystudents1.txt","w+");

        for(i=0;i<n;i++){
            s[i].total=0;
            s[i].per=0;
            printf("Enter RollNo : ");
            scanf("%d",&s[i].rno);
            fflush(stdin);
            printf("Enter Name : ");
            scanf("%[^\n]s",s[i].name);
            for(j=0;j<3;j++){
                printf("Enter Marks of Sub%d : ",j+1);
                scanf("%d",&s[i].sub[j].mark);
                s[i].total += s[i].sub[j].mark;
            }
            s[i].per = s[i].total / 3.0;

            fwrite(s+i,sizeof(student),1,fp);
        }
        fclose(fp);
}


void append(){
        student *s, s1;
        FILE *fp;
        int n,i,j;

        printf("Enter how many students : ");
        scanf("%d",&n);
        s = (student*)calloc(n,sizeof(student));
        fp = fopen("mystudents1.txt","a");

        for(i=0;i<n;i++){
            s[i].total=0;
            s[i].per=0;
            printf("Enter RollNo : ");
            scanf("%d",&s[i].rno);
            fflush(stdin);
            printf("Enter Name : ");
            scanf("%[^\n]s",s[i].name);
            for(j=0;j<3;j++){
                printf("Enter Marks of Sub%d : ",j+1);
                scanf("%d",&s[i].sub[j].mark);
                s[i].total += s[i].sub[j].mark;
            }
            s[i].per = s[i].total / 3.0;

            fwrite(s+i,sizeof(student),1,fp);
        }
        fclose(fp);
}

void search(){
    int i, j, found=0;
    student s1;
    FILE *fp;
    int rno;
    printf("Enter RollNo to Search : ");
    scanf("%d",&rno);

    fp = fopen("mystudents1.txt","r");
    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.rno == rno){
            found = 1;
            printf("\n%-5d%-20s",s1.rno,s1.name);
            for(j=0;j<3;j++){
                printf("%4d",s1.sub[j].mark);
            }
            printf("%5d%7.2f",s1.total,s1.per);
        }
    }
    if(!found)
        printf("\nNot Found.....\n");
    fclose(fp);
}

void update(){
    int i, j, found=0;
    student s1;
    FILE *fp, *fp1;
    int rno;
    printf("Enter RollNo to Update : ");
    scanf("%d",&rno);

    fp = fopen("mystudents1.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.rno == rno){
            found = 1;
            s1.total=0;
            s1.per=0;
            fflush(stdin);
            printf("Enter New Name : ");
            scanf("%[^\n]s",s1.name);
            for(j=0;j<3;j++){
                printf("Enter New Marks of Sub%d : ",j+1);
                scanf("%d",&s1.sub[j].mark);
                s1.total += s1.sub[j].mark;
            }
            s1.per = s1.total / 3.0;
        }
        fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
            fp = fopen("mystudents1.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(student),1,fp1)){
                fwrite(&s1,sizeof(student),1,fp);
            }
            fclose(fp);
            fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
}


void delete_rec(){
    int i, j, found=0;
    student s1;
    FILE *fp, *fp1;
    int rno;
    printf("Enter RollNo to Delete : ");
    scanf("%d",&rno);

    fp = fopen("mystudents1.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.rno == rno){
            found = 1;
        }
        else
            fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
            fp = fopen("mystudents1.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(student),1,fp1)){
                fwrite(&s1,sizeof(student),1,fp);
            }
            fclose(fp);
            fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
}


void count(){
        student s1;
        FILE *fp;
        fp = fopen("mystudents1.txt","r");
        fseek(fp,0,SEEK_END);
        int n = ftell(fp)/sizeof(student);
        printf("\nNo of Records = %d\n",n);
        fclose(fp);
}
void display(){
        student s1;
        FILE *fp;
        int j;
        fp = fopen("mystudents1.txt","r");
        while(fread(&s1,sizeof(student),1,fp))
        {
            printf("\n%-5d%-20s",s1.rno,s1.name);
            for(j=0;j<3;j++){
                printf("%4d",s1.sub[j].mark);
            }
            printf("%5d%7.2f",s1.total,s1.per);
        }
        fclose(fp);
}

void sort_on_screen(){
        student *s, s1;
        FILE *fp;
        fp = fopen("mystudents1.txt","r");
        fseek(fp,0,SEEK_END);
        int n = ftell(fp)/sizeof(student);
        int i,j;
        rewind(fp);
        s = (student*)calloc(n,sizeof(student));
        for(i=0;i<n;i++)
            fread(&s[i],sizeof(student),1,fp);

        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(s[i].total<s[j].total){
                    s1 = s[i];
                    s[i] = s[j];
                    s[j] = s1;
                }
            }
        }


        for(i=0;i<n;i++){
            printf("\n%-5d%-20s",s[i].rno,s[i].name);
            for(j=0;j<3;j++){
                printf("%4d",s[i].sub[j].mark);
            }
            printf("%5d%7.2f",s[i].total,s[i].per);
        }
        fclose(fp);
}

void sort_in_file(){

        student *s, s1;
        FILE *fp;
        fp = fopen("mystudents1.txt","r");
        fseek(fp,0,SEEK_END);
        int n = ftell(fp)/sizeof(student);
        int i,j;
        rewind(fp);
        s = (student*)calloc(n,sizeof(student));
        for(i=0;i<n;i++)
            fread(&s[i],sizeof(student),1,fp);

        fclose(fp);
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(s[i].total<s[j].total){
                    s1 = s[i];
                    s[i] = s[j];
                    s[j] = s1;
                }
            }
        }
        for(i=0;i<n;i++){
            printf("\n%-5d%-20s",s[i].rno,s[i].name);
            for(j=0;j<3;j++){
                printf("%4d",s[i].sub[j].mark);
            }
            printf("%5d%7.2f",s[i].total,s[i].per);
        }

        fp = fopen("mystudents1.txt","w");

        for(i=0;i<n;i++){
            fwrite(&s[i],sizeof(student),1,fp);
        }

        fclose(fp);
}

void sort_by_name(){
        student *s, s1;
        FILE *fp;
        fp = fopen("mystudents1.txt","r");
        fseek(fp,0,SEEK_END);
        int n = ftell(fp)/sizeof(student);
        int i,j;
        rewind(fp);
        s = (student*)calloc(n,sizeof(student));
        for(i=0;i<n;i++)
            fread(&s[i],sizeof(student),1,fp);

        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(strcmp(s[i].name,s[j].name)>0){
                    s1 = s[i];
                    s[i] = s[j];
                    s[j] = s1;
                }
            }
        }
        for(i=0;i<n;i++){
            printf("\n%-5d%-20s",s[i].rno,s[i].name);
            for(j=0;j<3;j++){
                printf("%4d",s[i].sub[j].mark);
            }
            printf("%5d%7.2f",s[i].total,s[i].per);
        }
        fclose(fp);
}


int main(){
    int ch;
    do{
        printf("\n1.CREATE");
        printf("\n2.APPEND");
        printf("\n3.DISPLAY");
        printf("\n4.NO OF RECORDS");
        printf("\n5.SEARCH");
        printf("\n6.UPDATE");
        printf("\n7.DELETE");
        printf("\n8.SORT IN FILE BY TOTAL DESC");
        printf("\n9.SORT ON SCREEN BY TOTAL DESC");
        printf("\n10.SORT ON SCREEN BY NAME");
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
            case 7:
                delete_rec();
            break;
            case 8:
                sort_in_file();
                break;
            case 9:
                sort_on_screen();
            break;
            case 10:
                sort_by_name();
            break;
        case 0:
                printf("\n\nThanks.....\n\n");
        }
        }while(ch!=0);

    return 0;
}