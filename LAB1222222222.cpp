#include <stdio.h>

struct Student {
        char Name[20] ;
        char ID[5] ;
        float ScoreSub[5] ;

    }typedef S ;

// int Grades(){ // เกรด

// }

int main() {
    S A;
    printf("Enter the details of 3 students :\n");
    printf("Student 1\n");
    printf("Name: ");
    scanf("%s",A.Name);
    printf("ID: ");
    scanf("%s",A.ID);
    for (int i = 0; i < 5; i++) //วิชา
    {
        printf("Scores in Subject %d: ",i+1);
        scanf("%f",&A.ScoreSub[i]);
    }

    for (int i = 0; i < 3; i++)//แสดง
    {
    printf("Student %d:\n",i);
    printf("Name : %s\n",A.Name);
    printf("ID : %s\n",A.ID);
    printf("Scores :");
    for (int s = 0; s < 6; s++)
    {
        printf("%.2f \t",A.ScoreSub[s]);
    }
    printf("\n");
    printf("Grades :");
    for ( i = 0; i < 5; i++)
    {
        printf("1");
    }
        printf("\n");
    printf(" Average Scores:");
    }
    
    return 0 ;
}//end main function
