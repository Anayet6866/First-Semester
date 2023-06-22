#include<stdio.h>
#include<string.h>
int i,j,n;
struct user
{
    int id,NOF;
    char name[20],pass[30],mail[30];
    int flist[100];
};
struct user a[1000];
void readdata()
{
    FILE *fr=fopen("userBD.txt","r");
    for(i=0;; i++)
    {
        if(feof(fr))
        {
            break;
        }
        fscanf(fr,"%d",&a[i].id);
        if(fgets(a[i].name,20,fr)!=NULL)
        {
            fgets(a[i].name,20,fr);
        }
        fscanf(fr,"%s",a[i].pass);
        fscanf(fr,"%s",a[i].mail);
        fscanf(fr,"%d",&a[i].NOF);
        for(j=0; j<a[i].NOF; j++)
        {
            fscanf(fr,"%d",&a[i].flist[j]);
        }
        n=i ;
    }
    fclose(fr);
}
void writedata()
{
    //printf("%d\n",n);
    FILE *fr=fopen("userBD.txt","w");
    for(i=0; i<n; i++)
    {
        fprintf(fr,"%d\n",a[i].id);
        fprintf(fr,"%s\n",a[i].name);
        fprintf(fr,"%s\n",a[i].pass);
        fprintf(fr,"%s\n",a[i].mail);
        fprintf(fr,"%d\n",a[i].NOF);
        for(j=0; j<a[i].NOF; j++)
        {
            fprintf(fr,"%d ",a[i].flist[j]);
        }
        fprintf(fr,"\n");
    }
    fclose(fr);
}
void showinfo()
{
    for(i=0; i<n; i++)
    {
        printf("Name: %s",a[i].name);
        printf("Password: %s\n",a[i].pass);
        printf("Email: %s\n",a[i].mail);
        printf("Number of friends: %d\n",a[i].NOF);
        printf("\n");
    }
}
void Addinfo()
{
    char N[30],e[30],P[30];
    printf("Enter name: ");
    scanf(" %[^\n]",N);
    printf("Enter password:");
    scanf(" %s",P);
    printf("Enter email:");
    scanf(" %s",e);
    a[n].id=n+1;
    strcpy(a[n].name,N);
    strcpy(a[n].pass,P);
    strcpy(a[n].mail,e);
    a[n].NOF=0;
    n++;
}
void Deleteuser()
{
    int ID,pos=-1;
    printf("Enter user ID:");
    scanf("%d",&ID);
    for(i=0; i<n; i++)
    {
        if(ID == a[i].id)
        {
            //printf("%d",ID);
            pos=i;
        }
    }
    //printf("%d",pos);

    //Reduce his/her friend number.
    for(i=0; i<n; i++)
    {
        for(j=0; j<a[i].NOF; j++)
        {
            if(a[i].flist[j]==ID)
            {
                a[i].NOF=a[i].NOF-1;
            }
        }
    }
    if(pos!=-1)
    {
        for(i=pos; i<n-1; i++)
        {
            a[i]=a[i+1];
            for(j=0; j<a[i].NOF; j++)
            {
                a[i].flist[j]=a[i].flist[j+1];
            }
        }
    }
    n--;
}
void Searchinfo()
{
    char NAME[30];
    printf("Enter name:");
    scanf(" %[^\n]",NAME);
    for(i=0; i<n; i++)
    {
        if(strstr(a[i].name,NAME)!=NULL)
        {
            printf("%s",a[i].name);
            printf("%s\n\n",a[i].mail);
        }
    }
}
void Strongpass()
{
    for(i=0; i<n; i++)
    {
        int c1=0,c2=0,c3=0,c4=0,c5=0,x,sum;
        x=strlen(a[i].pass);
        if(x>=8)
        {
            c1=1;
        }
        for(j=0; j<x; j++)
        {

            if(a[i].pass[j]>='A' && a[i].pass[j]<='Z')
            {
                c2=1;
            }
            if(a[i].pass[j]>='a' && a[i].pass[j]<='z')
            {
                c3=1;
            }
            if(a[i].pass[j]=='#' || a[i].pass[j]=='$'||a[i].pass[j]=='&'||a[i].pass[j]=='@' ||a[i].pass[j]=='*')
            {
                c4=1;
            }
            if(a[i].pass[j]>='0' && a[i].pass[j]<='9')
            {
                c5=1;
            }
        }
        if(c1==1 && c2==1 && c3==1 && c4==1 && c5==1)
        {
            printf("%s",a[i].name);
            printf("%s\n",a[i].mail);
        }
    }
}
void Addfriend(int id1,int id2)
{
    for(i=0; i<n; i++)
    {
        if(a[i].id==id1)
        {
            a[i].NOF++;
            a[i].flist[a[i].NOF-1]==id2;
        }
        else if(a[i].id==id2)
        {
            a[i].NOF++;
            a[i].flist[a[i].NOF-1]==id1;
        }
    }
}

int main()
{
    printf("P=1.Show user information.\n");
    printf("P=2.Add new user information.\n");
    printf("P=3.Delete user.\n");
    printf("P=4.Add friend\n");
    printf("P=5.Strong Password\n");
    printf("P=6.Search information.\n");
    //printf("2.")
    int p;
    scanf("%d",&p);
    if(p==1)
    {
        readdata();
        showinfo();
    }
    else if(p==2)
    {
        readdata();
        Addinfo();
        writedata();
    }
    else if(p==3)
    {
        readdata();
       // scanf("%d",&ID);
        //printf("%d",ID);
        Deleteuser();
        writedata();
    }
    else if(p==4)
    {
        int id1,id2;
        readdata();
        printf("Enter two user's id:\n");
        scanf("%d%d",&id1,&id2);
        Addfriend(id1,id2);
        writedata();
    }
    else if(p==5)
    {
        readdata();
        Strongpass();
    }
    else if(p==6)
    {
        readdata();
        Searchinfo();
    }
    return 0;
}
