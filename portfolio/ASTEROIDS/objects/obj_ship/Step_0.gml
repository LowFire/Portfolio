/// @description Check if ship is crashed. If so, destroy instance.

if (isCrashed == true){
		if (image_index == image_number - 1){
			instance_destroy();
			with (obj_controller)
				ship_destroyed = true;
		}
}
