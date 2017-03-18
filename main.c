#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>



//#define gotoxy(x,y) printf("\033[%d;%dH", (x),(y))

//Global Variables for Program
char buffer_read[UCHAR_MAX];
char *processed_string;
char *exit_condition = "exit";
char *remove_nl = "\n";

int exit_value;
int menu_selector;


//Methods declarartions

void initialization(int menu_argument);
void menu(int menu_argument);

void converter(int run_val);
void ident_names(int run_val);
void reserved_words(int run_val);
void practicalTest_01(int run_val);
void data_types_chap3(int run_val);
void string_inout_char4(int run_val);
void operator_expressions(int run_val);
void control_st_loop(int run_val);
void sandbox(int run_val);


int   exitHandler(char *s_buffer_read, int selector);
char* stringHandler(char *arg1_message, char *arg2_input, char *ret_val);
int   intHandler(char *message, char *input);
float floatHandler(char *message, char *input);
float sim_calc(float value_a, char operand, float value_b);
void  age_to_days(int input_value);


void flush(void);
void clear(void);

void debugger(int selector);


int main(int argc, char const *argv[]) {

  initialization(0);
  return 0;
}

void initialization(int menu_argument) {

  menu(menu_argument);
}

void menu(int menu_argument){

  menu_selector = menu_argument;

  char menu_intem_header [] = "Menu";
  char menu_intem_sellection [] = "Enter menu item number and press [ENTER]:";
  char menu_intem_1 [UCHAR_MAX] = "(1) - Chapert 1 - Intruduction: practical test convert inch to cantimeters";
  char menu_intem_2 [UCHAR_MAX] = "(2) - Chapert 2 - Allowed and Not Allowed identifyer names";
  char menu_intem_3 [UCHAR_MAX] = "(3) - Chapter 2 - Key and Reserved words in C";
  char menu_intem_4 [UCHAR_MAX] = "(4) - First practical test";
  char menu_intem_5 [UCHAR_MAX] = "(5) - Chapert 3 - Data types in C";
  char menu_intem_6 [UCHAR_MAX] = "(6) - Chapter 4 - Character Strings and Formatted Input/Output";
  char menu_intem_7 [UCHAR_MAX] = "(7) - Chapter 5 - Operators, Expressions, and Statements";
  char menu_intem_8 [UCHAR_MAX] = "(8) - Chapter 6 - C Control Statements: Looping";
  char menu_item_0  [UCHAR_MAX] = "(99) - SandBox";

  while (menu_selector == 0){
    //clear screen
    clear();
    debugger(menu_selector);

    printf("%s\n", menu_intem_header);
    printf("\n");
    printf("%s\n", menu_intem_1);
    printf("%s\n", menu_intem_2);
    printf("%s\n", menu_intem_3);
    printf("%s\n", menu_intem_4);
    printf("%s\n", menu_intem_5);
    printf("%s\n", menu_intem_6);
    printf("%s\n", menu_intem_7);
    printf("%s\n", menu_intem_8);
    printf("%s\n", menu_item_0);

    menu_selector = intHandler(menu_intem_sellection, buffer_read);

    if (menu_selector == 1) converter(menu_selector);
    else if (menu_selector == 2)  ident_names(menu_selector);
    else if (menu_selector == 3)  reserved_words(menu_selector);
    else if (menu_selector == 4)  practicalTest_01(menu_selector);
    else if (menu_selector == 5)  data_types_chap3(menu_selector);
    else if (menu_selector == 6)  string_inout_char4(menu_selector);
    else if (menu_selector == 7)  operator_expressions(menu_selector);
    else if (menu_selector == 8)  control_st_loop(menu_selector);
    else if (menu_selector == 99) sandbox(menu_selector);

    exitHandler(buffer_read, menu_selector);
  }
}

void flush(void){
  int fl;
  while ((fl = getchar()) != '\n' && fl != EOF) {}
}

