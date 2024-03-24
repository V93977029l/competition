#include <stdio.h>
int sum=0;
void cs(int x){
    while(x){
        if(x%10==2){
            sum--;
            break;
        }
        x/=10;
    }
}
int main() {    
    int n;
    scanf("%d",&n);
    sum=n;
    for(int i=1;i<=n;i++)
        cs(i);
    printf("%d",sum);
    return 0;
}
