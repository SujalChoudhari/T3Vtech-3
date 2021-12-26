#include <player.hpp>
#include <shooting-range.hpp>

sr::player::player()
{
	tt_camera_set_position(&m_pos);
}

void sr::player::update()
{
	//mouse movement
	int mouse_x_rel=0;
	int mouse_y_rel=0;
	tt_input_mouse_relative(&mouse_x_rel, &mouse_y_rel);
	side_angle+=0.001*mouse_x_rel;
	up_angle+=0.001*mouse_y_rel;
}