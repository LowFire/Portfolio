/// @description Draw flames

draw_self();

if (keyboard_check(ord("W")) && canThrust){
	draw_sprite_ext(spr_flame, subFrame_index, x, y + 14, 1, 1, 0, c_white, 1);
	subFrame_index = (subFrame_index + 1) % sprite_get_number(spr_flame);
}

if (keyboard_check(ord("D")) && canThrust){
	draw_sprite_ext(spr_flame, subFrame_index, x - 8, y + 3, 1, 1, 270, c_white, 1);
	subFrame_index = (subFrame_index + 1) % sprite_get_number(spr_flame);
}

if (keyboard_check(ord("A")) && canThrust){
	draw_sprite_ext(spr_flame, subFrame_index, x + 8, y + 3, 1, 1, 90, c_white, 1);
	subFrame_index = (subFrame_index + 1) % sprite_get_number(spr_flame);
}