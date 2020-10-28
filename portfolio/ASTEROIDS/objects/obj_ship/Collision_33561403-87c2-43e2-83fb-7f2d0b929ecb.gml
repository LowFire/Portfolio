/// @description The ship has crashed when collided with asteroid
if (invincible != true && isCrashed == false){
	isCrashed = true;
	canShoot = false;
	canThrust = false;
	image_speed = 1;
	sprite_index = spr_explosion;
	layer_hspeed(global.asteroid_layer, 0);
	layer_vspeed(global.asteroid_layer, 0);
	with (obj_asteroid){
		alt_spd_x = 0;
		alt_spd_y = 0;
	}
}
