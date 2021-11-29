#include <tt.h>

int main()
{
	tt_init("T3Vtech3 test window", 1920, 1080, false);

	float fov=0.5*tt_PI;
	tt_vec3 pos={0.5,0.5,1.0};
	tt_vec3 scale={1,1,1};
	tt_vec3 orientation={0.5,0.5,0.0};
	tt_3d_object *quad=tt_3d_object_new();
	tt_3d_object_make_quad(quad);

	for(int i=0; i<2000; i++)
	{
		tt_new_frame();
		//SDL_Delay(15);

		//scale.y=(float)i/90;
		pos.x=0.5*sin((float)i/50);
		pos.y=0.5*cos((float)i/50);
		pos.z=10;//*sin((float)i/100)+11;
		tt_3d_object_set_position(quad, &pos);
		tt_set_fov(fov);
		fov=0.5*tt_PI*i/2000;

	}


	return 0;
}