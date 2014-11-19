#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "textprocess.h"
#include "echo.h"
#include "l337.h"
#include "lower.h"
#include "doublecon.h"
#include "caesar.h"

int main () {
  string s;

  while(1) {
    getline(cin,s);
    if (cin.fail()) break;
    istringstream iss(s);
    string fname;
    iss >> fname;
    istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());

    TextProcessor *tp = new Echo;
    string dec;
    while (iss >> dec) {
      if (dec == "l337") {
        tp = new L337(*tp);
      }
      else if (dec == "lower") {
        tp = new Lower(*tp);
      }
      else if (dec == "doublecon") {
        tp = new DoubleCon(*tp);
      }
      else if (dec == "caesar") {
        int n;
        iss >> n;
        tp = new Caesar(*tp, n);
      }
   } 

   tp->setSource(in);

   string word;

   while (word = tp->getWord(), !tp->fail()) {
     cout << word << endl;
   }

   if (in != &cin) delete in;

   delete tp;
  }
}
