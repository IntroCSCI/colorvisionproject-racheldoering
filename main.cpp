#include <iostream>
#include <fstream>

using namespace std;

int main() {
 // Variables
 string vision;
 fstream reader;
 char decision;

 // Input and Output
 do{
  cout << "Would you like to see a visual of normal vision or tritanopia (blue/yellow color blindness)? " << endl;
  cout << "Enter norm or tri: " << endl;
  cin >> vision;

   // Decisions
   if(vision == "norm")
   {
     // File Input and Output
     reader.open ("normalvision.png");
     cout << "Look at normalvision.png in the visuals file." << endl;
     cout<< " "<<endl;

   }
   else if(vision == "tri")
   {
     reader.open("tritanopia.png");
     cout << "Look at tritanopia.png in the visuals file." << endl;
     cout<<" "<<endl;
   }
   else {
     cout << "Invalid input " << endl;
   }
   cout << "Would you like to look at a different visual? (y/n): "<<endl;
   cin >> decision;

 } while(decision != 'n');
 // Iteration


  
return 0;
}
