#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class shopping{

  private:
    int productCode;
    double price;
    double discount;
    string productName;

  public:
    void menu();
    void admin();
    void customer();
    void add();
    void edit();
    void remove();
    void list();
    void receipt();
};

void shopping::menu(){
  main:
  int choice;
  string email;
  string password;

  cout << "\t\t\t\t---------------------------------\n";
  cout << "\t\t\t\t        KOOKIE'S DOG CAFE        \n";
  cout << "\t\t\t\t---------------------------------\n";
  cout << "\t\t\t\t                                 \n";
  cout << "\t\t\t\t    1) Administrator             \n";
  cout << "\t\t\t\t                                 \n";
  cout << "\t\t\t\t    2) Customer                  \n";
  cout << "\t\t\t\t                                 \n";
  cout << "\t\t\t\t    3) Exit                      \n";
  cout << "\t\t\t\t                                 \n";
  cout << "\t\t\t\t Please select: ";

  cin >> choice;

  switch(choice){

  case 1:
    cout << "\n\t\t\t\t Please login  \n";
    cout << "\t\t\t\t Enter Email: ";

    cin >> email;

    cout << "\t\t\t\t Password: ";

  cin >> password;

    if((email == "admin@admin.com") && (password == "p@ssw0rd")){
      admin();
    } else {
      cout << "Invalid email and/or password.";
    }

    break;
  

  case 2:
    {
      customer();
    }

  case 3:
    {
      exit(0);
    }

  default:
    {
      cout << "Please select from the given options:";
    }
  }

  goto main;
}

void shopping::admin(){
  m:
  int choice;

  cout << "\n\n\n\t\t\t\t ADMINISTRATOR MENU \n\n";
  cout << "\n\t\t\t\t 1) Add product          \n";
  cout << "\n\t\t\t\t 2) Modify product       \n";
  cout << "\n\t\t\t\t 3) Delete product       \n";
  cout << "\n\t\t\t\t 4) Back to main menu    \n";

  cout << "\n\t\t\t\t Please enter your choice: ";

  cin >> choice;

  switch(choice){
    case 1:
      add();
      break;

    case 2:
      edit();
      break;

    case 3:
      remove();
      break;

    case 4:
      menu();
      break;

    default:
      cout << "Invalid choice.";
  }

  goto m;
}

void shopping::customer(){
  
  m:
  int choice;

  cout << "\n\n\n\t\t\t\t Main Menu \n\n";
  cout << "\n\t\t\t\t 1) Place order     \n";
  cout << "\n\t\t\t\t 2) Go back         \n";
  
  cout << "\n\t\t\t\t Please enter your choice: ";

  cin >> choice;

  switch(choice){

    case 1:
      receipt();
      break;

    case 2:
      menu();

    default:
      cout << "Invalid choice.";
      
  }

  goto m;
}

void shopping::add(){
  
  m:
  fstream data;
  int c;
  int token = 0;
  float p;
  float d;
  string n;

  cout << "\n\n\t\t\t\t ADD PRODUCT MENU \n";
  
  cout << "\n\t\t\t\t 1) Product code: ";
  cin >> productCode;
  
  cout << "\n\t\t\t\t 2) Product name: ";
  cin >> productName;
  
  cout << "\n\t\t\t\t 3) Product price: ";
  cin >> price;
  
  cout << "\n\t\t\t\t 4) Product discount: ";
  cin >> discount;
  
  data.open("cafemenu.txt",ios::in);

  if(!data){
    data.open("cafemenu.txt", ios::app|ios::out);
    data << " " << productCode << " " << productName << " " << price << " " << discount << "\n"; 
    data.close();
  } else {
    data >> c >> n >> p >> d;

    while(!data.eof()){
      if(c == productCode){
        token++;
      }
      data >> c >> n >> p >> d;
    }

    data.close();
  }

  if(token == 1)   
    goto m;
  else {
    data.open("cafemenu.txt", ios::app|ios::out);
    data << " " << productCode << " " << productName << " " << price << " " << discount << "\n"; 
    data.close();
  }
  
  cout << "\n\n\t\t Product successfuly added.";
}

