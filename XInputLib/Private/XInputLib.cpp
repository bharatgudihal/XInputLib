#include "../XInputLib.h"

XInputLib::XInputLib() {
	ZeroMemory(&m_state, sizeof(XINPUT_STATE));
	for (int index = 0; index < 4; index++) {
		isConnected(index);
	}
}

bool XInputLib::isConnected(int index) {
	DWORD result;
	assert(index < 4);
	result = XInputGetState(index, &m_state);
	if (result == ERROR_SUCCESS) {
		controllers[index].state = m_state;		
		return true;
	}
	else {		
		return false;
	}
}

bool VibrateLeft(uint8_t index, float intensity) {
	if (!library.isConnected(index)) {		
		return false;		
	}
	library.controllers[index].vibration.wLeftMotorSpeed = static_cast<WORD>(library.MAX_INTENSITY * intensity);
	DWORD result = XInputSetState(index, &library.controllers[index].vibration);
	if (result == ERROR_SUCCESS) {
		return true;
	}
	else {
		return false;
	}
}

bool VibrateRight(uint8_t index, float intensity) {
	if (!library.isConnected(index)) {
			return false;		
	}
	library.controllers[index].vibration.wRightMotorSpeed = static_cast<WORD>(library.MAX_INTENSITY * intensity);
	DWORD result = XInputSetState(index, &library.controllers[index].vibration);
	if (result == ERROR_SUCCESS) {
		return true;
	}
	else {
		return false;
	}
}