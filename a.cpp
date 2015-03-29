#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

int changeToSexa(char* pkt, int len){
    unsigned int temp = 0;
    char* ptr = pkt;

    for(int i=0; i<len/2; ++i){
        sscanf(ptr, "%02x", &temp);
        ptr += 2;
        pkt[i] = temp;
    }
    
    pkt[len/2] = 0;
    return 0;
}

int changeBack(char* pkt, char* res) {
    while(*pkt) {
        sprintf(res, "%02x", *pkt);
        ++pkt;
        res += 2;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    int len;
    scanf("%d", &len);

    char str[len+1];
    str[len] = 0;
    read(STDIN_FILENO, str, len);
    

    // printf("\nbefore modified:\n"); 
    // for(char* tp=str; *tp; ++tp) {
    //     printf("%02x ", *tp);
    // }
    // printf("\n\n");

    //do change
    changeToSexa(str, len);

    printf("after modified: \n");
    for(char* tp=str; *tp; ++tp) {
        printf("%02x ", *tp);
    }
    printf("\n\n");



    char pool[len+1];
    memset(pool, 0, sizeof(pool)+1);
    changeBack(str, pool);
    printf("%s\n", pool);

    return 0;
}