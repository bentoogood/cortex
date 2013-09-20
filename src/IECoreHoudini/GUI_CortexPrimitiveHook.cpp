//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2013, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Image Engine Design nor the names of any
//       other contributors to this software may be used to endorse or
//       promote products derived from this software without specific prior
//       written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

/// GUI_PrimitiveHooks are used in Houdini 12.5, but do not exist in earlier versions.
/// Check GR_Cortex.cpp for Cortex viewport rendering in Houdini 12.0.
#include "UT/UT_Version.h"
#if UT_MAJOR_VERSION_INT > 12 || UT_MINOR_VERSION_INT >= 5

#include "IECoreHoudini/GR_CortexPrimitive.h"
#include "IECoreHoudini/GU_CortexPrimitive.h"
#include "IECoreHoudini/GUI_CortexPrimitiveHook.h"

using namespace IECoreHoudini;

GUI_CortexPrimitiveHook::GUI_CortexPrimitiveHook() : GUI_PrimitiveHook( GU_CortexPrimitive::typeName )
{
}

GUI_CortexPrimitiveHook::~GUI_CortexPrimitiveHook()
{
}

GR_Primitive *GUI_CortexPrimitiveHook::createPrimitive( const GT_PrimitiveHandle &gt_prim, const GEO_Primitive	*geo_prim, const GR_RenderInfo *info, const char *cache_name, GR_PrimAcceptResult &processed )
{
    return new GR_CortexPrimitive( info, cache_name, geo_prim );
}

#endif // 12.5 or later
