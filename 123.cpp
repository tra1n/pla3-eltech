#include <string.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

void printHelp()
{
    printf ("%s\n","$ crypt [options] <key> <source> [<dest>]");
    printf ("%s\n","options:");
    printf ("%s\n","-a, --alphabet=<alphabet>  alphabet — àëôàâèò äëÿ ðàáîòû àëãîðèòìà (ïî óìîë÷àíèþ ñîäåðæèò áóêâû èç ëàòíèñêîãî àëôàâèòà è öèôðû: AaBbCc..Zz0..9)");
    printf ("%s\n","-t, --type=<type>          type ìîæåò áûòü 'encode' èëè 'decode', ïî óìîë÷àíèþ — encode");
    printf ("%s\n","-h, --help                 âûâîäèò ýòó ñïðàâêó");
    printf ("%s\n","key:");
    printf ("%s\n","êëþ÷ äëÿ øèôðîâàíèÿ/äåøèôðîâàíèÿ");
    printf ("%s\n","source:");
    printf ("%s\n","èñõîäíûé ôàéë äëÿ øèôðîâàíèÿ/äåøèôðîâàíèÿ");
    printf ("%s\n","dest:");
    printf ("%s\n","ôàéë, êóäà áóäåò çàïèñàí íîâûé, çàøèôðîâàííûé òåêñò. Åñëè íå óêàçàí, òî ïåðåïèñûâàåò source");
}

int main(int argc, char* argv[])
{
    int key = 0;
    int type = 0; 
    int KeyCounter;
    string str, newStr, opt, addopt;
    string newAlph = "0";
    for (int i = 1; i<argc; i++) 
    {
        opt.assign(argv[i]);
        addopt.assign(argv[i+1]);
        if (((opt == "-t") && (addopt == "decode")) || (opt == "--type=decode")) { type = 1 ; }
        if (((opt == "-t") && (addopt == "encode")) || (opt == "--type=encode")) { type = 0 ;} 
        if ((opt == "-a") && (addopt !="-t")) {newAlph = argv[i+1];}
        if ((int(argv[i]) > 47) && ((int(argv[i]) < 58))) { key = atoi(argv[i]);} 
        if ((opt == "-h") || (opt == "--help")) { printHelp(); return 0;} 
        cout<<opt<<endl;
    }

    const char *input;
    const char *output;
    if ((KeyCounter+3) == argc) { input = argv[KeyCounter+1]; output = argv[KeyCounter+2]; }
    if ((KeyCounter+2) == argc) { input = argv[KeyCounter+1]; output = argv[KeyCounter+1]; }

    if(key < 0) 
    {
        printf ("%s\n","Wrong key" );
        printf ("%s\n","Enter another key" );
        cin>>key;
    }
    if(type==1) {key=key*(-1);} 

    FILE *in,*out;
       in = fopen(input, "rb");
       if (in == NULL) {printf ("%s\n","Input file not found"); }
       vector <char> result;
        bool alph = (newAlph != "0");
       char s;
       while (!feof(in))
       {
            fread (&s ,sizeof(char) , 1, in);
            int symb=int(s);
            if (feof(in)) break;
            if (alph&&newAlph.find(s,0)==-1) {result.push_back(s); continue;}
            if((symb>=65) && (symb<=90)){symb= (char)(65+((symb-65+key+26*type)%26));} 
            if((symb>=97) && (symb<=122)) {symb += (char)(97+((symb-97+key+26*type)%26));} 
            if((symb>=48) && (symb<=57)){symb += (char)(48+((symb-48+key+10*type)%10));} 
            if ((symb<48) || ((symb>57) && (symb<65)) || ((symb>90) && (symb<97)) || (symb>122)){symb += (char)(symb);} 
        }

    fclose(in);
    out = fopen(output, "wb");
    int size = (int) newStr.size();
    for (int i =0;i < size; i++) fwrite(&result[i],sizeof(char),1,out);

    cout<<key;
    cout<<"   ";
    cout<<type;
    cout<<"   ";
    cout<<str;

    getch();
    return 0;
}
