bin/proFile: mainA3.o helperA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o sortEmployeesId.o countEmployees.o fireAll.o fireOne.o include/headerA3.h
	gcc -Wall -std=c99 -g mainA3.o helperA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o sortEmployeesId.o countEmployees.o fireAll.o fireOne.o -o bin/proFile

mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/mainA3.c

helperA3.o: src/helperA3.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/helperA3.c

recruitEmployee.o: src/recruitEmployee.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/recruitEmployee.c

printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/printAll.c

printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/printOne.c

lookOnId.o: src/lookOnId.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/lookOnId.c

lookOnFullName.o: src/lookOnFullName.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/lookOnFullName.c

sortEmployeesId.o: src/sortEmployeesId.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/sortEmployeesId.c

countEmployees.o: src/countEmployees.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/countEmployees.c

fireAll.o: src/fireAll.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/fireAll.c

fireOne.o: src/fireOne.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/fireOne.c

clean:
	rm *.o bin/proFile -f