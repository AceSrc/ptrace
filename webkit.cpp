#include "webkit.h"

XMLDocument xmlin, xmlout;
XMLElement *dpoints, *dlines;
namespace pstr {
	char *nts(int x) {
		int u = x, t = 0;
		while (u) u /= 10, t++;
		char *s = new char(t + 1);
		s[t--] = '\0';
		while (x) s[t--] = x % 10 + '0', x /= 10;
		return s;
	}
	char *combine(char *a, char *b) {
		int n = 0, m = 0;
		for ( ; a[n] != '\0'; n++) ;
		for ( ; b[m] != '\0'; m++) ;
		char *s = new char(n + m + 1);
		s[n + m] = '\0';
		for (int i = 0; i < n; i++) s[i] = a[i];
		for (int i = n; i < n + m; i++) s[i] = b[i - n];
		return s; 
	}
	char *combineWithBlank(char *a, char *b) {
		int n = 0, m = 0;
                for ( ; a[n] != '\0'; n++) ;
                for ( ; b[m] != '\0'; m++) ;
                char *s = new char(n + m + 2);
                s[n + m + 1] = '\0';
                for (int i = 0; i < n; i++) s[i] = a[i];
		s[n] = ' ';
                for (int i = n + 1; i <= n + m; i++) s[i] = b[i - n - 1];
                return s;

	}
}

void setInput(char *s) {
	xmlin.LoadFile(s);
}

void setOutput(char *s) {
	FILE *file = fopen(s, "w");
	fclose(file);
	xmlout.LoadFile(s);
	dpoints = xmlout.NewElement("points");
	dlines = xmlout.NewElement("lines");
	xmlout.InsertEndChild(dpoints);
	xmlout.InsertEndChild(dlines);
}

void drawPoint(int x, int y, char *s) {
	XMLElement *point = xmlout.NewElement("point");
	point->SetAttribute("x", pstr :: nts(x));
	point->SetAttribute("y", pstr :: nts(y));
	if (s) point->InsertEndChild(xmlout.NewText(s));
	dpoints->InsertEndChild(point);
}

void drawLine(int sx, int sy, int ex, int ey, char *s) {
	XMLElement *line = xmlout.NewElement("line");
	line->SetAttribute("sx", pstr :: nts(sx));
	line->SetAttribute("sy", pstr :: nts(sy));
	line->SetAttribute("ex", pstr :: nts(ex));
	line->SetAttribute("ey", pstr :: nts(ey));
	if (s) line->InsertEndChild(xmlout.NewText(s));
	dlines->InsertEndChild(line);
}

void outputStart() {
	setInput("in.xml");
	setOutput("out.xml");
}

void outputFinished() {
	xmlout.SaveFile("out.xml");
}
