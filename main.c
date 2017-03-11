#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
//Define Macros
//#define gotoxy(x,y) printf("\033[%d;%dH", (x),(y))

//Global Variables for Program
char buffer_read [UCHAR_MAX];
char *processed_string;
char *exit_condition = "exit";
char *remove_nl = "\n";

int run;
int exit_value;
int menu_selector;


//Methods declarartions
void flush(void);
void clear(void);
void converter(void);
void ident_names(void);
void reserved_words(void);
void practicalTest_01(void);
void data_types_chap3(void);
void string_inout_char4(void);
void operator_expressions(void);
void sandbox(void);
void debugger(void);
char* exitProcessor(char* arg1_message, char *arg2_input, int *param1);
char* stringHandler(char *arg1_message, char *arg2_input, char *ret_val);
int integerHandler(char *arg1_message, char *arg2_input, int ret_value);
float floatHandler(char *arg1_message, char *arg2_input, float ret_val);
double doubleHandler(char *arg1_message, char *arg2_input, double ret_val);
void age_to_days(int input_value);
void exit_block(void);

int main(int argc, char const *argv[]) {


  //Menu Strings
  char menu_intem_header [] = "Menu";
  char menu_intem_sellection [] = "Enter menu item number and press [ENTER]:";
  char menu_intem_1 [UCHAR_MAX] = "(1) - Chapert 1 - Intruduction: practical test convert inch to cantimeters";
  char menu_intem_2 [UCHAR_MAX] = "(2) - Chapert 2 - Allowed and Not Allowed identifyer names";
  char menu_intem_3 [UCHAR_MAX] = "(3) - Chapter 2 - Key and Reserved words in C";
  char menu_intem_4 [UCHAR_MAX] = "(4) - First practical test";
  char menu_intem_5 [UCHAR_MAX] = "(5) - Chapert 3 - Data types in C";
  char menu_intem_6 [UCHAR_MAX] = "(6) - Chapter 4 - Character Strings and Formatted Input/Output";
  char menu_intem_7 [UCHAR_MAX] = "(7) - Chapter 5 - Operators, Expressions, and Statements";
  char menu_item_0[] = "(0) - SandBox";


  run = 1;
  //Main code implementation
  while(run != 0){

    //clear screen
    clear();

    debugger();

    printf("%s\n", menu_intem_header);
    printf("\n");
    printf("%s\n", menu_intem_1);
    printf("%s\n", menu_intem_2);
    printf("%s\n", menu_intem_3);
    printf("%s\n", menu_intem_4);
    printf("%s\n", menu_intem_5);
    printf("%s\n", menu_intem_6);
    printf("%s\n", menu_intem_7);
    printf("%s\n", menu_item_0);

    if(run == 0) break;
    menu_selector = integerHandler(menu_intem_sellection, buffer_read, menu_selector);

    if(menu_selector == 1){
      converter();
    }
    else if(menu_selector == 2) {
      ident_names();
    }
    else if(menu_selector == 3){
      reserved_words();
    }
    else if (menu_selector == 4){
      practicalTest_01();
    }
    else if (menu_selector == 5) {
      data_types_chap3();
    }
    else if (menu_selector == 6) {
      string_inout_char4();
    }
    else if (menu_selector == 7) {
      operator_expressions();
    }
    else if (menu_selector == 0) {
      sandbox();
    }

  }

  return 0;
}

