#ifndef KGE_RENDERERD3D9_H
#define KGE_RENDERERD3D9_H

#include "../include/Renderer.h"
#include <d3d9.h>

namespace kge
{
	namespace gfx
	{
		class RendererD3D9 : public Renderer
		{
		public:

			//! Constructor
			RendererD3D9();

			//! Destructor
			~RendererD3D9();

			//! Initialize the renderer
			/*! test detail
				\param params The initialize parameters that user requested to
				initialize the renderer.
				\return Returns true on success.s
			 */
			bool Init(InitParameters &params);

			//! Clear the render target
			/*! 
				\param bColor Clear the color map?
				\param bDepth Clear the depth buffer?
				\param bStencil Clear the stencil buffer?
				\sa BeginRendering
			 */
			bool Clear(bool bColor, bool bDepth, bool bStencil);
		
			//! Begin the rendering
			/*! 
				\param bColor Clear the color map?
				\param bDepth Clear the depth buffer?
				\param bStencil Clear the stencil buffer?
				\sa Clear, EndRendering
			 */
			bool BeginRendering(bool bColor, bool bDepth, bool bStencil);

			//! End the rendering and draw to back buffer.
			/*! 
				\return Returns true on success.
			 */
			bool EndRendering();

		protected:

			LPDIRECT3DDEVICE9						m_pD3DDevice;			// D3D9 device
			IDirect3DSwapChain9*					m_pSwapChain;			// D3D9 swap chain
			D3DPRESENT_PARAMETERS					m_d3dpp;				// D3D9 present parameters
			D3DFORMAT								m_DSFMT;				// depth and Stencil Buffer
			D3DMULTISAMPLE_TYPE						m_msType;				// Multi sample type
			ul32									msQuality;				// Multi sample quality
			D3DCAPS9								m_d3dCaps;				// D3D9 Caps
			LPDIRECT3DSURFACE9						m_pBackBufferSurface,	// Main Back buffer surface
													m_pBackBufferZSurface;	// Main depth buffer surface
			kge::ul32								m_Behavior;				// Device Behavior
			D3DCOLOR								m_ClearColor;			// Clear Color

			// Search for the best depth and stencil format.
			void CheckStencil(const InitParameters &params);
			
			// Check stencil format
			bool CheckStencilFMT();
			
			// Check device if it is createable.
			bool CheckDevice(D3DCAPS9 *pCaps, DWORD dwBehavior);

		}; // RendererD3D9

	} // gfx

} // kge

#endif // KGE_RENDERERD3D9_H
