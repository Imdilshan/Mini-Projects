#include <iostream>
#include <string.h>
using namespace std;

char Menu(){
  cout << "Your choices are: " << endl;
  cout << "+ -> Addition " << endl;
  cout << "- -> Subtraction" << endl;
  cout << "* -> Multiplication" << endl;
  cout << "/ -> Division" << endl;
  cout << "m -> Toggle Mode (Normal / Chained)" << endl;
  cout << "r -> Reset(Fresh Start)" << endl;
  cout << "x -> Exit" << endl;
  
  cout << "Choose your operation: ";
  char op;
  cin >> op;
  return op;
}

void Previous_result(double result){
  cout << "Previous result: " << result << endl;
}

void Input(double &first, double &second){
  cout << "Enter First Value: ";
  cin >> first ;
  
  cout << "Enter Second Value: ";
  cin >> second ;
}

bool Input_Second(double &second, bool &chained_mode, char &active_operator){
  cout << "Enter Second Value (or 'm' to toggle, 'x' to exit): ";
  string input;
  cin >> input;

  if (input == "m") {
    chained_mode = !chained_mode;
    if (!chained_mode) active_operator = '\0';
    cout << "Mode switched to: " << (chained_mode ? "Chained" : "Normal") << endl;
    cout << '\n';
    return false;
  }
  else if (input == "x") {
    cout << "Exiting.." << endl;
    exit(0);
  }

  second = stod(input);
  return true;
}

int main(){
  double first, second;
  double result = 0.0;
  bool first_operation = true;
  
  bool chained_mode = false;
  char active_operator = '\0';
  
  while(true){
    cout << "Mode: " << (chained_mode ? "Chained" : "Normal") << endl;
    char choice;
    if(chained_mode && active_operator != '\0'){
      choice = active_operator;
      cout << "Active operation: " << choice << endl;
    }
    else{
      choice = Menu();
      if(chained_mode){
        active_operator = choice;
      }
    }
    if (!first_operation) {
      Previous_result(result);
    }
   
    switch(choice){
      case '+':
          if(first_operation){
            Input(first, second);
            first_operation = false;
          }
          else{
            first = result;
            if(!Input_Second(second, chained_mode, active_operator)) continue;
          }
          result = first + second;
          cout << "Result = " << result << endl << '\n';
          break;
        
      case '-':
          if(first_operation){
            Input(first, second);
            first_operation = false;
          }
          else{
            first = result;
            if(!Input_Second(second, chained_mode, active_operator)) continue;
          }
          result = first - second;
          cout << "Result = " << result << endl << '\n';
          break;
          
      case '*':
          if(first_operation){
            Input(first, second);
            first_operation = false;
          }
          else{
            first = result;
            if(!Input_Second(second, chained_mode, active_operator)) continue;
          }
          result = first * second;
          cout << "Result = " << result << endl << '\n';
          break;
          
      case '/':
          if(first_operation){
            Input(first, second);
            first_operation = false;
          }
          else{
            first = result;
            if(!Input_Second(second, chained_mode, active_operator)) continue;
          }
          if(second == 0){
             cout << "Error: Division by zero!" << endl;
          }
          else{
            result = first / second;
            cout << "Result = " << result << endl << '\n';
          }
          break;
          
      case 'm':
          chained_mode = !chained_mode;
          if(chained_mode == false){
            active_operator = '\0';
          }
          cout << "Mode Switched to: " << (chained_mode ? "Chained" : "Normal") << endl << '\n';
          break;
          
      case 'r':
          cout << "Enter the new Base Result Value: ";
          cin >> result;
          first_operation = true;  
          cout << "Base reset to " << result << endl << '\n';
          break;
      
      case 'x':
          cout << "Final Result: " << result << endl;
          return 0;
      default:
          cout << "Please choose a valid Operator." << endl;
    }
  }
  return 0;
}