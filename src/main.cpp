//============================================================================
// Name        : mipssystemc.cpp
// Author      : Alison Venâncio
// Version     :
// Copyright   : Projeto Final de Curso de Engenharia da Computação na Universidade Federal do Amazonas
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <systemc.h>
#include <cassert>
#include <iostream>
#include "AndGate.h"
int sc_main(int argc, char* argv[]) {

	sc_signal<bool> s1;
	sc_signal<bool> s2;
	sc_signal<bool> s3;

	std::cout << "TESTE";
	s1.write(true);
	s2.write(true);
	s3.write(false);

	and_gate and_gate("and_gate");
	and_gate.a(s1);
	and_gate.b(s2);
	and_gate.c(s3);

	and_gate.and_process();
	and_gate.test_process();

//	sc_start(100);
	return 0;
}
