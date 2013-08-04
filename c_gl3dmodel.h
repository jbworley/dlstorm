/***************************************************************
    DLSTORM Deadline's Code Storm Library
    Author: Seth Parson
****************************************************************/

#ifndef _DLSTORM_OPENGL_MODEL
#define _DLSTORM_OPENGL_MODEL

#include "c_gfx.h"
#include "c_gltexture.h"
#include "c_log.h"
#include "s_gnu.h"
#include "cimport.h"
#include "scene.h"
#include "postprocess.h"

class C_GFX;

class CGLModel {
public:
    CGLModel();
    CGLModel(CLog *pInLog);
    ~CGLModel();
    char        name[1024];

    bool        bMadeLog;
    CLog*       pLog;

    CGLModel*   pNext;
    CGLModel*   pPrev;
    CGAF*       pGAF;
    C_GFX*      pGFX;

    CGLModel*   nextMesh;
    CGLTexture* pTexture;
    char        texturename[1024];

    int         numMeshes;
    int         numMaterials;
    int         numTriangles;
    int         numUvCoords;


    float*  vertexArray;
    float*  normalArray;
    float*  uvArray;

    bool Load(char* filename);

    bool Draw(void);

    bool RenderSceneDraw(void);

    void Locate(float nx, float ny, float nz);
    void Rotate(float nx, float ny, float nz);
    void Scale(float nx,float ny,float nz);
    void Color(float nr,float ng,float nb);
};

#endif
