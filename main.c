#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <ctype.h>



//#define gotoxy(x,y) printf("\033[%d;%dH", (x),(y))

//Global Variables for Program
char buffer_read[UCHAR_MAX];
char *processed_string;
char *exit_condition = "exit";
char *remove_nl = "\n";

int exit_value;
int menu_selector;


//Methods declarartions

void menu(int initialization);

void converter(int run_param);
void ident_names(int run_param);
void reserved_words(int run_param);
void practicalTest_01(int run_param);
void data_types_chap3(int run_param);
void string_inout_char4(int run_param);
void operator_expressions(int run_param);
void control_st_loop(int run_param);
void operators_branch_jump(int run_param);
void symbol_io_validation(int run_param);
void sandbox(int run_param);


void   exitHandler(int run_param);
char* stringHandler(char *arg1_message, char *arg2_input, char *ret_val);
int   intHandler(char *message, char *input);
float floatHandler(char *message, char *input);
float sim_calc(float value_a, char operand, float value_b);
void  age_to_days(int input_value);




void flush(void);
void clear(void);

void debugger(char *s_msg1, int i_arg1, char *s_msg2, char *s_arg2);


int main(int argc, char const *argv[]) {

  //initialization(0);
  menu(0);
  return 0;
}



void menu(int initialization){


  char menu_intem_header [] = "Menu";
  char menu_intem_sellection [] = "Sellec menu entry and press [ENTER]:";
  char menu_intem_1 [UCHAR_MAX] = "(1) - Chapert 1 - Intruduction: practical test convert inch to cantimeters";
  char menu_intem_2 [UCHAR_MAX] = "(2) - Chapert 2 - Allowed and Not Allowed identifyer names";
  char menu_intem_3 [UCHAR_MAX] = "(3) - Chapter 2 - Key and Reserved words in C";
  char menu_intem_4 [UCHAR_MAX] = "(4) - First practical test";
  char menu_intem_5 [UCHAR_MAX] = "(5) - Chapert 3 - Data types in C";
  char menu_intem_6 [UCHAR_MAX] = "(6) - Chapter 4 - Character Strings and Formatted Input/Output";
  char menu_intem_7 [UCHAR_MAX] = "(7) - Chapter 5 - Operators, Expressions, and Statements";
  char menu_intem_8 [UCHAR_MAX] = "(8) - Chapter 6 - C Control Statements: Looping";
  char menu_intem_9 [UCHAR_MAX] = "(9) - Chapter 7 - C Control operators, branching and Jumps";
  char menu_intem_10[UCHAR_MAX] = "(10) - Chapter 8 - C Symbol input/output and input validation";
  char menu_item_0  [UCHAR_MAX] = "(99) - SandBox";

    //clear screen
    clear();
    //debugger("Menu location", menu_selector, "Last Buffer Read", buffer_read);

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
    printf("%s\n", menu_intem_9);
    printf("%s\n", menu_intem_10);
    printf("%s\n", menu_item_0);

    menu_selector = intHandler(menu_intem_sellection, buffer_read);

    switch (menu_selector) {
      case 1:
        converter(menu_selector);
        break;
      case 2:
        ident_names(menu_selector);
        break;
      case 3:
        reserved_words(menu_selector);
        break;
      case 4:
        practicalTest_01(menu_selector);
        break;
      case 5:
        data_types_chap3(menu_selector);
        break;
      case 6:
        string_inout_char4(menu_selector);
        break;
      case 7:
        operator_expressions(menu_selector);
        break;
      case 8:
        control_st_loop(menu_selector);
        break;
      case 9:
        operators_branch_jump(menu_selector);
        break;
      case 10:
        symbol_io_validation(menu_selector);
        break;
      case 99:
        sandbox(menu_selector);
        break;
      default:
        menu(0);
        break;
    }

    exitHandler(0);
    clear();
}

void flush(void){
  int fl;
  while ((fl = getchar()) != '\n' && fl != EOF) {}
}

//Clear screen Ubix.
void clear(void){
  printf("\e[1;1H\e[2J");
}

void debugger(char *s_msg1, int i_arg1, char *s_msg2, char *s_arg2){

  printf("Last buffer read :%s\n", s_arg2);
  printf("Current menu position :%d\n", i_arg1);
}


