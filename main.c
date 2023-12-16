#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct student
{
    char name[20];
    int rollno;
    long int contact;
    int y,m,d;
    char email[30];
    char address[100];
    char prevschool[20];
    int current_sem;
    float sem_pr;

    struct student* prev;
    struct student* next;
    

};
FILE *fp = NULL;
struct student* head = NULL;

void addstudent(){

    fp=fopen("test.txt","a+");
    
    struct student* st = (struct student*)malloc(sizeof(struct student));
    struct student* ptr,*p,*q;
    printf("Enter a name of student : ");
    scanf("\n");
    gets(st->name);
    fprintf(fp,"Name ---> %s\n",st->name);
   
    printf("Enter roll no of student : ");
    scanf("%d",&st->rollno);
    fprintf(fp,"Roll No ---> %d\n",st->rollno);
    
    printf("Enter Date of birth of student\nyear : ");
    scanf("%d",&st->y);
    printf("Month : ");
    scanf("%d",&st->m);
    printf("Day : ");
    scanf("%d",&st->d);
    fprintf(fp,"Date of birth ---> %d/%d/%d\n",st->d,st->m,st->y);
    
    printf("Enter contact number of student : ");
    scanf("%ld",&st->contact);
    fprintf(fp,"Contact Number ---> %ld\n",st->contact);
    
    printf("Enter address of student : ");
    scanf("\n");
    gets(st->address);
    fprintf(fp,"Address ---> %s\n",st->address);
    
    printf("Enter email address of student : ");
    scanf("%s",st->email);
    fprintf(fp,"Email ---> %s\n",st->email);
    
    printf("Enter name of previous school of student : ");
    scanf("\n");
    gets(st->prevschool);
    fprintf(fp,"Name of previous school ---> %s\n",st->prevschool);
    
    printf("Enter current semester of student : ");
    scanf("%d",&st->current_sem);
    fprintf(fp,"Current semester ---> %d\n",st->current_sem);
    
    printf("Enter percentage(last semester) of student : ");
    scanf("%f",&st->sem_pr);
    fprintf(fp,"Percentage(last semester) ---> %f\n\n\n",st->sem_pr);
    
    if(head==NULL){
        head=st;
        st->prev=NULL;
        st->next=NULL;
    }
    else
    {
        ptr = head;
        while((st->rollno > ptr->rollno) && ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        p = ptr->prev;
        if(ptr = head)
        {
            st->next = head;
            st->prev = NULL;
            head->prev = st;
            head = st;
        }
        else if((ptr->next==NULL)&&((st->rollno > ptr->rollno)))
        {
            st->prev = ptr;
            st->next = NULL;
            ptr->next = st;
        }
        else
        {
            st->next = ptr;
            st->prev = p;
            p->next = st;
            ptr->prev = st;
        }
    }

     printf("Student registered succesfully!!!");
     printf("\n\n");
}

void removestudent()
{
    struct student* ptr = head,*m=NULL,*n=NULL;
    int r;
    printf("ENTER STUDENT'S ROLL NO YOU WANT TO REMOVE : ");
    scanf("%d",&r);
    
    while(ptr->rollno != r)
    {
        ptr=ptr->next;
    }
    
    m=ptr->prev;
    n=ptr->next;
    if(ptr==head && n!=NULL){
        head=head->next;
        head->prev=NULL;
    }
    else if(n==NULL && m!=NULL){
        m->next=NULL;
    }
    else if(n==NULL && m==NULL){
        head=NULL;
        printf("List is empty\n");

    }
    else{
    m->next = n;
    n->prev = m;
    }
    printf("SUCCESFULLY REMOVED !!!\n\n");
}

void filter()
{
    if(head==NULL)
        {
            printf("List is empty\n");
            return;
        }
    int c,da,mo,ye;
    printf("1.by name\n2.by D.O.B\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        {
        char str[20];
        struct student * q = head;
        
        printf("ENTER THE NAME OF STUDENT YOU WANT TO SEARCH : ");
        scanf("\n");
        gets(str);
        
        printf(" ===============================================================================================================================================================\n");
        printf("|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        printf(" ===============================================================================================================================================================\n");
        label2:
        
        if(strcmp(str,q->name)==0)
        {
            if(q->next==NULL)
            {
                printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
                printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------------------");
                return;
            }
            else
            {
                printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
                q=q->next;
                goto label2;
            }
        }
        
        else
        {
            if(q->next==NULL){return;}
            q=q->next;
            goto label2;
        }
        }
        
        case 2:
        {  
            printf("1 .BY month\n");
            printf("2 .BY year \n");
            printf("ENTER CHOICE : ");
            scanf("%d",&da);
            struct student* q = head;
            switch(da)
            {
                case 1:
                {
                printf("Enter month of birth date : ");
                scanf("%d",&mo);
                printf(" ===============================================================================================================================================================\n");
                printf("|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
                printf(" ===============================================================================================================================================================\n");
                label3:
                if(q->m==mo)
                {
                     if(q->next==NULL)
                    {
                        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
                        printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------------------");
                        return;
                    }
                    else
                    {
                        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
                        q=q->next;
                        goto label3;
                    }
                }
                else
                {
                    if(q->next==NULL){return;}
                    q=q->next;
                    goto label3;
                }
                }
                
                case 2:
                {
                printf("Enter year of birth date : ");
                scanf("%d",&ye);
                printf(" ===============================================================================================================================================================\n");
                printf("|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
                printf(" ===============================================================================================================================================================\n");
                label4:
                if(q->y==ye)
                {
                     if(q->next==NULL)
                    {
                        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
                        printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                        return;
                    }
                    else
                    {
                        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
                        q=q->next;
                        goto label4;
                    }
                }
                else
                {
                    if(q->next==NULL){return;}
                    q=q->next;
                    goto label4;
                }
                }
            }
        }
    }
}
void displaylist()
{   
    fp=fopen("test.txt","a+");
    struct student * q = head;
    if(q==NULL){
        printf("List is empty\n");
    }
    else{
    while(q != NULL)
    {
        if(head->next==NULL){
        printf(" ===============================================================================================================================================================\n");
        printf("|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        printf(" ===============================================================================================================================================================\n");
        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
        printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------------------");

        fprintf(fp," ===============================================================================================================================================================\n");
        fprintf(fp,"|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        fprintf(fp," ===============================================================================================================================================================\n");
        fprintf(fp,"| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
        fprintf(fp," ---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        
        }
        
        else if(q==head){
        printf(" ===============================================================================================================================================================\n");
        printf("|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        printf(" ===============================================================================================================================================================\n");
        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);

        fprintf(fp," ===============================================================================================================================================================\n");
        fprintf(fp,"|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        fprintf(fp," ===============================================================================================================================================================\n");
        fprintf(fp,"| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);

        
        
        }
        
        
        else if(q->next==NULL){
        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
        printf(" --------------------------------------------------------------------------------------------------------------------------------------------------------------");        

        fprintf(fp,"| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
        fprintf(fp," --------------------------------------------------------------------------------------------------------------------------------------------------------------\n");        

        }
        else{
        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
        fprintf(fp,"| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->d,q->m,q->y,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);

        }
        
        
        q=q->next;
    }
    printf("\n\n");
    }
    fclose(fp);
}

    
void specificsearchRollno()
{
    int s;
    struct student * q = head;
    printf("ENTER THE ROLL NO OF STUDENT YOU WANT TO SEARCH : ");
    scanf("%d",&s);
    while(q->rollno != s)
    {
        q = q->next;
    }
    
        printf(" ====================================================================================================================================================\n");
        printf("|ROLL NO   |    NAME   |         EMAIL            |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        printf(" ====================================================================================================================================================\n");
        printf("| %-10d| %-10s| %-25s| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
        printf(" ----------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n");
}



void specificsearchName(){
    char str[20];
    struct student * q = head;
    printf("ENTER THE NAME OF STUDENT YOU WANT TO SEARCH : ");
    scanf("\n");
    gets(str);
    int j=0;
    while(q!=NULL){
    int i = strcmp(q->name,str);
    

    if(i!=0){
        
        q=q->next;
    }
    
    else if(i==0){
        printf(" ===================================================================================================================================================\n");
        printf("|ROLL NO  |    NAME   |         EMAIL            |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        printf(" ===================================================================================================================================================\n");
        printf("| %-8d| %-10s| %-25s| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->rollno,q->name,q->email,q->contact,q->address,q->prevschool,q->current_sem,q->sem_pr);
        printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n\n");
    break;    
    }
    
    }
}    

int main()
{
    char file[20];
    

    
    fp = fopen("test.txt","w+");
    
    
    printf("__________________________________________________________________________________________|\n");
    printf("|                                                                                         |\n");
    printf("|                                                                                         |\n");
    printf("|                        |=====================================|                          |\n");
    printf("|=======================<  WELCOME TO STUDENT DATABASE SYSTEM   >=========================|\n");
    printf("|                        |=====================================|                          |\n");
    printf("|                            BY : 20BCE205,20BCE206,20BCE213                              |\n");
    printf("|_________________________________________________________________________________________|\n\n\n");

    fprintf(fp,"__________________________________________________________________________________________|\n");
    fprintf(fp,"|                                                                                         |\n");
    fprintf(fp,"|                                                                                         |\n");
    fprintf(fp,"|                        |=====================================|                          |\n");
    fprintf(fp,"|=======================<  WELCOME TO STUDENT DATABASE SYSTEM   >=========================|\n");
    fprintf(fp,"|                        |=====================================|                          |\n");
    fprintf(fp,"|                         BY : 20BCE205,20BCE206,20BCE213                                 |\n");
    fprintf(fp,"|_________________________________________________________________________________________|\n\n\n");
   fclose(fp);
    int c,s;

    label:
        
        printf("________________________________________\n");
        printf("| 1 | for add a student                |\n");
        printf("|---|----------------------------------|\n");
        printf("| 2 | for remove student               |\n");
        printf("|---|----------------------------------|\n");
        printf("| 3 | for display full list of students|\n");
        printf("|---|----------------------------------|\n");
        printf("| 4 | for search a specific student    |\n");
        printf("|---|----------------------------------|\n");
        printf("| 5 | for Filter                       |\n");
        printf("|---|----------------------------------|\n");
        printf("| 6 | for Exit                         |\n");
        printf("|___|__________________________________|\n");
        printf("\nENTER YOUR CHOICE : ");
        scanf("%d",&c);
        printf("\n\n");
        switch(c)
        {
            case 1:
                
                addstudent();
            break;
            
            case 2:
                removestudent();
            break;
            
            case 3:
                displaylist();
            break;
            
            case 4:
            {
                printf("1.BY ROLL NO\n2.BY NAME\nENTER YOUR CHOICE : ");
                scanf("%d",&s);
                if(s==1)
                    specificsearchRollno();
                else if(s==2)
                    specificsearchName();
            }
            break;
            
            case 5:
                filter();
            break;
            
            case 6:
                return 0;
            break;

        }
         
        goto label;
}
