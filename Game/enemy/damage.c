#include "damage.h"

double Damage_Calculation(struct Scene *scene,struct Enemy *enemy)
{
	double damage = 0;
	if(CollideBox_IsCollide(&scene->player.collideBox,&scene->player.transform,enemy->face.collideBoxes,&enemy->face.transform)){// shoot at face 2.0x

	}
	if(CollideBox_IsCollide(&scene->player.collideBox,&scene->player.transform,enemy->face.collideBoxes,&enemy->face.transform)){// shoot at body 1.0x

	}
	if(CollideBox_IsCollide(&scene->player.collideBox,&scene->player.transform,enemy->face.collideBoxes,&enemy->face.transform)){// shoot at leg 0.5x

	}
	return damage;
}
