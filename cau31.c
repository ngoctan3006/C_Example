#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sinhvien
{
    char mssv[10];
    char hoten[30];
    float diem;
}sinhvien;
int dem=0;
void ghifile()
{
    sinhvien sv;
    FILE *file;
    file=fopen("SV.dat","wb");
    printf("\nNhap thông tin của sinh viên.");
    do
    {
        printf("\nMSSV : ");
        scanf("%s",sv.mssv);
        while(getchar()!='\n');
        printf("Họ tên : ");
        fgets(sv.hoten,sizeof(sv.hoten),stdin);
        printf("Điểm : ");
        scanf("%f",&sv.diem);
        if(sv.diem<0 || sv.diem >10)
        {
            while(0<sv.diem && sv.diem<10)
            {
                printf("\nNhap lai điểm : ");
                scanf("%f",&sv.diem);
            }
        }
        printf("\n----------------------\n");
        fprintf(file,"\n%s",sv.mssv);
        fprintf(file,"\n %s",sv.hoten);
        fprintf(file,"\n %.2f",sv.diem);
        //fprintf(file,"\n-------------------------\n");
        dem=dem+1;
    }while(strlen(sv.hoten)!=4);
    fclose(file);
}
void docfile(sinhvien a[])
{
    FILE*file;
    file=fopen("SV.dat","rb");
    for(int i=1;i<=dem;i++)
    {
        fscanf(file,"%s",a[i].mssv);
        printf("\nMSSV :%s",a[i].mssv);
        fscanf(file,"%s",a[i].hoten);
        printf("\nHọ tên :%s",a[i].hoten);
        fscanf(file,"%f",&a[i].diem);
        printf("\nĐiểm : %.2f",a[i].diem);
        printf("\n-------------------\n");
    }
    fclose(file);
}
/*void sapxepmssv()
{
    int x;
    sinhvien a[100];
    for(int i=1;i<=dem;i++)
    {
        for(int j=i+1;j<=dem;j++)
        {
            if(a[i].mssv>a[j].mssv)
            {
                x=a[i].mssv;
                a[i].mssv=a[j].mssv;
                a[j].mssv=x;
            }
        }
    }
    printf("\nThong tin các sinh viên sau khi sắp xếp là");
    for(int i=1;i<=dem;i++)
    {
        
    }
}*/
int main()
{
    sinhvien a[100];
    ghifile();
    docfile(a);
    return 0;

}