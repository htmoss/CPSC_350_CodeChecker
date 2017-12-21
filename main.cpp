#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  string f = argv[1];

  if ( argc != 2 )
  {
    cout<<"usage: "<< argv[0] <<" <filename>\n";
  }
  else
  {
    ifstream the_file ( argv[1] );
    //check to see if file opening succeeded
    if ( !the_file.is_open() )
    {
      cout<<"File reading error"<<endl;
    }
    else
    {
      while (true)
      {
        GenStack<char> *s1(new GenStack<char>(10));
        GenStack<int> *s2(new GenStack<int>(10));

        ifstream inFile;
      	inFile.open(f);

        if (inFile.is_open())
        {
          int currentLine = 0;
          string line = "";
          cout << "File is open" << endl;
          while (getline(inFile, line))
      		{
            currentLine++;
            for (int i = 0; i < line.length(); ++i)
            {
              if (line[i] == '(' || line[i] == '{' || line[i] == '[')
              {
                s1->push(line[i]);
                s2->push(currentLine);
              }
              else if (line[i] == ')' && s1->peek() == '(')
              {
                s1->pop();
                s2->pop();
              }
              else if (line[i] == '}' && s1->peek() == '{')
              {
                s1->pop();
                s2->pop();
              }
              else if (line[i] == ']' && s1->peek() == '[')
              {
                s1->pop();
                s2->pop();
              }
            }
      		}

          if (s1->isEmpty())
          {
            cout << "Your file had no errors! Would you like to check another file? (Please enter yes or no): ";
            string answer;
            cin >> answer;
            while (answer != "yes" && answer != "no")
            {
              cout<<"Please enter either 'yes' or 'no'."<<endl;
              cin >> answer;
            }
            if (answer == "no")
            {
              break;
            }
            else
            {
              cout << "Enter the file you would like to check next: ";
              string newfile;
              cin >> newfile;
              f = newfile;
            }
          }
          else
          {
            while (!s1->isEmpty())
            {
              cout << "You are missing a " << s1->pop() << " on line " << s2->pop() << endl;
            }
            cout << "Go fix your file and good luck!" << endl;
            break;
          }
          inFile.close();
        }
      }
    }
  }

  //testing
  /*
  int size = 3;
  GenStack <int> intStack(size);
  GenStack <char> charStack(size);

  intStack.push(3);
  intStack.push(4);

  charStack.push('A');
  charStack.push('B');

  cout<<"Peek: "<<intStack.peek()<<endl;
  cout<<"Popped: "<<intStack.pop()<<endl;

  cout<<"Peek: "<<charStack.peek()<<endl;
  cout<<"Popped: "<<charStack.pop()<<endl;


  return 0;
  */
}
