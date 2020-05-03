#include "PaintTraverse.hpp"

oPaintTraverse OriginalPaint;
void __fastcall hkPaintTraverse(void* panel, IVGuiPaintSurface* surface, unsigned long long VGUIPanel, bool ForceRepaint, bool AllowForce)
{
	OriginalPaint(panel, surface, VGUIPanel, ForceRepaint, AllowForce);

	static unsigned long long RenderSystemTop;
	if (RenderSystemTop == NULL)
	{
		const char* Name = pPanel->GetName(panel, VGUIPanel);

		//RenderSystemTopPanel
		if (Name[0] == 'R' && Name[6] == 'S' && Name[12] == 'T')
		{
			Msg(Color(255, 255, 255, 255), "Panel: %s \n", Name);
			RenderSystemTop = VGUIPanel;
		}
	}

	if (RenderSystemTop == VGUIPanel)
	{
		pRendererSurface = surface;

		EngineRenderer::DrawString(11, 550, 150, Color(255, 255, 255, 255), "Hello world!");
		EngineRenderer::DrawRect(150, 50, 50, 50, Color(255, 0, 0, 255));
	}
}
