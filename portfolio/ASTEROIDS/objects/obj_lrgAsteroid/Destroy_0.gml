/// @description Break apart into two small asteroids and one medium asteroid
repeat(2)
	instance_create_layer(x, y, "instances", obj_smlAsteroid);
instance_create_layer(x, y, "instances", obj_medAsteroid);