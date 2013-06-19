
#include "dlstorm.h"
#include "c_glmouse.h"
#include "c_gltexture.h"
#include "SDL.h"

/*************************************************////////////////////
// C_MouseCursor Class
/*************************************************////////////////////

C_MouseCursor::C_MouseCursor()
{
    memset(filename,0,1024);
    Cursor=0;
    // pLog->_Add("Mouse cursor created");
}

C_MouseCursor::C_MouseCursor(CLog *pInLog)
{
    pLog=pInLog;
    Cursor=0;
    pLog->_Add(">> C_MouseCursor::C_MouseCursor(CGAF *pInGAF, CLog *pInLog) OK");
}


C_MouseCursor::C_MouseCursor(CGAF *pInGAF, CLog *pInLog)
{
    pGAF=pInGAF;
    pLog=pInLog;
    Cursor=0;
    pLog->_Add(">> C_MouseCursor::C_MouseCursor(CGAF *pInGAF, CLog *pInLog) OK");
}

/*************************************************////////////////////
C_MouseCursor::C_MouseCursor(char *fn)
{
    memset(filename,0,1024);
    Cursor=0;
    load(fn);
    pLog->_Add("Mouse cursor created");
}
/*************************************************////////////////////
C_MouseCursor::~C_MouseCursor()
{
    kill();
    pLog->_Add("Mouse cursor destroyed");
}
/*************************************************////////////////////
GLvoid C_MouseCursor::kill()
{
    DEL(Cursor);
}

#include "ximage.h"

/*************************************************////////////////////
GLvoid C_MouseCursor::load(char *file)
{
    if(!strlen(file)) return;
    strcpy(filename,file);

    DEL(Cursor);
    Cursor=new CGLTexture();
    if(!Cursor) return;
    Cursor->bmap=0;
    Cursor->mask=0;
    Cursor->usemask=1;
    Cursor->Load(pGAF,va("%s.bmp",file),0);

	std::vector <std::string> vs;
	CxMemFile *hi;

	if(!pGAF) return;

	GAF_FileBuffer nfb;

	char fin[1024];    memset(fin,0,1024);
	nfb=pGAF->GetFile((LPSTR)va("%s.ini",file));
	if(nfb.Size>0)
	{
		//Log("                    \\--> Point file: %s.ini",file);
		hi=new CxMemFile((BYTE*)nfb.fb,nfb.Size);
		hi->GetS(fin,256);
		x_offset=atoi(fin); //Log("                       \\--> x_offset = %d",x_offset);

		hi->GetS(fin,256);
		y_offset=atoi(fin); //Log("                       \\--> y_offset = %d",y_offset);

		hi->GetS(fin,256);
		x_hotspot=atoi(fin); //Log("                       \\--> x_hopspot = %d",x_hotspot);

		hi->GetS(fin,256);
		y_hotspot=atoi(fin); //Log("                       \\--> y_hopspot = %d",y_hotspot);

		DEL(hi);
	}
}
/*************************************************////////////////////
GLvoid C_MouseCursor::draw(void)
{
    if(!Cursor) return;
    if(!Cursor->bmap) load(filename);
    if(!Cursor->mask) load(filename);
    if(!Cursor->bmap) return;
    if(!Cursor->mask) return;

    x=x/2;
    y=(-y/2)+(SDL_GetVideoSurface()->h/2);

    glLoadIdentity();
    glColor3f(1.0f,1.0f,1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_DST_COLOR,GL_ZERO);
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0,SDL_GetVideoSurface()->w,0,SDL_GetVideoSurface()->h);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(x,y,0);
    glBindTexture(GL_TEXTURE_2D,Cursor->mask);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f,1.0f,1.0f);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(float(x ),    float(y - 64),    1);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(float(x+64),  float(y - 64),    1);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(float(x+64),  float(y ),        1);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(float(x ),    float(y ),        1);
    glEnd();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0,SDL_GetVideoSurface()->w,0,SDL_GetVideoSurface()->h);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(x,y,0);
    glBindTexture(GL_TEXTURE_2D,Cursor->bmap);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f,1.0f,1.0f);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(float(x ),    float(y - 64),    1);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(float(x+64),  float(y - 64),    1);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(float(x+64),  float(y ),        1);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(float(x ),    float(y ),        1);
    glEnd();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);

}



/*************************************************//*************************************************/
/*************************************************//*************************************************/
/*************************************************//*************************************************/


C_GLMouse::C_GLMouse()
{

}

C_GLMouse::C_GLMouse(CGAF *pInGAF, CLog *pInLog)
{
    pGAF=pInGAF;
    pLog=pInLog;

    pCursor=new C_MouseCursor(pGAF,pLog);
    pCursor->load("mouse/0");
}

C_GLMouse::~C_GLMouse()
{
    DEL(pCursor);

}

