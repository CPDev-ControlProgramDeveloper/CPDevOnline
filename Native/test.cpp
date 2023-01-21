#include <stdio.h>
#include <unistd.h>

#include <sys/resource.h>

#include "vm_linux.h"
#include "vm_variable.h"
#include "xcp/WeJeStSt.c"

VMLinux* cpdev;
unsigned char* xcp = 0;

extern "C"
{
	int CPDev_LoadProgram(unsigned char data[], int length);
	int CPDev_Init();
	int CPDev_RunCycle();
	WM_BOOL CPDev_GetBool(int adr);

	unsigned char GetDataByte(unsigned int address);
	unsigned short GetDataWord(unsigned int address);
	unsigned GetDataDWord(unsigned int address);
	unsigned long long GetDataLWord(unsigned int address);
	float GetDataReal(unsigned int address);
	double GetDataLReal(unsigned int address);

	int GetData(unsigned int address, unsigned char len, unsigned char* buf);
	int SetData(unsigned int address, unsigned char len, unsigned char* buf);

}

int CPDev_LoadProgram(unsigned char data[], int length)
{
	int res;
	//printf("Output: %x %x %x %x\n", data[0], data[1], data[2], data[3]);
	if (!xcp) free(xcp);
	xcp = (WM_BYTE*)malloc(length);
	memcpy(xcp, data, length);
	res = cpdev->VMP_LoadProgramFromArray(xcp, DEFAULT_DATA_SIZE);

	if (res == 0)
	{
		cpdev->task_cycle = 500;
		cpdev->WM_Initialize(WM_MODE_FIRST_START | WM_MODE_NORMAL);
	}

	return res;

}


int CPDev_Init()
{
	cpdev = new VMLinux();
	//cpdev->VMP_LoadProgramFromArray(WeJeStSt_xcp, DEFAULT_DATA_SIZE);
	//cpdev->task_cycle = 500;
	//cpdev->WM_Initialize(WM_MODE_FIRST_START | WM_MODE_NORMAL);

	return 0;
}

int CPDev_RunCycle()
{

	WM_BOOL button = 0;

	WM_BYTE o0, o1, o2, o3;

	//cpdev->WM_SetData(onof, &button);

	cpdev->WM_RunCycle();

	cpdev->WM_GetData(0, 1, &o0);
	cpdev->WM_GetData(1, 1, &o1);
	cpdev->WM_GetData(2, 1, &o2);
	cpdev->WM_GetData(3, 1, &o3);
	printf("Output: %d %d %d %d\n", o0, o1, o2, o3);

	return 0;

}

WM_BOOL CPDev_GetBool(int adr)
{
	WM_BOOL res = 0;
	if (cpdev != NULL)
	{
		cpdev->WM_GetData((WM_ADDRESS)adr, 1, &res);
	}

	return res;
}

int GetData(unsigned int address, unsigned char len, unsigned char* buf)
{
	return cpdev->WM_GetData(address, len, buf);
}

int SetData(unsigned int address, unsigned char len, unsigned char* buf)
{
	return cpdev->WM_SetData(address, len, buf);
}

unsigned char GetDataByte(unsigned int address)
{
	unsigned char val;
	cpdev->WM_GetData(address, 1, &val);
	return val;
}

void SetDataByte(unsigned int address, unsigned char val)
{
	cpdev->WM_SetData(address, 1, &val);
}

unsigned short GetDataWord(unsigned int address)
{
	unsigned short val;
	cpdev->WM_GetData(address, 2, (unsigned char*)&val);
#ifdef BIG_ENDIAN
	val = ((val >> 8) | (val << 8));
#endif
	return val;
}


void SetDataWord(unsigned int address, unsigned short val)
{
#ifdef BIG_ENDIAN
	val = ((val >> 8) | (val << 8));
#endif
	cpdev->WM_SetData(address, 2, (unsigned char*)&val);
}


unsigned GetDataDWord(unsigned int address)
{
	unsigned val;
	cpdev->WM_GetData(address, 4, (unsigned char*)&val);
#ifdef BIG_ENDIAN
	ntohl(val);
#endif
	return val;
}


void SetDataDWord(unsigned int address, unsigned val)
{
#ifdef BIG_ENDIAN
	ntohl(val);
#endif
	cpdev->WM_SetData(address, 4, (unsigned char*)&val);
}

unsigned long long GetDataLWord(unsigned int address)
{
	unsigned long long val;
	cpdev->WM_GetData(address, 8, (unsigned char*)&val);
#ifdef BIG_ENDIAN
	ByteSwap((unsigned char*)&val, 8);
#endif
	return val;
}


void SetDataLWord(unsigned int address, unsigned long long val)
{
#ifdef BIG_ENDIAN
	ByteSwap((unsigned char*)&val, 8);
#endif
	cpdev->WM_SetData(address, 8, (unsigned char*)&val);
}

float GetDataReal(unsigned int address)
{
	float val;
	cpdev->WM_GetData(address, sizeof(float), (unsigned char*)&val);
	return val;
}


void SetDataReal(unsigned int address, float val)
{
	cpdev->WM_SetData(address, sizeof(float), (unsigned char*)&val);
}

double GetDataLReal(unsigned int address)
{
	double val;
	cpdev->WM_GetData(address, sizeof(double), (unsigned char*)&val);
	return val;
}
