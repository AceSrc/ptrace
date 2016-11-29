run : container.cpp webkit.cpp a
	g++ container.cpp webkit.cpp tinyxml2.cpp -o run -g
a : a.cpp webkit.cpp 
	g++ a.cpp webkit.cpp tinyxml2.cpp -o a -g
	
