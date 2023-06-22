#include<stdio.h>
#include<string.h>
//1.Show
//2.Delete
//3.Update
//4.Add New Student Information
int n,i;
struct student
{
    char id[20];
    char e[30];
    int mark,roll;
};
typedef struct student STD;
STD a[100];
void getdata ()
{

    FILE*fr=fopen("crude.txt","r");
    fscanf(fr,"%d",&n);
    for(i=0; i<n; i++)
    {
        fscanf(fr,"%s%d%d %s",a[i].id,&a[i].mark,&a[i].roll,a[i].e);
    }
    fclose(fr);
}
void writedata()
{
    FILE*fr=fopen("crude1.txt","w");
    //fprintf(fr,"%d\n",n);
    for(i=0; i<n; i++)
    {
        fprintf(fr,"%s %d %d %s\n",a[i].id,a[i].mark,a[i].roll,a[i].e);
    }
    fclose(fr);
}
void showdata()
{
    FILE*fr=fopen("crude1.txt","r");
    fscanf(fr,"%d",&n);
    for(i=0; i<n; i++)
    {
        fscanf(fr,"%s%d%d %s",a[i].id,&a[i].mark,&a[i].roll,a[i].e);
    }
    fclose(fr);
    printf("Update Information:\n\n");
    //printf("  Id       Mark  Roll       Email\n");
    for(i=0; i<n; i++)
    {
        printf("%s  %d  %d  %s\n",a[i].id,a[i].mark,a[i].roll,a[i].e);
    }
}

int main()
{
    int q;
    printf("Please,Enter Your Quary:\n1.Show data\n2.Delete Data\n3.Update Data\n4.Add New Student Data\n");
    scanf("%d",&q);
    if(q==1)
    {
        getdata();
        writedata();

        showdata();
    }
        if(q==2)
        {
            int pos=-1;
            char id[100];
            printf("Enter Student Id:\n");
            scanf("%s",id);
            getdata();
            for(i=0; i<n; i++)
            {
                //id search:
                if(strcmp(a[i].id,id)==0)
                {
                    pos=i;
                }
            }
            if(pos!=-1)
            {
                for(i=pos; i<n-1; i++)
                {
                    a[i]=a[i+1];
                }
            }
            n--;
            writedata();
            showdata();
        }
        if(q==3)
        {
            int pos=-1,m,roll;
            char id[100],e[30];
            printf("Enter Student\nId:\nNumber:\nRoll:\nEmail:\n");
            scanf("%s%d%d %s",id,&m,&roll,e);
            getdata();
            for(i=0; i<n; i++)
            {
                //id search:
                if(strcmp(a[i].id,id)==0)
                {
                    pos=i;
                }
            }
            if(pos!=-1)
            {
                a[pos].mark=m;
                a[pos].roll=roll;
                strcpy(a[pos].e,e);
            }
            writedata();
            showdata();
        }
        if(q==4)
        {
            int r,roll,mark;
            char id[100];
            char e[30];
            printf("Give student-->\nId:\nMark:\nRoll:\nEmail:\n");
            scanf("%s%d%d %s",&id,&mark,&roll,&e);
            getdata();
            strcpy(a[n].id,id);
            a[n].mark=mark;
            a[n].roll=roll;
            strcpy(a[n].e,e);
            n++;
            writedata();
            showdata();
        }

        return 0;
}
