/// @description Move onto next level
with (obj_drawGUI){
	draw_mission_complete = false;
	draw_start = true;
}
instance_destroy(obj_ship, false);
global.g_level++;
alarm_set(0, 2 * room_speed);

//reset scrolling background
layer_hspeed(global.asteroid_layer, 0);
layer_vspeed(global.asteroid_layer, 0);
layer_x(global.asteroid_layer, 0);
layer_y(global.asteroid_layer, 0);