all : client1 client2 client3 client4 client5 client6 client7 client8

client8: client8.o A.o B.o C.o E.o NTon.o
	g++-7 client8.o A.o B.o C.o D.o E.o NTon.o -o client8

client7: client7.o A.o B.o C.o E.o NTon.o
	g++-7 client7.o A.o B.o C.o D.o E.o NTon.o -o client7

client6: client6.o A.o B.o C.o D.o E.o NTon.o
	g++-7 client6.o A.o B.o C.o D.o E.o NTon.o -o client6

client5: client5.o A.o B.o C.o D.o E.o NTon.o
	g++-7 client5.o A.o B.o C.o D.o E.o NTon.o -o client5

client4: client4.o A.o B.o C.o D.o E.o NTon.o
	g++-7 client4.o A.o B.o C.o D.o E.o NTon.o -o client4
	
client3: client3.o A.o B.o C.o D.o E.o NTon.o
	g++-7 client3.o A.o B.o C.o D.o E.o NTon.o -o client3

client2: client2.o A.o B.o C.o D.o E.o NTon.o
	g++-7 client2.o A.o B.o C.o D.o E.o NTon.o -o client2
	
client1 : client1.o A.o B.o C.o D.o E.o NTon.o
	g++-7 client1.o A.o B.o C.o D.o E.o NTon.o -o client1

client8.o : client8.cpp A.h B.h C.h D.h E.h NTon.h
	g++-7 -c client8.cpp

client7.o : client7.cpp A.h B.h C.h D.h E.h NTon.h
	g++-7 -c client7.cpp

client6.o : client6.cpp A.h B.h C.h D.h E.h NTon.h
	g++-7 -c client6.cpp
	
client5.o : client5.cpp A.h B.h C.h D.h E.h NTon.h
	g++-7 -c client5.cpp

client4.o : client4.cpp A.h B.h C.h D.h E.h NTon.h
	g++-7 -c client4.cpp

client3.o : client3.cpp A.h B.h C.h D.h E.h NTon.h
	g++-7 -c client3.cpp

client2.o : client2.cpp A.h B.h C.h D.h E.h NTon.h
	g++-7 -c client2.cpp
	
client1.o : client1.cpp A.h B.h C.h D.h E.h NTon.h
	g++-7 -c client1.cpp
	
A.o : A.cpp A.h NTon.h
	g++-7 -c A.cpp

B.o : B.cpp B.h A.h
	g++-7 -c B.cpp

C.o : C.cpp C.h A.h
	g++-7 -c C.cpp

D.o : D.cpp D.h B.h
	g++-7 -c D.cpp
	
E.o : E.cpp E.h B.h C.h
	g++-7 -c E.cpp

NTon.o : NTon.cpp NTon.h
	g++-7 -c NTon.cpp

