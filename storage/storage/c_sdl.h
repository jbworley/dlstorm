/* Seth's SDL Graphics Wrapper */

#ifndef _SDL_GFX_LIBRARY
#define _SDL_GFX_LIBRARY

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef TEST_VGA16
#define NUM_COLORS  16
#else
#define NUM_COLORS  256
#endif

#include "SDL.h"
#include "ximage.h"
//#include "SDL_image.h"
#include "c_gaf.h"
#include "c_log.h"

//#pragma comment( lib, "SDLmain.lib" )
//#pragma comment( lib, "SDL.lib" )
//#pragma comment( lib, "SDL_image.lib" )

#ifdef __cplusplus
extern "C"
{
#endif
    void InitializeInput(void);
    void ShutDownInput(void);
    void RefreshMouse(void);
    bool GetMouseRelease(int iWhich);
    void SetMouseRelease(int iWhich,bool set);
    bool GetMouseDown(int iWhich);
    void SetMouseDown(int iWhich,bool set);
    bool GetMouseDblClick(int iWhich);
    void SetMouseDblClick(int iWhich,bool set);
    int  GetMouseX(void);
    void SetMouseX(int x);
    int  GetMouseY(void);
    void SetMouseY(int y);

	int  GetMouseWheelUp(void);
	void SetMouseWheelUp(bool m);
    int  GetMouseWheelDown(void);
	void SetMouseWheelDown(bool m);
    bool MouseInX(int x1,int x2);
    bool MouseInY(int y1,int y2);
    bool MouseIn( int x1,int y1,int x2,int y2);
    //bool MouseInXPct(float fx1,float fx2);
    //bool MouseInYPct(float fy1,float fy2);
    //bool MouseInPct( float fx1,float fy1, float fx2,float fy2);
#ifdef __cplusplus
}
#endif

//#define SDL_RGB(r,g,b) SDL_MapRGB(GFX->screen->format,r,g,b)
//#define _RGB(r,g,b) SDL_MapRGB(GFX->screen->format,r,g,b)
//#define __RGB(r,g,b) SDL_MapRGB(screen->format,r,g,b)

class C2DFont
{
public:

    C2DFont();
    C2DFont(char *file);
    ~C2DFont();

    void Write(int x, int y, char *string,int bank);
    void Load(char *file);

    SDL_Surface *Font;

};

class CSprite
{
public:

    CSprite();
    CSprite(SDL_Surface *source_surface);
    CSprite(SDL_Surface *source_surface,SDL_Surface *target_surface);
    ~CSprite();

    float x;
    float y;

    int health;
    int mana;
    int power;
    int status;
    int weapon1;
    int weapon2;

    SDL_Surface *source_surface;
    SDL_Surface *target_surface;

    SDL_Rect rect[256];
    bool visible;
    int animation_frame;
    int animation_lastframe;
    long animation_speed;
    bool animation_loop;
    bool animated;
    void Init(void);

    void LoadSurface(char *filename);
    void LoadMemSurface(unsigned char *fb);





    void SetColorKey(int r, int g, int b);

    void Draw(float x, float y);
    void Draw();
    void SetRect(int which,int x, int y, int w, int h);
    long animtimer;

    float xdir;
    float ydir;
    float xspeed;
    float yspeed;

};

//extern "C" SDL_Surface *LoadGAFSurface(CGAF* gaf,char *fn);

class CSDL_Wrap : public C2DFont
{
public:

    CSDL_Wrap();
    CSDL_Wrap(char *an);
    CSDL_Wrap(char *an,Uint32 w,Uint32 h,Uint32 b);
    CSDL_Wrap(char *an,Uint32 w,Uint32 h,Uint32 b, SDL_Surface *icon);
    CSDL_Wrap(char *an,Uint32 w,Uint32 h,Uint32 b, char *icon);
	CSDL_Wrap(char *an,Uint32 w,Uint32 h,Uint32 b, Uint16 f, char *icon);
    ~CSDL_Wrap();

    bool InitSuccess;

    Uint32 w;
    Uint32 h;
    Uint32 b;
    int    videoflags;
    char APP_NAME[_MAX_PATH];

    CGAF        *GAF;
    CLog        *Log;

    SDL_Surface *screen;
    SDL_Surface *Icon;

    bool         Begin(char *an,Uint32 width, Uint32 height, Uint32 bpp, SDL_Surface *icon);
    bool         Begin(char *an,Uint32 width, Uint32 height, Uint32 bpp, char *icon);

    bool         Init2D(int width, int height, int bpp);
    bool         Init2D(int width, int height, int bpp, SDL_Surface *icon);
    bool         ToggleFullScreen(void);
    Uint32       GetPixel(int x, int y);
    void         PutPixel(int x, int y, Uint32 pixel);

    void         DrawRect(int x, int y, int w, int h, Uint32 color);

    void         ClearScreen(Uint32 color);
    SDL_Surface *CreateScreen(Uint16 w, Uint16 h, Uint8 bpp, Uint32 flags);
    void         Flip(void);
    void         LoadFont(char *fn);

    SDL_Surface *LoadMemSurface(SDL_RWops *rw);
    SDL_Surface *LoadGAFSurface(char *fn);

    void        DrawMap(void);
    void        RebuildGAF(void);



};



#endif