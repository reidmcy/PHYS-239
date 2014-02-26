//Question 4
//Reid McIlroy-Young
//20416412
//February 25,2014

#include <iostream>
using namespace std;

ostream* function (ostream *aOut) {
    *(aOut) << "Hello" << endl;
    return aOut;
}

int main () {
    function(function(&cout));
}

/*
Output:
Hello
Hello
*/
