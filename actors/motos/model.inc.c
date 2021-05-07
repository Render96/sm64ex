Lights1 motos_motos_blue_sphere_lights = gdSPDefLights1(
	0x11, 0x2, 0x38,
	0x23, 0x4, 0x70, 0x28, 0x28, 0x28);

Lights1 motos_motos_yellow_sphere_lights = gdSPDefLights1(
	0x7F, 0x63, 0x0,
	0xFE, 0xC7, 0x0, 0x28, 0x28, 0x28);

Lights1 motos_motos_bolts_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 motos_motos_face_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx motos_motos_bolts_rgba32_aligner[] = {gsSPEndDisplayList()};
u8 motos_motos_bolts_rgba32[] = "actors/motos/motos_bolts.rgba32";

Gfx motos_motos_face_rgba32_aligner[] = {gsSPEndDisplayList()};
u8 motos_motos_face_rgba32[] = "actors/motos/motos_face.rgba32";

Vtx motos_pelvis_mesh_vtx_0[43] = {
	{{{0, 129, -120},0, {752, 240},{0x0, 0x58, 0xA4, 0xFF}}},
	{{{0, 178, 0},0, {688, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{85, 129, -85},0, {624, 240},{0x41, 0x58, 0xBF, 0xFF}}},
	{{{0, -2, -186},0, {752, 496},{0x0, 0x2, 0x81, 0xFF}}},
	{{{131, -2, -131},0, {624, 496},{0x5A, 0x2, 0xA6, 0xFF}}},
	{{{120, 129, 0},0, {496, 240},{0x5C, 0x58, 0x0, 0xFF}}},
	{{{0, 178, 0},0, {560, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{186, -2, 0},0, {496, 496},{0x7F, 0x2, 0x0, 0xFF}}},
	{{{85, 129, 85},0, {368, 240},{0x41, 0x58, 0x41, 0xFF}}},
	{{{0, 178, 0},0, {432, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{131, -2, 131},0, {368, 496},{0x5A, 0x2, 0x5A, 0xFF}}},
	{{{0, 129, 120},0, {240, 240},{0x0, 0x58, 0x5C, 0xFF}}},
	{{{0, 178, 0},0, {304, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, -2, 186},0, {240, 496},{0x0, 0x2, 0x7F, 0xFF}}},
	{{{-85, 129, 85},0, {112, 240},{0xBF, 0x58, 0x41, 0xFF}}},
	{{{0, 178, 0},0, {176, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-131, -2, 131},0, {112, 496},{0xA6, 0x2, 0x5A, 0xFF}}},
	{{{-120, 129, 0},0, {-16, 240},{0xA4, 0x58, 0x0, 0xFF}}},
	{{{0, 178, 0},0, {48, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-186, -2, 0},0, {-16, 496},{0x81, 0x2, 0x0, 0xFF}}},
	{{{-93, -120, 93},0, {112, 752},{0xBE, 0xAA, 0x42, 0xFF}}},
	{{{-131, -120, 0},0, {-16, 752},{0xA3, 0xAA, 0x0, 0xFF}}},
	{{{0, -176, 0},0, {48, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{0, -120, 131},0, {240, 752},{0x0, 0xAA, 0x5D, 0xFF}}},
	{{{93, -120, 93},0, {368, 752},{0x42, 0xAA, 0x42, 0xFF}}},
	{{{0, -176, 0},0, {304, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{131, -120, 0},0, {496, 752},{0x5D, 0xAA, 0x0, 0xFF}}},
	{{{0, -176, 0},0, {432, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{93, -120, -93},0, {624, 752},{0x42, 0xAA, 0xBE, 0xFF}}},
	{{{0, -176, 0},0, {560, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{0, -120, -131},0, {752, 752},{0x0, 0xAA, 0xA3, 0xFF}}},
	{{{0, -176, 0},0, {688, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-93, -120, -93},0, {880, 752},{0xBE, 0xAA, 0xBE, 0xFF}}},
	{{{0, -176, 0},0, {816, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-131, -2, -131},0, {880, 496},{0xA6, 0x2, 0xA6, 0xFF}}},
	{{{-131, -120, 0},0, {1008, 752},{0xA3, 0xAA, 0x0, 0xFF}}},
	{{{0, -176, 0},0, {944, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-186, -2, 0},0, {1008, 496},{0x81, 0x2, 0x0, 0xFF}}},
	{{{-85, 129, -85},0, {880, 240},{0xBF, 0x58, 0xBF, 0xFF}}},
	{{{-120, 129, 0},0, {1008, 240},{0xA4, 0x58, 0x0, 0xFF}}},
	{{{0, 178, 0},0, {944, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 178, 0},0, {816, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, -176, 0},0, {176, 1008},{0x0, 0x81, 0x0, 0xFF}}},
};

Gfx motos_pelvis_mesh_tri_0[] = {
	gsSPVertex(motos_pelvis_mesh_vtx_0 + 0, 43, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
	gsSP2Triangles(2, 6, 5, 0, 4, 5, 7, 0),
	gsSP2Triangles(7, 5, 8, 0, 5, 9, 8, 0),
	gsSP2Triangles(7, 8, 10, 0, 10, 8, 11, 0),
	gsSP2Triangles(8, 12, 11, 0, 10, 11, 13, 0),
	gsSP2Triangles(13, 11, 14, 0, 11, 15, 14, 0),
	gsSP2Triangles(13, 14, 16, 0, 16, 14, 17, 0),
	gsSP2Triangles(14, 18, 17, 0, 16, 17, 19, 0),
	gsSP2Triangles(20, 16, 19, 0, 20, 19, 21, 0),
	gsSP2Triangles(22, 20, 21, 0, 23, 16, 20, 0),
	gsSP2Triangles(23, 13, 16, 0, 24, 13, 23, 0),
	gsSP2Triangles(25, 24, 23, 0, 24, 10, 13, 0),
	gsSP2Triangles(26, 10, 24, 0, 27, 26, 24, 0),
	gsSP2Triangles(26, 7, 10, 0, 28, 7, 26, 0),
	gsSP2Triangles(29, 28, 26, 0, 28, 4, 7, 0),
	gsSP2Triangles(30, 4, 28, 0, 31, 30, 28, 0),
	gsSP2Triangles(30, 3, 4, 0, 32, 3, 30, 0),
	gsSP2Triangles(33, 32, 30, 0, 32, 34, 3, 0),
	gsSP2Triangles(35, 34, 32, 0, 36, 35, 32, 0),
	gsSP2Triangles(35, 37, 34, 0, 37, 38, 34, 0),
	gsSP2Triangles(37, 39, 38, 0, 39, 40, 38, 0),
	gsSP2Triangles(34, 38, 0, 0, 38, 41, 0, 0),
	gsSP2Triangles(34, 0, 3, 0, 42, 23, 20, 0),
	gsSPEndDisplayList(),
};

Vtx motos_leg_L_mesh_vtx_0[28] = {
	{{{-42, -33, -1},0, {598, 240},{0xA1, 0xAC, 0x0, 0xFF}}},
	{{{-17, -33, -37},0, {394, 240},{0xE2, 0xAC, 0xA6, 0xFF}}},
	{{{-5, -48, -1},0, {496, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-58, 1, -1},0, {598, 496},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-21, 1, 51},0, {803, 496},{0xD8, 0x0, 0x79, 0xFF}}},
	{{{-17, -33, 36},0, {803, 240},{0xE2, 0xAC, 0x5A, 0xFF}}},
	{{{-5, -48, -1},0, {701, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{37, 1, 31},0, {1008, 496},{0x67, 0x0, 0x4A, 0xFF}}},
	{{{25, 35, 22},0, {1008, 752},{0x4D, 0x54, 0x37, 0xFF}}},
	{{{-17, 35, 36},0, {803, 752},{0xE2, 0x54, 0x5A, 0xFF}}},
	{{{-5, 49, -1},0, {906, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-42, 35, -1},0, {598, 752},{0xA1, 0x54, 0x0, 0xFF}}},
	{{{-5, 49, -1},0, {701, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-21, 1, -53},0, {394, 496},{0xD8, 0x0, 0x87, 0xFF}}},
	{{{-17, 35, -37},0, {394, 752},{0xE2, 0x54, 0xA6, 0xFF}}},
	{{{-5, 49, -1},0, {496, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{37, 1, -33},0, {189, 496},{0x67, 0x0, 0xB6, 0xFF}}},
	{{{25, 35, -23},0, {189, 752},{0x4D, 0x54, 0xC9, 0xFF}}},
	{{{-5, 49, -1},0, {291, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{37, 1, 31},0, {-16, 496},{0x67, 0x0, 0x4A, 0xFF}}},
	{{{25, 35, 22},0, {-16, 752},{0x4D, 0x54, 0x37, 0xFF}}},
	{{{-5, 49, -1},0, {86, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{25, -33, 22},0, {-16, 240},{0x4D, 0xAC, 0x37, 0xFF}}},
	{{{25, -33, -23},0, {189, 240},{0x4D, 0xAC, 0xC9, 0xFF}}},
	{{{-5, -48, -1},0, {86, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-5, -48, -1},0, {291, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{25, -33, 22},0, {1008, 240},{0x4D, 0xAC, 0x37, 0xFF}}},
	{{{-5, -48, -1},0, {906, -16},{0x0, 0x81, 0x0, 0xFF}}},
};

Gfx motos_leg_L_mesh_tri_0[] = {
	gsSPVertex(motos_leg_L_mesh_vtx_0 + 0, 28, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 0, 5, 0),
	gsSP2Triangles(5, 0, 6, 0, 7, 4, 5, 0),
	gsSP2Triangles(8, 4, 7, 0, 8, 9, 4, 0),
	gsSP2Triangles(10, 9, 8, 0, 9, 3, 4, 0),
	gsSP2Triangles(9, 11, 3, 0, 12, 11, 9, 0),
	gsSP2Triangles(11, 13, 3, 0, 11, 14, 13, 0),
	gsSP2Triangles(15, 14, 11, 0, 14, 16, 13, 0),
	gsSP2Triangles(14, 17, 16, 0, 18, 17, 14, 0),
	gsSP2Triangles(17, 19, 16, 0, 17, 20, 19, 0),
	gsSP2Triangles(21, 20, 17, 0, 16, 19, 22, 0),
	gsSP2Triangles(16, 22, 23, 0, 23, 22, 24, 0),
	gsSP2Triangles(13, 16, 23, 0, 13, 23, 1, 0),
	gsSP2Triangles(1, 23, 25, 0, 3, 13, 1, 0),
	gsSP2Triangles(26, 5, 27, 0, 7, 5, 26, 0),
	gsSPEndDisplayList(),
};

Vtx motos_foot_L_mesh_vtx_0[32] = {
	{{{-46, -2, -41},0, {524, 382},{0xBF, 0xAA, 0xBC, 0xFF}}},
	{{{-144, 40, -1},0, {534, 361},{0xBF, 0xAA, 0xBC, 0xFF}}},
	{{{-77, 38, -63},0, {536, 363},{0xBF, 0xAA, 0xBC, 0xFF}}},
	{{{-144, 40, -1},0, {534, 361},{0x3, 0x7F, 0x0, 0xFF}}},
	{{{-77, 38, 62},0, {535, 359},{0x3, 0x7F, 0x0, 0xFF}}},
	{{{-77, 38, -63},0, {536, 363},{0x3, 0x7F, 0x0, 0xFF}}},
	{{{-46, -2, -41},0, {524, 382},{0xCE, 0x8B, 0x0, 0xFF}}},
	{{{-46, -2, 40},0, {524, 348},{0xCE, 0x8B, 0x0, 0xFF}}},
	{{{-144, 40, -1},0, {534, 361},{0xCE, 0x8B, 0x0, 0xFF}}},
	{{{-77, 38, 62},0, {535, 359},{0xBF, 0xAA, 0x44, 0xFF}}},
	{{{-144, 40, -1},0, {534, 361},{0xBF, 0xAA, 0x44, 0xFF}}},
	{{{-46, -2, 40},0, {524, 348},{0xBF, 0xAA, 0x44, 0xFF}}},
	{{{-77, 38, -63},0, {536, 363},{0x0, 0xC4, 0x90, 0xFF}}},
	{{{50, 38, -63},0, {541, 362},{0x0, 0xC4, 0x90, 0xFF}}},
	{{{38, -2, -41},0, {554, 368},{0x0, 0xC4, 0x90, 0xFF}}},
	{{{-46, -2, -41},0, {524, 382},{0x0, 0xC4, 0x90, 0xFF}}},
	{{{50, 38, -63},0, {541, 362},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-77, 38, -63},0, {536, 363},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-77, 38, 62},0, {535, 359},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{50, 38, 62},0, {539, 358},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{38, -2, 40},0, {-16, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-46, -2, 40},0, {-16, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-46, -2, -41},0, {1008, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{38, -2, -41},0, {1008, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{50, 38, -63},0, {541, 362},{0x7A, 0xDB, 0x0, 0xFF}}},
	{{{50, 38, 62},0, {539, 358},{0x7A, 0xDB, 0x0, 0xFF}}},
	{{{38, -2, 40},0, {544, 353},{0x7A, 0xDB, 0x0, 0xFF}}},
	{{{38, -2, -41},0, {554, 368},{0x7A, 0xDB, 0x0, 0xFF}}},
	{{{50, 38, 62},0, {539, 358},{0x0, 0xC4, 0x70, 0xFF}}},
	{{{-77, 38, 62},0, {535, 359},{0x0, 0xC4, 0x70, 0xFF}}},
	{{{-46, -2, 40},0, {524, 348},{0x0, 0xC4, 0x70, 0xFF}}},
	{{{38, -2, 40},0, {544, 353},{0x0, 0xC4, 0x70, 0xFF}}},
};

Gfx motos_foot_L_mesh_tri_0[] = {
	gsSPVertex(motos_foot_L_mesh_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPEndDisplayList(),
};

Vtx motos_leg_R_mesh_vtx_0[28] = {
	{{{42, -33, -1},0, {598, 240},{0x5F, 0xAC, 0x0, 0xFF}}},
	{{{5, -48, -1},0, {496, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{17, -33, -37},0, {394, 240},{0x1E, 0xAC, 0xA6, 0xFF}}},
	{{{58, 1, -1},0, {598, 496},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{21, 1, -53},0, {394, 496},{0x28, 0x0, 0x87, 0xFF}}},
	{{{-25, -33, -23},0, {189, 240},{0xB3, 0xAC, 0xC9, 0xFF}}},
	{{{5, -48, -1},0, {291, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-37, 1, -33},0, {189, 496},{0x99, 0x0, 0xB6, 0xFF}}},
	{{{-25, -33, 22},0, {-16, 240},{0xB3, 0xAC, 0x37, 0xFF}}},
	{{{5, -48, -1},0, {86, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-37, 1, 31},0, {-16, 496},{0x99, 0x0, 0x4A, 0xFF}}},
	{{{-25, 35, -23},0, {189, 752},{0xB3, 0x54, 0xC9, 0xFF}}},
	{{{-25, 35, 22},0, {-16, 752},{0xB3, 0x54, 0x37, 0xFF}}},
	{{{5, 49, -1},0, {86, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{17, 35, -37},0, {394, 752},{0x1E, 0x54, 0xA6, 0xFF}}},
	{{{42, 35, -1},0, {598, 752},{0x5F, 0x54, 0x0, 0xFF}}},
	{{{5, 49, -1},0, {496, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{17, 35, 36},0, {803, 752},{0x1E, 0x54, 0x5A, 0xFF}}},
	{{{5, 49, -1},0, {701, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{21, 1, 51},0, {803, 496},{0x28, 0x0, 0x79, 0xFF}}},
	{{{-25, 35, 22},0, {1008, 752},{0xB3, 0x54, 0x37, 0xFF}}},
	{{{5, 49, -1},0, {906, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-37, 1, 31},0, {1008, 496},{0x99, 0x0, 0x4A, 0xFF}}},
	{{{17, -33, 36},0, {803, 240},{0x1E, 0xAC, 0x5A, 0xFF}}},
	{{{-25, -33, 22},0, {1008, 240},{0xB3, 0xAC, 0x37, 0xFF}}},
	{{{5, -48, -1},0, {906, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{5, -48, -1},0, {701, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{5, 49, -1},0, {291, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx motos_leg_R_mesh_tri_0[] = {
	gsSPVertex(motos_leg_R_mesh_vtx_0 + 0, 28, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
	gsSP2Triangles(2, 6, 5, 0, 4, 5, 7, 0),
	gsSP2Triangles(7, 5, 8, 0, 5, 9, 8, 0),
	gsSP2Triangles(7, 8, 10, 0, 11, 7, 10, 0),
	gsSP2Triangles(11, 10, 12, 0, 13, 11, 12, 0),
	gsSP2Triangles(14, 7, 11, 0, 14, 4, 7, 0),
	gsSP2Triangles(15, 4, 14, 0, 16, 15, 14, 0),
	gsSP2Triangles(15, 3, 4, 0, 17, 3, 15, 0),
	gsSP2Triangles(18, 17, 15, 0, 17, 19, 3, 0),
	gsSP2Triangles(20, 19, 17, 0, 21, 20, 17, 0),
	gsSP2Triangles(20, 22, 19, 0, 22, 23, 19, 0),
	gsSP2Triangles(22, 24, 23, 0, 24, 25, 23, 0),
	gsSP2Triangles(19, 23, 0, 0, 23, 26, 0, 0),
	gsSP2Triangles(19, 0, 3, 0, 27, 14, 11, 0),
	gsSPEndDisplayList(),
};

Vtx motos_foot_R_mesh_vtx_0[32] = {
	{{{46, -2, -41},0, {524, 382},{0x41, 0xAA, 0xBC, 0xFF}}},
	{{{77, 38, -63},0, {536, 363},{0x41, 0xAA, 0xBC, 0xFF}}},
	{{{144, 40, -1},0, {534, 361},{0x41, 0xAA, 0xBC, 0xFF}}},
	{{{144, 40, -1},0, {534, 361},{0xFD, 0x7F, 0x0, 0xFF}}},
	{{{77, 38, -63},0, {536, 363},{0xFD, 0x7F, 0x0, 0xFF}}},
	{{{77, 38, 62},0, {535, 359},{0xFD, 0x7F, 0x0, 0xFF}}},
	{{{46, -2, -41},0, {524, 382},{0x32, 0x8B, 0x0, 0xFF}}},
	{{{144, 40, -1},0, {534, 361},{0x32, 0x8B, 0x0, 0xFF}}},
	{{{46, -2, 40},0, {524, 348},{0x32, 0x8B, 0x0, 0xFF}}},
	{{{77, 38, 62},0, {535, 359},{0x41, 0xAA, 0x44, 0xFF}}},
	{{{46, -2, 40},0, {524, 348},{0x41, 0xAA, 0x44, 0xFF}}},
	{{{144, 40, -1},0, {534, 361},{0x41, 0xAA, 0x44, 0xFF}}},
	{{{77, 38, -63},0, {536, 363},{0x0, 0xC4, 0x90, 0xFF}}},
	{{{46, -2, -41},0, {524, 382},{0x0, 0xC4, 0x90, 0xFF}}},
	{{{-38, -2, -41},0, {554, 368},{0x0, 0xC4, 0x90, 0xFF}}},
	{{{-50, 38, -63},0, {541, 362},{0x0, 0xC4, 0x90, 0xFF}}},
	{{{-50, 38, -63},0, {541, 362},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{77, 38, 62},0, {535, 359},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{77, 38, -63},0, {536, 363},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-50, 38, 62},0, {539, 358},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-38, -2, 40},0, {-16, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-38, -2, -41},0, {1008, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{46, -2, -41},0, {1008, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{46, -2, 40},0, {-16, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-50, 38, -63},0, {541, 362},{0x86, 0xDB, 0x0, 0xFF}}},
	{{{-38, -2, -41},0, {554, 368},{0x86, 0xDB, 0x0, 0xFF}}},
	{{{-38, -2, 40},0, {544, 353},{0x86, 0xDB, 0x0, 0xFF}}},
	{{{-50, 38, 62},0, {539, 358},{0x86, 0xDB, 0x0, 0xFF}}},
	{{{-50, 38, 62},0, {539, 358},{0x0, 0xC4, 0x70, 0xFF}}},
	{{{46, -2, 40},0, {524, 348},{0x0, 0xC4, 0x70, 0xFF}}},
	{{{77, 38, 62},0, {535, 359},{0x0, 0xC4, 0x70, 0xFF}}},
	{{{-38, -2, 40},0, {544, 353},{0x0, 0xC4, 0x70, 0xFF}}},
};

Gfx motos_foot_R_mesh_tri_0[] = {
	gsSPVertex(motos_foot_R_mesh_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 31, 29, 0),
	gsSPEndDisplayList(),
};

Vtx motos_arm_L_mesh_vtx_0[33] = {
	{{{-17, -29, -34},0, {667, 240},{0xCF, 0xB1, 0xAA, 0xFF}}},
	{{{-35, 3, -34},0, {496, 240},{0xA1, 0x1, 0xAC, 0xFF}}},
	{{{0, 3, -49},0, {581, -16},{0x0, 0x3, 0x81, 0xFF}}},
	{{{-24, -46, 1},0, {667, 496},{0xC1, 0x92, 0xFF, 0xFF}}},
	{{{27, -46, 1},0, {837, 496},{0x41, 0x93, 0xFD, 0xFF}}},
	{{{19, -29, -34},0, {837, 240},{0x32, 0xB2, 0xA9, 0xFF}}},
	{{{0, 3, -49},0, {752, -16},{0x0, 0x3, 0x81, 0xFF}}},
	{{{51, 3, 1},0, {1008, 496},{0x7F, 0x7, 0xFE, 0xFF}}},
	{{{36, 3, 37},0, {1008, 752},{0x60, 0x8, 0x52, 0xFF}}},
	{{{23, -31, 37},0, {837, 752},{0x37, 0xB3, 0x54, 0xFF}}},
	{{{0, 3, 51},0, {923, 1008},{0xFF, 0x4, 0x7F, 0xFF}}},
	{{{-13, -31, 37},0, {667, 752},{0xD4, 0xAE, 0x57, 0xFF}}},
	{{{0, 3, 51},0, {752, 1008},{0xFF, 0x4, 0x7F, 0xFF}}},
	{{{-50, 3, 1},0, {496, 496},{0x81, 0x1, 0x1, 0xFF}}},
	{{{-35, 3, 37},0, {496, 752},{0xA1, 0x0, 0x54, 0xFF}}},
	{{{0, 3, 51},0, {581, 1008},{0xFF, 0x4, 0x7F, 0xFF}}},
	{{{-26, 46, 0},0, {325, 496},{0xC1, 0x6E, 0xFE, 0xFF}}},
	{{{-18, 30, 37},0, {325, 752},{0xD0, 0x52, 0x54, 0xFF}}},
	{{{0, 3, 51},0, {411, 1008},{0xFF, 0x4, 0x7F, 0xFF}}},
	{{{24, 46, 0},0, {155, 496},{0x3C, 0x70, 0xFE, 0xFF}}},
	{{{17, 30, 37},0, {155, 752},{0x2F, 0x54, 0x54, 0xFF}}},
	{{{0, 3, 51},0, {240, 1008},{0xFF, 0x4, 0x7F, 0xFF}}},
	{{{51, 3, 1},0, {-16, 496},{0x7F, 0x7, 0xFE, 0xFF}}},
	{{{36, 3, 37},0, {-16, 752},{0x60, 0x8, 0x52, 0xFF}}},
	{{{0, 3, 51},0, {69, 1008},{0xFF, 0x4, 0x7F, 0xFF}}},
	{{{36, 3, -34},0, {-16, 240},{0x5F, 0x5, 0xAC, 0xFF}}},
	{{{17, 30, -34},0, {155, 240},{0x2E, 0x52, 0xAB, 0xFF}}},
	{{{0, 3, -49},0, {69, -16},{0x0, 0x3, 0x81, 0xFF}}},
	{{{-18, 30, -34},0, {325, 240},{0xCF, 0x50, 0xAB, 0xFF}}},
	{{{0, 3, -49},0, {240, -16},{0x0, 0x3, 0x81, 0xFF}}},
	{{{0, 3, -49},0, {411, -16},{0x0, 0x3, 0x81, 0xFF}}},
	{{{36, 3, -34},0, {1008, 240},{0x5F, 0x5, 0xAC, 0xFF}}},
	{{{0, 3, -49},0, {923, -16},{0x0, 0x3, 0x81, 0xFF}}},
};

Gfx motos_arm_L_mesh_tri_0[] = {
	gsSPVertex(motos_arm_L_mesh_vtx_0 + 0, 33, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 0, 5, 0),
	gsSP2Triangles(5, 0, 6, 0, 7, 4, 5, 0),
	gsSP2Triangles(8, 4, 7, 0, 8, 9, 4, 0),
	gsSP2Triangles(10, 9, 8, 0, 9, 3, 4, 0),
	gsSP2Triangles(9, 11, 3, 0, 12, 11, 9, 0),
	gsSP2Triangles(11, 13, 3, 0, 11, 14, 13, 0),
	gsSP2Triangles(15, 14, 11, 0, 14, 16, 13, 0),
	gsSP2Triangles(14, 17, 16, 0, 18, 17, 14, 0),
	gsSP2Triangles(17, 19, 16, 0, 17, 20, 19, 0),
	gsSP2Triangles(21, 20, 17, 0, 20, 22, 19, 0),
	gsSP2Triangles(20, 23, 22, 0, 24, 23, 20, 0),
	gsSP2Triangles(19, 22, 25, 0, 19, 25, 26, 0),
	gsSP2Triangles(26, 25, 27, 0, 16, 19, 26, 0),
	gsSP2Triangles(16, 26, 28, 0, 28, 26, 29, 0),
	gsSP2Triangles(13, 16, 28, 0, 13, 28, 1, 0),
	gsSP2Triangles(1, 28, 30, 0, 3, 13, 1, 0),
	gsSP2Triangles(31, 5, 32, 0, 7, 5, 31, 0),
	gsSPEndDisplayList(),
};

Vtx motos_hand_bottom_L_mesh_vtx_0[9] = {
	{{{0, 31, 45},0, {554, 613},{0x9A, 0xD, 0x4A, 0xFF}}},
	{{{0, 146, 26},0, {536, 641},{0x9A, 0xD, 0x4A, 0xFF}}},
	{{{-31, 42, 0},0, {502, 635},{0x9A, 0xD, 0x4A, 0xFF}}},
	{{{32, 42, 0},0, {554, 670},{0x66, 0xD, 0x4A, 0xFF}}},
	{{{0, 146, 26},0, {536, 641},{0x66, 0xD, 0x4A, 0xFF}}},
	{{{0, 31, 45},0, {554, 613},{0x66, 0xD, 0x4A, 0xFF}}},
	{{{-31, 42, 0},0, {502, 635},{0x0, 0x1F, 0x85, 0xFF}}},
	{{{0, 146, 26},0, {536, 641},{0x0, 0x1F, 0x85, 0xFF}}},
	{{{32, 42, 0},0, {554, 670},{0x0, 0x1F, 0x85, 0xFF}}},
};

Gfx motos_hand_bottom_L_mesh_tri_0[] = {
	gsSPVertex(motos_hand_bottom_L_mesh_vtx_0 + 0, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSPEndDisplayList(),
};

Vtx motos_hand_top_L_mesh_vtx_0[9] = {
	{{{0, 25, -47},0, {606, 613},{0x9B, 0x3, 0xB4, 0xFF}}},
	{{{-31, 45, -4},0, {606, 670},{0x9B, 0x3, 0xB4, 0xFF}}},
	{{{0, 142, -42},0, {588, 641},{0x9B, 0x3, 0xB4, 0xFF}}},
	{{{32, 45, -4},0, {554, 635},{0x65, 0x3, 0xB4, 0xFF}}},
	{{{0, 25, -47},0, {606, 613},{0x65, 0x3, 0xB4, 0xFF}}},
	{{{0, 142, -42},0, {588, 641},{0x65, 0x3, 0xB4, 0xFF}}},
	{{{-31, 45, -4},0, {606, 670},{0x0, 0x2F, 0x76, 0xFF}}},
	{{{32, 45, -4},0, {554, 635},{0x0, 0x2F, 0x76, 0xFF}}},
	{{{0, 142, -42},0, {588, 641},{0x0, 0x2F, 0x76, 0xFF}}},
};

Gfx motos_hand_top_L_mesh_tri_0[] = {
	gsSPVertex(motos_hand_top_L_mesh_vtx_0 + 0, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSPEndDisplayList(),
};

Vtx motos_arm_R_mesh_vtx_0[33] = {
	{{{17, -29, -34},0, {667, 240},{0x31, 0xB1, 0xAA, 0xFF}}},
	{{{0, 3, -49},0, {581, -16},{0x0, 0x3, 0x81, 0xFF}}},
	{{{35, 3, -34},0, {496, 240},{0x5F, 0x1, 0xAC, 0xFF}}},
	{{{24, -46, 1},0, {667, 496},{0x3F, 0x92, 0xFF, 0xFF}}},
	{{{50, 3, 1},0, {496, 496},{0x7F, 0x1, 0x1, 0xFF}}},
	{{{18, 30, -34},0, {325, 240},{0x31, 0x50, 0xAB, 0xFF}}},
	{{{0, 3, -49},0, {411, -16},{0x0, 0x3, 0x81, 0xFF}}},
	{{{26, 46, 0},0, {325, 496},{0x3F, 0x6E, 0xFE, 0xFF}}},
	{{{-17, 30, -34},0, {155, 240},{0xD2, 0x52, 0xAB, 0xFF}}},
	{{{0, 3, -49},0, {240, -16},{0x0, 0x3, 0x81, 0xFF}}},
	{{{-24, 46, 0},0, {155, 496},{0xC4, 0x70, 0xFE, 0xFF}}},
	{{{-36, 3, -34},0, {-16, 240},{0xA1, 0x5, 0xAC, 0xFF}}},
	{{{0, 3, -49},0, {69, -16},{0x0, 0x3, 0x81, 0xFF}}},
	{{{-51, 3, 1},0, {-16, 496},{0x81, 0x7, 0xFE, 0xFF}}},
	{{{-17, 30, 37},0, {155, 752},{0xD1, 0x54, 0x54, 0xFF}}},
	{{{-36, 3, 37},0, {-16, 752},{0xA0, 0x8, 0x52, 0xFF}}},
	{{{0, 3, 51},0, {69, 1008},{0x1, 0x4, 0x7F, 0xFF}}},
	{{{18, 30, 37},0, {325, 752},{0x30, 0x52, 0x54, 0xFF}}},
	{{{35, 3, 37},0, {496, 752},{0x5F, 0x0, 0x54, 0xFF}}},
	{{{0, 3, 51},0, {411, 1008},{0x1, 0x4, 0x7F, 0xFF}}},
	{{{13, -31, 37},0, {667, 752},{0x2C, 0xAE, 0x57, 0xFF}}},
	{{{0, 3, 51},0, {581, 1008},{0x1, 0x4, 0x7F, 0xFF}}},
	{{{-23, -31, 37},0, {837, 752},{0xC9, 0xB3, 0x54, 0xFF}}},
	{{{0, 3, 51},0, {752, 1008},{0x1, 0x4, 0x7F, 0xFF}}},
	{{{-27, -46, 1},0, {837, 496},{0xBF, 0x93, 0xFD, 0xFF}}},
	{{{-36, 3, 37},0, {1008, 752},{0xA0, 0x8, 0x52, 0xFF}}},
	{{{0, 3, 51},0, {923, 1008},{0x1, 0x4, 0x7F, 0xFF}}},
	{{{-51, 3, 1},0, {1008, 496},{0x81, 0x7, 0xFE, 0xFF}}},
	{{{-19, -29, -34},0, {837, 240},{0xCE, 0xB2, 0xA9, 0xFF}}},
	{{{-36, 3, -34},0, {1008, 240},{0xA1, 0x5, 0xAC, 0xFF}}},
	{{{0, 3, -49},0, {923, -16},{0x0, 0x3, 0x81, 0xFF}}},
	{{{0, 3, -49},0, {752, -16},{0x0, 0x3, 0x81, 0xFF}}},
	{{{0, 3, 51},0, {240, 1008},{0x1, 0x4, 0x7F, 0xFF}}},
};

Gfx motos_arm_R_mesh_tri_0[] = {
	gsSPVertex(motos_arm_R_mesh_vtx_0 + 0, 33, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
	gsSP2Triangles(2, 6, 5, 0, 4, 5, 7, 0),
	gsSP2Triangles(7, 5, 8, 0, 5, 9, 8, 0),
	gsSP2Triangles(7, 8, 10, 0, 10, 8, 11, 0),
	gsSP2Triangles(8, 12, 11, 0, 10, 11, 13, 0),
	gsSP2Triangles(14, 10, 13, 0, 14, 13, 15, 0),
	gsSP2Triangles(16, 14, 15, 0, 17, 10, 14, 0),
	gsSP2Triangles(17, 7, 10, 0, 18, 7, 17, 0),
	gsSP2Triangles(19, 18, 17, 0, 18, 4, 7, 0),
	gsSP2Triangles(20, 4, 18, 0, 21, 20, 18, 0),
	gsSP2Triangles(20, 3, 4, 0, 22, 3, 20, 0),
	gsSP2Triangles(23, 22, 20, 0, 22, 24, 3, 0),
	gsSP2Triangles(25, 24, 22, 0, 26, 25, 22, 0),
	gsSP2Triangles(25, 27, 24, 0, 27, 28, 24, 0),
	gsSP2Triangles(27, 29, 28, 0, 29, 30, 28, 0),
	gsSP2Triangles(24, 28, 0, 0, 28, 31, 0, 0),
	gsSP2Triangles(24, 0, 3, 0, 32, 17, 14, 0),
	gsSPEndDisplayList(),
};

Vtx motos_hand_bottom_R_mesh_vtx_0[9] = {
	{{{0, 31, 45},0, {554, 613},{0x66, 0xD, 0x4A, 0xFF}}},
	{{{31, 42, 0},0, {502, 635},{0x66, 0xD, 0x4A, 0xFF}}},
	{{{0, 146, 26},0, {536, 641},{0x66, 0xD, 0x4A, 0xFF}}},
	{{{-32, 42, 0},0, {554, 670},{0x9A, 0xD, 0x4A, 0xFF}}},
	{{{0, 31, 45},0, {554, 613},{0x9A, 0xD, 0x4A, 0xFF}}},
	{{{0, 146, 26},0, {536, 641},{0x9A, 0xD, 0x4A, 0xFF}}},
	{{{31, 42, 0},0, {502, 635},{0x0, 0x1F, 0x85, 0xFF}}},
	{{{-32, 42, 0},0, {554, 670},{0x0, 0x1F, 0x85, 0xFF}}},
	{{{0, 146, 26},0, {536, 641},{0x0, 0x1F, 0x85, 0xFF}}},
};

Gfx motos_hand_bottom_R_mesh_tri_0[] = {
	gsSPVertex(motos_hand_bottom_R_mesh_vtx_0 + 0, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSPEndDisplayList(),
};

Vtx motos_hand_top_R_mesh_vtx_0[9] = {
	{{{0, 25, -47},0, {606, 613},{0x65, 0x3, 0xB4, 0xFF}}},
	{{{0, 142, -42},0, {588, 641},{0x65, 0x3, 0xB4, 0xFF}}},
	{{{31, 45, -4},0, {606, 670},{0x65, 0x3, 0xB4, 0xFF}}},
	{{{-32, 45, -4},0, {554, 635},{0x9B, 0x3, 0xB4, 0xFF}}},
	{{{0, 142, -42},0, {588, 641},{0x9B, 0x3, 0xB4, 0xFF}}},
	{{{0, 25, -47},0, {606, 613},{0x9B, 0x3, 0xB4, 0xFF}}},
	{{{31, 45, -4},0, {606, 670},{0x0, 0x2F, 0x76, 0xFF}}},
	{{{0, 142, -42},0, {588, 641},{0x0, 0x2F, 0x76, 0xFF}}},
	{{{-32, 45, -4},0, {554, 635},{0x0, 0x2F, 0x76, 0xFF}}},
};

Gfx motos_hand_top_R_mesh_tri_0[] = {
	gsSPVertex(motos_hand_top_R_mesh_vtx_0 + 0, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSPEndDisplayList(),
};

Vtx motos_head_mesh_vtx_0[45] = {
	{{{45, 32, -31},0, {647, 356},{0x12, 0x79, 0xDC, 0xFF}}},
	{{{1, 32, -52},0, {587, 356},{0x12, 0x79, 0xDC, 0xFF}}},
	{{{1, 49, 4},0, {587, 417},{0x12, 0x79, 0xDC, 0xFF}}},
	{{{1, 32, -52},0, {647, 356},{0xEE, 0x79, 0xDC, 0xFF}}},
	{{{-43, 32, -31},0, {587, 356},{0xEE, 0x79, 0xDC, 0xFF}}},
	{{{1, 49, 4},0, {587, 417},{0xEE, 0x79, 0xDC, 0xFF}}},
	{{{-43, 32, -31},0, {647, 356},{0xD9, 0x79, 0xF7, 0xFF}}},
	{{{-54, 32, 17},0, {587, 356},{0xD9, 0x79, 0xF7, 0xFF}}},
	{{{1, 49, 4},0, {587, 417},{0xD9, 0x79, 0xF7, 0xFF}}},
	{{{-54, 32, 17},0, {647, 356},{0xE0, 0x78, 0x19, 0xFF}}},
	{{{-23, 32, 55},0, {587, 356},{0xE0, 0x78, 0x19, 0xFF}}},
	{{{1, 49, 4},0, {587, 417},{0xE0, 0x78, 0x19, 0xFF}}},
	{{{-23, 32, 55},0, {647, 356},{0x0, 0x79, 0x28, 0xFF}}},
	{{{26, 32, 55},0, {587, 356},{0x0, 0x79, 0x28, 0xFF}}},
	{{{1, 49, 4},0, {587, 417},{0x0, 0x79, 0x28, 0xFF}}},
	{{{26, 32, 55},0, {647, 356},{0x20, 0x78, 0x19, 0xFF}}},
	{{{56, 32, 17},0, {587, 356},{0x20, 0x78, 0x19, 0xFF}}},
	{{{1, 49, 4},0, {587, 417},{0x20, 0x78, 0x19, 0xFF}}},
	{{{56, 32, 17},0, {647, 356},{0x27, 0x79, 0xF7, 0xFF}}},
	{{{45, 32, -31},0, {587, 356},{0x27, 0x79, 0xF7, 0xFF}}},
	{{{1, 49, 4},0, {587, 417},{0x27, 0x79, 0xF7, 0xFF}}},
	{{{1, 32, -52},0, {-16, 1008},{0x32, 0x37, 0x99, 0xFF}}},
	{{{45, 32, -31},0, {1008, 1008},{0x32, 0x37, 0x99, 0xFF}}},
	{{{64, -13, -46},0, {1008, -16},{0x32, 0x37, 0x99, 0xFF}}},
	{{{1, -13, -76},0, {-16, -16},{0x32, 0x37, 0x99, 0xFF}}},
	{{{-43, 32, -31},0, {-16, 1008},{0xCE, 0x37, 0x99, 0xFF}}},
	{{{1, 32, -52},0, {1008, 1008},{0xCE, 0x37, 0x99, 0xFF}}},
	{{{1, -13, -76},0, {1008, -16},{0xCE, 0x37, 0x99, 0xFF}}},
	{{{-62, -13, -46},0, {-16, -16},{0xCE, 0x37, 0x99, 0xFF}}},
	{{{-54, 32, 17},0, {-16, 1008},{0x90, 0x37, 0xE6, 0xFF}}},
	{{{-43, 32, -31},0, {1008, 1008},{0x90, 0x37, 0xE6, 0xFF}}},
	{{{-62, -13, -46},0, {1008, -16},{0x90, 0x37, 0xE6, 0xFF}}},
	{{{-77, -13, 22},0, {-16, -16},{0x90, 0x37, 0xE6, 0xFF}}},
	{{{-23, 32, 55},0, {1008, 1008},{0xA6, 0x37, 0x48, 0xFF}}},
	{{{-54, 32, 17},0, {1008, -16},{0xA6, 0x37, 0x48, 0xFF}}},
	{{{-77, -13, 22},0, {-16, -16},{0xA6, 0x37, 0x48, 0xFF}}},
	{{{-34, -13, 77},0, {-16, 1008},{0xA6, 0x37, 0x48, 0xFF}}},
	{{{56, 32, 17},0, {-16, 1008},{0x5A, 0x37, 0x48, 0xFF}}},
	{{{26, 32, 55},0, {1008, 1008},{0x5A, 0x37, 0x48, 0xFF}}},
	{{{36, -13, 77},0, {1008, -16},{0x5A, 0x37, 0x48, 0xFF}}},
	{{{80, -13, 22},0, {-16, -16},{0x5A, 0x37, 0x48, 0xFF}}},
	{{{45, 32, -31},0, {-16, 1008},{0x70, 0x37, 0xE6, 0xFF}}},
	{{{56, 32, 17},0, {1008, 1008},{0x70, 0x37, 0xE6, 0xFF}}},
	{{{80, -13, 22},0, {1008, -16},{0x70, 0x37, 0xE6, 0xFF}}},
	{{{64, -13, -46},0, {-16, -16},{0x70, 0x37, 0xE6, 0xFF}}},
};

Gfx motos_head_mesh_tri_0[] = {
	gsSPVertex(motos_head_mesh_vtx_0 + 0, 45, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(21, 23, 24, 0, 25, 26, 27, 0),
	gsSP2Triangles(25, 27, 28, 0, 29, 30, 31, 0),
	gsSP2Triangles(29, 31, 32, 0, 33, 34, 35, 0),
	gsSP2Triangles(33, 35, 36, 0, 37, 38, 39, 0),
	gsSP2Triangles(37, 39, 40, 0, 41, 42, 43, 0),
	gsSP1Triangle(41, 43, 44, 0),
	gsSPEndDisplayList(),
};Vtx motos_head_mesh_vtx_1[4] = {
	{{{-23, 32, 55},0, {306, -16},{0x0, 0x37, 0x73, 0xFF}}},
	{{{-34, -13, 77},0, {-22, 1008},{0x0, 0x37, 0x73, 0xFF}}},
	{{{36, -13, 77},0, {2150, 1008},{0x0, 0x37, 0x73, 0xFF}}},
	{{{26, 32, 55},0, {1822, -16},{0x0, 0x37, 0x73, 0xFF}}},
};

Gfx motos_head_mesh_tri_1[] = {
	gsSPVertex(motos_head_mesh_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_motos_motos_blue_sphere[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(motos_motos_blue_sphere_lights),
	gsSPEndDisplayList(),
};


Gfx mat_motos_motos_yellow_sphere[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(motos_motos_yellow_sphere_lights),
	gsSPEndDisplayList(),
};


Gfx mat_motos_motos_bolts[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, motos_motos_bolts_rgba32),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_32b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_32b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(motos_motos_bolts_lights),
	gsSPEndDisplayList(),
};


Gfx mat_motos_motos_face[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, motos_motos_face_rgba32),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_32b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_32b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(motos_motos_face_lights),
	gsSPEndDisplayList(),
};


Gfx motos_pelvis_mesh[] = {
	gsSPDisplayList(mat_motos_motos_blue_sphere),
	gsSPDisplayList(motos_pelvis_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx motos_leg_L_mesh[] = {
	gsSPDisplayList(mat_motos_motos_yellow_sphere),
	gsSPDisplayList(motos_leg_L_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx motos_foot_L_mesh[] = {
	gsSPDisplayList(mat_motos_motos_bolts),
	gsSPDisplayList(motos_foot_L_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx motos_leg_R_mesh[] = {
	gsSPDisplayList(mat_motos_motos_yellow_sphere),
	gsSPDisplayList(motos_leg_R_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx motos_foot_R_mesh[] = {
	gsSPDisplayList(mat_motos_motos_bolts),
	gsSPDisplayList(motos_foot_R_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx motos_arm_L_mesh[] = {
	gsSPDisplayList(mat_motos_motos_yellow_sphere),
	gsSPDisplayList(motos_arm_L_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx motos_hand_bottom_L_mesh[] = {
	gsSPDisplayList(mat_motos_motos_bolts),
	gsSPDisplayList(motos_hand_bottom_L_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx motos_hand_top_L_mesh[] = {
	gsSPDisplayList(mat_motos_motos_bolts),
	gsSPDisplayList(motos_hand_top_L_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx motos_arm_R_mesh[] = {
	gsSPDisplayList(mat_motos_motos_yellow_sphere),
	gsSPDisplayList(motos_arm_R_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx motos_hand_bottom_R_mesh[] = {
	gsSPDisplayList(mat_motos_motos_bolts),
	gsSPDisplayList(motos_hand_bottom_R_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx motos_hand_top_R_mesh[] = {
	gsSPDisplayList(mat_motos_motos_bolts),
	gsSPDisplayList(motos_hand_top_R_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx motos_head_mesh[] = {
	gsSPDisplayList(mat_motos_motos_bolts),
	gsSPDisplayList(motos_head_mesh_tri_0),
	gsSPDisplayList(mat_motos_motos_face),
	gsSPDisplayList(motos_head_mesh_tri_1),
	gsSPEndDisplayList(),
};



Gfx motos_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