//Clear screen Ubix.
void clear(void){
  printf("\e[1;1H\e[2J");
}

void debugger(int selector){

  printf("Last buffer read :%s\n", buffer_read);
  printf("Current menu position :%d\n", selector);
}


//Mathod to conver Inch -> CM. Menu item 1.0
void converter(int run_val) {

  //Strings declarartions
  char item_01_header [] = "Convert application";
  char item_01_description [] = "(inch -> cm)";
  char inches [] = "inches :";
  char cm [] = "cm :";

  //Code variables declarartion
  float input_value;
  const float conv_value = 2.54;
  float result;



  while (menu_selector > 0) {

    //clear screen
    clear();
    debugger(menu_selector);

    printf("%s\n", item_01_header);
    printf("\n%s\n", item_01_description);

    input_value = -1;

    while (input_value != 0) {
      input_value = floatHandler("Enter value in inches: 0.0\b\b\b", buffer_read);
      result = input_value * conv_value;
      printf("%s %f\n", inches, input_value);
      printf("%s %f\n", cm, result);
    }

    exitHandler(buffer_read, menu_selector);
  }
}

//Method for Allowed/Not Allowed names. Menu item 2.1
void ident_names(int run_val){

//code variabeles declarartion
  char *aNameHeader[0];
  char *a_Name[5];

  char *naNameHeader[0];
  char *na_Name[5];

  int size;
  int step;
  int i_arr_no;


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

  while(menu_selector > 0){
  step = 0;
  i_arr_no = 0;
  size = sizeof(a_Name)/sizeof(a_Name[0]);

//Clear screen
clear();

//Code handling
printf("%s\t%s\n\n", aNameHeader[0], naNameHeader[0]);


 while (step++ < size){
   printf("%s", a_Name[i_arr_no]);
   printf("\t%s\n", na_Name[i_arr_no]);
   ++i_arr_no;
 }

 exitHandler(buffer_read, menu_selector);
  }
}

//Key/Reserved words method implementation
void reserved_words(int run_val){

//Variables declarartion
  char *rWords[43];

  int size;
  int step;
  int column;
  int i_arr_no;

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

  while (menu_selector > 0) {

  clear();

  size = sizeof(rWords) / sizeof(rWords[0]);

  step = 0;
  column = 0;
  i_arr_no = 0;

  while (step++ < size) {

    printf("%s\t", rWords[i_arr_no]);
    if (column == 5) {
      printf("\n");
      column = 0;
    }
    ++i_arr_no;
    ++column;
    }
    printf("\n");
    exitHandler(buffer_read, menu_selector);
  }
}

//Practical Test 01

void practicalTest_01(int run_val) {


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


  while (menu_selector > 0) {

    clear();

    printf("%s\n\n", test_1_task_1);


    stringHandler("Enert :NAME\b\b\b\b", buffer_read, test_01_name);
    stringHandler("Enter :SURNAME\b\b\b\b\b\b\b", buffer_read, test_01_surname);
    stringHandler("Enter :STREET\b\b\b\b\b\b", buffer_read, test_01_street);
    stringHandler("Enter :ZIP\b\b\b", buffer_read, test_01_zip);
    stringHandler("Enter :CITY\b\b\b\b", buffer_read, test_01_city);
    stringHandler("Enter :SATE\b\b\b\b", buffer_read, test_01_state);
    stringHandler("Enter :COUNTRY\b\b\b\b\b\b\b", buffer_read, test_01_coutntry);
    test_01_age = intHandler("Please eneter your age :", buffer_read);



    clear();
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

    exitHandler(buffer_read, menu_selector);
  }

}


