#include<stdio.h>
#include<string.h>
int i = 0,j=0,pos=0;
int cnt=0,temp;
struct student
{
    char cc[70], cn[70], s[5], in[20], list[70];
    int st;
};
typedef struct student students;
students arr[100];
void readData()
{
    FILE*fp = fopen ("classDB.txt","r");
    while ((fscanf(fp, " %[^\n]", &arr[i].cc)) != -1)
    {
        cnt++;
        fscanf(fp, " %[^\n]", &arr[i].cn);
        fscanf(fp, " %[^\n]", &arr[i].s);
        fscanf(fp, " %[^\n]", &arr[i].in);
        fscanf(fp, "%d", &arr[i].st);
        if(arr[i].st == 0)
        {
            i++;
            continue;
        }
        if(arr[i].st != 0){
        fscanf(fp, " %[^\n]", &arr[i].list);
        }
        i++;
    }   fclose(fp);
}
void showData()
{
    for(i=0; i<cnt; i++)
    {
        printf("%s\n",arr[i].cc);
        printf("%s\n",arr[i].cn);
        printf("%s\n",arr[i].s);
        printf("%s\n",arr[i].in);
        printf("%d\n",arr[i].st);
        if(arr[i].st == 0)
        {
            continue;
        }
        if(arr[i].st != 0){
        printf("%s\n",arr[i].list);
        }
    }
}
void searchByTN()
{
    char sir[20];
    int kIN[10];
    int key=0;
    scanf("%s", sir);
    for ( i = 0; i < cnt; i++)
    {
        if (strcmp(arr[i].in,sir)==0 )
        {
            kIN[key]=i;
            key++;
        }
    }
    for(j=0; j<key+1; j++)
    {
        printf("Code: %s\n",arr[kIN[j]].cc);
        printf("Name: %s\n",arr[kIN[j]].cn);
        printf("Section: %s\n",arr[kIN[j]].s);
        printf("Number of Students: %d\n",arr[kIN[j]].st);
    }
}
void addInfo()
{
    char cc1[70], cn1[70], s1[5], in1[20];
        scanf(" %[^\n]", cc1);
        scanf(" %[^\n]", cn1);
        scanf(" %[^\n]", s1);
        scanf(" %[^\n]", in1);
        FILE *fp = fopen("classDB.txt", "a+");
        fprintf(fp, "\n");
        fprintf(fp, "%s\n%s\n%s\n%s\n",cc1,cn1,s1,in1);
        fprintf(fp, "0");
        fclose(fp);
}
void update()
{
    char list2[10], cc2[10], s2[10];
    scanf("%s",list2);
    scanf("%s",cc2);
    scanf("%s",s2);
    for ( j = 0; j < cnt; j++)
    {
        if (strcmp(arr[i].s,s2))
        {
            pos = j;
            break;
        }
    }
    FILE *fp = fopen("classDB.txt", "w");
    for(i=0; i<cnt; i++)
    {
        if (i==pos)
        {
            fprintf(fp, "%s\n",arr[i].cc);
            fprintf(fp, "%s\n",arr[i].cn);
            fprintf(fp, "%s\n",arr[i].in);
            fprintf(fp, "%s\n",arr[i].s);
            fprintf(fp, "%d\n",arr[i].st+1);
            fprintf(fp, "%s",arr[i].list);
            fprintf(fp, " ");
            fprintf(fp, "%s\n", list2);
            continue;
        }

        fprintf(fp, "%s\n",arr[i].cc);
        fprintf(fp, "%s\n",arr[i].cn);
        fprintf(fp, "%s\n",arr[i].s);
        fprintf(fp, "%s\n",arr[i].in);
        fprintf(fp, "%d\n",arr[i].st);
        if(arr[i].st == 0)
        {
            continue;
        }
        if(arr[i].st != 0){
        fprintf(fp, "%s\n",arr[i].list);
        }
    }
    fclose(fp);
}
void del()
{
    FILE *fp=fopen("userDB.txt", "w");
    for(i=0; i<cnt; i++)
    {
        if(arr[i].st==0) continue;
        fprintf(fp, "%s\n",arr[i].cc);
        fprintf(fp, "%s\n",arr[i].cn);
        fprintf(fp, "%s\n",arr[i].s);
        fprintf(fp, "%s\n",arr[i].in);
        fprintf(fp, "%d\n",arr[i].st);
        if(arr[i].st == 0)
        {
            continue;
        }
        if(arr[i].st != 0){
        fprintf(fp, "%s\n",arr[i].list);
        }
    }
    fclose(fp);
}
void find()
{
    char key6[10];
    scanf("%s", key6);
    for ( i = 0; i < cnt; i++)
    {
        if (strstr(arr[i].cn,key6) != NULL)
        {
            printf("%s\n",arr[i].cc);
            printf("%s\n",arr[i].cn);
            printf("%s\n",arr[i].s);
            printf("%s\n",arr[i].in);
            printf("%d\n",arr[i].st);
            if(arr[i].st == 0)
            {
                continue;
            }
            if(arr[i].st != 0){
            printf("%s\n",arr[i].list);
            }
        }
    }
}
void sort()
{
    char key7[20];
    int p[20], k=0;
    scanf("%s", key7);
    for ( j = 0; j < cnt; j++)
    {
        if (strcmp(arr[j].in,key7)==0)
        {
            p[k]=j;
            k++;
        }
    }

    for (i = 0; i <k; i++)
    {
        for (j = i+1; j <k; j++)
        {
            if (arr[p[i]].st>arr[p[j]].st)
            {
                temp= p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    j=0;
    for(j=0; j<k; j++)
    {
        printf("Code: %s\n",arr[p[j]].cc);
        printf("Name: %s\n",arr[p[j]].cn);
        printf("Section: %s\n",arr[p[j]].s);
        printf("Number of Students: %d\n",arr[p[j]].st);
    }
}
int main()
{
    printf("show data press1\n");
    printf("1.b press 2\n");
    printf("1.c press 3\n");
    printf("2.a press 4\n");
    printf("2.b press 5\n");
    printf("3.a press 6\n");
    printf("3.b press 7\n");
    readData();
    int dec;
    scanf("%d", &dec);
    if(dec==1) showData();
    if (dec==2) searchByTN();
    if(dec==3) addInfo();
    if (dec==4) update();
    if (dec==5) del();
    if (dec==6) find();
    if (dec==7) sort();
    return 0;
}

