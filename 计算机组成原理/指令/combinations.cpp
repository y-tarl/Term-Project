#include <bits/stdc++.h>

using namespace std;

int main() {
    int R0, R1, R2, R3;

    int P60H, P61H, P62H;

    cin >> R0;  // IN R0, 00H | 读取 n
    //$P 00 20  ;0000 IN R0, 00H | 读取 n
    //$P 01 00
    cin >> R1;  // IN R1, 00H | 读取 m
    //$P 02 21 ;0001   IN R1, 00H | 读取 m
    //$P 03 00
    R0 = R0 - R1;  // SUB R0, R1 | R0=n-m
    //$P 04 84  ;0100 SUB R0, R1 | R0=n-m
    R2 = R0;  // MOV R2, R0 | R2=n-m
    //$P 05 42   ;0010 MOV R2, R0 | R2=n-m
    R3 = 0x00;  // LDI R3, 00H | R3 存储计数 <==> i
    //$P 06 63   ;0011 LDI R3, 00H | R3 存储计数 <==> i
    //$P 07 00
    R0 = 0x01;  // LDI R0, 01H | R0 存储结果 <==> res
    //$P 08 60  ; 0000 LDI R0, 01H | R0 存储结果 <==> res
    //$P 09 01  ; 0001
    P60H = R1;  // STA R1, 60H | 将 m 存入主存 60H
    //$P 0A D1  ; 0001 STA R1, 60H | 将 m 存入主存 60H
    //$P 0B 60

    LOOP:
    if (R1 - R3 == 0)// CMP R1, R3 | i==m+1
        //$P 0C BD   ;1101 CMP R1, R3 | i==m+1

        goto RESULT; // BZC RESULT
    //$P 0D F0   ;0000  直接寻址 + **  BZC RESULT
    //$P 0E 39

    R3++;  // INC R3 | i++
    //$P 0F 73  ; 0011  ** + E  INC R3 | i++
    P62H = R3;  // STA R3, 62H | 更新主存62H中的i
    //$P 10 D3  ; 0011  直接寻址 + E  STA R3, 62H | 更新主存62H中的i
    //$P 11 62
    R2++;// INC R2 | n-m++
    //$P 12 72   ;0010  ** + E  INC R2 | n-m++
    P61H = R2;  // STA R2, 61H | 更新主存61H中的n-m
    //$P 13 D2  ;0002 STA R2, 61H | 更新主存61H中的n-m
    //$P 14 61
    R3 = 0;// LDI R3, 00H | R3 存放相乘的结果
    //$P 15 63   ;0003  ** + E LDI R3, 00H | R3 存放相乘的结果
    //$P 16 00
    MULT:
    R1 = 0x00;// LDI R1, 00H | R1 存放比较数
    //$P 17 61   ;0001  ** + E   LDI R1, 00H | R1 存放比较数
    //$P 18 00
    if (R2 - R1 == 0)// CMP R2, R1 | n-m==0
        //$P 19 B6  ;0110  CMP R2, R1 | n-m==0
        goto MULTEND;  // BZC MULTEND
    //$P 1A F0  ; 0000  直接寻址 + **  BZC MULTEND
    //$P 1B 26


    R1 = 0x01;// LDI R1, 01H | R1 存放比较数
    //$P 1C 61   ;0001  ** + E  LDI R1, 01H | R1 存放比较数
    //$P 1D 01
    if ((R1 & R2) == 0) //CHECK R1, R2 | n-m%2==0
        //$P 1E 19   ;1001  CHECK R1, R2 | n-m%2==0
        goto EVEN; // BZC EVEN
    //$P 1F F0   ;0000  直接寻址 + **  BZC EVEN
    //$P 20 22
    R3 = R3 + R0;// ADD R3, R0 | res+=R0
    //$P 21 03  ; 0011  ADD R3, R0 | res+=R0
    EVEN:
    R0 = R0 << 1;// SHL R0 | R0<<=1
    //$P 22 A0  ; 0000 ** + E  SHL R0 | R0<<=1
    R2 = R2 >> 1;// SHR R2 | R2>>=1
    //$P 23 92   ;0010 ** + E  SHR R2 | R2>>=1
    goto MULT;// JMP MULT
    //$P 24 E0 ; 直接寻址+**+E JMP MULT
    //$P 25 17


    MULTEND://除法开始
    R1 = P62H;// LAD R1, 62H |  R1=i 临时作为除数
    //$P 26 C1  ;0001  直接寻址 + E  LAD R1, 62H |  R1=i 临时作为除数
    //$P 27 62
    R0 = 0x01;// LDI R0, 00H | R0 仍然作为结果
    //$P 28 60  ; 0000   ** + E   LDI  R0, 00H | R0 仍然作为结果
    //$P 29 01

    DIV:
    R3 = R3 - R1;// SUB R3, R1 | R3-=R1
    //$P 2A 87  ; 0111  SUB R3, R1 | R3-=R1
    if (R3 - R2 == 0)// CMP R3, R1 | i==m+1
        //$P 2B BB   ;1011 CMP R3, R1 | i==m+1
        goto END;// BZC DIVEND
    //$P 2C F0  ; 0000  直接寻址 + **  BZC DIVEND
    //$P 2D 31
    R0++;// INC R0 | R0++
    //$P 2E 70   ;0111  ** + E  INC R0 | R0++
    goto DIV;// JMP DIV
    //$P 2F E0  ;直接寻址+**+E JMP DIV
    //$P 30 2A

    END:
    R1 = P60H;// LAD R1, 60H | R1=m
    //$P 31 C1   ;0001  直接寻址 + E   LAD R1, 60H | R1=m
    //$P 32 60
    R2 = P61H;// LAD R2, 61H | R2=n-m
    //$P 33 C2  ; 0010  直接寻址 + E  LAD R2, 61H | R2=n-m
    //$P 34 61
    R3 = P62H;// LAD R3, 62H | R3=i
    //$P 35 C3  ; 0011  直接寻址 + E  LAD R3, 62H | R3=i
    //$P 36 62
    goto LOOP;// JMP LOOP
    //$P 37 E0  ;直接寻址+**+E JMP LOOP
    //$P 38 0C

    RESULT:
    cout << R0 << endl;// OUT R0, 00H | 输出结果
    //$P 39 30   ;0000 E+**  OUT R0, 40H | 输出结果
    //$P 3A 40
    //$P 3B 50    ;HLT
}