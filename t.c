#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define size 20
#define maxlen 26

char productions[size][maxlen]={'\0'};
char nonterminals[size]={'\0'};
char startsymbol;
int n;

void setadd(char *s,char c){
    if(!strchr(s,c)){
        int i=strlen(s);
        s[i]=c;
        s[i+1]='\0';
        
    }
}

int is_in_set(char *set,char c){
    return strchr(set,c)!=NULL;
}

void set_remove(char *set,char c){
    if(!strchr(set,c)){
        return;
    }else{
       int i=strchr(set,c)-set;
        while(set[i++]){
            set[i-1]=set[i];
        }
        set[i++]='\0';
    }
}

void printset(char *set)
{
    int i=0;
    printf("{");
    for(i=0;set[i]!='\0';i++)
    {
        printf("%c\t",set[i]);
        
    }
    printf("}\n");
}

void readproductions(){
    printf("Enter number of productions:\n");
    scanf("%d",&n);
    printf("Enter productions:\n");
    getchar();
    for(int i=0;i<n;i++){
        scanf("%[^\n]",productions[i]);
        getchar();
        setadd(nonterminals,productions[i][0]);
    }
    startsymbol=productions[0][0];
}

void calc_first(char symbol,char *set){
    if(symbol=='\0'){
        return;
    }else if(!isupper(symbol)){
        if(is_in_set(set,'#')){
            set_remove(set,'#');
        }
        setadd(set,symbol);
    }else{
        for(int i=0;i<n;i++){
            if(productions[i][0]==symbol){
                int j=2;
                char temp_first[size]={'\0'};
                while(productions[i][j]!='\0'){
                    calc_first(productions[i][j],temp_first);
                    for(int l=0;temp_first[l]!=0;l++){
                        setadd(set,temp_first[l]);
                    }

                    if(is_in_set(temp_first,'#')){
                        j++;
                    }else{
                        set_remove(set,'#');
                        break;
                    }
                }
            }
        }
    }
}


int main(){
    char temp[size];
    readproductions();

    for(int i=0;i<n;i++){
        strcpy(temp,"");
        calc_first(nonterminals[i],temp);
        printf("FIRST(%c) = { %s }\n", nonterminals[i], temp);
    }
}