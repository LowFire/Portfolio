/// @description Start level once timer is up
with (obj_drawGUI){
	draw_start = false;
	draw_lives = true;
}
level_started = true;
//Spawn ship and asteroids
instance_create_layer(512, 512, "instances", obj_ship);

//Increase number of asteroids every level
if (global.g_level != 1){
	if (global.g_level % 9 == 0)
		global.num_lrg_asteroids++;
	else if (global.g_level % 3 == 0)
		global.num_med_asteroids++;
	else
		global.num_sml_asteroids++;
}

//Give a life every 10 levels
if (global.g_level % 5 == 0)
	global.g_lives++;

randomize(); //Create random seed
repeat (global.num_lrg_asteroids){
	rand_pos_x = irandom_range(0, 1024);
	rand_pos_y = irandom_range(0, 1024);
	instance_create_layer(rand_pos_x, rand_pos_y, "instances", obj_lrgAsteroid);
}

repeat (global.num_med_asteroids){
	rand_pos_x = irandom_range(0, 1024);
	rand_pos_y = irandom_range(0, 1024);
	instance_create_layer(rand_pos_x, rand_pos_y, "instances", obj_medAsteroid);
}

repeat (global.num_sml_asteroids){
	rand_pos_x = irandom_range(0, 1024);
	rand_pos_y = irandom_range(0, 1024);
	instance_create_layer(rand_pos_x, rand_pos_y, "instances", obj_smlAsteroid);
}