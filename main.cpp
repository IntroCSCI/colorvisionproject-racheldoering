#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

// function prototypes:
char chooseMenu();
void convertVisual();
vector <int> convertRGB(double r, double g, double b, ostream &writer);
int readRBGValue(string color);
void print (vector <int> &x, ostream &writer);
void showConversions(string filename);

// global variable
vector <double> matrixMultiplier = {0.95, 0.05, 0.0,  0.0, 0.433, 0.567,  0.0, 0.475, 0.525}; // 3 by 3 matix, reading across the rows, formatted into a vector, key variable to conversions


int main() {
  char choice;
  vector <int> rgb = {0, 0, 0};
  double r, g, b;
  ofstream ofs("conversions.txt", std::ofstream::out); // outputs conversions file to allow operations



  do{
    choice = chooseMenu();
    if (choice=='V' || choice == 'v') 
    {
    convertVisual(); 
    }
    if (choice=='C' || choice == 'c')
    {
      r = readRBGValue("red");
      g = readRBGValue("green");
      b = readRBGValue("blue");
      rgb = convertRGB(r, g, b, ofs);
      print(rgb, ofs);
    }
    if ( choice=='S' || choice == 's')
    {
      showConversions("conversions.txt");
    }
  } while (choice != 'Q' && choice != 'q');

  ofs.close();
  return 0;
}

char chooseMenu() {
  char choice;

  cout << "Menu\n----\n";
  cout << "Look at visuals (V):\n";
  cout << "Convert RGB values(C):\n";
  cout << "See all conversions made(S):\n";
  cout << "Quit (Q):\n";
  
    
  cin >> choice;
  cin.ignore();
    
  return choice;
}

// user will be directed to open associated file
void convertVisual() {
  string vision;
  fstream reader;
  char decision;

  do{
    cout << "Would you like to see a visual of normal vision or tritanopia (blue/yellow color blindness)? " << endl;
    cout << "Enter norm or tri: " << endl;
    cin >> vision;

    if(vision == "norm")
    {
     cout << "Look at normalvision.png in the visuals file." << endl;
     cout<< " "<<endl;
    }
    else if(vision == "tri")
    {
      cout << "Look at tritanopia.png in the visuals file." << endl;
      cout<<" "<<endl;
    }
    else {
      cout << "Invalid input. Enter norm or tri. " << endl;
    }
    cout << "Would you like to look at a different visual? (y/n): "<<endl;
    cin >> decision;
  } while(decision != 'n');
}

// takes in values for r, g, and b and inputs them into a 1 by 3 matrix
vector <int> convertRGB(double r, double g, double b, ostream &writer) {
  vector <int> product = {0, 0, 0};
  
  // using vectors by index to do matrix multiplication, stripping the proporitions of the color values, and storing the new values into a converted product vector
  product[0] = round((r* matrixMultiplier[0])+ (g* matrixMultiplier[3]) + (b* matrixMultiplier[6]));
  product[1] = round((r* matrixMultiplier[1])+ (g* matrixMultiplier[4]) + (b* matrixMultiplier[7]));
  product[2] = round((r* matrixMultiplier[2])+ (g* matrixMultiplier[5]) + (b* matrixMultiplier[8]));

  writer << "You entered: " << r << " " << g << " " << b << endl; // writes entered values to the file
  cout << "You entered: " << r << " " << g << " " << b << endl; // outputs the entered values to the console

  return product;
}

// 
int readRBGValue(string color) {
  int value = -1;
  while (value < 0 || value > 255){
    cout << "Enter a value for " << color << "  (0-255): ";
    cin >> value;
    cin.ignore();
    if (value < 0 || value > 255) 
    {
      cout << "Invalid input. Enter a number between 0-255. \n";
    }
  }
  return value;
}

void print (vector <int> &x, ostream &writer) {
  writer << "Converted tritanopia values: ";
  cout << "Converted tri values: ";

  for (int i = 0; i < x.size(); i++){
    writer << x.at(i) << ' ';
    cout << x.at(i) << ' ';
  }
  writer << endl;
  cout << endl << endl;
}

void showConversions(string filename) {
  string line;
  ifstream file (filename, std::ifstream::in);
  
  if (file.is_open()) {
    while (getline(file, line)){
     cout << line << endl;
    }
  }
  else {
    cout << "Could not open conversions" << endl;
  }
  file.close();
}