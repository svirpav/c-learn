#include <stdio.h>

int main(int argc, char const *argv[]) {

  //Methods scope defention
  void converter();

  //Menu Strings
  char menu_intem_header [] = "Menu";
  char menu_intem_sellection [] = "Enter menu item number and press [ENTER]";
  char menu_intem_1 [] = "1. C intruduction: practical test convert inch to catimeters";
  //code variables
  int simb;

  //Main code implementation
  while(simb != 'e'){
    simb = -1;
    printf("\e[1;1H\e[2J");
    printf("%s\n", menu_intem_header);
    printf("\n");
    printf("%s\n", menu_intem_1);

    printf("%s", menu_intem_sellection);
    printf(":");
    simb = getchar();
    printf("%c\n", simb );
    if(simb == '1'){
      converter();
    }
  }

  return 0;
}

void converter() {

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
    item_01_simb = -1;
    printf("\e[1;1H\e[2J");
    printf("%s\n", item_01_header);
    printf("\n%s", item_01_description);
    scanf("%f", &input_value);
    result = input_value * conv_value;
    printf("%s %f\n", inches, input_value );
    printf("%s %f\n", cm, result);

    while (item_01_simb != 'r') {
      item_01_simb = -1;
      printf("%s", item_01_exitpromt);
      getchar();
      item_01_simb = getchar();
      printf("%c\n", item_01_simb );
      if (item_01_simb == 'e') break;
    }

  }
}
