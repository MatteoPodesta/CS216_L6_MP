**11/10/2025**
* class definition style & standards:  first, member vars  none per line and do not forget to initialize them;  second functions: separate group of functions  by a blank line; either matching setter/getter pairs or list all setters back to back and list all getters back to back; start with a default c’tor, followed by  copy c’tor (if any), then other c’tors in the order of increased number of arguments, d’tor- right after c’tor(s), overloaded functions- list them back to back in the order of increased number of arguments;  all accessor/getter functions should be const; all functions with more than one statement should be normal (defined externally, outside of the class and below main()), no inline functions with more than one statement; initialize all member variables to appropriate default values at the time of definition; all member variables must be private; classes must provide a strong exception guarantee; must have default c’tor; implement Rule of Three when necessary
* To provide you with thorough feedback, your instructor reads your code line by line, sometimes multiple times. Jumping from file to file is too time-consuming. Unless noted otherwise, place your class definitions above the main() and all function definitions below main(), all in one file. While the industry standard involves multi-source file programs, we will use a single file format for these labs unless instructed otherwise.
* Posted instructions are not optional, and not following the instructions will result in a lower grade. It applies to all assignments in this course.
* I will replace this lab’s score with your next lab score, as long as the next lab score is higher and all mistakes from this lab are corrected
* istream& operator>>(istream& is, Fraction& fractionObj) allows  a Fraction object to become invalid. Should store new numerator and denominator in temp variables and then call SetFraction with 3 ags;  what of a user enters non-numeric value? -10
*  124 should be member function; 2/4 is not equal to 4/8? -5
*  do not use this-> unless you really have to, it reduces readability; local vars and function parameters should have different names, nStuId, new_StudID, newStudId ; you can call member function directly SetFraction() -2
* ostream& operator<<(ostream& os, const Fraction& fractionObj)  convoluted  logic -2
```text
//example only
string res;

int whole=numer/denom;
int tempNumer= numer%denom;
// =68/20 = 3 8/20 ; 6
res=to_string(numer)+"/" + to_string(denom)+" == "; //improper  ""
res+=((whole!=0)? (to_string(whole)+ " ") :"" ); //whole, if any18/20 == 
res+=((tempNumer>0)? (to_string(tempNumer)+ "/"+to_string(denom)):""); // n/d,  if

```
* inadequate and/ insufficient test data/ not all possible scenarios and edge cases have been tested; e.g., each record has 4 pieces of data; pow(2,4)->16  possible combinations of valid/invalid and only one of them is a valid record; all menu options should be tested;  no zeros, negative numbers, etc.; big test numbers != good test data; must test all created functions -5

