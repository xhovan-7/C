#include "func.h"


void readData(struct Student s[], int n,int m, FILE *in){
    for(int i=0; i<n; i++){
        fscanf(in,"%s%s%d",s[i].name,s[i].surname,&s[i].id);
        for(int j=0; j<m; j++){
            fscanf(in,"%d",&s[i].grades[j]);
        }
    }
}

void selSorting(struct Student s[], int n, int gradeIndex){
    int minindex;
    for(int i=0; i<n-1; i++){
        minindex=i;
        for(int j=i+1;j<n; j++){
            if(s[j].grades[gradeIndex]<s[minindex].grades[gradeIndex])
                minindex=j;
        }
        struct Student temp=s[i];
        s[i]=s[minindex];
        s[minindex]=temp;
    }
}
void selSortingByID(struct Student s[], int n){
    int minindex;
    for(int i=0; i<n-1; i++){
        minindex=i;
        for(int j=i+1;j<n; j++){
            if(s[j].id<s[minindex].id)
                minindex=j;
        }
        struct Student temp=s[i];
        s[i]=s[minindex];
        s[minindex]=temp;
    }
}

int binarySearchByID(struct Student s[], int n, int enteredID){
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(s[mid].id==enteredID)
            return mid;
        else if(s[mid].id>enteredID)
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

void printData(struct Student s[], int n, int m, FILE *output){
    int gradeIndex;
    scanf("%d",&gradeIndex);
    selSorting(s,n,gradeIndex);
    for(int i=0; i<n; i++){
        fprintf(output,"%s %s %d \n",s[i].name, s[i].surname,s[i].id);
        for(int j=0; j<m; j++){
            fprintf(output,"%d \n",s[i].grades[j]);
        }
    }

    int id;
    scanf("%d",&id);
    selSortingByID(s,n);
    int index=binarySearchByID(s,n,id);
    if(index==-1)
        fprintf(output,"Id not found");
    else
        s[index].grades[0]=100;
    fprintf(output,"%s %s %d \n",s[index].name,s[index].surname, s[index].id);
    for(int i=0;i<m;i++){
        fprintf(output,"%d\n",s[index].grades[i]);
    }
}  