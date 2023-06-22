//File create,delete,update:
#include<stdio.h>
int main()
{
    int i,j,n,a[1000],q,r,m,o;
    scanf("%d",&q);
    if(q==1)
    {
        FILE*fr;
        fr=fopen("New.txt","r");
        fscanf(fr,"%d",&n);
        for(i=0; i<n; i++)
        {
            fscanf(fr,"%d",&a[i]);
        }
        fclose(fr);
        /*for(i=0; i<n; i++)
        {
            printf("%d ",a[i]);
        }*/
    }
    else if(q==2)
    {
        scanf("%d%d",&r,&m);
        //1.Read the file into array;
        FILE*fr=fopen("New.txt","r");
        fscanf(fr,"%d",&n);
        for(i=0; i<n; i++)
        {
            fscanf(fr,"%d",&a[i]);
        }
        fclose(fr);
        //2.delete the file
        fr=fopen("New.txt","w");
        //3.update the file
        a[r-1]=m;
        fprintf(fr,"%d\n",n);
        for(i=0; i<n; i++)
        {
            fprintf(fr,"%d ",a[i]);
        }
        fclose(fr);
    }
    else if(q==3)
    {
        scanf("%d",&r);
        //1.Read the file:
        FILE*fr=fopen("New.txt","r");
        fscanf(fr,"%d",&n);
        for(i=0; i<n; i++)
        {
            fscanf(fr,"%d",&a[i]);
        }
        fclose(fr);
        /*for(i=0; i<n; i++)
        {
            printf("%d ",a[i]);
        }*/

        //delete the quary input:
        fr=fopen("New.txt","w");
        fprintf(fr,"%d\n",n-1);
        for(i=0;i<n;i++)
        {
            if(i!=r-1)
            {
                fprintf(fr,"%d\n",a[i]);
            }
        }
        fclose(fr);
    }
    else if(q==4)
    {
        scanf("%d",&m);
        FILE*fr;
        fr=fopen("New.txt","r");
        fscanf(fr,"%d",&n);
        for(i=0; i<n; i++)
        {
            fscanf(fr,"%d",&a[i]);
        }
        fclose(fr);

        //Add data:
        fr=fopen("New.txt","w");
        fprintf(fr,"%d\n",n+1);
        for(i=0;i<n;i++)
        {
            fprintf(fr,"%d\n",a[i]);
        }
        fprintf(fr,"%d",m);
        fclose(fr);
    }
    return 0;
}
