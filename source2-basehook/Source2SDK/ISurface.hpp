#pragma once

enum FontFlags_t
{
	FONTFLAG_NONE,
	FONTFLAG_ITALIC = 0x001,
	FONTFLAG_UNDERLINE = 0x002,
	FONTFLAG_STRIKEOUT = 0x004,
	FONTFLAG_SYMBOL = 0x008,
	FONTFLAG_ANTIALIAS = 0x010,
	FONTFLAG_GAUSSIANBLUR = 0x020,
	FONTFLAG_ROTARY = 0x040,
	FONTFLAG_DROPSHADOW = 0x080,
	FONTFLAG_ADDITIVE = 0x100,
	FONTFLAG_OUTLINE = 0x200,
	FONTFLAG_CUSTOM = 0x400,
	FONTFLAG_BITMAP = 0x800,
};

struct Vector2D
{
	Vector2D() {}
	Vector2D(float x, float y) { this->x = x; this->y = y; }
	float x;
	float y;
};

struct Vertex_t
{
	Vertex_t() {}
	Vertex_t(const Vector2D& pos, const Vector2D& coord = Vector2D(0, 0))
	{
		m_Position = pos;
		m_TexCoord = coord;
	}

	void Init(const Vector2D& pos, const Vector2D& coord = Vector2D(0, 0))
	{
		m_Position = pos;
		m_TexCoord = coord;
	}

	Vector2D	m_Position;
	Vector2D	m_TexCoord;
};

class ISurface
{
public:
	unsigned long CreateFonts(void)
	{
		using OriginalFn = unsigned long(__thiscall*)(void*);
		return CallVfunc< OriginalFn >(this, 51)(this);
	}

	void SetFontGlyphSet(unsigned long& font, const char* WindowsFontName, int tall, int weight, int blur, int scanlines, int flags)
	{
		using OriginalFn = void(__thiscall*)(void*, unsigned long, const char*, int, int, int, int, int, int, int);
		CallVfunc<OriginalFn>(this, 58)(this, font, WindowsFontName, tall, weight, blur, scanlines, flags, 0, 0);
	}

	void GetTextSize(unsigned long font, const wchar_t* text, int& width, int& tall)
	{
		using OriginalFn = bool(__thiscall*)(void*, unsigned long, const wchar_t*, int&, int&);
		CallVfunc<OriginalFn>(this, 66)(this, font, text, width, tall);
	}
};

extern ISurface* pSurface;

class IVGuiPaintSurface
{
public:
	void DrawColoredCircle(int centerx, int centery, float radius, int r, int g, int b, int a)
	{
		typedef void(__thiscall* OriginalFn)(void*, int, int, int, int, int, int, int);
		CallVfunc< OriginalFn >(this, 7)(this, centerx, centery, radius, r, g, b, a);
	}

	void DrawFilledRectFade(int x0, int y0, int x1, int y1, size_t alpha0, size_t alpha1, bool horizontal)
	{
		using OriginalFn = void(__thiscall*)(void*, int, int, int, int, size_t, size_t, bool);
		CallVfunc<OriginalFn>(this, 9)(this, x0, y0, x1, y1, alpha0, alpha1, horizontal);
	}

	void DrawOutlinedCircle(int x, int y, int radius, int segments)
	{
		typedef void(__thiscall* OriginalFn)(void*, int, int, int, int);
		CallVfunc< OriginalFn >(this, 10)(this, x, y, radius, segments);
	}

	void DrawSetTextFont(unsigned long font)
	{
		using OriginalFn = void(__thiscall*)(void*, unsigned long);
		CallVfunc< OriginalFn >(this, 13)(this, font);
	}

	void DrawSetColor(int r, int g, int b, int a)
	{
		using OriginalFn = void(__thiscall*)(void*, int, int, int, int);
		CallVfunc<OriginalFn>(this, 17)(this, r, g, b, a);
	}

	void DrawFilledRect(int x0, int y0, int x1, int y1)
	{
		using OriginalFn = void(__thiscall*)(void*, int, int, int, int);
		CallVfunc< OriginalFn >(this, 19)(this, x0, y0, x1, y1);
	}

	void DrawOutlinedRect(int x0, int y0, int x1, int y1)
	{
		using OriginalFn = void(__thiscall*)(void*, int, int, int, int);
		CallVfunc< OriginalFn >(this, 21)(this, x0, y0, x1, y1);
	}

	void DrawLine(int x0, int y0, int x1, int y1)
	{
		using OriginalFn = void(__thiscall*)(void*, int, int, int, int);
		CallVfunc< OriginalFn >(this, 22)(this, x0, y0, x1, y1);
	}

	void DrawSetTextColor(int r, int g, int b, int a)
	{
		using OriginalFn = void(__thiscall*)(void*, int, int, int, int);
		CallVfunc< OriginalFn >(this, 25)(this, r, g, b, a);
	}

	void DrawSetTextPos(int x, int y)
	{
		using OriginalFn = void(__thiscall*)(void*, int, int);
		CallVfunc< OriginalFn >(this, 26)(this, x, y);
	}

	void DrawPrintText(const wchar_t* text, int textLen)
	{
		using OriginalFn = void(__thiscall*)(void*, const wchar_t*, int);
		CallVfunc< OriginalFn >(this, 27)(this, text, textLen);
	}

	void DrawSetTexture(int id)
	{
		typedef void(__thiscall* OriginalFn)(void*, int);
		CallVfunc< OriginalFn >(this, 33)(this, id);
	}

	void DrawTexturedPolygon(int Count, Vertex_t* Vertices, bool bClipVertices = false)
	{
		typedef void(__thiscall* OriginalFn)(void*, int, Vertex_t*, bool);
		return CallVfunc< OriginalFn >(this, 38)(this, Count, Vertices, bClipVertices);
	}

	void GetTextSize(unsigned long font, const wchar_t* text, int& width, int& tall)
	{
		using OriginalFn = bool(__thiscall*)(void*, unsigned long, const wchar_t*, int&, int&);
		CallVfunc< OriginalFn >(this, 57)(this, font, text, width, tall);
	}

	int CreateNewTextureID(bool procedural = false)
	{
		typedef int(__thiscall* OriginalFn)(void*, bool);
		return CallVfunc< OriginalFn >(this, 60)(this, procedural);
	}

	void DrawSetTextureRGBA(int id, const unsigned char* rgba, int wide, int tall, int hw = 0, bool fr = true)
	{
		using OriginalFn = void(__thiscall*)(void*, int, const unsigned char*, int, int, int, bool);
		CallVfunc< OriginalFn >(this, 64)(this, id, rgba, wide, tall, hw, fr);
	}
};

extern IVGuiPaintSurface* pPaintSurface;