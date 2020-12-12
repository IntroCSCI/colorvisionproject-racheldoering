#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "color.h"
using namespace std;

// function prototypes:
char chooseMenu();
void print (vector <int> &x, ostream &writer);
void showConversions(string filename);

int main() {
  ColorConverter colorConverter;
  char choice;
  ifstream reader;
  ofstream writer;  
  vector <int> rgb = {0, 0, 0};
  string type;
  double r, g, b;
  ofstream ofs("conversions.txt", std::ofstream::out); // outputs conversions file to allow operations

   do {
    choice = chooseMenu();
    if (choice == 'V' || choice == 'v') {
      colorConverter.convertVisual(); 
    }
    if (choice == 'C' || choice == 'c') {
      cout << "Which type would you like to convert to in terms of RGB Values? Protanopia(P) or Tritanopia(T)?\n";
      cin >> type;
        r = colorConverter.readRBGValue("red");
        g = colorConverter.readRBGValue("green");
        b = colorConverter.readRBGValue("blue");
      if (type == "t" || type == "T"){
        rgb = colorConverter.tritanopia(r, g, b, ofs);
      }
      if (type == "p" || type == " P"){
        rgb = colorConverter.protanopia(r, g, b, ofs);
      }
      print(rgb, ofs);
    }
    if ( choice == 'S' || choice == 's') {
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

void print (vector <int> &x, ostream &writer) {
  writer << "Converted values: ";
  cout << "Converted values: ";

  for (int i = 0; i < x.size(); i++) {
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
    while (getline(file, line)) {
     cout << line << endl;
    }
  }
  else {
    cout << "Could not open conversions" << endl;
  }
  file.close();
}