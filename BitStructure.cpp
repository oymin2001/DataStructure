#include<iostream>
#include<algorithm>
using namespace std;

typedef struct TwoFieldsBitStruct {
    unsigned char first : 4, second : 4;
}TwoFieldsBitStruct;

typedef struct ThreeFieldsBitStruct {
    unsigned char style : 3, size : 2, color : 3;
}ThreeFieldsBitStruct;

void printBits(unsigned char* pU_char);

int main() {
    TwoFieldsBitStruct octet1;
    ThreeFieldsBitStruct octet2;
    unsigned char* pU_char;

    octet1.first = 6;
    octet1.second = 3;
    printf("sizeof(octet1)=%d\n", sizeof(octet1));
    printf("octet1 is defined as {first(4-bit)=%d,second(4-bit)=%d}\n", octet1.first, octet1.second);
    printf("octet1=%#X", octet1);
    pU_char = (unsigned char*)&octet1;
    printBits(pU_char);

    octet2.style = 5;
    octet2.size = 2;
    octet2.color = 6;
    printf("sizeof(octet2)=%d\n", sizeof(octet2));
    printf("octet2 is defined as {style(3-bit)=%d,size(2-bit)=%d,color(3-bit)=%d}\n", octet2.style, octet2.size,octet2.color);
    printf("octet2=%#X", octet2);
    pU_char = (unsigned char*)&octet2;
    printBits(pU_char);
    return 0;
}

void printBits(unsigned char* pU_char) {

    unsigned char uc[8];
    unsigned char byte;
    byte = *pU_char;
    for (size_t i = 0; i < 8; i++)
    {
        uc[i] = byte & 0x1;
        byte = byte >> 1;
    }
    printf(",in bit pattern(");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", uc[i]);
    }
    printf(")\n");
};

