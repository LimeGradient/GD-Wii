# Basic File Setup
You need to include stdio, stdlib, gccore, and wpad.h as the very basic for scripts. You also need a static void pointer (ex. <code>static void *xfb = NULL</code>) and a GXRModeObj (ex. <code>static GXRModeObj *rmode = NULL</code>). You then need to Initialize the Video and WPAD Systems with <code>VIDEO_Init();</code> and <code>WPAD_Init();</code>

# Printing
Make sure that the console was Initialized with <code>console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);</code> or some variation on this function. Then you want to printf which will print text to the screen. 