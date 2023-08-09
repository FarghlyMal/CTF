#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

char flag_[51] = "";

void bruteForce(char* dictionary);

int64_t flag_check(char flag[51]);

int j = 0;

int i=0 ;


int main() {

    char dictionary[] = "{}abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_?";

    bruteForce(dictionary);


    return 0;
}
void bruteForce(char* dictionary) {

    
    for (j = 0; j <= 66; )
    {
        char current_char = dictionary[j];
 //       printf("char : %c at [%d] \n", current_char, i);
        flag_[i] = current_char;
        flag_check(flag_);
        if (i >= 50)
        {
            break;
        }
    }
    
    printf("Correct Flag : ");
    for (int x =0 ;x<=i; x++)
    {
        printf("%c",flag_[x]);
    }

}






int64_t flag_check(char flag[51])
{
    int64_t static_val[7]; // [rsp+0h] [rbp-1D0h]
    int16_t v2; // [rsp+30h] [rbp-1A0h]
    char Deoced_flag[32]; // [rsp+40h] [rbp-190h] BYREF
    int64_t const_vals[32]; // [rsp+60h] [rbp-170h]
    char input_flag[51]; // [rsp+160h] [rbp-70h] BYREF
    int v6; // [rsp+1C0h] [rbp-10h]
    uint8_t v7; // [rsp+1C7h] [rbp-9h]
    //int i; // [rsp+1C8h] [rbp-8h]
    char v9; // [rsp+1CEh] [rbp-2h]
    uint8_t v10; // [rsp+1CFh] [rbp-1h]

    memset(input_flag, 0, sizeof(input_flag));
    v6 = 0;
    //  printf("Enter The Flag:");
    strcpy_s(input_flag, flag);
    const_vals[0] = 0xF3E8CBAE4506845ALL;
    const_vals[1] = 0xD008415E3DA6FE57LL;
    const_vals[2] = 0xA000DD2081212233LL;
    const_vals[3] = 0x1D18F58B0471AF23LL;
    const_vals[4] = 0x3E7842CE09650FE1LL;
    const_vals[5] = 0xACE032648FCA37C3LL;
    const_vals[6] = 0x95F407C02A7C91DELL;
    const_vals[7] = 0x527AB667E553409FLL;
    const_vals[8] = 0x2E7282C94B833F4ELL;
    const_vals[9] = 0xC7D7B7CC1EF11C76LL;
    const_vals[10] = 0x1635194D1A79108ALL;
    const_vals[11] = 0x9244AB86CD2B437DLL;
    const_vals[12] = 0x24A79BB914980ED4LL;
    const_vals[13] = 0x4FFDF0D33AE23C1BLL;
    const_vals[14] = 0xDA6A80480CA3D177LL;
    const_vals[15] = 0xEC0B96FA5B47D8BDLL;
    const_vals[16] = 0xE727B17F11D949CFLL;
    const_vals[17] = 0x5DB33628E663B2C5LL;
    const_vals[18] = 0x9CB0F62570A8DCFBLL;
    const_vals[19] = 0xFCA985E439B85FA5LL;
    const_vals[20] = 0x74FF69F230510213LL;
    const_vals[21] = 0x6158C21746B559BFLL;
    const_vals[22] = 0xEF6CEE899EA4EB99LL;
    const_vals[23] = 0xDB6DBC548C7390A2LL;
    const_vals[24] = 0x34F7508DA1E3D62CLL;
    const_vals[25] = 0x6B68BE8E7B01F9D5LL;
    const_vals[26] = 0x1F15932FED2D9D55LL;
    const_vals[27] = 0x56EA5C0DF8AA88C4LL;
    const_vals[28] = 0x4A626F05389AC103LL;
    const_vals[29] = 0xAD7E75299460DF12LL;
    const_vals[30] = 0x3B87BABBB4310AE9LL;
    const_vals[31] = 0xC6974CC8666ED226LL;
    strcpy_s(Deoced_flag, "689df84315f73e8c01efe535");
    Deoced_flag[25] = 0;
    static_val[0] = 0xA2D81B89C91EA301LL;
    static_val[1] = 0x50BEEA056C0664ADLL;
    static_val[2] = 0xEFB9C02AF9C37924LL;
    static_val[3] = 0xBB059906A5477823LL;
    static_val[4] = 0x97847BFE5A064AFCLL;
    static_val[5] = 0xF3C8F3B317BD0EECLL;
    static_val[6] = -4294;
    v10 = 0;
    v9 = 0;
    v7 = 0;
    for (; i <= 51;)
    {
        v7 = *((char*)input_flag + i);
        v10 = *((char*)const_vals + v7);
        v9 = Deoced_flag[i % 24];
        if (((i % 24) & 1) != 0)
            v9 = ~v9;
        v10 ^= v9;
        v10 = *((char*)const_vals + v10);
        if ((v10 & 1) != 0)
            v10 ^= 0x42u;
        v10 = ~v10;
        unsigned char lol = *((char*)static_val + i);
        if (v10 != lol)
        {
          
            j++;
                    
            break;
        }
        else {
       //     printf("successful_Char ____: %c  \n", input_flag[i]);
         
            i++;
            j = -1;



        }
    }
    
    return 1;
}