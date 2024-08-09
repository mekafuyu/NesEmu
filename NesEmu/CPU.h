#pragma once

#include <cstdint>

class CPU
{
private:
	uint8_t a = 0x00;
	uint8_t x = 0x00;
	uint8_t y = 0x00;
	uint8_t p = 0x00;
	uint8_t s = 0x00;
	uint16_t pc = 0x0000;

	uint8_t* memory;

	void updateStatusFlag(uint8_t currreg);
public:
	bool run();

	void linkMemory(uint8_t* memory);
	uint8_t* getMemory();

	uint8_t getAccumulator();
	void setAccumulator(uint8_t value);

	uint8_t getIndexX();
	void setIndexX(uint8_t value);

	uint8_t getIndexY();
	void setIndexY(uint8_t value);

	uint8_t getStatus();
	void setStatus(uint8_t value);

	uint16_t getProgramCounter();
	void setProgramCounter(uint8_t value);
	
	CPU();
	~CPU();
};
