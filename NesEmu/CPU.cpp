#include "CPU.h"

bool CPU::run()
{
	switch (*this->memory)
	{
	// LDA
	case 0xA9:
		this->memory++;
		this->pc++;

		this->a = *this->memory;
		updateStatusFlag(this->a);

		break;

	// TAX
	case 0xAA:
		this->x = this->a;
		updateStatusFlag(this->x);

		break;

	// INX
	case 0xE8:
		this->x++;
		updateStatusFlag(this->x);

		break;

	// BRK
	case 0x00:
		this->memory++;
		this->pc++;
		return false;
		break;

	default:
		break;
	}

	this->memory++;
	this->pc++;
	return true;
}


void CPU::updateStatusFlag(uint8_t currreg)
{
	this->s &= 0b01111101;
	if (currreg == 0)
	{
		this->s |= 0b00000010;
		return;
	}

	if ((currreg & 0b10000000) != 0)
	{
		this->s |= 0b10000000;
	}
}

void CPU::linkMemory(uint8_t* memory)
{
	this->memory = memory;
}

uint8_t* CPU::getMemory()
{
	return this->memory;
}

uint8_t CPU::getAccumulator()
{
	return this->a;
}

void CPU::setAccumulator(uint8_t value)
{
	this->a = value;
}

uint8_t CPU::getIndexX()
{
	return this->x;
}

void CPU::setIndexX(uint8_t value)
{
	this->x = value;
}

uint8_t CPU::getIndexY()
{
	return this->y;
}

void CPU::setIndexY(uint8_t value)
{
	this->y = value;
}

uint8_t CPU::getStatus()
{
	return this->s;
}

void CPU::setStatus(uint8_t value)
{
	this->s = value;
}

uint16_t CPU::getProgramCounter()
{
	return this->pc;
}

void CPU::setProgramCounter(uint8_t value)
{
	this->pc = value;
}

CPU::CPU()
{
}

CPU::~CPU()
{
}