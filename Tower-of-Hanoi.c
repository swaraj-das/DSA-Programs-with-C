#include<stdio.h>
void TowerofHanoi(int n, char s, char d, char t){
    if(n>=1){
        TowerofHanoi(n-1, s, t, d);
        printf("Moved the disk from %c to %c\n", s, d);
        TowerofHanoi(n-1, t, d, s);
    }
}

int main(void){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    TowerofHanoi(n,'S','D','T');
    return 0;
}