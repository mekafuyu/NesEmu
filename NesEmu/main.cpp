#include <iostream>
#include <iomanip>
#include <bitset>
#include "CPU.h"

using namespace std;


void logCpu(CPU * cpu, uint8_t * memory)
{
	cout << "State:" << dec << endl;
	cout << "\tReg A: " << unsigned(cpu->getAccumulator()) << endl;
	cout << "\tReg X: " << unsigned(cpu->getIndexX()) << endl;
	cout << "\tReg Y: " << unsigned(cpu->getIndexY()) << endl;
	cout << "\tReg S: " << bitset<8>(cpu->getStatus()) << endl;
	cout << "\tReg PC: " << unsigned(cpu->getProgramCounter()) << " | MemPtr: " << cpu->getMemory() - memory << endl;
};

int main() {

	uint8_t memory[0xFFFF] = { 0xA9, 0xC0, 0xAA, 0xE8, 0x00 };

	CPU* cpu = new CPU();
	cpu->linkMemory(memory);

	bool run = true;
	do
	{
		logCpu(cpu, memory);
		cout << "\nInstruct Exec: " << hex << uppercase << unsigned(*(cpu->getMemory())) << endl;
		run = cpu->run();
	} while (run);
	logCpu(cpu, memory);

}

