#include "color.h"
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const double ColorConverter::PRO_MULTIPLIER[9] = {0.567, 0.433, 0.0,  0.558, 0.442, 0.0,  0.0 ,0.242, 0.758};
const double ColorConverter::TRI_MULTIPLIER[9] = {0.95, 0.05, 0.0,  0.0, 0.433, 0.567,  0.0, 0.475, 0.525};
// Member function implementations...
void ColorConverter::convertVisual() {
  do {
    cout << "Would you like to see a visual of normal vision or tritanopia (blue/yellow color blindness)? " << endl;
    cout << "Enter norm or tri: " << endl;
    cin >> vision;

    if(vision == "norm") {
     cout << "Look at normalvision.png in the visuals file." << endl;
     cout<< " "<<endl;
    }
    else if(vision == "tri") {
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

vector <int> ColorConverter::protanopia(double r, double g, double b, ostream &writer) {
  vector <int> product = {0,0,0};
  product = convert(r,g,b,PRO_MULTIPLIER);
  
  writer << "Converting to protanopia, you entered: " << r << " " << g << " " << b << endl; // writes entered values to the file
  cout << "Converting to protanopia, you entered: " << r << " " << g << " " << b << endl; // outputs the entered values to the console

  return product;
}

vector <int> ColorConverter::tritanopia(double r, double g, double b, ostream &writer) { //PUBLIC
  vector <int> product = {0,0,0};
  product = convert(r,g,b,TRI_MULTIPLIER);

  writer << "Converting to tritanopia, you entered: " << r << " " << g << " " << b << endl; // writes entered values to the file
  cout << "Converting to tritanopia, you entered: " << r << " " << g << " " << b << endl; // outputs the entered values to the console

  return product;
}

vector <int> ColorConverter::convert(double r, double g, double b, const double multiplier[9]) { //PRIVATE
  vector <int> product = {0,0,0};
  product[0] = round((r* multiplier[0])+ (g* multiplier[3]) + (b* multiplier[6]));
  product[1] = round((r* multiplier[1])+ (g* multiplier[4]) + (b* multiplier[7]));
  product[2] = round((r* multiplier[2])+ (g* multiplier[5]) + (b* multiplier[8]));
  // multiplies the corresponding 3x3 matrix taking the form of a vector

    return product;
}

int ColorConverter::readRBGValue(string color) {
  int value = -1 ;
  while (value < 0 || value > 255) {
    cout << "Enter a value for " << color << "  (0-255): ";
    cin >> value;
    cin.ignore();
    if (value < 0 || value > 255) {
      cout << "Invalid input. Enter a number between 0-255. \n";
    }
  }
  return value;
}

ColorConverter::ColorConverter(){
}
