/*
 * AndOrGate.cpp
 *
 *  Created on: 04/06/2014
 *      Author: developer
 */

#include <systemc.h>
#include <iostream>
using namespace std;

SC_MODULE(and_gate) {
	sc_inout<bool> a;
	sc_inout<bool> b;
	sc_out<bool> c;

	sc_clock clk;

	void and_process() {
		c = a.read() && b.read();
		cout << " a=" << a << " b=" << b << " c=" << c;
	}

	void test_process() {
		while (true) {
			assert((a.read() & b.read()) == c.read());
			//wait();
			b.write(b.read());
		}
	}

	SC_CTOR(and_gate) {

		SC_METHOD(and_process);
		sensitive << a;
		sensitive << b;

	}

};
