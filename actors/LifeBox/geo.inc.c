#include "src/game/envfx_snow.h"

const GeoLayout LifeBox_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, LifeBox_LifeBox_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, LifeBox_LifeBox_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
