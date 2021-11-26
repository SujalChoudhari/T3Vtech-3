#include <tt.h>

int main()
{
	tt_init("T3Vtech3 test window", 1920, 1080, true);

	tt_vec3 pos={0.5,0.5,0.0};
	tt_vec3 orientation={0.5,0.5,0.0};
	tt_3d_object *quad=tt_3d_object_new();
	tt_3d_object_make_quad(quad);

	for(int i=0; i<5; i++)
	{
		tt_new_frame();
		SDL_Delay(3000);
	}


	return 0;
}