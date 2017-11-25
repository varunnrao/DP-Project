a.out :	client.o A.o B.o C.o D.o NTon.o
	g++-7 client.o A.o B.o C.o D.o NTon.o

client.o : client.cpp A.h B.h C.h D.h NTon.h
	g++-7 -c client.cpp
	
A.o : A.cpp A.h NTon.h
	g++-7 -c A.cpp

B.o : B.cpp B.h A.h
	g++-7 -c B.cpp

C.o : C.cpp C.h A.h
	g++-7 -c C.cpp

D.o : D.cpp D.h B.h
	g++-7 -c D.cpp

NTon.o : NTon.cpp NTon.h
	g++-7 -c NTon.cpp

