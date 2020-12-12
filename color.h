#ifndef COLOR_H
#define COLOR_H
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class ColorConverter {
  private: // Only can be used directly INSIDE this class
    string vision;
    char decision;
    static const double PRO_MULTIPLIER[9];
    static const double TRI_MULTIPLIER[9];
  
  public: // Can be used directly INSIDE and OUTSIDE this class
    // Member function prototypes...
    void convertVisual();
    int readRBGValue(string color);
    ColorConverter();
    vector <int> protanopia(double r, double g, double b, ostream &writer);
    vector <int> tritanopia(double r, double g, double b, ostream &writer);
    vector <int> convert(double r, double g, double b, const double multiplier[9]);
    
};

#endif