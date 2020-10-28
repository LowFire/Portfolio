/// @description Rotate right
direction -= 4;
image_angle = direction;
flame_direction = direction;
direction_rads = degtorad(direction);
flame_pos_x = x + (16 * sin(direction_rads));
flame_pos_y = y + (16 * cos(direction_rads));