#ifndef TT_GFX_H
#define TT_GFX_H

#include <tt.h>
#include "shaders.h"
#include "camera.h"
#include "renderer/renderer.h"
#include "lighting/lighting.h"
#include "objects/3d/textures/textures.h"
#include "objects/3d/objects/objects.h"
#include "objects/2d/fonts/fonts.h"
#include "objects/2d/textures/textures.h"
#include "objects/2d/objects/objects.h"

bool tt_gfx_init(const bool quiet); //returns true if successfull

//cleaning up what was initalized by the graphics system
void tt_gfx_quit(const bool quiet);

#endif