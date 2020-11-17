# Simulation: Normal vision vs Tritanopia

## Description
Tritanopia or blue/yellow color blindness is rare but is caused by a missing/malfunctioning S-cone. This program simulates what it would look like to have tritanopia. It asks the user which type of vision they want to see and then opens the corresponding picture.

## v0.2 Updates
This program simulates tritanopia in two different ways. It presents a menu to the user so they can select whether they want to look at visuals to see the difference between normal and tritanopia, convert RGB values of their choosing, or see all the conversions they made while running the program.

## Developer

Rachel Doering

## Example

To run the program, give the following commands:

```
 g++ -std=c++11 main.cpp -o cvp; ./cvp
Menu
----
Look at visuals (V):
Convert RGB values(C):
See all conversions made(S):
Quit (Q):
v
Would you like to see a visual of normal vision or tritanopia (blue/yellow color blindness)? 
Enter norm or tri: 
norm
Look at normalvision.png in the visuals file.
 
Would you like to look at a different visual? (y/n): 
y
Would you like to see a visual of normal vision or tritanopia (blue/yellow color blindness)? 
Enter norm or tri: 
tri
Look at tritanopia.png in the visuals file.
 
Would you like to look at a different visual? (y/n): 
n
Menu
----
Look at visuals (V):
Convert RGB values(C):
See all conversions made(S):
Quit (Q):
c
Enter a value for red  (0-255): 255
Enter a value for green  (0-255): 120
Enter a value for blue  (0-255): 200
You entered: 255 120 200
Converted tri values: 242 160 173 

Menu
----
Look at visuals (V):
Convert RGB values(C):
See all conversions made(S):
Quit (Q):
s
You entered: 255 120 200
Converted tritanopia values: 242 160 173 
Menu
----
Look at visuals (V):
Convert RGB values(C):
See all conversions made(S):
Quit (Q):
q
 
```

## C++ Guide

### Variables and Data Types

vector <double> matrixMultiplier = {0.95, 0.05, 0.0,  0.0, 0.433, 0.567,  0.0, 0.475, 0.525}; 
Outside the main program, I globalized a vector variable called matrixMultiplier, because it's a key part of converting RGB values. Each index represents the values of a 3 by 3 matrix as you are reading across the rows.
_These 3x3 values come from the following source: https://github.com/PlanetCentauri/ColorblindFilter/blob/master/Code
Found through stakeholder_
 

char choice;
vector <int> rgb = {0, 0, 0};
double r, g, b;
ofstream ofs("conversion.txt", std::ofstream::out);
Within the main program, I declared a *string* variable called *choice* to account for the users choice within the *ChooseMenu()* function.

I initialized a *vector* called *rgb* at (0,0,0) to avoid garbage values when doing the conversion operations in the *convertRGBValues()* function.

I declared a *double* variable for the *r* , *g*, and *b* so that the multiplication for the conversions involves two decimal values being multiplied. 

I declared an *ofstream* variable called *ofs* in create and write to the "conversions.txt" file.

### Input and Output

The user is to input a V, C, S, or Q in either upper or lower case when the menu is presented to them. The input commands for the option they selected will be outputted following the format of the corresponding functions. 

When looking at visuals (selecting V), the user should input norm or tri and the following output is to open the corresponding file. Then the user is to input either y or n, depending on whether or not they want to look at another visual.

When converting RGB values (selecting C), the user is directed to input values between 0 and 255 for red, green, and blue pigments. The program then outputs the values they entered and the converted values.

When the user selects S from the menu, the program outputs the "conversions.txt file that stores all the values they inputted and converted.


### Decisions

The user enters a V, C, S or Q to direct them to the corresponding fuction commands. 

Within the look at visuals option, the user either enters norm or tri to see a certain visual. Then they enter y or n, depending on if they want to see another visual.

Within the readRBGValue() function, the user is instructed to enter another value if their input wasn't between 0 and 255.

Within the showConversions() function, an if statement is used to confirm that the file opened properly and then display it. If it doesn't open, the program displays an error message.

### Iteration

In the main program, I used a do...while loop to call the functions according to the users selected choice while their choice wasn't quit. (Q/q)

Within the convertVisual() function, I used a do...while loop to run the program when the user's choice of vision while their decision is not 'n'.

In the readRBGValue() function, I used a while loop. While their value for each color is less than 0 or greater than 255, the program asks the user for a value. I used this loop to run through each color so they don't have to reinput all the values, but just the color value that was outside of these boundaries.  


In the print() function, I used a for loop to run through the product vector so they can be outputted to the console and written to the conversions.txt file.

In the showConversions() function, I used a while loop to read the file line by line. 

### File Input and Output

I used the variable:
  ofstream ofs("conversions.txt", std::ofstream::out);
in order to create a file and open it for operations. When I wanted text or user input to be added to this file, I used the ostream &writer parameter within functions. I declared the variable ifstream file (filename, std::ifstream::in);
combined with a while loop to read the file line by line within the showConversions() function.

### Arrays/Vectors

Outside main (globalized):
vector <double> matrixMultiplier = {0.95, 0.05, 0.0,  0.0, 0.433, 0.567,  0.0, 0.475, 0.525};
3 by 3 matix, reading across the rows, formatted into a vector, key variable to conversions

Within the main program:
vector <int> rgb = {0, 0, 0}; 
Initialized at 0 to avoid "magic numbers" and when rgb is passed into the vector <int> &x parameter (converted values) of the print() function.

Within the convertRGBValues() function:
vector <int> product = {0, 0, 0}; 
Initialized at 0 to avoid "magic numbers". This function includes a function to carry out matrix multiplication in order to convert the values. Those new values are then stores in each index while being rounded off into integers like standard RGB values would be. The product vector is then returned.


### Functions
char chooseMenu();
Presents the main menu to the user and returns choice in terms of a char.

void convertVisual();
Allows the user to look at different visuals of vision (presents a string that tells them where to look). No parameters and no return value.

vector <int> convertRGB(double r, double g, double b, ostream &writer);
The convertRGB() function takes in 4 parameters. 3 doubles called r, g, b, and an ostream pass-by-reference variable called &writer. R, g, and b take in the values that the user wants to convert for each color. The function then inserts these values into a math function multiplying the 1x3 matrix with the 3x3 matrix in order to produce the 1x3 product vector that is to be returned. I put these the matrices in terms of vector in order to simplify the multiplication process. The ostream variable is called by reference because it will be modified if the user decides to convert more values.

int readRBGValue(string color);
This funtion takes in a string variable called color. In the main program, I called "red", "green", and "blue" so the function can run through these values one by one to ensure the input is within the boundaries of 0 and 255. The inputted value is then returned to the function to be inputted into r, g, and b. 

void print (vector <int> &x, ostream &writer);
Takes in a pass-by-reference vector of integers called x as well as an ostream variable called writer. This function loops throught the inputted values for r, g, b by way of vector and then outputs them to the console and writes them to the conversions file. These are pass by reference, so the user can enter new values and the file will be modified when they do so. There is no return value.

void showConversions(string filename);
This function has one string parameter called filename, which is called with "conversions.txt" in the main program so the function opens for reading. There is no return value. 