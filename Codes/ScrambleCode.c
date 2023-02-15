#include <stdio.h>
#include<string.h>

int main() {
    char str[100], sol[100];
    scanf("%s", str);
    int in=0;
    
    for(int i=0; i<strlen(str); i++){
        if(str[i]<'a'){
            if(str[i+1]==str[i] && str[i+2]==str[i]){
                sol[in] = str[i]+'a'-'A';
                i=i+2;
                in++;
                continue;
            }
            else if(str[i+1]== str[i]+'a'-'A'){
                i=i+1;
                continue;
            }
            else{
                sol[in] = str[i]+'a'-'A';
                in++;
            }
        }
        else{
            if(str[i+1]==str[i] && str[i+2]==str[i]){
                sol[in] = str[i]-'a'+'A';
                i=i+2;
                in++;
                continue;
            }
            else if(str[i+1]== str[i]-'a'+'A'){
                i=i+1;
                continue;
            }
            else{
                sol[in] = str[i]-'a'+'A';
                in++;
            }
        }

    }
    for(int j=0; j<in; j++){
        printf("%c", sol[j]);
    }
    return 0;
}