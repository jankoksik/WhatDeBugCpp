#include <string>
using namespace std;

enum colors {
    black = 0,
    red = 1,
    green = 2,
    yellow = 3,
    blue = 4,
    magenta = 5,
    cyan =6,
    white =7
};

typedef colors colors;

/*
reset             0  (everything back to normal)
bold/bright       1  (often a brighter shade of the same colour)
underline         4
inverse           7  (swap foreground and background colours)
bold/bright off  21
underline off    24
inverse off      27
*/

int sumc(int a, int b)
{
    return a + b;
}

string CustomText(string input, colors Fcolor, colors Bcolor,  string options)
    
{
string result = "\033[";

if(Fcolor == black){
    result+= "30;";
}
else if (Fcolor == red)
{
    result+= "31;";
}
else if (Fcolor == green){
    result+= "32;";
}
else if (Fcolor == yellow){
    result+= "33;";
}
else if (Fcolor == blue){
    result+= "34;";
}
else if (Fcolor == magenta){
    result+= "35;";
}
else if (Fcolor == cyan){
    result+= "36;";
}
else if (Fcolor == white){
    result+= "37;";
}

if(Bcolor == black){
    result+= "40";
}
else if (Bcolor == red)
{
    result+= "41";
}
else if (Bcolor == green){
    result+= "42";
}
else if (Bcolor == yellow){
    result+= "43";
}
else if (Bcolor == blue){
    result+= "44";
}
else if (Bcolor == magenta){
    result+= "45";
}
else if (Bcolor == cyan){
    result+= "46";
}
else if (Bcolor == white){
    result+= "47";
}

result += options + "m";
result += input;
result += "\033[0m\n";

return result;
}

