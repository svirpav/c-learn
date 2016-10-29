#include <stdio.h>

//Methods declarartions
void flush(void);
void clear(void);
void converter(void);
void ident_names(void);
void reserved_words();

int main(int argc, char const *argv[]) {


  //Menu Strings
  char menu_intem_header [] = "Menu";
  char menu_intem_sellection [] = "Enter menu item number and press [ENTER]";
  char menu_intem_1 [] = "1. C intruduction: practical test convert inch to catimeters";
  char menu_intem_2 [] = "2 - Allowed and Not Allowed identifyer names";
  char menu_intem_3 [] = "3 - Key and Reserved words in C";


  //Code variables ddeclarartion
  char simb;

  //Main code implementation
  while(simb != 'e'){
    clear();
    printf("%s\n", menu_intem_header);
    printf("\n");
    printf("%s\n", menu_intem_1);
    printf("%s\n", menu_intem_2);
    printf("%s\n", menu_intem_3);

    printf("%s", menu_intem_sellection);
    printf(":");
    simb = getchar();
    if(simb == '1'){
      converter();
    }
    if(simb == '2') {
      ident_names();
    }
    if(simb == '3'){
      reserved_words();
    }
  }

  return 0;
}

//Mathod to conver Inch -> CM. Menu item 1.0
void converter(void) {

  //Strings declarartions
  char item_01_header [] = "Convert application";
  char item_01_description [] = "(inch -> cm) Pease enter value :";
  char item_01_exitpromt [] = "For EXIT type e, to reload r and press [ENTER] :";
  char inches [] = "inches :";
  char cm [] = "cm :";

  //Code variables declarartion
  float input_value;
  float conv_value;
  float result;
  int item_01_simb;

  //Methode converter code handling
  conv_value = 2.54;

  while (item_01_simb != 'e') {
    item_01_simb = '0';
    clear();
    printf("%s\n", item_01_header);
    printf("\n%s", item_01_description);
    scanf("%f", &input_value);
    result = input_value * conv_value;
    printf("%s %f\n", inches, input_value );
    printf("%s %f\n", cm, result);
    flush();

    while (item_01_simb != 'r') {
      printf("%s", item_01_exitpromt);
      item_01_simb = getchar();
      if (item_01_simb == 'e') break;
      flush();
    }

  }
}

//Method for Allowed/Not Allowed names. Menu item 2.1
void ident_names(void){

//code variabeles declarartion
  char *aNameHeader[0];
  char *a_Name[5];

  char *naNameHeader[0];
  char *na_Name[5];

  int size;
  int step;

//code variables value assignments
  aNameHeader[0] = "Allowed Names";
  naNameHeader[0] = "Not Allowed Names";

  a_Name[0] = "allowname";
  a_Name[1] = "Name_Name";
  a_Name[2] = "nameName";
  a_Name[3] = "allowname2";
  a_Name[4] = "_allowname";

  na_Name[0] = "**name";
  na_Name[1] = "Name-Name";
  na_Name[2] = "name Name";
  na_Name[3] = "2allowname";
  na_Name[4] = "allow`name";

  step = 0;
  size = sizeof(a_Name)/sizeof(a_Name[0]);

//Clear screen
clear();

//Code handling
printf("%s\t%s\n\n", aNameHeader[0], naNameHeader[0]);


 while (step < size){
   printf("%s", a_Name[step]);
   printf("\t%s\n", na_Name[step]);
   step ++;
 }

  flush();
  getchar();
}

//Key/Reserved words method implementation
void reserved_words(void){

//Variables declarartion
  char key_header[] = "Key words in C, restricted to use.";
  char *rWords[43];

  int size;
  int step;
  int column;

  rWords[0] = "auto";
  rWords[1] = "break";
  rWords[2] = "case";
  rWords[3] = "char";
  rWords[4] = "const";
  rWords[5] = "continue";
  rWords[6] = "default";
  rWords[7] = "do";
  rWords[8] = "double";
  rWords[9] = "else";
  rWords[10] = "enum";
  rWords[11] = "extern";
  rWords[12] = "float";
  rWords[13] = "for";
  rWords[14] = "goto";
  rWords[15] = "if";
  rWords[16] = "inline";
  rWords[17] = "int";
  rWords[18] = "long";
  rWords[19] = "register";
  rWords[20] = "return";
  rWords[21] = "restrict";
  rWords[22] = "short";
  rWords[23] = "signed";
  rWords[24] = "sizeof";
  rWords[25] = "static";
  rWords[26] = "struct";
  rWords[27] = "switch";
  rWords[28] = "typeof";
  rWords[29] = "union";
  rWords[30] = "unsigned";
  rWords[31] = "void";
  rWords[32] = "volatile";
  rWords[33] = "while";
  rWords[34] = "_Alignas";
  rWords[35] = "_Alignof";
  rWords[36] = "_Bool";
  rWords[37] = "_Complex";
  rWords[38] = "_Generic";
  rWords[39] = "_Imaginary";
  rWords[40] = "_Noreturn";
  rWords[41] = "_Static_asset";
  rWords[42] = "#_Thread_local";

  size = sizeof(rWords) / sizeof(rWords[0]);

  step = 0;
  column = 0;

  while (step < size) {

    printf("%s\t", rWords[step]);
    if (column == 5) {
      printf("\n");
      column = 0;
    }
    column++;
    step++;
  }

  flush();
  getchar();
}

//Flufh getchar() buffer;
void flush(void){
  int fl;
  while ((fl = getchar()) != '\n' && fl != EOF) {}
}

//Clear screen Ubix.
void clear(void){
  printf("\e[1;1H\e[2J");
}
