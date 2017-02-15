#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Define Macros
#define MAX_CAHR_LEN 256

//Global Variables for Program
char buffer_read [MAX_CAHR_LEN];
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
void sandbox(void);
void debugger(void);
char* exitProcessor(char* arg1_message, char *arg2_input, int *param1);
char* stringHandler(char *arg1_message, char *arg2_input, char *ret_val);
int integerHandler(char *arg1_message, char *arg2_input, int ret_value);
float floatHandler(char *arg1_message, char *arg2_input, int ret_val);
void age_to_days(int input_value);

int main(int argc, char const *argv[]) {


  //Menu Strings
  char menu_intem_header [] = "Menu";
  char menu_intem_sellection [] = "Enter menu item number and press [ENTER]";
  char menu_intem_1 [] = "1 - C intruduction: practical test convert inch to catimeters";
  char menu_intem_2 [] = "2 - Allowed and Not Allowed identifyer names";
  char menu_intem_3 [] = "3 - Key and Reserved words in C";
  char menu_intem_4 [] = "4 - Practical test 1.0";
  char menu_item_5[] = "0 - SandBox";


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
    printf("%s\n", menu_item_5);


    processed_string = exitProcessor(menu_intem_sellection, buffer_read, &run);
    if(run == 0) break;
    menu_selector = atoi(processed_string);

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
  char item_01_exitpromt [] = "For EXIT type e, to reload r and press [ENTER] :";
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

    input_value = floatHandler("Place value", buffer_read, input_value);
    result = input_value * conv_value;
    printf("%s %f\n", inches, input_value);
    printf("%s %f\n", cm, result);


    processed_string = exitProcessor("To exit from this block type (exit) and press [ENTER]", buffer_read, &run);
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

  int run = 3;

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

  processed_string = exitProcessor("To exit from this block type (exit) and press [ENTER]", buffer_read, &run);
  }
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

    printf("\nEnter command :");
    processed_string = exitProcessor("To exit from this block type (exit) and press [ENTER]", buffer_read, &run);
  }
}

//Practical Test 01

void practicalTest_01(void) {


  //Methor variables
  char *test_1_task_1 = "1 - Task 1 :Input you name and surname then it will be printed in different varitions";
  char *test_1_task_2 = "2 - Task 2 :Input your adress system will prin it.";

  char test_01_name[MAX_CAHR_LEN];
  char test_01_surname[MAX_CAHR_LEN];
  char test_01_street[MAX_CAHR_LEN];
  char test_01_city[MAX_CAHR_LEN];
  char test_01_zip[MAX_CAHR_LEN];
  char test_01_state[MAX_CAHR_LEN];
  char test_01_coutntry[MAX_CAHR_LEN];
  int test_01_age;

  run = 5;

  while (run == 5) {

    clear();

    debugger();

    printf("%s\n\n", test_1_task_1);


    stringHandler("Enert your name", buffer_read, test_01_name);
    stringHandler("Enter your familyname", buffer_read, test_01_surname);
    stringHandler("Enter street name", buffer_read, test_01_street);
    stringHandler("Enter ZIP", buffer_read, test_01_zip);
    stringHandler("Enter city name", buffer_read, test_01_city);
    stringHandler("Enter state name", buffer_read, test_01_state);
    stringHandler("Enter country name", buffer_read, test_01_coutntry);
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
    processed_string = exitProcessor("To exit from this block type (exit) and press [ENTER]", buffer_read, &run);
  }

}


//SandBox

void sandbox(void){

  int age;
  char string[MAX_CAHR_LEN];
  run = 6;

  while (run == 6) {

    clear();

    debugger();

    printf("Hello you are in SANDBOX\n\n");

    stringHandler("Enter value",buffer_read, string);
    printf("%s\n", string);

    processed_string = exitProcessor("To exit from this block type (exit) and press [ENTER]", buffer_read, &run);

  }

}

char* exitProcessor(char* arg1_message, char *arg2_input, int *param1){

  printf("%s: ", arg1_message);
  fgets(arg2_input, MAX_CAHR_LEN, stdin);
  arg2_input = strtok(arg2_input, "\n");

  if (arg2_input == NULL) {
    arg2_input = "User Input is pissing";
  }

  if (exit_value = strcmp(arg2_input, exit_condition) == 0) {
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

  printf("%s: ", arg1_message);
  fgets(arg2_input, MAX_CAHR_LEN, stdin);
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

  printf("%s: ", arg1_message);
  fgets(arg2_input, MAX_CAHR_LEN, stdin);
  arg2_input = strtok(arg2_input, "\n");
  if (arg2_input == NULL) {
    ret_value = 0;
  }
  else{
    ret_value = atoi(arg2_input);
  }


  return ret_value;
}

float floatHandler(char *arg1_message, char *arg2_input, int ret_val){

  printf("%s: ", arg1_message);
  fgets(arg2_input, MAX_CAHR_LEN, stdin);
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
