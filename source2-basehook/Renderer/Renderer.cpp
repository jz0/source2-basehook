#include "Renderer.hpp"

IVGuiPaintSurface* pRendererSurface = nullptr;

void EngineRenderer::DrawRect(int x, int y, int w, int h, Color color)
{
	pRendererSurface->DrawSetColor(color.r, color.g, color.b, color.a);
	pRendererSurface->DrawFilledRect(x, y, x + w, y + h);
}

void EngineRenderer::DrawOutlinedRect(int x, int y, int w, int h, Color color)
{
	pRendererSurface->DrawSetColor(color.r, color.g, color.b, color.a);
	pRendererSurface->DrawOutlinedRect(x, y, x + w, y + h);
}

void EngineRenderer::DrawGradientRect(Vector2D pos, Vector2D size, Color top, Color bottom, bool horizontal)
{
	pRendererSurface->DrawSetColor(top.r, top.g, top.b, top.a);
	pRendererSurface->DrawFilledRectFade(pos.x, pos.y, pos.x + size.x, pos.y + size.y, 255, 255, horizontal);

	pRendererSurface->DrawSetColor(bottom.r, bottom.g, bottom.b, bottom.a);
	pRendererSurface->DrawFilledRectFade(pos.x, pos.y, pos.x + size.x, pos.y + size.y, 0, 255, horizontal);
}

void EngineRenderer::DrawLine(int x0, int y0, int x1, int y1, Color color)
{
	pRendererSurface->DrawSetColor(color.r, color.g, color.b, color.a);
	pRendererSurface->DrawLine(x0, y0, x1, y1);
}

void EngineRenderer::DrawColoredCircle(int x, int y, float radius, Color color)
{
	//pRendererSurface->DrawSetColor(color.r, color.g, color.b, color.a);
	//pRendererSurface->DrawOutlinedCircle(250, 250, 50, 8);
	//pRendererSurface->DrawColoredCircle(x, y, radius, color.r, color.g, color.b, color.a);
	pRendererSurface->DrawColoredCircle(x, y, radius, color.r, color.g, color.b, color.a);
}

void EngineRenderer::DrawTexturedPolygon(int n, Vertex_t* vertice, Color color)
{
	static int TextureID = pRendererSurface->CreateNewTextureID(true);
	static unsigned char Buf[4] = { 255, 255, 255, 255 };
	pRendererSurface->DrawSetTextureRGBA(TextureID, Buf, 1, 1);
	pRendererSurface->DrawSetColor(color.r, color.g, color.b, color.a);
	pRendererSurface->DrawSetTexture(TextureID);
	pRendererSurface->DrawTexturedPolygon(n, vertice);
}

void EngineRenderer::DrawFilledCircle(Vector2D position, float smoothness, float radius, Color color)
{
	std::vector<Vertex_t> vertices;
	float step = (float)M_PI * 2.0f / smoothness;

	for (float a = 0; a < (M_PI * 2.0f); a += step)
		vertices.push_back(Vertex_t(Vector2D(radius * cosf(a) + position.x, radius * sinf(a) + position.y)));

	DrawTexturedPolygon((int)smoothness, vertices.data(), color);
}

void EngineRenderer::DrawString(unsigned long font, int x, int y, Color color, const char* str, ...)
{
	if (!str)
		return;

	va_list			arg;
	char			buffer[1024];
	wchar_t			wstring[1024];

	va_start(arg, str);
	_vsnprintf_s(buffer, sizeof(buffer), str, arg);
	va_end(arg);

	MultiByteToWideChar(CP_UTF8, 0, buffer, 256, wstring, 256);

	pRendererSurface->DrawSetTextPos(x, y);
	pRendererSurface->DrawSetTextFont(font);
	pRendererSurface->DrawSetTextColor(color.r, color.g, color.b, color.a);
	pRendererSurface->DrawPrintText(wstring, wcslen(wstring));
}