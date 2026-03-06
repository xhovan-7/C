#include <stdio.h>


void scanList(int list[], int nr){
    printf("Enter list %d numbers: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &list[i]);
    }
}

void printList(int list[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    
}

int smallCheck(int list[], int merged[], int i, int *l){
    if (list[i] != list[i+1]){
        
        merged[*l] = list[i];
        (*l)++;
        
        return i + 1;
    }
     
    int temp = list[i];
    i++;
    i++;

    if (i > 9)  return i;
    
    while (temp == list[i] && i <= 9) 
        i++;

    return i;
}



int main()
{
    int list1[10];
    int list2[10];
    int merged[20];
    int l = 0;

    scanList(list1, 1);
    scanList(list2, 2);

    for (int i = 0, j = 0; i < 10 || j < 10;){
        if (i < 9 && j < 9 ){

            if (list1[i] < list2[j])
                i = smallCheck(list1, merged, i, &l);

            else if (list1[i] > list2[j])
                j = smallCheck(list2, merged, j, &l);

            else{
                i++;
                j++;

                while (list1[i-1] == list2[j])
                    j++;

                while (list1[i] == list2[j-1])
                    i++;
            }
        
        }
        else if (i == 9 && j < 9){
            if (list1[i] < list2[j])
                merged[l] = list1[i];

            else if (list1[i] > list2[j])
                j = smallCheck(list2, merged, j, &l);

            else{
                j++;
                i++;
                while (list1[i-1] == list2[j] && j < 10)
                    j++;
            }
        }

        else if (i < 9 && j == 9){
            if (list1[i] < list2[j])
                i = smallCheck(list1, merged, i, &l);

            else if (list1[i] > list2[j])
                merged[l] = list1[j];

            else{
                i++;
                j++;
                while (list1[i] == list2[j-1] && i < 10)
                    i++;
            }
        }

        else if (i == 9 && j == 9){
            if (list1[i] < list2[j]){
                merged[l] = list1[i];
                l++;
                merged[l] = list2[j];
            }
            else if (list1[i] > list2[j]){
                merged[l] = list2[j];
                l++;
                merged[l] = list1[i];
            }
            else{
                i++;
                j++;
            }
        }

        else if (i < j)
            i = smallCheck(list1, merged, i, &l);
        
        else if (i > j)
            j = smallCheck(list2, merged, j, &l);  

    }

    printList(merged, l);
    printf("BYE");

    return 0;
}
