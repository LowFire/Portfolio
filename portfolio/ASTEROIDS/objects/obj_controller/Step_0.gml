/// @description Check for states
//Subtract a life if ship is crashed
if (ship_destroyed == true && asteroids_destroyed == false){
	if (global.g_lives > 0){
		global.g_lives--;
		alarm_set(1, 1 * room_speed);
	}
	else
		with (obj_drawGUI){
			draw_game_over = true;
			create_gameOver_buttons = true;
		}
	ship_destroyed = false;
}

//Check if all asteroids are destroyed
if (instance_number(obj_asteroid) == 0 && level_started == true){
	with (obj_drawGUI)
		draw_mission_complete = true;
	alarm_set(2, 2 * room_speed);
	level_started = false;
}

if (restart == true){
	//reset global variables to defaults
	global.g_level = 1;
	global.g_lives = 3;
	global.num_lrg_asteroids = 0;
	global.num_med_asteroids = 0;
	global.num_sml_asteroids = 2;
	
	//destroy all instances in room
	instance_destroy(obj_ship, false);
	instance_destroy(obj_asteroid, false);
	instance_destroy(obj_button, false);
	
	//Setup for first level
	with (obj_drawGUI){
		draw_game_over = false;
		draw_start = true;
	}
	alarm_set(0, 2 * room_speed);
	level_started = false;
	restart = false;
}