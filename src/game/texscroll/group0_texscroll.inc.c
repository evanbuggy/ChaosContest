#include "actors/group0.h"
#include "actors/title_bg/texscroll.inc.c"
#include "actors/electro_luigi/texscroll.inc.c"
#include "actors/starselectbg/texscroll.inc.c"
#include "actors/RingBox/texscroll.inc.c"
#include "actors/LifeBox/texscroll.inc.c"
void scroll_textures_group0() {
	scroll_actor_geo_title_bg();
		scroll_actor_geo_electro_luigi();
	scroll_actor_geo_starselectbg();
	scroll_actor_geo_RingBox();
	scroll_actor_geo_LifeBox();
}
