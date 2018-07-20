#ifndef _settings_h
#define _settings_h 

#define XRES    1280
#define YRES    720

#define ASPECT ((float)XRES/(float)YRES)
#define WINDOWFLAGS (WS_VISIBLE | WS_OVERLAPPEDWINDOW)


#define TICKTIME (1.0/30.0)

#define MAX_SCENE_OBJECTS 1024*10


#endif // _settings_h