void data_types_chap3(int run_val) {

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

    while (menu_selector > 0) {

      clear();

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

      data_value_int = intHandler("Please enter value int: 0\b", buffer_read);
      data_value_float = floatHandler("Please inter value float: 0.0\b\b\b", buffer_read);

      printf("Decimal: %d\n", data_value_int);
      printf("Octa: %o\n", data_value_int);
      printf("Hex: %x\n\n", data_value_int);

      printf("Float: %f\n", data_value_float);
      printf("Float expanent: %e\n", data_value_float);
      printf("Float bool expanent: %a\n", data_value_float);
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

      exitHandler(buffer_read, menu_selector);
    }
}

//Chap-4 String and format input/output text

void string_inout_char4(int run_val){

  int i_string_size;
  int i_string_size_01;
  int i_string_length;

  char s_string_01[UCHAR_MAX];


  while (menu_selector > 0) {
    clear();
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

    exitHandler(buffer_read, menu_selector);
  }

}

void operator_expressions(int run_val){

  int i_op_selecot;
  int i_op_while_value_01;
  int i_op_while_value_02;
  int i_op_while_value_03;
  int i_op_while_value_04;

  double d_op_exp_value;
  double d_op_exp_sum;
  const double CROP = 2E16;
  double d_op_exp_perc;
  int i_op_exp_step;
  int i_op_exp_limit;

  char s_op_exp_cell[UCHAR_MAX] = "Cell No.";
  char s_op_exp_add[UCHAR_MAX] = "Added Wheat Unit(s)";
  char s_op_exp_sum[UCHAR_MAX] = "Total Wheat Unit(s)";
  char s_op_exp_perc[UCHAR_MAX] = "%% Compare to world wheat produced ";

  float f_op_calc_a;
  float f_op_calc_b;
  char  c_op_calc_operand;


  int i_op_con_value;
  float f_op_con_value;
  short sh_op_conv_value;

  while (menu_selector >0) {

    clear();
    printf("Operators, Expressions, and Statements\n");

    printf("1 - while()\n");
    printf("2 - Exponent + while() cycle\n");
    printf("3 - Simple calculator\n");
    printf("4 - Type conversation\n");
    printf("5 - Practical Test\n");

    i_op_selecot = intHandler("Sellect block what you would like to test :", buffer_read);

    if(i_op_selecot == 1){

        printf("This block will conver F to C\n");

        i_op_while_value_01 = intHandler("Enter start weather value in F :", buffer_read);
        i_op_while_value_02 = intHandler("Enert end weather value in F :", buffer_read);
        i_op_while_value_03 = intHandler("Enter weather step :", buffer_read);

        while (i_op_while_value_01 <= i_op_while_value_02) {
        i_op_while_value_04 = (i_op_while_value_01 - 32 ) / 1.8;
        printf("%9d F = %d C\n", i_op_while_value_01, i_op_while_value_04);
        i_op_while_value_01 += i_op_while_value_03;
      }
    }

    else if(i_op_selecot == 2){
      clear();
      printf("Exponential growth\n");

      i_op_exp_step = 1;
      i_op_exp_limit = intHandler("Please enter limit value :", buffer_read);
      d_op_exp_value = 1.0;
      d_op_exp_sum = 0.0;
      printf("%s\t%s\t%s\t%s\n", s_op_exp_cell, s_op_exp_add, s_op_exp_sum, s_op_exp_perc);
      while (i_op_exp_step <= i_op_exp_limit) {
        d_op_exp_sum = d_op_exp_sum + d_op_exp_value;
        d_op_exp_perc = d_op_exp_sum/CROP;
        printf("%d %25.5e %23.5e %23.5e%%\n" , i_op_exp_step, d_op_exp_value, d_op_exp_sum, d_op_exp_perc);
        d_op_exp_value = 2.0 * d_op_exp_value;

        i_op_exp_step++;
      }

    }

    else if (i_op_selecot == 3) {

      printf("This is Simple calculator\n");
      scanf("%f%c%f", &f_op_calc_a, &c_op_calc_operand, &f_op_calc_b); flush();
      printf("%f\n", sim_calc(f_op_calc_a, c_op_calc_operand, f_op_calc_b));
    }

    else if (i_op_selecot == 4) {

      i_op_con_value = intHandler("Enter int value : 0\b", buffer_read);
      f_op_con_value = i_op_con_value;
      sh_op_conv_value = i_op_con_value;
      printf("Vlue conversation from int -> float : %d -> %f\n", i_op_con_value, f_op_con_value);
      printf("Value converted from int to short : %d -> %d\n", i_op_con_value, sh_op_conv_value);

      f_op_con_value = floatHandler("Enter float value : 0.0\b\b\b", buffer_read);
      i_op_con_value = f_op_con_value;
      printf("Value conversation from float to int : %f -> %d\n", f_op_con_value, i_op_con_value);
    }

    else if (i_op_selecot == 5) {

        const int C_I_MIN_TO_HOURS = 60;

        int i_op_pr_min;
        int i_op_pr_h;

        while ((i_op_pr_min = intHandler("Enter minutes :", buffer_read)) != 0) {

          printf("%d Minutes - ", i_op_pr_min);
          i_op_pr_h = i_op_pr_min / C_I_MIN_TO_HOURS;
          i_op_pr_min = i_op_pr_min % C_I_MIN_TO_HOURS;
          printf("%d hours %d minutes \n", i_op_pr_h, i_op_pr_min);
        }

    }

    printf("\n");
    exitHandler(buffer_read, menu_selector);
  }
}


