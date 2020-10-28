/// @description draw headers
draw_set_font(ft_arial);
draw_set_halign(fa_center);
draw_set_valign(fa_top);
draw_set_color(c_white);

// Draw main menu
if (draw_menu == true){
	draw_text_ext_transformed(256, 50, "ASTEROIDS", 3, 300, 3, 3, 0);
}


//Draw lives count
if (draw_lives == true)
	draw_text(50, 0, "Lives: " + string(global.g_lives));
	
//draw level start header
if (draw_start == true)
	draw_text_ext_transformed(256, 256, "LEVEL: " + string(global.g_level), 3, 300, 2, 2, 0);
	
if (draw_mission_complete == true)
	draw_text_ext_transformed(256, 256, "MISSION   COMPLETE ", 3, 300, 2, 2, 0);
	
//draw game over headers
if (draw_game_over == true)
	draw_text_ext_transformed(256, 256, "GAME   OVER", 3, 300, 2, 2, 0);


//draw controls
if (draw_controls == true){
	draw_text_transformed(256, 50, "CONTROLS", 3, 3, 0);
	draw_text_transformed(256, 150, "W - Thrust ship forward.", 2, 2, 0);
	draw_text_transformed(256, 200, "A - Rotate ship left.", 2, 2, 0);
	draw_text_transformed(256, 250, "D - Rotate ship right.", 2, 2, 0);
	draw_text_transformed(256, 300, "Up - Fire weapon.", 2, 2, 0);
}