void C_GLMouse::InitializeInput(void)
{
    bLeftDown             = 0;
    bMiddleDown           = 0;
    bRightDown            = 0;
    bLeftDblClick         = 0;
    bMiddleDblClick       = 0;
    bRightDblClick        = 0;
    bWheelUp              = 0;
    bWheelDown            = 0;
    lLeftDownTick         = dlcs_get_tickcount();
    lMiddleDownTick       = dlcs_get_tickcount();
    lRightDownTick        = dlcs_get_tickcount();
    lLeftDblClickTimer    = dlcs_get_tickcount();
    lMiddleDblClickTimer  = dlcs_get_tickcount();
    lRightDblClickTimer   = dlcs_get_tickcount();
}

void C_GLMouse::draw()
{
    pCursor->x=ix+pCursor->x_offset;
    pCursor->y=iy+pCursor->y_offset;
    pCursor->draw();
}

/*************************************************/

void C_GLMouse::Refresh(void)
{
    bool bLeft=0;
    bool bRight=0;
    bool bMiddle=0;
    int butt;

    unsigned long current_tick=dlcs_get_tickcount();

    butt       = SDL_GetMouseState(&ix,&iy);

    bLeft      = TOBOOL((SDL_BUTTON(SDL_BUTTON_LEFT)      & butt));
    bMiddle    = TOBOOL((SDL_BUTTON(SDL_BUTTON_MIDDLE)    & butt));
    bRight     = TOBOOL((SDL_BUTTON(SDL_BUTTON_RIGHT)     & butt));

    bLeftRelease=0;
    bRightRelease=0;
    bMiddleRelease=0;
    bLeftDblClick=0;
    bMiddleDblClick=0;
    bRightDblClick=0;
    bLeftDownTick=0;
    bMiddleDownTick=0;
    bRightDownTick=0;

    if(bLeftDown)
    {
        if(current_tick-lLeftDownTick > C_GLM_DOWNTICK_TIME)
        {
            bLeftDownTick=1;
            lLeftDownTick=current_tick;
        }

        if(!bLeft)
        {
            bLeftRelease = 1;
            if(current_tick-lLeftDblClickTimer<C_GLM_DOUBLECLICK_TIME)
            {
                bLeftDblClick = 1;
            }
            lLeftDblClickTimer=current_tick;
        }
    }

    if(bRightDown)
    {
        if(current_tick-lRightDownTick > C_GLM_DOWNTICK_TIME)
        {
            bRightDownTick=1;
            lRightDownTick=current_tick;
        }

        if(!bRight)
        {
            bRightRelease  = 1;
            if(current_tick-lRightDblClickTimer<C_GLM_DOUBLECLICK_TIME)
            {
                bRightDblClick = 1;
            }
            lRightDblClickTimer=current_tick;
        }
    }

    if(bMiddleDown)
    {
        if(current_tick-lMiddleDownTick > C_GLM_DOWNTICK_TIME)
        {
            bMiddleDownTick=1;
            lMiddleDownTick=current_tick;
        }

        if(!bMiddle)
        {
            bMiddleRelease = 1;
            if(current_tick-lMiddleDblClickTimer<C_GLM_DOUBLECLICK_TIME)
            {
                bMiddleDblClick = 1;
            }
            lMiddleDblClickTimer=current_tick;
        }
    }

    bLeftDown   = bLeft;
    bRightDown  = bRight;
    bMiddleDown = bMiddle;
}

/*************************************************/

bool C_GLMouse::ButtonDownTick(int iWhich)
{
    switch(iWhich)
    {
        case SDL_BUTTON_LEFT:
            return bLeftDownTick;
        case SDL_BUTTON_MIDDLE:
            return bMiddleDownTick;
        case SDL_BUTTON_RIGHT:
            return bRightDownTick;
        default:
            return 0;
            break;
    }
    return 0;
}

/*************************************************/

void C_GLMouse::SetDownTick(int iWhich,bool set)
{
    switch(iWhich)
    {
        case SDL_BUTTON_LEFT:
            bLeftDownTick=set;
            return;
        case SDL_BUTTON_MIDDLE:
            bMiddleDownTick=set;
            return;
        case SDL_BUTTON_RIGHT:
            bRightDownTick=set;
            return;
        default:
            break;
    }
}
/*************************************************/

bool C_GLMouse::LeftClick()
{
    return Click(SDL_BUTTON_LEFT);
}

/*************************************************/

bool C_GLMouse::MiddleClick()
{
    return Click(SDL_BUTTON_MIDDLE);
}

/*************************************************/

bool C_GLMouse::RightClick()
{
    return Click(SDL_BUTTON_RIGHT);
}

/*************************************************/