void control_st_loop(int run){

  while (menu_selector > 0) {
    clear();
    debugger(menu_selector);
    printf("C Control Statements: Looping\n");

    exitHandler(buffer_read, menu_selector);
  }
}

//SandBox

void sandbox(int run_val){

  char s_sand_string[UCHAR_MAX];
  int i_sand_int;

  while (menu_selector >0 ) {

    clear();

    printf("Hello you are in SANDBOX\n\n");

    stringHandler("Enter string :", buffer_read, s_sand_string);
    i_sand_int = intHandler("Enter number :", buffer_read);
    printf("%s\n", s_sand_string);
    printf("%d\n", i_sand_int);

    exitHandler(buffer_read, menu_selector);
  }

}



int exitHandler(char *s_buffer, int selector){

  char s_rm_nl  [UCHAR_MAX] = "\n";
  char s_exit_str [UCHAR_MAX] = "exit";

  int i_exit;

  printf("To exit from block nr. (%d) type (exit) end press [ENTER] :", selector);
  fgets(s_buffer, UCHAR_MAX, stdin);
  s_buffer = strtok(s_buffer, s_rm_nl);

  if(s_buffer == NULL) s_buffer = "User input missing";

  if ((i_exit = strcmp(s_buffer, s_exit_str)) == 0) {
    if (selector > 0) initialization(0);

    else {

      clear();
      exit(0);
    }
  }
return selector;
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


int intHandler(char *message, char *input){

  int i_return;
  printf("%s", message);
  fgets(input, UCHAR_MAX, stdin);
  input = strtok(input, "\n");

  if (input == NULL) i_return = 0;
  else i_return = atoi(input);

  return i_return;
}



float floatHandler(char *message, char *input){

  float f_return;
  printf("%s", message);
  fgets(input, UCHAR_MAX, stdin);
  input = strtok(input, "\n");
  if (input == NULL) f_return = 0;
  else f_return = atof(input);

  return f_return;
}




void age_to_days(int input_value){

  int day_val;
  day_val = input_value * 365;
  printf("Your age is %d years, this %d days.\n", input_value, day_val);
}

float sim_calc(float value_a, char operand, float value_b){

  float calc_result;
  calc_result = 0;

  if(operand == '+'){
    calc_result = value_a + value_b;
  }

  else if (operand == '-') {
    calc_result = value_a - value_b;
  }
  else if (operand == '/') {
    calc_result = value_a / value_b;
  }
  else if (operand == '*') {
    calc_result = value_a * value_b;
  }

  return calc_result;
}
