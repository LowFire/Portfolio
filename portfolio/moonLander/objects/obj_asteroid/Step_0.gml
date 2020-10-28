/// @description Rotate every step. Wrap if outside room.

image_angle += rotation;

//wrap if outside room. (Deosn't work properly with Outside Room event)
if (x > room_width + (sprite_width / 2))
	x = -(sprite_width / 2) + 1;
if (x < -(sprite_width / 2))
	x = room_width + (sprite_width / 2) - 1;
	
if (y > room_height + (sprite_height / 2))
	y = -(sprite_height / 2) + 1;
if (y < -(sprite_height / 2))
	y = room_height + (sprite_height / 2) - 1;