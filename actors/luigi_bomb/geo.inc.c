#include "src/game/envfx_snow.h"

const GeoLayout luigi_bomb_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, 0, 0, 0, luigi_bomb_luigi_bomb_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
