/// @description Check fuel and crash

if (fuel <= 0 && canThrust == true)
{
	fuel = 0;
	canThrust = false;
}

if (isCrashed == true){
	canThrust = false;
	gravity = 0;
	other.sprite_index = spr_explosion;
	if (image_index > image_number - 1)
		instance_destroy();
}