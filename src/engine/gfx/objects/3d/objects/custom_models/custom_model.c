#include <tt.h>


tt_3d_custom_model* tt_3d_custom_model_load_file(const char *path)
{
	int num_verts;
	int num_indices;
	GLfloat *vertex_data;
	GLuint *index_data;
	float size_bounding_sphere;
	tt_3d_collision_aabb aabb;

	//deciding the file type
	//OBJ
	if(strstr(path, ".obj") || strstr(path, ".OBJ"))
	{

		if(!tt_3d_object_custom_model_load_obj_file(
			path, 
			&num_verts,
			&num_indices,
			&vertex_data, 
			&index_data,
			&size_bounding_sphere,
			&aabb))
		{
			return NULL;
		}
		else
		{
			printf("OBJ model from %s successfully loaded\n", path);
		}
	}
	else
	{
		return NULL;
	}

	//creating the custom model
	tt_3d_custom_model *model=malloc(sizeof(tt_3d_custom_model));
	if(!model)
	{
		printf("[ERROR] memory couldn't be allocated for a custom 3D model\n");
		return NULL;
	}
	//saving data to the custom object's struct
	model->num_verts=num_verts;
	model->num_indices=num_indices;
	model->size_bounding_sphere=size_bounding_sphere;
	model->aabb=aabb;
	/* aabb values;
	printf("aabb: x_max: %f\n", model->aabb.x_max);
	printf("aabb: x_min: %f\n", model->aabb.x_min);
	printf("aabb: y_max: %f\n", model->aabb.y_max);
	printf("aabb: y_min: %f\n", model->aabb.y_min);
	printf("aabb: z_max: %f\n", model->aabb.z_max);
	printf("aabb: z_min: %f\n", model->aabb.z_min);
	*/

	glGenVertexArrays(1, &model->vao);
	glBindVertexArray(model->vao);
	glGenBuffers(1, &model->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, model->vbo);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(tt_3d_custom_model_vertex)*num_verts, 
		vertex_data, 
		GL_STATIC_DRAW);
	glGenBuffers(1, &model->ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->ibo);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		sizeof(GLuint)*num_indices,
		index_data,
		GL_STATIC_DRAW);

	free(vertex_data);
	free(index_data);

	return model;
}


void tt_3d_custom_model_delete(tt_3d_custom_model **model)
{
	glDeleteVertexArrays(1, &(*model)->vao);
	glDeleteBuffers(1, &(*model)->vbo);
	glDeleteBuffers(1, &(*model)->ibo);

	*model=NULL; //mark the custom model as deleted
}
