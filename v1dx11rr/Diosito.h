#ifndef _DIOSITO_H_
#define _DIOSITO_H_

//////////////
// INCLUDES //
//////////////
#include <math.h>
#include "Camara.h"

////////////////////////////////////////////////////////////////////////////////
// Class name: CameraClass
////////////////////////////////////////////////////////////////////////////////
class Diosito
{
private:

	Camara* camara;
	float distancefromplayer = 20;
	float pitch = 20;

	void calculateanglearounplayer(float angy) {
		anglearoundplayer = angy;
	}

	float calculatehorizontaldistance() {
		return  distancefromplayer * cos((pitch * 180) / 3.1416);
	}

	float calculatevericaldistance() {
		return  distancefromplayer * sin((pitch * 180) / 3.1416);
	}

	void calculatecameraposition(float horizDistance, float verticDistance, float angy) {

		//float theta = angy + anglearoundplayer;
		float theta = angy;
		float offsetX = horizDistance * sin(((angy * 0.0003f) * 180) / 3.1416);
		float offsetZ = horizDistance * cos(((angy * 0.0003f) * 180) / 3.1416);

		posx = camara->posCam.x - offsetX;
		posz = camara->posCam.z - offsetZ;
		posy = camara->posCam.y + verticDistance;

		/*posx = camara->posCam.x + distancefromplayer * sin(angy * 0.0174532925f);
		posz = camara->posCam.z + distancefromplayer * cos(angy * 0.0174532925f);
		posy = camara->posCam.y + verticDistance;*/
	}

public:

	float anglearoundplayer = 0;
	float yaw = 0;


	Diosito(Camara& camara) {
		this->camara = &camara;
	}

	float posx, posy, posz = 0;

	void move(float angy, float angx) {
		calculateanglearounplayer(angy);
		float horizontaldistance = calculatehorizontaldistance();
		float verticaldistance = calculatevericaldistance();
		calculatecameraposition(horizontaldistance, verticaldistance, angy);
	}
};

#endif