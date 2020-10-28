/// @description Wrap to other side or stop movement if leaving top.
// You can write your code in this editor

if (x > room_width + 16) //Wrap if lander leaves left or right boundaries
	x = -15;
if (x < -16)
	x = room_width + 15;
if (y - 14 < 0 ){ //Dont let the lander leave the top of the room;
	y =  16;
	vspeed = 0;
}
