#include <tt.h>

//this is the beginning of the 3D object rendering list
extern tt_node *tt_3d_list_entry_node;

void tt_delete_3d_object(tt_3d_object *object)
{
	//if this object is the first object in the render list
	if(object->node==tt_3d_list_entry_node)
	{
		tt_list_remove_node(&tt_3d_list_entry_node);
	}
	else
	{
		tt_list_remove_node(&object->node);
	}

	free(object);

}
