/// @description Check for success or failure
// You can write your code in this editor

if (success){
	with(obj_drawGUI)
		drawSuccess = true;
	with (obj_lander){
		canThrust = false;
		gravity = 0;
		vspeed = 0;
		hspeed = 0;
	}
	with (obj_asteroid)
		instance_destroy();
}
		
if (failure){
	with(obj_drawGUI)
		drawFailure = true;
	with (obj_lander){
		canThrust = false;
	}
}