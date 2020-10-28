/// @description Draw flames when thrusting
draw_self();
if (keyboard_check(ord("W")) && canThrust)
{
	draw_sprite_ext(spr_flames, flame_index, flame_pos_x, flame_pos_y, 1, 1, flame_direction, c_white, 1);
	flame_index++;
}

if (keyboard_check_released(ord("W")))
	flame_index = 0;