//Mathod to conver Inch -> CM. Menu item 1.0
void converter(int run_param){

  int i_run;
  float f_cnv_read_val;
  float f_cnv_cm;
  const float F_INCH_TO_CM = 2.54;
while (run_param == 1) {
  clear();
  printf("This is DEMO converet for exit type 'e' and press [ENTER]\n");
  while (printf("inch : "),(i_run = scanf("%f", &f_cnv_read_val)) == 1) {
    f_cnv_cm = f_cnv_read_val * F_INCH_TO_CM;
    printf("(%f) inch = (%f) cm\n", f_cnv_read_val, f_cnv_cm);
  }
  exitHandler(run_param);
 }
}

//Method for Allowed/Not Allowed names. Menu item 2.1
void ident_names(int run_param){

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

  while(menu_selector == 2){
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
  getchar();
  exitHandler(run_param);
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

    printf("%13s\t", rWords[i_arr_no]);
    if (column == 5) {
      printf("\n");
      column = 0;
    }
    ++i_arr_no;
    ++column;
    }
    printf("\n");
    getchar();
    exitHandler(menu_selector);
  }
}

//Practical Test 01

void practicalTest_01(int run_param) {


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


  while (run_param == 4) {

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

    getchar();
    exitHandler(menu_selector);
  }

}


