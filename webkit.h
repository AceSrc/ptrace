#include "tinyxml2.h"
#include <stdio.h>
using namespace tinyxml2;
extern XMLDocument xmlin, xmlout;
extern XMLElement *dpoints, *dlines;
namespace pstr {
	char *nts(int x);
	char *combine(char *a, char *b);
	char *combineWithBlank(char *a, char *b);
}
void setInput(char *s);
void setOutput(char *s);
void drawPoint(int x, int y, char *s = NULL);
void drawLine(int sx, int sy, int ex, int ey, char *s = NULL);
void outputStart();
void outputFinished();