bool C_GLMouse::Click(int iWhich)
{
    switch(iWhich)
    {
        case SDL_BUTTON_LEFT:
            return bLeftRelease;
        case SDL_BUTTON_MIDDLE:
            return bMiddleRelease;
        case SDL_BUTTON_RIGHT:
            return bRightRelease;
        default:
            return 0;
            break;
    }
    return 0;
}
/*************************************************/
void C_GLMouse::SetClick(int iWhich,bool set)
{
    switch(iWhich)
    {
        case SDL_BUTTON_LEFT:
            bLeftRelease=set;
            return;
        case SDL_BUTTON_MIDDLE:
            bMiddleRelease=set;
            return;
        case SDL_BUTTON_RIGHT:
            bRightRelease=set;
            return;
        default:
            break;
    }
}
/*************************************************/
void C_GLMouse::SetButtonDown(int iWhich,bool set)
{
    switch(iWhich)
    {
        case SDL_BUTTON_LEFT:
            bLeftDown=set;
        case SDL_BUTTON_RIGHT:
            bRightDown=set;
        case SDL_BUTTON_MIDDLE:
            bMiddleDown=set;
        default:
            return;
    }
}
/*************************************************/
bool C_GLMouse::ButtonDown(int iWhich)
{
    switch(iWhich)
    {
        case SDL_BUTTON_LEFT:
            return bLeftDown;
        case SDL_BUTTON_RIGHT:
            return bRightDown;
        case SDL_BUTTON_MIDDLE:
            return bMiddleDown;
        default:
            return 0;
    }
    return 0;
}
/*************************************************/
bool C_GLMouse::DoubleClick(int iWhich)
{
    switch(iWhich)
    {
        case SDL_BUTTON_LEFT:
            return bLeftDblClick;
        case SDL_BUTTON_RIGHT:
            return bRightDblClick;
        case SDL_BUTTON_MIDDLE:
            return bMiddleDblClick;
        default:
            return 0;
    }
    return 0;
}
/*************************************************/
int  C_GLMouse::X(void){ return ix; }
/*************************************************/
void C_GLMouse::SetX(int x) { ix=x; }
/*************************************************/
int  C_GLMouse::Y(void){return iy;}
/*************************************************/
void C_GLMouse::SetY(int y) { iy=y; }
/*************************************************/
bool C_GLMouse::InX(int x1,int x2)
{
    //float sfx=(float)((float)x1/800)*(float)pClientData->ScreenWidth;
	//float mfx=(float)((float)GetMouseX()/800)*(float)pClientData->ScreenWidth;
	//float sfx2=(float)((float)x1/800)*(float)pClientData->ScreenWidth;
	//if((mfx>sfx) && (mfx<sfx2)) return true;
	if((X()>x1) && (X()<x2))
		return true;
	return false;
}
/*************************************************/
bool C_GLMouse::InY(int y1,int y2)
{
	//float sfy=(float)((float)y1/600)*(float)pClientData->ScreenHeight;
	//float mfy=(float)((float)GetMouseY()/600)*(float)pClientData->ScreenHeight;
	//float sfy2=(float)((float)y1/600)*(float)pClientData->ScreenHeight;
    //if((mfy>sfy) && (mfy<sfy2)) return true;
	if((Y()>y1) && (Y()<y2)) return true;
	return false;
}
/*************************************************/
bool C_GLMouse::In( int x1,int y1,int x2,int y2)
{
    if((InX(x1,x2))&&(InY(y1,y2)))
        return true;
    return false;
}
/*************************************************/

bool C_GLMouse::InRect(RECT rc)
{
    return (In(rc.left,rc.top,rc.left+rc.right,rc.top+rc.bottom));
}

/*************************************************
bool C_GLMouse::InXPct(float fx1,float fx2)
{
	if((X()>(pClientData->ScreenWidth*fx1)) && (X()<(pClientData->ScreenWidth*fx2)))
		return true;
	return false;
}
*/
/*************************************************
bool C_GLMouse::InYPct(float fy1,float fy2)
{
	if((Y()>(pClientData->ScreenHeight*fy1)) && (Y()<(pClientData->ScreenHeight*fy2)))
		return true;
	return false;
}
*/
/*************************************************
bool C_GLMouse::InPct( float fx1,float fy1,float fx2,float fy2)
{
	if((InXPct(fx1,fx2))&&(InYPct(fy1,fy2)))
		return true;
	return false;
}
*/
/*************************************************/
void C_GLMouse::SetWheelUp(bool m)
{
    bWheelUp=m;
}
/*************************************************/
int  C_GLMouse::WheelUp(void)
{
    //return bWheelUp;
    if(bWheelUp)
    {
        bWheelUp=0;
        return 1;
    }
    else
    {
        return 0;
    }
}
/*************************************************/
void C_GLMouse::SetWheelDown(bool m)
{
    bWheelDown=m;
}
/*************************************************/
int  C_GLMouse::WheelDown(void)
{
    //return bWheelDown;
    if(bWheelDown)
    {
        bWheelDown=0;
        return 1;
    }
    else
    {
        return 0;
    }
}
/*************************************************/
