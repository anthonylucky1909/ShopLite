main: main.o control.o seller.o  open.o admin.o information.o transaction.o refresh.o
	g++ -o main main.o control.o seller.o  open.o admin.o information.o transaction.o refresh.o -g


main.o: main.cpp
	g++ -c -o main.o main.cpp
control.o: control.cpp
	g++ -c -o control.o control.cpp
seller.o: seller.cpp
	g++ -c -o seller.o seller.cpp
open.o: open.cpp
	g++ -c -o open.o open.cpp
admin.o: admin.cpp
	g++ -c -o admin.o admin.cpp
information.o :information.cpp
	g++ -c -o information.o information.cpp
transaction.o :transaction.cpp
	g++ -c -o transaction.o transaction.cpp

refresh.o : refresh.cpp
	g++ -c -o refresh.o refresh.cpp

clean:
	rm -rf *o main