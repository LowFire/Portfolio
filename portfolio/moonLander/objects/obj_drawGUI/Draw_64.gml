/// @description draw menues

draw_set_font(ft_arial);
draw_set_halign(fa_center);

if (room == room_first)
	draw_text_ext_transformed(400, 100, "Moon Lander", 10, 500, 3, 3, 0);
else 
	with (obj_lander)
		draw_text(50, 20, "Fuel: " + string(fuel));
		
if (drawSuccess){
	draw_text_ext_transformed(400, 100, "Mission Successful", 10, 500, 3, 3, 0);
	newButton = instance_create_layer(400, 200, "buttons", obj_button);
	newButton.text = "Replay";
	newButton.script = scr_reset;
}
if (drawFailure){
	draw_text_ext_transformed(400, 100, "Mission Failed", 10, 500, 3, 3, 0);
	newButton = instance_create_layer(400, 200, "buttons", obj_button);
	newButton.text = "Retry";
	newButton.script = scr_reset;
}