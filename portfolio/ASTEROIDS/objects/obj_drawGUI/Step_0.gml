/// @description Dynamically create buttons

if (create_menu_buttons == true){
	new_buttons = array_create(3);
	new_buttons[0] = instance_create_layer(512, 512, "instances", obj_button);
	new_buttons[1] = instance_create_layer(512, 576, "instances", obj_button);
	new_buttons[2] = instance_create_layer(512, 640, "instances", obj_button);
	
	//for start button
	new_buttons[0].image_xscale = 2;
	new_buttons[0].image_yscale = 2;
	new_buttons[0].script = scr_next_room;
	new_buttons[0].text = "Start";
	
	new_buttons[1].image_xscale = 2.2;
	new_buttons[1].image_yscale = 2;
	new_buttons[1].script = scr_controls;
	new_buttons[1].text = "Controls";
	
	new_buttons[2].image_xscale = 2;
	new_buttons[2].image_yscale = 2;
	new_buttons[2].script = scr_quit;
	new_buttons[2].text = "Quit";
	create_menu_buttons = false;
}

if (create_controlsBack_button == true){
	new_button = instance_create_layer(512, 800, "instances", obj_button);
	new_button.image_xscale = 2;
	new_button.image_yscale = 2;
	new_button.script = scr_back;
	new_button.text = "BACK";
	create_controlsBack_button = false;
}

if (create_gameOver_buttons == true){
	restart_button = instance_create_depth(512, 632, -100, obj_button)
	quit_button = instance_create_depth(512, 696, -100, obj_button)
	restart_button.script = scr_restart;
	restart_button.text = "Restart";
	restart_button.image_xscale = 2;
	restart_button.image_yscale = 2;
	quit_button.script = scr_quit;
	quit_button.text = "Quit";
	quit_button.image_xscale = 2;
	quit_button.image_yscale = 2;
	create_gameOver_buttons = false;
}