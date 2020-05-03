#pragma once
#include "../Source2SDK/SDK.hpp"
#include "../Include.hpp"

namespace EngineRenderer
{
	void DrawRect(int x, int y, int w, int h, Color color);
	void DrawOutlinedRect(int x, int y, int w, int h, Color color);
	void DrawGradientRect(Vector2D Position, Vector2D Size, Color Top, Color Bottom, bool Horizontal);
	void DrawLine(int x0, int y0, int x1, int y1, Color color);
	void DrawColoredCircle(int x, int y, float radius, Color color);
	void DrawTexturedPolygon(int n, Vertex_t* vertice, Color color);
	void DrawFilledCircle(Vector2D position, float smoothness, float radius, Color color);
	void DrawString(unsigned long font, int x, int y, Color color, const char* str, ...);
}

extern IVGuiPaintSurface* pRendererSurface;