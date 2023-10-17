#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <grrlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <ogc/tpl.h>

int main(int argc, char* argv[]) {
	GRRLIB_Init();
	WPAD_Init();
	while (1) {
		WPAD_ScanPads();
		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break;
		GRRLIB_Render();
	}
	GRRLIB_Exit();
	exit(0);
}