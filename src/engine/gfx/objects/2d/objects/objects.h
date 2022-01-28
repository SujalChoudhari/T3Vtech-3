#ifndef TT_GFX_OBJECTS_2D_H
#define TT_GFX_OBJECTS_2D_H


struct tt_2d_object
{
	//OpenGL relevant data
	GLuint vao;
	GLuint vbo;
	GLuint ibo;
	uint32_t num_indices;

	//transformations
	tt_vec2 translation;

} typedef tt_2d_object;

//engine internal functions
void tt_gfx_prepare_sprite();
void tt_2d_object_clear_render_list();

//common 2d object functions
tt_2d_object* tt_2d_object_new();
void tt_2d_object_render(tt_2d_object *object);
void tt_2d_object_set_position(tt_2d_object *object, tt_vec2 *position);

//sprite
void tt_2d_object_make_sprite(tt_2d_object *object);

#endif