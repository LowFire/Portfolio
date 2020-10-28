/// @description Initialize global variables
global.g_lives = 3;
global.g_level = 1;
global.num_lrg_asteroids = 0;
global.num_med_asteroids = 0;
global.num_sml_asteroids = 2;
global.asteroid_layer = layer_create(50);
global.bg_asteroids = layer_background_create(global.asteroid_layer, bg_asteroid_belt);
layer_background_vtiled(global.bg_asteroids, true);
layer_background_htiled(global.bg_asteroids, true);
with (obj_drawGUI){
	draw_menu = false;
	draw_start = true;
}
alarm_set(0, 2 * room_speed);