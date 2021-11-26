#version 450

layout(location = 0) in vec3 pos;

uniform mat4 translation;
uniform mat4 scale;
uniform mat4 rotation;

void main()
{
	//basic transformations
	vec4 tmp_pos = vec4 (pos, 1.0);
	tmp_pos = translation * scale * rotation * tmp_pos;
	gl_Position = tmp_pos;
}