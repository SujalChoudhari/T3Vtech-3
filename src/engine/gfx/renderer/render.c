#include <tt.h>

extern GLuint tt_std_3d_shader; //the default shader program for all 3d objects
extern GLuint tt_std_2d_shader; //the default shader program for all 2d objects

//this is the beginning of the 3D object rendering list
extern tt_node *tt_3d_list_entry_node;


void tt_gfx_render()
{
	//render 3D stuff
	tt_gfx_3d_preparation();
	
	tt_3d_object *current_object=NULL;
	if(tt_3d_list_entry_node)
	{
		current_object=tt_3d_list_entry_node->data;
		tt_node *current_node=tt_3d_list_entry_node;

		while(true)
		{
			//prepare uniforms
			GLint translation=glGetUniformLocation(tt_std_3d_shader, "translation");
			GLint scale=glGetUniformLocation(tt_std_3d_shader, "scale");
			GLint rotation=glGetUniformLocation(tt_std_3d_shader, "rotation");

			//set uniforms
			const GLfloat *mat4_uniform=(const GLfloat*)current_object->translation.array;
			glUniformMatrix4fv(translation, 1, GL_FALSE, mat4_uniform);

			mat4_uniform=(const GLfloat*)current_object->scale.array;
			glUniformMatrix4fv(scale, 1, GL_FALSE, mat4_uniform);
			
			mat4_uniform=(const GLfloat*)current_object->rotation.array;
			glUniformMatrix4fv(rotation, 1, GL_FALSE, mat4_uniform);

			//bind buffers
			glBindVertexArray(current_object->vao);
			glBindBuffer(GL_ARRAY_BUFFER, current_object->vbo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, current_object->ibo);

			//describe vertex data
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (void*)0);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (void*)(3*sizeof(GLfloat)));
			glEnableVertexAttribArray(1);

			//use textures
			glBindTexture(GL_TEXTURE_2D, current_object->texture);
			
			glDrawElements(
				GL_TRIANGLES,
				current_object->num_indices,
				GL_UNSIGNED_INT,
				NULL);


			//get to the next object to render
			current_node=tt_list_next_node(current_node);
			if(!current_node) //if no following object is left then exit
			{
				break;
			}
			current_object=current_node->data;
		}
	}

	//render 2D stuff
	tt_gfx_2d_preparation();
}
