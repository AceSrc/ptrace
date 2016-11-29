#include <iostream>
#include <stdio.h>
#include <string.h>
#include "webkit.h"
using namespace std;
int main() {
	outputStart();
	drawPoint(2, 3, "HelloWorld");
	drawLine(2, 3, 4, 5, "Hello World!");
	outputFinished();
	return 0;
}
