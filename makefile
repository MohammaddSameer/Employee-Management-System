bin/proFile: mainA3.o helperA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o sortEmployeesId.o countEmployees.o fireAll.o fireOne.o include/headerA3.h
	gcc -Wall -std=c99 -g mainA3.o helperA3.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o sortEmployeesId.o countEmployees.o fireAll.o fireOne.o -o bin/proFile

mainA3.o: mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -g -c mainA3.c

helperA3.o: helperA3.c include/headerA3.h
	gcc -Wall -std=c99 -g -c helperA3.c

recruitEmployee.o: recruitEmployee.c include/headerA3.h
	gcc -Wall -std=c99 -g -c recruitEmployee.c

printAll.o: printAll.c include/headerA3.h
	gcc -Wall -std=c99 -g -c printAll.c

printOne.o: printOne.c include/headerA3.h
	gcc -Wall -std=c99 -g -c printOne.c

lookOnId.o: lookOnId.c include/headerA3.h
	gcc -Wall -std=c99 -g -c lookOnId.c

lookOnFullName.o: lookOnFullName.c include/headerA3.h
	gcc -Wall -std=c99 -g -c lookOnFullName.c

sortEmployeesId.o: sortEmployeesId.c include/headerA3.h
	gcc -Wall -std=c99 -g -c sortEmployeesId.c

countEmployees.o: countEmployees.c include/headerA3.h
	gcc -Wall -std=c99 -g -c countEmployees.c

fireAll.o: fireAll.c include/headerA3.h
	gcc -Wall -std=c99 -g -c fireAll.c

fireOne.o: fireOne.c include/headerA3.h
	gcc -Wall -std=c99 -g -c fireOne.c

clean:
	rm *.o bin/proFile -f