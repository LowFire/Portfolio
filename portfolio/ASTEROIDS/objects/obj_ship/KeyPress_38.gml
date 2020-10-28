/// @description Fire bullet
if (canShoot == true){
	direction_rads = degtorad(direction);
	bullet_pos_x = x - (15 * sin(direction_rads));
	bullet_pos_y = y - (15 * cos(direction_rads));
	new_bullet = instance_create_layer(bullet_pos_x, bullet_pos_y, "instances", obj_bullet);
	with (new_bullet)
	{
		direction = other.direction + 90;
		speed = 10;
	}
}