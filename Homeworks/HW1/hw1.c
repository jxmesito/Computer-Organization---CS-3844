#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int bToDec(int n);
int hexToDec(char hexVal[]);
int octToDec(int num);

//main function
int main( int argc, char *argv[] )
{
    int isBin, isOct,isDec,isHex, // 0 = not, 1 = is
        number, //holds the input numbers
        val, //holds the val of numb string entered
        i,j; //temp vars

    char letter, //temp var
         sign, //holds sign of num
         num[20]; //holds string form of num

    if(argc<2)
    {
        printf("\nUsage: ./hw1 0 123 abcd -45...");
        return 0;
    }

   //process cmd line args
    for (i = 1; i < argc; ++i)
    {   
        printf("\n\n%s%7s%15s%15s%15s%15s","=== Checking",argv[i],"Octal","Decimal","Unsigned","Hexadecimal");

       //set flags to 1 and strings to null
        isBin=1;
        isOct=1;
        isDec=1;
        isHex=1;
        num[0]='\0';
        sign='\0';

        //add to string form of the number
        for(j=0;j<strlen(argv[i]);j++)
        {
            num[j]=argv[i][j];
            letter=toupper(argv[i][j]);
            if((letter=='+' || letter=='-')&&(j==0))
            {
                sign=letter;
                continue;
            }
    
           //reset flags if any invalid characters found

            if(letter!='0'&& letter!='1')
                isBin=0;
            if(letter<'0'||letter>'7')
                isOct=0;
            if(letter<'0'||letter>'9')
                isDec=0;
            if(!isxdigit(letter)) // isxdigit is in the ctype header
                isHex=0;
        }
        num[j]='\0';
        int len=strlen(num);
        if(sign=='-'||sign=='+')
            for(int i=0;i<=len-1;i++) num[i]=num[i+1];

        if(isBin==1)
        {
            val=bToDec(atoi(num));
            if(sign=='-') val=-val;
            printf("\n%s%28o%15d%15u%15x","Base-2",val,val,val,val);
       }
        if(isOct==1)
        {   val=octToDec(atoi(num));
            if(sign=='-') val=-val;
            printf("\n%s%28o%15d%15u%15x","Base-8",val,val,val,val);
        }
        if(isDec==1)
        {   val = atoi(num);
            if(sign=='-') val=-val;
            printf("\n%s%27o%15d%15u%15x","Base-10",val,val,val,val);
        }
        if(isHex==1)
        {   val=hexToDec(num);
            if(sign=='-') val=-val;
            printf("\n%s%27o%15d%15u%15x","Base-16",val,val,val,val);
        }
    }
    return 0;
}

int bToDec(int n)
{
    int num = n;
    int dec_value = 0;

    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }
    return dec_value;
}

int hexToDec(char hexVal[])
{
    int len = strlen(hexVal);
    int base = 1;

    int dec_val = 0;

    for (int i=len-1; i>=0; i--)
    {
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base; // subtract 48 from ascii value
            base = base * 16;
        }
        else if (toupper(hexVal[i])>='A' && toupper(hexVal[i])<='F') 
        {
            dec_val += (toupper(hexVal[i]) - 55)*base; //subtract 55 from ASCII value
            base = base*16;
        }
    }
    return dec_val;
}

int octToDec(int num)
{
    long int octal=num, decimal = 0;
    int i = 0;
    while (octal != 0)
    {
        decimal =  decimal +(octal % 10)* pow(8, i++);
        octal = octal / 10;
    }
   return decimal;
}


