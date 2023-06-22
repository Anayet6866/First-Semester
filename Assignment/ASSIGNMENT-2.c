#include<stdio.h>
#include<string.h>
struct section
{
    char course_code[10],course_name[20],course_inst[30],section[5],stu_id[100];
    int num_stu_enrl;
};
struct section a[1000];
int i,j;
void writedata()
{

    int n=0;
    FILE *fp=fopen("classDB.txt","r");
    for(i=0;(fscanf(fp,"%[^\n]",&a[i].course_code))!=-1;i++)
    {
        n++;
        fscanf(fp,"% [^\n]",&a[i].course_name);
        fscanf(fp,"% [^\n]",&a[i].section);
        fscanf(fp,"% [^\n]",&a[i].course_name);
        fscanf(fp,"% [^\n]",&a[i].course_inst);
        fscanf(fp,"%d",&a[i].num_stu_enrl);
        if(a[i].num_stu_enrl==0)
        {
            continue;
        }
        else if(a[i].num_stu_enrl!=0)
        {
            fscanf(fp,"% [^\n]",&a[i].stu_id);
        }

    }
}
int main()
{
    int i,n,j;
    writedata();
    printf("%d\n",n);
    for(i=0; i<n; i++)
    {

        printf("%s\n",a[i].course_code);
        printf("%s\n",a[i].course_name);
        printf("%s\n",a[i].section);
        printf("%s\n",a[i].course_inst);
        printf("%d\n",a[i].num_stu_enrl);
        if(a[i].num_stu_enrl==0)
        {
            continue;
        }
        if(a[i].num_stu_enrl!=0)
        {
            printf("%s\n",a[i].stu_id);
        }

    }
    return 0;

}
