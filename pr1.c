#include <stdio.h>
#include<stdlib.h>
int Bcamp=0, Lcamp=0;
void linearSearch(int list[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        Lcamp++;
        if(list[i]==key) 
        { 
            printf("\n key found at= %d",i);
            return;
        }    
    }
    printf("\n key not found ");
}
void binary_search(int list[], int low, int high, int key)
{
    int mid;
    Bcamp ++;
    if (low > high)
    {
        printf("Key not found\n");
        return;
    }
    mid = (low + high) / 2;
    if (list[mid] == key)
    {
        printf("\n Key found at position= %d \n",mid);
    }
    else if (list[mid] > key)
    {
        binary_search(list, low, mid - 1, key);
    }
    else if (list[mid] < key)
    {
        binary_search(list, mid + 1, high, key);
    }
    
}
int main()
{
    int list[]={10,20,30,40,50,60,70,80,90};
    clock_t a,b, c,d;
    int n=sizeof(list)/sizeof(int);
    int key=70;
    a=clock();
    binary_search(list,0,n-1,key);
    b=clock();
    double time1=(double)(b-a)/1000;
    c=clock();
    linearSearch(list,n-1,key);
    d=clock();
    double time2=(double)(d-c)/1000;
    printf("\nbinary search Number of cmparision= %d",Bcamp);
    
    printf("\nlinear Search Number of cmparision= %d",Lcamp);
    printf(" \n time taken by  Binary search= %f",time1);
    printf(" \n time taken by  linear search= %f",time2);
    return 0;
}
