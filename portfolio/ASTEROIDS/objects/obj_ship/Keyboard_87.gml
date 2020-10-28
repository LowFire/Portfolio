/// @description Thrust ship forward
if (canThrust == true){
	accel_x += thrust * cos(degtorad(direction + 90));
	accel_y += thrust * sin(degtorad(direction + 90));
	layer_hspeed(global.asteroid_layer, -accel_x / 3);
	layer_vspeed(global.asteroid_layer, accel_y / 3);
	with (obj_asteroid){
		alt_spd_x = -other.accel_x;
		alt_spd_y = other.accel_y;
	}
}