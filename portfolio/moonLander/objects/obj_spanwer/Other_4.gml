/// @description Spawn instances
// You can write your code in this editor

//get a random seed
randomize();

//spawn obj_lander
lander_spawn_x = random_range(40, 760);
lander_spawn_y = 40
instance_create_layer(lander_spawn_x, lander_spawn_y, "instances", obj_lander);

//spawn obj_landingPad
landingPad_spawn_x = random_range(60, 740);
landingPad_spawn_y = 686;
instance_create_layer(landingPad_spawn_x, landingPad_spawn_y - 32, "instances", obj_landingPad);

//spawn asteroids
repeat (6){
	asteroid_spawn_x = random_range(10, 790);
	asteroid_spawn_y = random_range(250, 550);
	asteroid = floor(random(3));
	switch (asteroid){
		case 0:
		instance_create_layer(asteroid_spawn_x, asteroid_spawn_y, "asteroids", obj_smlAsteroid);
		break;
		case 1:
		instance_create_layer(asteroid_spawn_x, asteroid_spawn_y, "asteroids", obj_medAsteroid);
		break;
		case 2:
		instance_create_layer(asteroid_spawn_x, asteroid_spawn_y, "asteroids", obj_lrgAsteroid);
	};
}