#include "settings.h"
#include "scene.h"
#include "menu.h"

PIXELFORMATDESCRIPTOR pfd =
{
	sizeof(PIXELFORMATDESCRIPTOR),
	1,
	PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
	PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
	32,                   // Colordepth of the framebuffer.
	0, 0, 0, 0, 0, 0,
	0,
	0,
	0,
	0, 0, 0, 0,
	24,                   // Number of bits for the depthbuffer
	8,                    // Number of bits for the stencilbuffer
	0,                    // Number of Aux buffers in the framebuffer.
	PFD_MAIN_PLANE,
	0,
	0, 0, 0
};

const int attribList[] =
{
    WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
    WGL_CONTEXT_MINOR_VERSION_ARB, 3,
    0 // End
};



int WinMain( HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    HWND hWnd = CreateWindowExA(WS_EX_APPWINDOW, "static", 0, WINDOWFLAGS, 0, 0, XRES, YRES, 0, 0, 0, 0);
    HDC context = GetDC(hWnd);
    SetPixelFormat(context, ChoosePixelFormat(context, &pfd), &pfd);
    wglMakeCurrent(context, wglCreateContext(context));

    auto hContext = ((PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB"))(context, 0, attribList);
    wglMakeCurrent(NULL, NULL);
    wglMakeCurrent(context, hContext);

    //MessageBoxA(0, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);
    loadGlPointers(); // load the sthi
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    Scene* scene= new Scene(context, hWnd);
    scene->createObject(new Menu());

    do
    {
    static MSG dummyMessage;
        PeekMessageA(&dummyMessage, 0, 0, 0, 1); // Remove all Windows messages to prevent "Program not responding" dialog.
        DefWindowProc(dummyMessage.hwnd, dummyMessage.message, dummyMessage.wParam, dummyMessage.lParam);
        scene->rootUpdate();
    } while (!GetAsyncKeyState(VK_ESCAPE));

    ExitProcess(0);
    return 0;
}

void * __cdecl operator new(unsigned int bytes)
{
    return HeapAlloc(GetProcessHeap(), 0, bytes);
}

void * __cdecl operator new[](unsigned int bytes)
{
    return HeapAlloc(GetProcessHeap(), 0, bytes);
}

void __cdecl operator delete(void *ptr)
{
    if (ptr) HeapFree(GetProcessHeap(), 0, ptr);
}

void __cdecl operator delete[](void *ptr)
{
    if (ptr) HeapFree(GetProcessHeap(), 0, ptr);
}

extern "C" int __cdecl __purecall(void)
{
    return 0;
}