//Mathod to conver Inch -> CM. Menu item 1.0
void converter(void) {

  //Strings declarartions
  char item_01_header [] = "Convert application";
  char item_01_description [] = "(inch -> cm)";
  char inches [] = "inches :";
  char cm [] = "cm :";

  //Code variables declarartion
  float input_value;
  float conv_value;
  float result;

  //Methode converter code handling
  conv_value = 2.54;


  run = 2;
  while (run == 2) {

    //clear screen
    clear();

    debugger();

    printf("%s\n", item_01_header);
    printf("\n%s\n", item_01_description);

    input_value = floatHandler("Enter value in inches: 0.0\b\b\b", buffer_read, input_value);
    result = input_value * conv_value;
    printf("%s %f\n", inches, input_value);
    printf("%s %f\n", cm, result);


    exit_block();
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

  run = 3;
  while(run == 3){
  step = 0;
  size = sizeof(a_Name)/sizeof(a_Name[0]);

//Clear screen
clear();

debugger();

//Code handling
printf("%s\t%s\n\n", aNameHeader[0], naNameHeader[0]);


 while (step < size){
   printf("%s", a_Name[step]);
   printf("\t%s\n", na_Name[step]);
   step ++;
 }

  exit_block();
  }
}

//Key/Reserved words method implementation
void reserved_words(void){

//Variables declarartion
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

  run = 4;
  while (run == 4) {

  clear();

  debugger();

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
    printf("\n");
    exit_block();
  }
}

//Practical Test 01

void practicalTest_01(void) {


  //Methor variables
  char *test_1_task_1 = "1 - Task 1 :Input you name and surname then it will be printed in different varitions";

  char test_01_name[UCHAR_MAX];
  char test_01_surname[UCHAR_MAX];
  char test_01_street[UCHAR_MAX];
  char test_01_city[UCHAR_MAX];
  char test_01_zip[UCHAR_MAX];
  char test_01_state[UCHAR_MAX];
  char test_01_coutntry[UCHAR_MAX];
  int test_01_age;

  run = 5;

  while (run == 5) {

    clear();

    debugger();

    printf("%s\n\n", test_1_task_1);


    stringHandler("Enert :NAME\b\b\b\b", buffer_read, test_01_name);
    stringHandler("Enter :SURNAME\b\b\b\b\b\b\b", buffer_read, test_01_surname);
    stringHandler("Enter :STREET\b\b\b\b\b\b", buffer_read, test_01_street);
    stringHandler("Enter :ZIP\b\b\b", buffer_read, test_01_zip);
    stringHandler("Enter :CITY\b\b\b\b", buffer_read, test_01_city);
    stringHandler("Enter :SATE\b\b\b\b", buffer_read, test_01_state);
    stringHandler("Enter :COUNTRY\b\b\b\b\b\b\b", buffer_read, test_01_coutntry);
    test_01_age = integerHandler("Please eneter your age", buffer_read, test_01_age);



    clear();
    debugger();
    printf("This block prints printf(arg1, arg2 \\n)\n");
    printf("%s %s\n\n", test_01_name, test_01_surname);

    printf("This block prints printf(arg1 \\n, arg2 \\n) \n");
    printf("%s\n%s\n\n", test_01_name, test_01_surname);

    printf("This block prints printf(arg1\\n), printf(arg2\\n) \n");
    printf("%s\n", test_01_name);
    printf("%s\n\n", test_01_surname);

    printf("This bloc will print personal information details\n\n");
    printf("%s %s\n", test_01_name, test_01_surname);
    printf("%s\n", test_01_street);
    printf("%s, %s, %s\n", test_01_city, test_01_zip, test_01_state);
    printf("%s\n\n", test_01_coutntry);

    age_to_days(test_01_age);



    printf("Exit command :");
    exit_block();
  }

}


void data_types_chap3(void) {

    run = 7;


    char *data_kr[7];
    char *data_c90[2];
    char *data_c99[3];
    unsigned char data_ch;
    int row;

    data_kr[0] = "int";
    data_kr[1] = "short";
    data_kr[2] = "long";
    data_kr[3] = "unsigned";
    data_kr[4] = "char";
    data_kr[5] = "double";
    data_kr[6] = "float";

    data_c90[0] = "signed";
    data_c90[1] = "void";

    data_c99[0] = "_Bool";
    data_c99[1] = "_Complex";
    data_c99[2] = "_Imaginary";

    int data_value_int;
    float data_value_float;
    double data_value_double;

    while (run == 7) {

      clear();
      debugger();

      printf("Date types key Reserved words \n\n");

      printf("K&R standat:\n");
      for (int i = 0; i < 7; i++) {
        printf("%9s\n", data_kr[i]);
      }
      printf("\n");

      printf("C90 standrad Reserved key words:\n");
      for (int i = 0; i < 2; i++) {
        printf("%s\n", data_c90[i]);
      }

      printf("\n");

      printf("C99 standrad Reserved key words:\n");
      for (int i = 0; i < 3; i++) {
        printf("%s\n", data_c99[i]);
      }



      printf("\n");

      data_value_int = integerHandler("Please enter value int: 0\b", buffer_read, data_value_int);
      data_value_float = floatHandler("Please inter value float: 0.0\b\b\b", buffer_read, data_value_float);
      data_value_double = doubleHandler("Please eneter value double: 0.0\b\b\b", buffer_read, data_value_double);

      printf("Decimal: %d\n", data_value_int);
      printf("Octa: %o\n", data_value_int);
      printf("Hex: %x\n\n", data_value_int);

      printf("Float: %f\n", data_value_float);
      printf("Double: %f\n", data_value_double);

      printf("Float expanent: %e\n", data_value_float);
      printf("Double expanent: %e\n", data_value_double);

      printf("Float bool expanent: %a\n", data_value_float);
      printf("Double bool expanent: %a\n", data_value_double);
      printf("\n");

      printf("Size of char %zd(byte)\n", sizeof(char));
      printf("Size of short %zd(byte)\n", sizeof(short));
      printf("Size of int %zd(byte)\n", sizeof(int));
      printf("Size of long int %zd(byte)\n", sizeof(long int));
      //printf("Size of long char %zd(byte)\n", sizeof(long char));
      //printf("Size of long short %zd(byte)\n", sizeof(long short));
      printf("Size of long %zd(byte)\n", sizeof(long));
      printf("Size of float %zd(byte)\n", sizeof(float));
      //printf("Size of long float %zd(byte)\n", sizeof(long float));
      printf("Size of double %zd(byte)\n", sizeof(double));
      printf("Size of long double %zd(byte)\n", sizeof(long double));

      printf("\n");


      row = 0;

      printf("Regular symbols: \n");
      for (int i = 0; i < 256; i++) {

        if(i > 32 && i < 127){
          data_ch = i;
          printf("%c(%d) ",data_ch, data_ch );
          row ++;

          if(row == 10){
              row = 0;
              printf("\n");
          }
        }

      }

      row = 0;

      printf("\n\n");

      printf("Special symbols: \n");
      for (int i = 0; i < 256; i++) {

        if(i > 160){
          data_ch = i;
          printf("%c(%d) ",data_ch, data_ch );
          row ++;

          if(row == 10){
              row = 0;
              printf("\n");
          }
        }
      }
      printf("\n\n");

      exit_block();
    }
}

//Chap-4 String and format input/output text

void string_inout_char4(void){

  int i_string_size;
  int i_string_size_01;
  int i_string_length;

  char s_string_01[UCHAR_MAX];

  run = 8;

  while (run == 8) {
    clear();
    debugger();
    printf("Charpter-4 Character Strings and Formatted Input/Output\n");

    stringHandler("Please eneter any string: (__________)\b\b\b\b\b\b\b\b\b\b\b", buffer_read, s_string_01);
    i_string_length = strlen(s_string_01);
    i_string_size = sizeof s_string_01;
    i_string_size_01 = sizeof(s_string_01);
    printf("Entered string is: %s\n", s_string_01);
    printf("The lenght of the string is : %d letters\n", i_string_length);
    printf("There is %d bites reserved in memory to store this string\n", i_string_size);
    //printf("The adress of size is :%d\n", &i_string_size);
    //printf("The address of lenght is :%d\n", &i_string_length);

    printf("\n");
    exit_block();
  }

}

void operator_expressions(void){

  run = 9;

  while (run == 9) {

    clear();
    debugger();
    printf("Operators, Expressions, and Statements\n");

    printf("\n");
    exit_block();
  }
}


//SandBox

void sandbox(void){

  float value;
  float f_number;
  char string[UCHAR_MAX];
  run = 6;

  while (run == 6) {

    clear();

    debugger();


    printf("Hello you are in SANDBOX\n\n");
    printf("Enter value:");
    printf("_______\b\b\b\b\b\b\b");
    scanf("%f", &f_number);
    printf("That is the number%f\n", f_number);

    stringHandler("Enter value",buffer_read, string);
    printf("%s\n", string);

    value = atof(string);
    printf("Convertd number is : %f\n", value);

    exit_block();

  }

}

char* exitProcessor(char* arg1_message, char *arg2_input, int *param1){

  printf("%s: ", arg1_message);
  fgets(arg2_input, UCHAR_MAX, stdin);
  arg2_input = strtok(arg2_input, "\n");

  if (arg2_input == NULL) {
    arg2_input = "User Input is pissing";
  }

  if ((exit_value = strcmp(arg2_input, exit_condition))== 0) {
    if(*param1 > 1){
      *param1 = 1;
    }
    else{
      *param1 = 0;
    }
  }

  return arg2_input;
}

char* stringHandler(char *arg1_message, char *arg2_input, char *ret_value){

  printf("%s", arg1_message);
  fgets(arg2_input, UCHAR_MAX, stdin);
  arg2_input = strtok(arg2_input, "\n");

  if (arg2_input == NULL) {
    strcpy(ret_value, "Input is missing");
  }
  else{
    strcpy(ret_value, arg2_input);
  }

  return ret_value;
}


int integerHandler(char *arg1_message, char *arg2_input, int ret_value){

  printf("%s", arg1_message);
  fgets(arg2_input, UCHAR_MAX, stdin);
  arg2_input = strtok(arg2_input, "\n");
  if (arg2_input == NULL) {
    ret_value = 0;
  }
  else{
    ret_value = atoi(arg2_input);
  }


  return ret_value;
}

float floatHandler(char *arg1_message, char *arg2_input, float ret_val){

  printf("%s", arg1_message);
  fgets(arg2_input, UCHAR_MAX, stdin);
  arg2_input = strtok(arg2_input, "\n");
  if (arg2_input == NULL) {
    ret_val = 0;
  }
  else{
    ret_val = atof(arg2_input);
  }

  return ret_val;
}

double doubleHandler(char *arg1_message, char *arg2_input, double ret_val){

  printf("%s", arg1_message);
  fgets(arg2_input, UCHAR_MAX, stdin);
  arg2_input = strtok(arg2_input, "\n");
  if (arg2_input == NULL) {
    ret_val = 0;
  }
  else{
    ret_val = atof(arg2_input);
  }

  return ret_val;
}



void age_to_days(int input_value){

  int day_val;
  day_val = input_value * 365;
  printf("Your age is %d years, this %d days.\n", input_value, day_val);
}


void exit_block(void){

  processed_string = exitProcessor("To exit from this block type (exit) and press [ENTER]", buffer_read, &run);
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

void debugger(void) {

  printf("DEBUG\n");
  printf("%d\n", run);
  printf("%s\n", buffer_read);
  printf("DEBUG\n\n");

}
