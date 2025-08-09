myshell: myshell.cpp
	# Preparing
	mkdir -p ci/obj
	mkdir -p usr/bin

	# Compiling libs
	g++ -c -o ci/obj/print.o lib/print.cpp
	g++ -c -o ci/obj/args.o lib/args.cpp
	g++ -c -o ci/obj/initMyshell.o lib/initMyshell.cpp
	g++ -c -o ci/obj/dealWithInput.o lib/dealWithInput.cpp
	g++ -c -o ci/obj/execute.o lib/execute.cpp
	g++ -c -o ci/obj/childRoutine.o lib/childRoutine.cpp
	g++ -c -o ci/obj/parentRoutine.o lib/parentRoutine.cpp

	# Building static libs
	ar rvs ci/myshell.a ci/obj/*.o

	# Compiling features
	gcc -o usr/bin/pingme usr/lib/pingme.c

	# Compiling main program with all static libs
	g++ -o myshell myshell.cpp ci/myshell.a
