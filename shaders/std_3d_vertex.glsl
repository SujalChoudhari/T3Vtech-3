#version 450
#define NUM_MAX_DIR_LIGHTS 8


layout(location = 0) in vec3 pos_in;
layout(location = 1) in vec2 base_tex_coord_in;
layout(location = 2) in vec3 normal_in;

//directional lighting light sources
layout(std140, binding = 0) uniform dir_light
{
	vec4 dir_light_num_active; //active number of lights
	vec4 dir_light_dir[NUM_MAX_DIR_LIGHTS]; //direction
	vec4 dir_light_color[NUM_MAX_DIR_LIGHTS]; //light color
	vec4 dir_light_strength[NUM_MAX_DIR_LIGHTS]; //light intensity
};

uniform mat4 translation;
uniform mat4 scale;
uniform mat4 rotation;
uniform mat4 projection;

//gouraud shading
uniform bool gouraud_shading_toggle;
uniform vec3 gouraud_shading_dir;
uniform vec3 gouraud_shading_color;
uniform float gouraud_shading_light_strength;

out vec2 base_tex_coord;
out float gouraud_strength;
out float directional_light_angle[NUM_MAX_DIR_LIGHTS];



void main()
{
	//basic transformations
	vec4 pos = vec4 (pos_in, 1.0);
	pos = projection * translation * scale * rotation * pos;
	vec4 normal_tmp = rotation * vec4(normal_in, 1.0);
	vec3 normal=normalize(vec3(normal_tmp.xyz));

	//gouraud shading
	//directional_light_color=gouraud_shading_color;
	//directional_light_strength=gouraud_shading_light_strength;
	if(gouraud_shading_toggle)
	{
		for(int i=0; i<dir_light_num_active.x; i++)
		{
			directional_light_angle[i]=dot(-dir_light_dir[i].xyz, normal);
			if(directional_light_angle[i]<0)
			{
				directional_light_angle[i]=0;
			}
		}
	}

	//output
	gl_Position = pos;
	base_tex_coord=base_tex_coord_in;
}