void data_types_chap3(int run_param) {

    char *data_kr[7];
    char *data_c90[2];
    char *data_c99[3];
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

    while (run_param == 5) {

      clear();

      printf("Date types key Reserved words \n\n");

      printf("K&R standat:\n");
      for (int i = 0; i < 7; i++) {
        printf("%8s\n", data_kr[i]);
      }
      printf("\n");

      printf("C90 standrad Reserved key words:\n");
      for (int i = 0; i < 2; i++) {
        printf("%9s\n", data_c90[i]);
      }

      printf("\n");

      printf("C99 standrad Reserved key words:\n");
      for (int i = 0; i < 3; i++) {
        printf("%9s\n", data_c99[i]);
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

      printf("Size of long %zd(byte)\n", sizeof(long));
      printf("Size of float %zd(byte)\n", sizeof(float));

      printf("Size of double %zd(byte)\n", sizeof(double));
      printf("Size of long double %zd(byte)\n", sizeof(long double));

      printf("\n");


      row = 0;

      printf("Regular symbols: \n");

      int i_dtp_cnt;
      int i_dtp_row;
      unsigned char c_dtp_smb;
      i_dtp_row = 0;
      i_dtp_cnt = 0;

      i_dtp_cnt = 33;
      while ((c_dtp_smb = i_dtp_cnt++) < 127) {
        printf(" %4d- %c", i_dtp_cnt, c_dtp_smb);
        if (i_dtp_row++ == 10) {
          printf("\n");
          i_dtp_row = 0;
        }
      }


      printf("\n\n");

      getchar();
      exitHandler(menu_selector);
    }
}

//Chap-4 String and format input/output text

void string_inout_char4(int run_param){

  int i_string_size;
  int i_string_size_01;
  int i_string_length;

  char s_string_01[UCHAR_MAX];


  while (run_param == 6) {
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

    getchar();
    exitHandler(menu_selector);
  }

}

void operator_expressions(int run_param){

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

  while (run_param == 7) {

    clear();
    printf("Operators, Expressions, and Statements\n");

    printf("1 - while()\n");
    printf("2 - Exponent + while() cycle\n");
    printf("3 - Simple calculator\n");
    printf("4 - Type conversation\n");
    printf("5 - Practical Test\n");
    printf("6 - Exit\n");

    i_op_selecot = intHandler("Sellect block what you would like to test :", buffer_read);

    if(i_op_selecot == 1){

        clear();
        printf("This block will conver F to C\n");



        do{
          i_op_while_value_01 = intHandler("Enter start weather value in F :", buffer_read);
          i_op_while_value_02 = intHandler("Enert end weather value in F :", buffer_read);
          i_op_while_value_03 = intHandler("Enter weather step :", buffer_read);
          while (i_op_while_value_01 <= i_op_while_value_02) {
          i_op_while_value_04 = (i_op_while_value_01 - 32 ) / 1.8;
          printf("%9d F = %d C\n", i_op_while_value_01, i_op_while_value_04);
          i_op_while_value_01 += i_op_while_value_03;
          if(i_op_while_value_01 == 0)break;
         }
        }
        while (i_op_while_value_02 > 0);

    }

    else if(i_op_selecot == 2){
      clear();
      printf("Exponential growth\n");

      i_op_exp_step = 1;
      d_op_exp_value = 1.0;
      d_op_exp_sum = 0.0;


      int temp;
      while (printf("Please enter limit value to exit type 'e' and pess [ENTER] :"),(temp = scanf("%d", &i_op_exp_limit)) == 1) {
        printf("%s\t%s\t%s\t%s\n", s_op_exp_cell, s_op_exp_add, s_op_exp_sum, s_op_exp_perc);
        while (i_op_exp_step <= i_op_exp_limit) {
          d_op_exp_sum = d_op_exp_sum + d_op_exp_value;
          d_op_exp_perc = d_op_exp_sum/CROP;
          printf("%d %25.5e %23.5e %23.5e%%\n" , i_op_exp_step, d_op_exp_value, d_op_exp_sum, d_op_exp_perc);
          d_op_exp_value = 2.0 * d_op_exp_value;

          i_op_exp_step++;
        }
      }

    }

    else if (i_op_selecot == 3) {

      int temp;
      clear();
      printf("This is Simple calculator to exit from calculator type 'e' and exit\n");

      while ((temp = scanf("%f%c%f", &f_op_calc_a, &c_op_calc_operand, &f_op_calc_b)) == 3) {
        printf("%f\n", sim_calc(f_op_calc_a, c_op_calc_operand, f_op_calc_b));
        printf("%d\n", temp);
      }

    }

    else if (i_op_selecot == 4) {

      clear();
      int temp;
      while (printf("Enter int value to exit type 'e' and press [ENTER] :"), (temp = scanf("%d", &i_op_con_value)) == 1) {
        f_op_con_value = i_op_con_value;
        sh_op_conv_value = i_op_con_value;
        printf("Vlue conversation from int -> float : %d -> %f\n", i_op_con_value, f_op_con_value);
        printf("Value converted from int to short : %d -> %d\n", i_op_con_value, sh_op_conv_value);
        flush();

        f_op_con_value = floatHandler("Enter float value : 0.0\b\b\b", buffer_read);
        i_op_con_value = f_op_con_value;
        printf("Value conversation from float to int : %f -> %d\n", f_op_con_value, i_op_con_value);
      }
    }

    else if (i_op_selecot == 5) {

        const int C_I_MIN_TO_HOURS = 60;

        int i_op_pr_min;
        int i_op_pr_h;

        clear();

        while ((i_op_pr_min = intHandler("Enter minutes :", buffer_read)) != 0) {

          printf("%d Minutes - ", i_op_pr_min);
          i_op_pr_h = i_op_pr_min / C_I_MIN_TO_HOURS;
          i_op_pr_min = i_op_pr_min % C_I_MIN_TO_HOURS;
          printf("%d hours %d minutes \n", i_op_pr_h, i_op_pr_min);
        }

    }

    else if (i_op_selecot == 6) {
      exitHandler(run_param);
    }
  }
}


void control_st_loop(int run_param){

  int i_control_select;




  while (run_param == 8) {
    clear();
    printf("C Control Statements: Looping\n");

    printf("(1) - Advanced calculator\n");
    printf("(2) - Cycle for\n");
    printf("(3) - Power of two\n");
    printf("(4) - Restauran profit calculation\n");
    printf("(5) - Practical test_1\n");
    printf("(6) - Practical test_2\n");

    i_control_select = intHandler("Select block :", buffer_read);

    if (i_control_select == 1) {

    float f_ctrl_start_value;
    float f_ctrl_add_value;
    char  c_ctrl_sign;

    clear();
    printf("Extended calculator :\n");
    printf("Place start value and press [ENTER] :");
    scanf("%f", &f_ctrl_start_value);

    int temp;

    while (flush(),printf("expression :"),(temp = scanf("%c%f", &c_ctrl_sign, &f_ctrl_add_value)) == 2) {
      switch (c_ctrl_sign) {
        case '+':
          printf("%f\n", f_ctrl_start_value += f_ctrl_add_value);
          break;
        case '-':
          printf("%f\n", f_ctrl_start_value -= f_ctrl_add_value);
          break;
        case '/':
          printf("%f\n", f_ctrl_start_value /= f_ctrl_add_value);
          break;
        case '*':
          printf("%f\n", f_ctrl_start_value *= f_ctrl_add_value);
          break;
        }
    }
}

    if (i_control_select == 2) {
      int i_ctrl_for_init;
      int i_ctrl_for_limit;
      char s_ctrl_for_cond[UCHAR_MAX];

      clear();
      printf("This is block - for(initialization; condition; operation)\n");

      int temp;
      while (printf("Enter initizalization value :"),(temp = scanf("%d", &i_ctrl_for_init)) == 1) {
        flush();
        i_ctrl_for_limit =  intHandler("Enter limit value :", buffer_read);
        stringHandler("Select + or - conditon :", buffer_read, s_ctrl_for_cond);

        if (strcmp(s_ctrl_for_cond, "+") == 0) {

        int i_ctrl_for;
        char s_ctrl_for_string[UCHAR_MAX] = "block for";
        for (i_ctrl_for = i_ctrl_for_init; i_ctrl_for < i_ctrl_for_limit; i_ctrl_for++) {
        printf("(%d)%s\n", i_ctrl_for, s_ctrl_for_string);
      }
  }
        else if (strcmp(s_ctrl_for_cond, "-") == 0) {

        int i_ctrl_for;
        char s_ctrl_for_string[UCHAR_MAX] = "block for";
        for (i_ctrl_for = i_ctrl_for_init; i_ctrl_for > i_ctrl_for_limit; i_ctrl_for--) {
        printf("(%d)%s\n", i_ctrl_for, s_ctrl_for_string);
      }
    }
  }
  }

    if (i_control_select == 3) {

      float f_ctrl_p2_time;
      int i_ctrl_p2_power;
      int i_ctrl_p2_count;
      int i_ctrl_p2_limit;
      clear();
      printf("Block power of 2\n");
      int temp;
      while (printf("Enter count :"), (temp = scanf("%d", &i_ctrl_p2_limit)) == 1) {
        flush();
        for (f_ctrl_p2_time = 0, i_ctrl_p2_count = 1, i_ctrl_p2_power =1; i_ctrl_p2_count < i_ctrl_p2_limit; i_ctrl_p2_count++, i_ctrl_p2_power += i_ctrl_p2_power){

          f_ctrl_p2_time += 1.0 / i_ctrl_p2_power;
          printf("%0.30f\n", f_ctrl_p2_time);
        }
      }

      //i_ctrl_p2_limit = intHandler("Enter count ", buffer_read);

    }

    if(i_control_select == 4){

      int i_ctrl_rest_tables;
      int i_ctrl_rest_hours;
      int i_ctrl_rest_persons_per_table;


      const float F_CTRL_REST_TAX = 0.085;

      float f_ctrl_rest_averege_menu_price;
      float f_ctrl_res_time_per_tab;
      float f_ctrl_rest_tips;
      float f_ctrl_person_per_day;
      float f_ctrl_rest_result = 0;

      clear();
      printf("Restaurant profit calculator\n");

      int temp;
      while (printf("Enter table count in Restaurant :"), (temp = scanf("%d", &i_ctrl_rest_tables)) == 1) {
        flush();
        i_ctrl_rest_hours = intHandler("How many hours open your Restaurant :", buffer_read);
        i_ctrl_rest_persons_per_table = intHandler("How many persons at on table :", buffer_read);
        f_ctrl_rest_averege_menu_price  = floatHandler("Average menu price :", buffer_read);
        f_ctrl_res_time_per_tab = floatHandler("How many minutes per table :", buffer_read);
        f_ctrl_rest_tips  = floatHandler("How much tips :", buffer_read);

        f_ctrl_person_per_day = i_ctrl_rest_hours * 60;
        f_ctrl_person_per_day = (f_ctrl_person_per_day / f_ctrl_res_time_per_tab) * i_ctrl_rest_persons_per_table;

        f_ctrl_rest_tips = f_ctrl_rest_tips  / 100;
        f_ctrl_rest_averege_menu_price += f_ctrl_rest_averege_menu_price * F_CTRL_REST_TAX;
        f_ctrl_rest_averege_menu_price += f_ctrl_rest_averege_menu_price * f_ctrl_rest_tips;
        f_ctrl_rest_result = f_ctrl_rest_averege_menu_price * f_ctrl_person_per_day;



        printf("People trough put is :%0.f\n", f_ctrl_person_per_day);
        printf("Menu cost + TAX : %.2f\n", f_ctrl_rest_averege_menu_price);
        printf("Your sales is : %f\n", f_ctrl_rest_result);
      }

      //i_ctrl_rest_tables = intHandler("How many tables in you Restaurant :", buffer_read);;

    }

    if(i_control_select == 5){

      char s_ctrl_pt_str[UCHAR_MAX];
      int i_ctrl_pt_st_lenght;

      clear();

      while (strcmp(s_ctrl_pt_str, "exit") != 0) {
        stringHandler("Enter phrase :", buffer_read, s_ctrl_pt_str);
        i_ctrl_pt_st_lenght = strlen(s_ctrl_pt_str);

        printf("The lenght is :%d\n", i_ctrl_pt_st_lenght);
        printf("You have entered :%s\n", s_ctrl_pt_str);
        for(int i = i_ctrl_pt_st_lenght; i >= 0; i--) printf("%c", s_ctrl_pt_str[i]);
        printf("\n");
        //exitHandler(run_param);
      }
      strcpy(s_ctrl_pt_str, "");
      exitHandler(run_param);
    }


          if(i_control_select == 6){

            int i_ctrl_pt_limit_max;
            float f_ctrl_pt_one_result;
            float f_ctrl_pt_one = 1.0;

            clear();
            int temp;
            while (printf("Please enetr value, to exit press 'e' :"),(temp = scanf("%d", &i_ctrl_pt_limit_max)) == 1) {
              for(int i = 2; i <= i_ctrl_pt_limit_max; i += 2){

                f_ctrl_pt_one_result = f_ctrl_pt_one / i;
                printf("1/%d = %.30f\n", i, f_ctrl_pt_one_result);
              }
            }
            exitHandler(run_param);
          }

          else exitHandler(run_param);
  }
}

void operators_branch_jump(int run_param){

  int i_obj_menu_selctor;


  while (menu_selector > 0) {
    clear();

    printf("Control operators, branches, jumps \n\n");

    printf("1. Simple word encoder \n");
    printf("2. ctype.h - isaplha()\n");
    printf("3. Residual\n");
    printf("4. continue & break\n");
    printf("5. Switch\n");
    printf("\n");

    i_obj_menu_selctor = intHandler("Sellect from above options: ", buffer_read);

    if(i_obj_menu_selctor == 1){

      char c_obj_str_01;
      int temp;

      temp = 1;
      clear();

      while (temp == 1) {
        printf("Enter pharse to encode it if you like to exit type '#' :");
        while ((c_obj_str_01 = getchar()) != '\n') {

          if (c_obj_str_01 == '#') temp = 0;
          putchar(c_obj_str_01 + 1);
        }
        //printf("%c\n", c_obj_str_01);
        printf("\n");
        }
      }




    else if(i_obj_menu_selctor == 2){

      char c_obj_str_01;
      int temp;

      temp = 1;

      clear();

      while (temp == 1) {
        printf("Enter pharse to encode it :");
        while ((c_obj_str_01 = getchar()) != '\n') {

          if(c_obj_str_01 == '#') temp = 0;

          if (isalpha(c_obj_str_01)) putchar(c_obj_str_01 + 10);
          else putchar(c_obj_str_01);
        }
        printf("\n");
      }
    }



    else if(i_obj_menu_selctor == 3){

      int i_obj_residual;
      int i_obj_exp_residual;

      clear();

      while ((i_obj_residual = intHandler("Enter the number to exit enter 0 :", buffer_read)) > 0) {

        for (int i = 2; i <= 100; i++) {

          if((i_obj_residual % i) == 0){
            i_obj_exp_residual = i_obj_residual;

            while((i_obj_exp_residual % i) == 0){
              i_obj_exp_residual /= i;
              printf("%d / %d = %d\n", i_obj_exp_residual * i, i, i_obj_exp_residual);
            }

          }
          else;
        }
      }
    }

    else if (i_obj_menu_selctor == 4) {

      int i_obj_cb_end_val;
      int i_obj_cb_iterup_val;
      int i_obj_cb_start_val;
      char s_obj_cb_selec[UCHAR_MAX];
      int temp;

      clear();

      while (printf("Please enter end value for count, to exit enter 'e' :") ,(temp = scanf("%d", &i_obj_cb_end_val)) == 1) {

        flush();
        i_obj_cb_iterup_val = intHandler("Please enter interuption value :", buffer_read);
        stringHandler("Sellect continue or break :", buffer_read, s_obj_cb_selec);
        i_obj_cb_start_val = 0;


        if (strcmp(s_obj_cb_selec, "break") == 0) {
          while (i_obj_cb_start_val <= i_obj_cb_end_val) {
            printf("Step :%d\n", i_obj_cb_start_val);
            i_obj_cb_start_val++;
            if(i_obj_cb_start_val == i_obj_cb_iterup_val){
              printf("Break \n");
              break;
            }
          }
        }
        else if (strcmp(s_obj_cb_selec, "continue") == 0) {
          while (i_obj_cb_start_val < i_obj_cb_end_val) {
            i_obj_cb_start_val++;
            if(i_obj_cb_start_val == i_obj_cb_iterup_val) {
              printf("Continue\n");
              continue;
            }
            printf("Step :%d\n", i_obj_cb_start_val);
          }
        }

        else printf("Incorrect entery!\n");
      }
      flush();
    }

    else if (i_obj_menu_selctor == 5) {

      char c_obj_case = 0;
      int i_obj_char_count[UCHAR_MAX];
      int i_obj_index;
      int temp;

      clear();


      for(int i = 0; i <= UCHAR_MAX; i++){
        i_obj_char_count[i] = 0;
      }

      temp = 1;
      printf("Type any sentence it will calculate letter amoutn to exit type '#' :");
      while (temp == 1) {
        while ((c_obj_case = getchar()) != '\n') {
          switch (c_obj_case) {
            case 'a':
              i_obj_index = c_obj_case;
              i_obj_char_count[i_obj_index] += 1;
              break;
            case 'b':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'c':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'd':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'e':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'f':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'g':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'h':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'i':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'j':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'k':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'l':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'm':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'n':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'o':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'p':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'q':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'r':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 's':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 't':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'u':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'v':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'w':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'x':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'y':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case 'z':
            i_obj_index = c_obj_case;
            i_obj_char_count[i_obj_index] += 1;
            break;
            case '#':
            temp = 0;
            break;
          }
        }

        for(char c = 'a'; c <= 'z'; c++){
          int i_obj_internal_index;
          i_obj_internal_index = c;
          if(i_obj_char_count[i_obj_internal_index] > 0){
            printf("Letter(%c) was presnt %d times.\n", c, i_obj_char_count[i_obj_internal_index]);
          }
        }
      }

    }

    exitHandler(run_param);
  }
}

void symbol_io_validation(int run_param){


int i_smb_v_menu_selector;


while (run_param > 0) {
  clear();
  printf("Menu - (%d) - Symbol input output and input validation \n", run_param);

  printf("1. Echo\n");
  printf("2. Exit\n");

  void smb_echo(void);

  i_smb_v_menu_selector = intHandler("Sellec sub-menu option :", buffer_read);
  switch (i_smb_v_menu_selector) {
    case 1:
      smb_echo();
      break;
    case 2:
      exitHandler(run_param);
      break;
    }
  }
}

void smb_echo(){

  char c_smb_echo;
  clear();
  printf("10.1 Echo menu\n");
  printf("Type any word and program will type ECHO to exit type '#'\n");
  printf(" :");
  while ((c_smb_echo = getchar()) != '#') {
    putchar(c_smb_echo);
  }
}

//SandBox

void sandbox(int run_param){

}



void exitHandler(int run_param){

  char s_rm_nl  [UCHAR_MAX] = "\n";
  char s_buffer_reader [UCHAR_MAX];

  int i_run;
  int i_exit;

  i_run = run_param;
  while (i_run > 0) {

    //clear();
    printf("Last menu (%d)\n", run_param);
    printf("Would ypu like to exit [yes/no] :");
    fgets(s_buffer_reader, UCHAR_MAX, stdin);
    strtok(s_buffer_reader, s_rm_nl);

    if (run_param > 0) {
      if ((i_exit = strcmp(s_buffer_reader, "yes")) == 0) {
        i_run = 0;
        menu(0);
      }
      else if ((i_exit = strcmp(s_buffer_reader, "no")) == 0) {
        i_run = 0;
        break;
      }
    }
      else{
        exit(0);
      }
  }


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