void shopping::edit(){

  fstream data, data1;
  int productKey;
  int token = 0;
  int c;
  float p, d;
  string n;

  cout << "\n\n\t\t\t\t MODIFY PRODUCT \n\n";
  
  cout << "\n\t\t\t\t Product code: ";
  cin >> productCode;
  
  data.open("cafemenu.txt", ios::in);

  if(!data){
    
    cout << "\n\nFile does not exist.";
    
  } else {
    
    data1.open("cafemenu1.txt", ios::app|ios::out);

    data >> productCode >> productName >> price >> discount;
    
    while(!data.eof()){
      
      if(productKey == productCode){
        cout << "\n\t\t\t\t Product new code: ";
        cin >> c;

        cout << "\n\t\t\t\t Product name: ";
        cin >> n;

        cout << "\n\t\t\t\t Price: ";
        cin >> p;

        cout << "\n\t\t\t\t Discount: ";
        cin >> d;

        data1 << " " << c << " " << n << " " << d << "\n";
        cout << "\n\t\t\t\t Product edited.";
        token++;
      } else {

        data1 << " " << productCode << " " << productName << " " << price << " " << discount << "\n";
      }

      data >> productCode >> productName >> price >> discount;
      
    }

    data.close();
    data1.close();
  }
  
  ::remove("cafemenu.txt");
  rename("cafemenu1.txt", "cafemenu.txt");

  if(token == 0){
    
    cout << "\n\n Record not found.";
    
  }
}

void shopping::remove(){

  fstream data, data1;
  int productKey;
  int token = 0;

  cout << "\n\n\t\t\t\t DELETE PRODUCT \n\n";
  
  cout << "\n\t\t\t\t Product code: ";
  cin >> productKey;

  data.open("cafemenu.txt", ios::in);

  if(!data){
    
    cout << "File does not exist.";
    
  } else {

    data1.open("cafemenu.txt", ios::app|ios::out);
    data >> productCode >> productName >> price >> discount;

    while(!data.eof()){
      if(productCode == productKey){
        cout << "\n\n\t Product deleted succesfully";
        token++;  
      } else{
        data1 << " " << productCode << " " << productName << " " << price << " " << discount << "\n";
      }

      data >> productCode >> productName >> price >> discount;
    }

    data.close();
    data1.close();
    ::remove("cafemenu.txt");
    rename("cafemenu1.txt", "cafemenu.txt");

    if (token == 0){
      cout << "\n\n Record not found";
    }
  }
  
}


void shopping::list(){

  fstream data;
  data.open("cafemenu.txt", ios::in);

  cout << "\n\n ---------------------------------- \n";
  cout << "ProNo\t\tName\t\tPrice\n";
  cout << "\n\n ---------------------------------- \n";

  data >> productCode >> productName >> price >> discount;

  while(!data.eof()){
    cout << productCode << "\t\t" << productName << "\t\t\t";
    cout << setprecision(2) << fixed << price << "\n";
    data >> productCode >> productName >> price >> discount;
  }
    data.close();
}

void shopping::receipt(){
  
  fstream data;

  int arrc[100];
  int arrq[100];
  char choice;
  int c = 0;
  float amount = 0;
  float dis = 0;
  float total = 0;

  cout << "\n\n\t\t\t RECEIPT ";
  data.open("cafemenu.txt", ios::in);

  if(!data){
    cout << "\n\n Empty database";
  } else {
    data.close();

    list();
    cout << "\n------------------------------\n";
    cout << "\n       PLACE YOUR ORDER       \n";
    cout << "\n------------------------------\n";

    do{

      m:
      cout << "\n\nEnter product code: ";
      cin >> arrc[c];

      cout << "\n\nEnter product quantity: ";
      cin >> arrq[c];

      for(int i = 0; i < c; i++){
        if(arrc[c] == arrc[i]){
          cout << "\n\n Duplicate product code. Please try again.";
          goto m;
        }
      }

    c++;
      
      cout << "\n\n Do you want to buy another product? (Y/N). ";
      cin >> choice;
      
    }

    while (choice == 'Y');

    cout << "\n\n\t\t\t----------------- RECEIPT -----------------";
    cout << "\nProduct No\t Product Name\t Qty\t Price\t Amount\t Discount\n";
    
    for(int i = 0; i < c; i++){
      data.open("cafemenu.txt", ios::in);
      data >> productCode >> productName >> price >> discount;

      while(!data.eof()){
        
        if(productCode == arrc[i]){
          
          amount = price * arrq[i];
          discount = amount - (amount*discount/100);
          total = total + discount;

          cout << "\n" << productCode << "\t\t" << productName << "\t\t" << arrq[i] << "\t\t";
          cout << setprecision(2) << fixed << price << "\t\t" ;
          cout << amount << "\t\t" << discount;
        }

        data >> productCode >> productName >> price >> discount;
      }
        
    }

    data.close();
  }

  cout << "\n\n\t\t\t_______________________________________";
  cout << "\n Total Amount: " << total;
}

int main() {

  shopping s;
  s.menu();
  
  return 0;

}