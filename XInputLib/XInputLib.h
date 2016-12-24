#pragma once
#include <Windows.h>
#include <Xinput.h>
#include <assert.h>
#include <stdint.h>

struct Controller
{
	XINPUT_STATE state;
	XINPUT_VIBRATION vibration;	
};

class XInputLib {
public:
	XInputLib();
	Controller controllers[4];
	bool isConnected(int);
	XINPUT_STATE m_state;
	const DWORD MAX_INTENSITY = 65535;	
};

XInputLib library;

extern "C"
{
	__declspec(dllexport) bool VibrateRight(uint8_t controllerIndex, float intensity);
	__declspec(dllexport) bool VibrateLeft(uint8_t controllerIndex, float intensity);
}