/// @description Check hp every step. Update position using alt_speed and alt_direction

if (hp <= 0)
	instance_destroy();
	
image_angle += rotation;

//update position
x += alt_spd_x;
y += alt_spd_y;