#ifndef SEGMENT2_H
#define SEGMENT2_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

extern void *puppyprint_font_lut[];
extern void *puppyprint_kerning_lut[][82];
extern const struct PPTextFont *const gPuppyPrintFontTable[];

extern u8 seg2_course_name_table[];
extern u8 seg2_act_name_table[];
extern Gfx dl_rgba16_text_begin[];
extern Gfx dl_rgba16_text_end[];
extern Gfx dl_ia_text_begin[];
extern Gfx dl_ia_text_end[];
extern Texture texture_radial_light[];
extern Texture texture_transition_star_half[];
extern Texture texture_transition_circle_half[];
extern Texture texture_transition_mario[];
extern Texture texture_transition_bowser_half[];
extern Texture texture_waterbox_water[];
extern Texture texture_waterbox_mist[];
extern Texture texture_waterbox_jrb_water[];
extern Texture texture_waterbox_unknown_water[];
extern Texture texture_waterbox_lava[];
extern Gfx dl_proj_mtx_fullscreen[];
extern Gfx dl_draw_quad_verts_0123[];
extern Gfx dl_screen_transition_end[];
extern Gfx dl_transition_draw_filled_region[];
extern Gfx dl_shadow_circle[];
extern Gfx dl_shadow_square[];
extern Gfx dl_shadow_4_verts[];
extern Gfx dl_shadow_end[];
extern Gfx dl_skybox_begin[];
extern Gfx dl_skybox_tile_tex_settings[];
extern Gfx dl_skybox_end[];
extern Gfx dl_waterbox_ia16_begin[];
extern Gfx dl_waterbox_rgba16_begin[];
extern Gfx dl_waterbox_end[];
extern Gfx dl_paintings_draw_ripples[];
extern Gfx dl_paintings_rippling_begin[];
extern Gfx dl_paintings_rippling_end[];
extern Gfx dl_paintings_env_mapped_begin[];
extern Gfx dl_paintings_env_mapped_end[];
extern s16 seg2_painting_triangle_mesh[];
extern s16 seg2_painting_mesh_neighbor_tris[];
extern Texture *main_hud_lut[58];
extern Gfx dl_hud_img_load_tex_block[];
extern Gfx dl_hud_img_begin[];
extern Gfx dl_hud_img_end[];
extern void *main_font_lut[];
extern Gfx dl_ia_text_tex_settings[];
extern Gfx dl_rgba16_load_tex_block[];
extern void *main_credits_font_lut[];
extern Texture *main_hud_camera_lut[6];
extern Gfx dl_shade_screen_begin[];
extern Gfx dl_shade_screen_end[];
extern Gfx dl_draw_text_bg_box[];
extern Gfx dl_draw_triangle[];
extern void *seg2_dialog_table[];
extern Gfx dl_billboard_num_0[];
extern Gfx dl_billboard_num_1[];
extern Gfx dl_billboard_num_2[];
extern Gfx dl_billboard_num_3[];
extern Gfx dl_billboard_num_4[];
extern Gfx dl_billboard_num_5[];
extern Gfx dl_billboard_num_6[];
extern Gfx dl_billboard_num_7[];
extern Gfx dl_billboard_num_8[];
extern Gfx dl_billboard_num_9[];
extern Gfx dl_draw_lightning_box[];
#ifdef DIALOG_INDICATOR
extern Gfx dl_billboard_num_A[];
extern Gfx dl_billboard_num_B[];
extern Gfx dl_billboard_num_C[];
extern Gfx dl_billboard_num_D[];
extern Gfx dl_billboard_num_E[];
extern Gfx dl_billboard_num_F[];
#endif

extern u8 render_hud_time_TIME_rgba16[];

extern u8 TIME_TIME_rgba16[];

extern u8 render_hud_time_2_TIME2_rgba16[];

extern u8 render_hud_mario_name_mariohud_rgba16[];

extern u8 render_hud_mario_life_icon_new_shadowmarioraw2_rgba32[];

extern u8 render_hud_mario_life_icon_new_shadowmarioraw2_rgba16[];

extern u8 render_hud_mario_name_2_mariohud0_rgba16[];

extern u8 render_rank_a_00_ARank00_rgba16[];

extern u8 render_rank_a_01_ARank01_rgba16[];

extern u8 render_rank_b_01_BRank01_rgba16[];

extern u8 render_rank_b_00_BRank00_rgba16[];

extern u8 render_rank_c_00_CRank00_rgba16[];

extern u8 render_rank_c_01_CRank01_rgba16[];

extern u8 render_rank_d_00_DRank00_rgba16[];

extern u8 render_rank_d_01_DRank01_rgba16[];

extern u8 render_s_rank_00_SRank00_rgba16[];

extern u8 render_s_rank_01_SRank01_rgba16[];

extern u8 render_hud_time_TIME__2__rgba16[];

#endif // SEGMENT2_H
