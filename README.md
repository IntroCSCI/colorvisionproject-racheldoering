# Simulation: Normal vision vs Tritanopia

## Description

Tritanopia or blue/yellow color blindness is rare but is caused by a missing/malfunctioning S-cone. This program simulates what it would look like to have tritanopia. It asks the user which type of vision they want to see and then opens the corresponding picture.

## Developer

Rachel Doering

## Example

To run the program, give the following commands:

```
g++ --std=c++11 main.cpp -o cvp
./cvp
norm
y
tri
n
```

Here is an example of the program running:

```
g++ -std=c++11 main.cpp -o cvp; ./cvp
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
 
```

## C++ Guide

### Variables and Data Types
 
I declared the *string* variable called 'vision' to account for the vision type input. I also delared a *char* variable called 'decision' so the user can say if they want so see another visual, using 'y' or 'n'. Lastly, I declared the *fstream* variable called 'reader' so I could use file input and output functions.

### Input and Output

The user is to input 'vision' with a value of either "norm" or "tri". If the user enters neither of these values, there is an error message and the loop will ask them again. The program then asks if they want look at another visual with input of decision values 'y' or 'n'.

### Decisions

I used *if* and *else if* statements to open the corresponding picture files, based on the users choice of 'vision'. Then I used the *else* to output an error message if neither of these options were inputted. 

### Iteration

I used a *do...while* loop to run the program when the user decision is not 'n' meaning they didn't want another visual. If they enter 'y', the program will continue to run, until they enter 'n'. The *do...while* loop ensures the loop will run at least once.

### File Input and Output

I downloaded my png files and saved them into the 'visuals' folder. When the user specifies either 'norm' or 'tri', the program opens the file. However, since c++ doesn;t support image output, the program intructs the user to go look at the corresponding file.