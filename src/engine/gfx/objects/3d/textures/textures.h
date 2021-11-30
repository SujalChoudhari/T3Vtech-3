#ifndef TT_GFX_TEXTURE_H
#define TT_GFX_TEXTURE_H

struct tt_3d_texture
{
	GLuint texture;
} typedef tt_3d_texture;

tt_3d_texture* tt_3d_texture_new(const char *path, const bool bilinear_filtering);
void tt_3d_texture_delete(tt_3d_texture **texture);
#endif