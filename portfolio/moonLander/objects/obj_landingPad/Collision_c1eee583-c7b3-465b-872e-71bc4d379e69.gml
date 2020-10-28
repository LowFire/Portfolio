/// @description Detect successful landing

if (!other.isCrashed){
	if (collision_point(x, y, other, false, false) && other.vspeed < 5 
	&& other.hspeed < 3)
		with (obj_gameController)
			success = true;
	else{
		other.isCrashed = true;
		with(obj_gameController)
			failure = true;
	}
}