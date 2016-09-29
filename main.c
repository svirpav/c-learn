#include <stdio.h>

int main(int argc, char const *argv[]) {

  //Methods scope defention
  void converter();
  //void debuger();

  //Menu Strings
  char menu_intem_header [] = "Menu";
  char menu_intem_sellection [] = "Enter menu item number and press [ENTER]";
  char menu_intem_1 [] = "1. C intruduction: practical test convert inch to catimeters";
  //char menu_intem_2 [] = "0. Play are debuuger";
  //code variables
  char simb;

  //Main code implementation
  while(simb != 'e'){
    printf("\e[1;1H\e[2J");
    printf("%s\n", menu_intem_header);
    printf("\n");
    printf("%s\n", menu_intem_1);

    printf("%s", menu_intem_sellection);
    printf(":");
    simb = getchar();
    if(simb == '1'){
      converter();
    }
  }

  return 0;
}

void converter() {

  void flush();
  //Item Strings
  char item_01_header [] = "Convert application";
  char item_01_description [] = "(inch -> cm) Pease enter value :";
  char item_01_exitpromt [] = "For EXIT type e, to reload r and press [ENTER] :";
  char inches [] = "inches :";
  char cm [] = "cm :";

  //code variables
  float input_value;
  float conv_value = 2.54;
  float result;

  int item_01_simb;

  //item_01_ code implementation
  while (item_01_simb != 'e') {
    item_01_simb = '0';
    printf("\e[1;1H\e[2J");
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

void flush() {
  int fl;
  while ((fl = getchar()) != '\n' && fl != EOF) {}
}
